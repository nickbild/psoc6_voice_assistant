/******************************************************************************
* File Name:   main.c
*
* Description: This is the main file for mtb-example-ml-deepcraft-deploy-audio
* Code Example.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2024-2025, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include <float.h>

/* Model to use */
#include <models/model.h>

/*******************************************************************************
* Macros
********************************************************************************/
/* Desired sample rate. Typical values: 8/16/22.05/32/44.1/48 kHz */
#define SAMPLE_RATE_HZ              16000

/* Audio Subsystem Clock. Typical values depends on the desire sample rate:
- 8/16/48kHz    : 24.576 MHz
- 22.05/44.1kHz : 22.579 MHz */
#define AUDIO_SYS_CLOCK_HZ          24576000

/* Decimation Rate of the PDM/PCM block. Typical value is 64 */
#define DECIMATION_RATE             64

/* Microphone sensitivity
 * PGA in 0.5 dB increment, for example a value of 5 would mean +2.5 dB. */
#define MICROPHONE_GAIN             20

/* Multiplication factor of the input signal.
 * This should ideally be 1. Higher values will have a negative impact on
 * the sampling dynamic range. However, it can be used as a last resort 
 * when MICROPHONE_GAIN is already at maximum and the ML model was trained
 * with data at a higher amplitude than the microphone captures.
 * Note: If you use the same board for recording training data and 
 * deployment of your own ML model set this to 1.0. */
#define DIGITAL_BOOST_FACTOR            10.0f

/* Specifies the dynamic range in bits.
 * PCM word length, see the A/D specific documentation for valid ranges. */
#define AUIDO_BITS_PER_SAMPLE       16

/* PDM/PCM Pins */
#define PDM_DATA                    P10_5
#define PDM_CLK                     P10_4

/* Size of audio buffer */
#define AUDIO_BUFFER_SIZE           512

/* Converts given audio sample into range [-1,1] */
#define SAMPLE_NORMALIZE(sample)        (((float) (sample)) / (float) (1 << (AUIDO_BITS_PER_SAMPLE - 1)))

/* DEEPCRAFT compatibility defines to support all versions of code generation APIs */
#ifndef IPWIN_RET_SUCCESS
#define IPWIN_RET_SUCCESS (0)
#endif
#ifndef IPWIN_RET_NODATA
#define IPWIN_RET_NODATA (-1)
#endif
#ifndef IPWIN_RET_ERROR
#define IPWIN_RET_ERROR (-2)
#endif
#ifndef IMAI_DATA_OUT_SYMBOLS
#define IMAI_DATA_OUT_SYMBOLS IMAI_SYMBOL_MAP
#endif
/* End DEEPCFRAT compatibility defines */

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
static void init_board(void);
static void init_audio(cyhal_pdm_pcm_t* pdm_pcm);
static void halt_error(int code);
static void pdm_frequency_fix();


/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
* This is the main function for CM4 CPU. It initializes BSP, PDM micropohone and 
* the ML model. It reads audio data continuously, processes it within the model
* and displays the output.
*
* Parameters:
*  void
*
* Return:
*  int
*

*******************************************************************************/
int main(void)
{
    int16_t audio_buffer[AUDIO_BUFFER_SIZE] = {0};
    float label_scores[IMAI_DATA_OUT_COUNT];
    char *label_text[] = IMAI_DATA_OUT_SYMBOLS;

    cy_rslt_t result;
    size_t audio_count;
    cyhal_pdm_pcm_t pdm_pcm;
    int16_t prev_best_label = 0;
    int16_t best_label = 0;
    float sample = 0.0f;
    float sample_abs = 0.0f;
    float max_score = 0.0f;
    float sample_max = 0;
    float sample_max_slow = 0;

    /* Basic board setup */
    init_board();

    /* Initialize model */
    result = IMAI_init();
    halt_error(result);

    /* Initialize audio sampling */
    init_audio(&pdm_pcm);

    /* ANSI ESC sequence for clear screen */
    printf("\x1b[2J\x1b[;H\x1b[?25l;");

    for (;;)
    {
        /* Move cursor home */
        // printf("\033[H");
        // printf("DEEPCRAFT Studio Audio Model Example\r\n\n");

        /* Initialize the audio_buffer to zeroes and read data
         * from the pdm mic into it */
        audio_count = AUDIO_BUFFER_SIZE;
        memset(audio_buffer, 0, AUDIO_BUFFER_SIZE * sizeof(uint16_t));
        result = cyhal_pdm_pcm_read(&pdm_pcm, (void *) audio_buffer, &audio_count);
        halt_error(result);

        sample_max_slow -= 0.0005;
        sample_max = 0;
        for(int i = 0; i < audio_count; i++)
        {
            /* Convert integer sample to float and pass it to the model */
            sample = SAMPLE_NORMALIZE(audio_buffer[i]) * DIGITAL_BOOST_FACTOR;
            if (sample > 1.0)
            {
                sample = 1.0;
            }
            else if (sample < -1.0)
            {
                sample = -1.0;
            }
            result = IMAI_enqueue(&sample);
            halt_error(result);

            /* Used to tune gain control. sample_max should be near 1.0 
             * when shouting directly into the microphone */
            sample_abs = fabs(sample);
            if(sample_abs > sample_max)
            {
                sample_max = sample_abs;
            }

            if(sample_max > sample_max_slow)
            {
                sample_max_slow = sample_max;
            }
            /* Check if there is any model output to process */
            best_label = 0;
            max_score = -1000.0f;
            switch(IMAI_dequeue(label_scores))
            {
                case IMAI_RET_SUCCESS:      /* We have data, display it */

                    for(int i = 0; i < IMAI_DATA_OUT_COUNT; i++)
                    {
                        printf("label: %-10s: score: %.4f\r\n", label_text[i], label_scores[i]);
                        if (label_scores[i] > max_score)
                        {
                            max_score = label_scores[i];
                            best_label = i;
                        }
                    }
                    printf("\r\n");

                    /* Post processing
                     * If the previous best label still has a confidence score above > 0.05
                     * keep it as the best label. */
                    if(prev_best_label != 0 && label_scores[prev_best_label] > 0.05)
                    {
                        best_label = prev_best_label;
                        printf("Output: %-30s\r\n", label_text[best_label]);
                    }
                    /* Otherwise, if the best label is not "unlabeled", and conf score is above 0.5
                     * use it as best label. */
                    else if(best_label != 0 && max_score >= 0.50)
                    {
                        prev_best_label = best_label;
                        printf("Output: %-30s\r\n", label_text[best_label]);
                    }
                    /* Else the best label is "unlabeled" */
                    printf("\r\n");
                    printf("Volume: %.4f    (%.2f)\r\n", sample_max, sample_max_slow);
                    printf("Audio buffer utilization: %.3f\r\n", audio_count / (float)AUDIO_BUFFER_SIZE);
                    break;
                case IMAI_RET_NODATA:   /* No new output, continue with sampling */
                    break;
                case IMAI_RET_ERROR:    /* Abort on error */
                    halt_error(IMAI_RET_ERROR);
                    break;
            }
        }
    }
}


/*******************************************************************************
* Function Name: init_board
********************************************************************************
* Summary:
*    This function is a one-time setup for the board that initializes the device 
*    and board peripherals
*
* Parameters:
*    void
*
* Return:
*    void
*
*
*******************************************************************************/
static void init_board(void)
{
    cy_rslt_t result;
    /* Clear watchdog timer so that it doesn't trigger a reset */
    #if defined (CY_DEVICE_SECURE)
        cyhal_wdt_t wdt_obj;
        result = cyhal_wdt_init(&wdt_obj, cyhal_wdt_get_max_timeout_ms());
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        cyhal_wdt_free(&wdt_obj);
    #endif

    /* Initialize the device and board peripherals */
    result = cybsp_init();
    halt_error(result);

    /* Enable global interrupts */
    __enable_irq();

    /* Initialize retarget-io to use the debug UART port */
    result = cy_retarget_io_init_fc(
        CYBSP_DEBUG_UART_TX,
        CYBSP_DEBUG_UART_RX,
        CYBSP_DEBUG_UART_CTS,
        CYBSP_DEBUG_UART_RTS,
        CY_RETARGET_IO_BAUDRATE);
    halt_error(result);
}


/*******************************************************************************
* Function Name: init_audio
********************************************************************************
* Summary:
*    This function initializes and configures the PDM mic. It starts an  
*    asynchronous read which triggers an interrupt when completed.
*
* Parameters:
*   pdm_pcm        Pointer to the cyhal_pdm_pcm_t structure
*
* Return:
*     void
*
*
*******************************************************************************/
static void init_audio(cyhal_pdm_pcm_t* pdm_pcm)
{
    cy_rslt_t result;
    cyhal_clock_t audio_clock;
    cyhal_clock_t pll_clock;

    const cyhal_pdm_pcm_cfg_t pdm_pcm_cfg =
    {
        .sample_rate     = SAMPLE_RATE_HZ,              /* Sample rate in Hz */
        .decimation_rate = DECIMATION_RATE,             /* Decimation Rate of the PDM/PCM block */
        .mode            = CYHAL_PDM_PCM_MODE_LEFT,     /* Microphone to use (Channel) */
        .word_length     = AUIDO_BITS_PER_SAMPLE,       /* Bits per sample */
        .left_gain       = MICROPHONE_GAIN,             /* Left channel gain dB ("volume") */
        .right_gain      = MICROPHONE_GAIN,             /* Right channel gain dB ("volume") */
    };

    /* Initialize the PLL */
    result = cyhal_clock_reserve(&pll_clock, &CYHAL_CLOCK_PLL[1]);
    halt_error(result);
    result = cyhal_clock_set_frequency(&pll_clock, AUDIO_SYS_CLOCK_HZ, NULL);
    halt_error(result);
    result = cyhal_clock_set_enabled(&pll_clock, true, true);
    halt_error(result);

    /* Initialize the audio subsystem clock (CLK_HF[1])
     * The CLK_HF[1] is the root clock for the I2S and PDM/PCM blocks */
    result = cyhal_clock_reserve(&audio_clock, &CYHAL_CLOCK_HF[1]);
    halt_error(result);

    /* Source the audio subsystem clock from PLL */
    result = cyhal_clock_set_source(&audio_clock, &pll_clock);
    halt_error(result);
    result = cyhal_clock_set_enabled(&audio_clock, true, true);
    halt_error(result);

    /* Initialize the pulse-density modulation to pulse-code modulation (PDM/PCM) converter. */
    result = cyhal_pdm_pcm_init(pdm_pcm, PDM_DATA, PDM_CLK, &audio_clock, &pdm_pcm_cfg);
    halt_error(result);

    /* Clear PDM/PCM RX FIFO */
    result = cyhal_pdm_pcm_clear(pdm_pcm);
    halt_error(result);

    /* Workaround to fix PDM clock, see comment above. */
    pdm_frequency_fix();

    /* Start PDM/PCM */
    result = cyhal_pdm_pcm_start(pdm_pcm);
    halt_error(result);
}


/*******************************************************************************
* Function Name: halt_error
********************************************************************************
* Summary:
*    This function halts the execution using an infinite loop. If the given
*    parameter is 0 (for success) this function does nothing.    
*
* Parameters:
*    code          Return code from the calling function 
*                  
* Return:
*    void
*
*
*******************************************************************************/
static void halt_error(int code)
{
    if(code != 0)
    {
        for(;;) /* Infinite loop to halt the execution */
        {
        }
    }
}


/*******************************************************************************
* Function Name: pdm_frequency_fix
********************************************************************************
* Summary:
*    This function is a workaround to apply correct clock frequency to the mic.
*    This is to keep the clock frequency in range with mic specification.
*
* Parameters:
*    void
*
* Return:
*    void
*
*
*******************************************************************************/
static void pdm_frequency_fix()
{
    static uint32_t* pdm_reg = (uint32_t*)(0x40A00010);
    uint32_t clk_clock_div_stage_1 = 2;
    uint32_t mclkq_clock_div_stage_2 = 1;
    uint32_t cko_clock_div_stage_3 = 8;
    /* mic_freq / (2*16000) */
    uint32_t needed_sinc_rate = AUDIO_SYS_CLOCK_HZ / ( clk_clock_div_stage_1 * 
        mclkq_clock_div_stage_2 * cko_clock_div_stage_3 * 2 * SAMPLE_RATE_HZ);
    uint32_t pdm_data = (clk_clock_div_stage_1 - 1) << 0;
    pdm_data |= (mclkq_clock_div_stage_2 - 1) << 4;
    pdm_data |= (cko_clock_div_stage_3 - 1) << 8;
    pdm_data |= needed_sinc_rate << 16;
    *pdm_reg = pdm_data;
}
