/*
* ImagiNet Compiler 5.3.2704+410e4fb4b60c8e7a62c8d76d1afc33d002b21553
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 05/08/2025 00:46:07 UTC. Any changes will be lost.
* 
* Model ID  a6dcc9fd-116e-46fa-8561-e66662647223
* 
* Memory    Size                      Efficiency
* Buffers   40000 bytes (RAM)         100 %
* State     58128 bytes (RAM)         100 %
* Readonly  30324 bytes (Flash)       100 %
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param data_out Output features. Output float[3].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_dequeue(float *data_out);
* 
*  @description: Try write data to model.
*  @param data_in Input features. Input float[1].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_enqueue(const float *data_in);
* 
*  @description: Closes and flushes streams, free any heap allocated memory.
*  void IMAI_finalize(void);
* 
*  @description: Initializes buffers to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_init(void);
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "mtb_ml_model.h"

#include "model.h"

#ifdef __GNUC__
#define ALIGNED(x) __attribute__((aligned(x)))
#else
#define ALIGNED(x) __declspec(align(x))
#endif
// Working memory
static ALIGNED(16) int8_t _buffer[40000];
static ALIGNED(16) int8_t _state[58128];

// Parameters
static const uint32_t _K7[] = {
    0x0000001c, 0x334c4654, 0x00200014, 0x0018001c, 0x00100014, 0x0000000c, 0x00040008, 0x00000014, 
    0x0000001c, 0x000000a4, 0x000000fc, 0x00003880, 0x00003890, 0x00006d4c, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x00000050, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff84, 
    0x00000035, 0x00000004, 0x0000001c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 
    0x61727563, 0x302d7963, 0x00000000, 0x00000001, 0x00000004, 0xffffc75a, 0x00000004, 0x00000007, 
    0x75706e69, 0x00325f74, 0x00000002, 0x00000034, 0x00000004, 0xffffffdc, 0x00000033, 0x00000004, 
    0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 0x00415441, 0x000c0008, 0x00040008, 
    0x00000008, 0x00000032, 0x00000004, 0x00000013, 0x5f6e696d, 0x746e7572, 0x5f656d69, 0x73726576, 
    0x006e6f69, 0x00000034, 0x00003780, 0x00003778, 0x00003764, 0x00003748, 0x00003728, 0x00003708, 
    0x000036e8, 0x000036c8, 0x00003118, 0x000030d8, 0x00002d68, 0x00002cf8, 0x00002628, 0x000025b8, 
    0x00001ca8, 0x00001c18, 0x00001008, 0x00000f78, 0x00000f5c, 0x00000f1c, 0x00000ecc, 0x00000e7c, 
    0x00000e2c, 0x00000ddc, 0x00000ccc, 0x00000bbc, 0x00000aac, 0x0000099c, 0x0000078c, 0x0000057c, 
    0x0000036c, 0x0000015c, 0x00000154, 0x0000014c, 0x00000144, 0x0000013c, 0x00000134, 0x0000012c, 
    0x00000124, 0x0000011c, 0x00000114, 0x0000010c, 0x00000104, 0x000000fc, 0x000000dc, 0x000000ac, 
    0x000000a4, 0x0000009c, 0x00000094, 0x0000008c, 0x0000006c, 0x00000004, 0xffffc89e, 0x00000004, 
    0x00000058, 0x0000000c, 0x000e0008, 0x00040008, 0x00000008, 0x00000010, 0x00000028, 0x00060000, 
    0x00040008, 0x00000006, 0x00000004, 0x00000001, 0x000003eb, 0x000a0000, 0x000c0010, 0x00040008, 
    0x0000000a, 0x00000002, 0x00000002, 0x00000004, 0x00000006, 0x35312e32, 0x0000302e, 0xffffc902, 
    0x00000004, 0x00000010, 0x34312e31, 0x0000302e, 0x00000000, 0x00000000, 0xffff95e0, 0xffff95e4, 
    0xffff95e8, 0xffff95ec, 0xffffc92e, 0x00000004, 0x00000020, 0x08000800, 0x08000800, 0x08000800, 
    0x08000800, 0x08000800, 0x08000800, 0x08000800, 0x08000800, 0xffffc95a, 0x00000004, 0x00000010, 
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffff9638, 0xffff963c, 0xffff9640, 0xffff9644, 
    0xffff9648, 0xffff964c, 0xffff9650, 0xffff9654, 0xffff9658, 0xffff965c, 0xffff9660, 0xffff9664, 
    0xffffc9a6, 0x00000004, 0x00000200, 0x11d8f00a, 0xf0161e31, 0xde27382b, 0x0813eef3, 0x37ce0e1a, 
    0xe0dcd725, 0x38341e1c, 0xdf16e70a, 0x00c4e318, 0xfa11eaf8, 0xec28e61f, 0xdb2608bc, 0xf118c3d4, 
    0xf3eb1bb6, 0x2c1f3dd3, 0x1cca1907, 0xdbda7ffd, 0xd0be36e3, 0x030ae806, 0xdbb71d03, 0x0fb4fbab, 
    0xebccc7f9, 0x1cebcf0c, 0xd9a9d2ab, 0x0d35e8e9, 0xec14c2d6, 0x121112f6, 0xfeff01d2, 0x114a5a02, 
    0x23ebee03, 0x37331c2d, 0x502d083b, 0x72ebd4e7, 0x293cef31, 0xee02174f, 0x0a1d30ec, 0x44c5ffd2, 
    0xb9f2d836, 0xea274ce1, 0x98f6e7ca, 0x4701f6c4, 0xf4f4f308, 0xdc514515, 0x050f14d1, 0x20ce26e4, 
    0xf8eb1035, 0xfb4e4eed, 0x1f33b8e6, 0xe9e321f1, 0xecd82641, 0xeb0f1f1d, 0x0b29b41e, 0x0b2accf5, 
    0xf9c7da1a, 0x080fd6e5, 0xf2e80421, 0x019e2b12, 0x9a0f6632, 0x6de0a740, 0xd6dabf2c, 0x2b050b20, 
    0xffedceb6, 0xb3d20dcd, 0x12bb1eed, 0x490fe6fc, 0xe802d1e4, 0xb9130bf6, 0x3bfb4f17, 0x603dde30, 
    0xec0300f6, 0x13162c52, 0x55fb0a06, 0x13d9131b, 0xd8e3290f, 0x0d07d915, 0x12cf30f9, 0x1df0d2de, 
    0xf1bf1118, 0xe9db0ce9, 0xd6ab31d5, 0x411f1923, 0x224227ea, 0x17fb55e3, 0x37f4f4d8, 0x1c461e42, 
    0x1f2c154b, 0x54493e28, 0x3ce01010, 0xc8344f05, 0xffe31829, 0x05f2e8ec, 0x17e4241b, 0xd0d4dbcd, 
    0x19c8dd49, 0xdcf4dcea, 0x0ac121f5, 0x500c4adb, 0x1305ec36, 0xe33c1e44, 0x1e0ad83f, 0x1c00db21, 
    0xdd0dfede, 0x35252f0a, 0x162ee32c, 0x56fee3e3, 0x25f806cf, 0xd24e1a13, 0x39152819, 0x141d0433, 
    0x2b3e3605, 0xf15b5b0e, 0x28331213, 0x15212814, 0xf63422df, 0xf1f9f916, 0x133102d8, 0x0e69fe0b, 
    0x343f280e, 0xb1fe4432, 0x4f07e944, 0x29dd191f, 0xed2a28e9, 0xdaea4e12, 0xe1e22ae1, 0x4c1933d5, 
    0xf0b7ddd4, 0x04df5bf2, 0xd006e6c9, 0xffffcbb2, 0x00000004, 0x00000200, 0x39521a44, 0x3b350e1e, 
    0x4d0e074f, 0x3d2d2d23, 0x342c0033, 0x15161946, 0x62532c51, 0x073f2b34, 0xd1c0fae1, 0x161bfce7, 
    0x03e0cb20, 0xe0e5261f, 0x29ea23d1, 0xfee80eba, 0xe31fdfdf, 0x05a81a09, 0x1bd17f1d, 0xd9203b36, 
    0xfb1fb912, 0xeeeb35ed, 0x1b03c508, 0x02c1adc6, 0x01ff15ee, 0xdac8e2d1, 0x2100e535, 0x2b0f2b24, 
    0x0d0a0139, 0xc1190923, 0xe0123821, 0xfac1ffbf, 0x23f232dc, 0xdcc91120, 0x1d1e3116, 0x1dee3004, 
    0xe8211307, 0x1a51bdfd, 0xfe17000b, 0x2228ec03, 0x56030000, 0x2ee21e4a, 0x123f314f, 0x443d0041, 
    0x2a344829, 0x06603c2b, 0xfe363214, 0x483b092c, 0x61151c0c, 0xf8432f49, 0x19f85609, 0x2a411b41, 
    0x26441e38, 0x4a013f2c, 0xf8160112, 0x3d3e041b, 0x1d53472b, 0x3a3c0b1a, 0x3642320d, 0x31291cec, 
    0xf7694e3e, 0x22fa14fb, 0xef28f823, 0x16110d46, 0x672c143d, 0x12582a31, 0x44ef68fe, 0xdde10d5a, 
    0x3247de37, 0x362ffd11, 0xfa1a02ec, 0x2934f0ef, 0x14103124, 0x393821e4, 0x35d521d8, 0x1d1612db, 
    0xd36825ed, 0xfa034fed, 0x3b02e5b7, 0xd7cee306, 0xed010dbe, 0xf2dcbaf4, 0xf60be452, 0xe5157235, 
    0x1a123767, 0xc901d34a, 0xfbb50dd6, 0xe5dabccf, 0xe83717e2, 0xdbe311d3, 0xfaf34504, 0x052d1239, 
    0x433d1ff4, 0x0030ed2a, 0x46ec330c, 0xf4240a21, 0x0243e033, 0x3b4201eb, 0x331f3c29, 0x39370228, 
    0x14f6235d, 0x04010821, 0x15243c39, 0x3d4d5041, 0x5b552916, 0xfe150749, 0x40d91713, 0xfefd3f64, 
    0x55fac46f, 0xdefae844, 0x25150c48, 0xec2b0906, 0xf8f10a2c, 0x2fce0617, 0x0ddbf51b, 0xf2f60c5e, 
    0x2529074c, 0xcbf4253e, 0xf624fd27, 0x2df5f6cc, 0xddfb191a, 0x2ce90d0f, 0x193c2816, 0x2d37e9fe, 
    0x280a07f7, 0x1839161a, 0x29ff34f2, 0x3902ec01, 0xf9f01f04, 0x013805e9, 0xffffcdbe, 0x00000004, 
    0x00000200, 0xc4d20aee, 0xd0c6cade, 0x32f6cb09, 0x1923e2e6, 0xe301c1d0, 0xf60ee6e2, 0x2bd3c41a, 
    0x452ac104, 0xefeff2fe, 0xdddcf902, 0xe3dd3cdb, 0xfa37d7f9, 0xe626d814, 0x0320584f, 0x11290538, 
    0x1027294b, 0x221d05d7, 0x03221e14, 0x4ab2ec06, 0xfc09c638, 0xf5ca2aef, 0xcd14e149, 0x243100e2, 
    0xe9d802ea, 0xdd25502e, 0x1de4f5e9, 0xfdedd1d3, 0xe9d3c4f7, 0xe4453503, 0x237d5723, 0xeb11d465, 
    0x20400a02, 0xfe25fff1, 0x1a13240c, 0xe7bdec00, 0xb848ef3d, 0xdfdcfbcf, 0x2d4229ec, 0xe99c0f23, 
    0x570905ef, 0x84dc1509, 0xb188f801, 0x06e0e0d6, 0x0b10fcd3, 0xd72b0b1a, 0x2c5236e3, 0x2e0cb223, 
    0x391cdb0c, 0xc027e6e5, 0xdcc04e4a, 0x67b9e506, 0xd8edec25, 0xbaee21f3, 0x4314f9df, 0x0bc3e735, 
    0x5a252029, 0x4de0f4e1, 0x1562e8b3, 0xa35026f3, 0xc11016dc, 0x52cc2221, 0xbd03eefa, 0x25f529db, 
    0xfbfaede1, 0x2bac1ff4, 0xc53cbeeb, 0xcaf8de2b, 0xd2df5223, 0x2ec71ab7, 0xd0d7d9a3, 0xdbdf090b, 
    0x27c2e520, 0xfdd9e718, 0x0c28d83a, 0x44ec180d, 0x3812c50e, 0xdae8dcf3, 0xfb1c1d3e, 0xe222bb13, 
    0x3131babc, 0xc745fe24, 0x4cd12adc, 0x09e5f52c, 0x0cf5ea19, 0xfe552c40, 0xfa16051f, 0xbde6da01, 
    0xf0d5012b, 0x00f148ce, 0xedcdebc1, 0x8118df01, 0xa52738ab, 0xcee6b9d9, 0xead1be01, 0x20d000f0, 
    0xeee2fdcd, 0x3710123d, 0x22f83440, 0x123a36f5, 0xf9521619, 0xf232562d, 0xeff7fcd5, 0x606f26e8, 
    0xd80e2c12, 0x0d54f622, 0xeed634d4, 0xf0c5440b, 0x1cd2ba12, 0xce2b3122, 0x1c15432e, 0xdc2cbb26, 
    0xe54b4334, 0x3312ef03, 0x0c30df22, 0xe5de1fd3, 0xc4f64816, 0x2fb1bd19, 0xcdceefb1, 0xcb2e37e1, 
    0xdffdfd0a, 0x650d4f23, 0x3817f718, 0xfbe54f50, 0xd116441f, 0x1a073a29, 0x1d1010cb, 0xef4a15e5, 
    0x201ae001, 0xffffcfca, 0x00000004, 0x00000200, 0x0d1f0103, 0x3c20ebd5, 0xfc3057e3, 0x344426f5, 
    0x35020511, 0x051e133b, 0x26385220, 0x1753240e, 0xfbf00b08, 0xe407100c, 0xec16d430, 0xdd092116, 
    0x2fe70df5, 0xeef9cfdb, 0xf4092309, 0xe4e9100b, 0x08b67f12, 0xd4062eff, 0x30fbcd4c, 0xd2de58ff, 
    0x2d17e4e5, 0xd9e5dce4, 0xe109f1ec, 0x00f112e7, 0x2714e933, 0x20002d25, 0x4e18371a, 0x0afb0604, 
    0x1efcef0c, 0x04da071d, 0x003512d4, 0x021d042a, 0xfa2261ff, 0x29010e0c, 0x07274313, 0x25294809, 
    0x592d4903, 0x1c2efe58, 0x565c2706, 0x1e1c242b, 0x141d2f0a, 0x0a66ebf6, 0x062f0b00, 0x552a5425, 
    0x17081d2c, 0x44084a60, 0x10272e2a, 0x0c4e4043, 0x26046408, 0x30194021, 0xf12f212e, 0xfd2c0d14, 
    0x3624242e, 0x2e181b34, 0x46280234, 0x11262617, 0x243668e8, 0x064c044a, 0x253d3240, 0x1d021b31, 
    0x2306ecfe, 0x0d2b201b, 0x10111a26, 0xf5260714, 0xfc106830, 0xf51e2b22, 0xff280e2c, 0x29ee3611, 
    0x491406f9, 0xfafe2034, 0x10f60a07, 0x0c23ccf6, 0x112267f1, 0x1bfb30ef, 0xef206d33, 0x2ede5033, 
    0x54fff623, 0x24fc020d, 0xfb1b1317, 0x20f7fa18, 0x0fd8232d, 0xf7204942, 0x47292b15, 0x131f2029, 
    0x163009ff, 0x0a121619, 0x222936f4, 0x081d10ee, 0x23cf3fea, 0xd21cf80d, 0x131fdd21, 0xf6f5540d, 
    0x111fd30b, 0x0a0b0425, 0xdc070ef1, 0x202e13f4, 0x01e43831, 0xed0b0efb, 0x15fcb351, 0xf330f029, 
    0x0b0ee933, 0x18212200, 0x1b1df02f, 0x09e74df4, 0x08cc2a19, 0xee170f3c, 0x46200e56, 0x2e0c2030, 
    0x3f1e20d3, 0x18e90d23, 0x1f27fe00, 0x2c2af7ff, 0x0cf0362b, 0x07ea3d52, 0x091fda3c, 0x13ffff19, 
    0x0f20def0, 0x14fee91c, 0x1a32eb12, 0xf331d12b, 0xeee0f520, 0xdaeefc08, 0xdcf6d90c, 0xe92126ed, 
    0x02f71206, 0xebfd2e0c, 0xd9e00c16, 0x1ae6111c, 0xffffd1d6, 0x00000004, 0x00000100, 0xd1db033e, 
    0x4ed432b6, 0x31c9e21e, 0xe63ad2f4, 0xbff11531, 0x43f024f0, 0x37c6e04f, 0xe34caff3, 0x09fdf5ed, 
    0xcf350401, 0xe8dae92e, 0xfff111fa, 0xfa01dadc, 0xfcf1f6f7, 0x20e5f615, 0x01270412, 0xdcfdd92c, 
    0x1e4e02db, 0x01ebf52c, 0xf511e4db, 0xafaeed2f, 0x400326ce, 0x5b81b54c, 0xf14abce5, 0xca0bd63c, 
    0x3ffd3313, 0x30c8d81c, 0xfe30e2e2, 0xfc25f5ff, 0xff000b0f, 0x1f271124, 0xeafc1405, 0x23001819, 
    0x022a200a, 0x2135f606, 0xdfeeff01, 0x1101eae7, 0xdd260511, 0xe800f018, 0x39f40126, 0x1147ee0a, 
    0x24cd00f1, 0xf2030e02, 0x02f01bf7, 0x0a2ee5d3, 0xf9eedbc3, 0xf01c05f5, 0x2afc0f06, 0xcff51ee9, 
    0x0cf003d0, 0x0dbfec0d, 0xec5adddc, 0x160fef12, 0x29e81a04, 0x32133003, 0xdc25f5ed, 0x381b11f9, 
    0x130d121b, 0x0f291bff, 0xdb0305df, 0xfef3e8e2, 0x05f9e6d7, 0xeaf3fb04, 0xf60ff1e2, 0xffffd2e2, 
    0x00000004, 0x00000100, 0x2d520cc2, 0xd717e511, 0xa52d25ee, 0x19f35821, 0xd2cebdd1, 0x56da0c01, 
    0x1cd66817, 0x041cc0e6, 0x21b8dbd6, 0x28180ffe, 0x15feb207, 0xe8bd21ec, 0x4c3aece5, 0xce10e32d, 
    0xf66627e0, 0x10d22a10, 0x52401053, 0x779ec607, 0x092931d1, 0x03e61dca, 0x2c38e7cd, 0x85ebd600, 
    0x9935169c, 0x7ff71549, 0x03250a9e, 0xfad7f3cb, 0xa5ebf10c, 0x35f12b0a, 0x2cff0cda, 0x19b2dcdd, 
    0x860c1714, 0x1803fb2e, 0x23e102ea, 0x12f204db, 0x2ed4021c, 0x1eef011e, 0xf7f2edea, 0xee3d2e2f, 
    0xbf22af47, 0x03e70c47, 0x265bc904, 0x3cdc4011, 0x10105210, 0x031cda28, 0x250ae6d8, 0xeff403df, 
    0x092d2feb, 0x0b0fed17, 0x0e6b19e0, 0xd975e342, 0xe8591ed9, 0x2ae10a19, 0x0c1fc00a, 0x23f92ff3, 
    0xf52d16d7, 0x08f42e2d, 0x1a48e4fa, 0xffed9ae9, 0x0de925df, 0x0704f336, 0x141eacdc, 0xfad2dd19, 
    0xf50cf7e0, 0x11232a13, 0xffffd3ee, 0x00000004, 0x00000100, 0x1b10f176, 0xd467504e, 0xd9301403, 
    0x00d53ad9, 0x29110e18, 0xe612181d, 0x110d1dcc, 0xfbef3ff9, 0x3f110011, 0x081a3513, 0x0c281ef4, 
    0xded025fd, 0x4f171c08, 0xdb01041a, 0xf32c0fdf, 0xf5c316f5, 0x2f1b14e7, 0xad5518fd, 0xce6ddcc4, 
    0x24c360f9, 0x1d0e323e, 0xdd545510, 0xec332ccc, 0xe6a803e2, 0xeab8d90c, 0x813a33fd, 0xff1cbf03, 
    0x0d0e27e7, 0xfb12f814, 0x4901ff2b, 0x1b01f804, 0x01170406, 0xde1800fc, 0x350d02f2, 0x09efff20, 
    0x131eedf9, 0x2a35ff2e, 0xcf2927e1, 0xf11002cd, 0xd4e237e4, 0x2d161114, 0xd504f301, 0x0f0424d4, 
    0xc4cf531d, 0xbce4fd09, 0x1df4e9ff, 0xe0f5f52b, 0x1ef5e70b, 0xe60c0fd9, 0x10dbecec, 0x15dc2712, 
    0x0b12017c, 0x26360df4, 0xe708f4ed, 0x071e00e0, 0x00ea111b, 0xbcf2e7e4, 0xe1e3ff03, 0x1ee0071d, 
    0xdf09c3f3, 0x3400e0f4, 0x0124fce0, 0xce03e9fa, 0x1d0f122d, 0xffffd4fa, 0x00000004, 0x00000100, 
    0xfff6b8c4, 0x00d7a690, 0xfc289405, 0x5a17f612, 0xedeed1c3, 0x50d805ea, 0x5ab7da40, 0x464f8800, 
    0xc001ccb9, 0x0b23def2, 0xed0adb1a, 0x34d413fa, 0xe420c39f, 0x121fc3df, 0xcdd0bec4, 0x13f9f529, 
    0xe8e5ceef, 0x0fccf7f3, 0xf6bdda3b, 0x2c46d332, 0x19f2e7e3, 0x0ac5beea, 0xf5e9da04, 0x412ff838, 
    0xf93bd9ee, 0xf0fcdfba, 0xea08060e, 0x31f11319, 0x0837c221, 0x1fed0904, 0xf8f4f61d, 0x2b000bdc, 
    0xf0180bfc, 0xe71716c2, 0x21f4233b, 0x1e1af0fd, 0x0fd6e2ef, 0x1b09dce5, 0xe6fed433, 0x7fbefc3c, 
    0xe3fcd9ff, 0xe3edd0af, 0x01f0f825, 0x3d23fae1, 0x2a07daf0, 0xe91803f3, 0xd41be0f2, 0x0cfa0c2a, 
    0xe8e902a5, 0x25e1bdb2, 0xf8ece806, 0x484c24f3, 0xf1f4c2eb, 0xd81310c3, 0xd7cef9f8, 0x141db3fb, 
    0x1022e5d3, 0xe6ac07a5, 0x03e4fc11, 0x16f1db0c, 0xbab6c1e4, 0x3eb0ddb9, 0xeb0ae41b, 0xe353d530, 
    0xffffd606, 0x00000004, 0x00000040, 0x00000270, 0xfffffe21, 0x00000121, 0x0000001f, 0x00000288, 
    0x00000274, 0x00000005, 0xffffff78, 0x000000f2, 0x0000026f, 0x00000192, 0x0000018f, 0x00000438, 
    0x000000cd, 0xffffff5d, 0x00000077, 0xffffd652, 0x00000004, 0x00000040, 0x000017f7, 0x000013db, 
    0x0000135c, 0x000015a0, 0x00001562, 0x000019c4, 0x000018bd, 0x0000162a, 0x000015b0, 0x000013d4, 
    0x0000148f, 0x0000143b, 0x00001775, 0x0000159e, 0x000015d0, 0x00001557, 0xffffd69e, 0x00000004, 
    0x00000040, 0xfffffef3, 0x0000001e, 0xfffffd6e, 0xffffff6d, 0x00000022, 0xfffffe10, 0x00000050, 
    0x00000110, 0x000000e2, 0xfffffe1c, 0xfffffeaa, 0x000000c8, 0x0000020d, 0xffffffc2, 0x000000d0, 
    0x0000027d, 0xffffd6ea, 0x00000004, 0x00000040, 0x00000315, 0x00000197, 0x00000207, 0x000003db, 
    0x0000027f, 0x000003ef, 0x00000421, 0x0000032f, 0x000001f6, 0x00000255, 0x000002db, 0x000000f7, 
    0x0000028f, 0x0000023f, 0x00000216, 0x0000007b, 0xffffd736, 0x00000004, 0x00000030, 0x08452ebd, 
    0xb20dbd0e, 0xbf0ffdb2, 0xe8eb4d1e, 0xee87b29d, 0x7a8b9dbe, 0x24c38142, 0xee3dd853, 0x0d1f1f40, 
    0xf24a4349, 0x2f0634dd, 0xc01f2db8, 0xffffd772, 0x00000004, 0x0000000c, 0x00000112, 0x0000062f, 
    0xfffff891, 0xffffd78a, 0x00000004, 0x00000080, 0x000017d8, 0xfffffc96, 0xfffff144, 0x00001489, 
    0xffffe0b9, 0xfffffe99, 0x000017f6, 0x000029c7, 0x000032cd, 0xffffeb6c, 0x0000094d, 0xffffd31a, 
    0x00002dcb, 0x00000d91, 0xfffffd58, 0xfffff52a, 0xffffcab1, 0xffffc312, 0xffffb1d9, 0xffffe336, 
    0xffffdb43, 0xffffdbb1, 0xffffe288, 0xffffa7a5, 0xffffda5f, 0x00002806, 0xffffe551, 0x00002771, 
    0xfffff812, 0xfffff21c, 0x00001117, 0x0000045a, 0xffffd816, 0x00000004, 0x00000c00, 0x22f72d16, 
    0xbed84bed, 0x0abacaf1, 0xabe92b33, 0x08f5d1dc, 0x33d7b90e, 0x12f50727, 0x9f0aeecc, 0x0fe6fcec, 
    0xb1c2f6c2, 0xb4c427e7, 0xe4f325e5, 0xf8d4e4cd, 0x0244b021, 0x31f32201, 0xe43b28d8, 0xc4e83a27, 
    0xb70d36ef, 0xf1fc4988, 0x42fcee1b, 0x18b8f114, 0x07e8ae39, 0xcc5bfe94, 0xa3e27fff, 0xfdd9f746, 
    0xff213ff8, 0xdc047fcb, 0x020162cf, 0x091e190b, 0x18fde4f9, 0xcb1d10d4, 0x0011f604, 0x17ded33b, 
    0xe7111204, 0x0cd320f7, 0xf4e7f6cf, 0xf1f1e9e1, 0xead30a18, 0xd104fddf, 0x220a141f, 0xf8e3d71f, 
    0x091cf200, 0x0e0229d8, 0x38ee240e, 0x0310c808, 0x05f41710, 0xd5252804, 0xdf061624, 0xcef0d617, 
    0x10fedde3, 0xe41dcf00, 0x1534b92d, 0x4d3af7f1, 0x10e93001, 0xc281d00a, 0x06ede7e0, 0x222808e3, 
    0x22164be6, 0x2727cdd5, 0xff12de17, 0x59172a02, 0x2f01ced1, 0xddf1f134, 0x33df1001, 0x1b0f0ce5, 
    0xd4fada23, 0xfa23e428, 0x5dfde015, 0xf80415d8, 0x11d81b1f, 0xf2f12028, 0x32c4422b, 0xd4e5c707, 
    0xef5abc28, 0xe913e3e9, 0xb4f92021, 0xf4f2fa04, 0x15d518e9, 0xe4070f29, 0xc603eff5, 0xeedf24ce, 
    0xf9dd56c7, 0xeedf282e, 0x7fc532f0, 0x010323e2, 0x26f82b08, 0x49003306, 0x403d5aca, 0x37f7ab40, 
    0xf901e811, 0x04edf61a, 0x99c44e22, 0x222920fc, 0x4525c7b0, 0xc5a4a0ff, 0x1a21952f, 0x080cf001, 
    0x02f11de7, 0xe9d8f717, 0x12ff45ec, 0x0c00031d, 0xf927f406, 0x077f38cc, 0x08120b20, 0xf124ded1, 
    0xfc09db1d, 0xf6112900, 0x09e00f06, 0xe5ff0613, 0xfdfef6e4, 0xcd392209, 0xee18e508, 0x300eebd1, 
    0x0a12e6d5, 0x1c0e1b13, 0x0e14ffd9, 0xd42bf402, 0xe31c330e, 0x015a2908, 0xff400ac9, 0xecf0c1e7, 
    0x42d53ac8, 0xc308e631, 0x07a4df81, 0xc805fc2d, 0x0717d3ea, 0xca515d20, 0xc2f31222, 0xafeae5d7, 
    0x354fcfe5, 0x0bd2e006, 0x17a04fe6, 0x0accf7d0, 0xc5f233c5, 0x19733ded, 0x19f83e34, 0x4a3acb40, 
    0x511434fc, 0xa91f61af, 0x52e40482, 0xf3c4d8e5, 0x24d4caa8, 0x224d78a2, 0xeb1c2ccb, 0xf1bca6e9, 
    0x3203fa45, 0x620fb0f5, 0x81f0bbf5, 0x0c0144d7, 0xf435de38, 0x34bf9e27, 0xfa9beaf7, 0xced94de2, 
    0x03f9110b, 0xf3eb1804, 0x68bb260d, 0xf7f727df, 0x032fffb4, 0x66ff1818, 0x031e49e6, 0x33d9f3db, 
    0x06e02be3, 0x351f2c16, 0xdd073ffc, 0x45ea1ac0, 0x1d34c7b1, 0xfabfdcde, 0x39e2e43d, 0x2cd9afc0, 
    0xbdc7ac00, 0x0a7ff9fa, 0x184f0437, 0x292b28d1, 0xbe17f2e7, 0x9a04c843, 0xdfcdcac5, 0x24071c0d, 
    0x2beca4c8, 0xaaf0fb43, 0x4e43e6f8, 0x0a1009ec, 0xb59acef2, 0x0a24d90f, 0x13fda203, 0xf51474fe, 
    0xd60dd1f1, 0x9325b7c8, 0x6fc7fd76, 0x66e3aa8a, 0xf6b6a3d0, 0xcbd5f0dc, 0x5913e40a, 0xe0d0d70e, 
    0xfdc5f71f, 0xdcc17fdc, 0x390255ca, 0xc4fbc0f9, 0xccf51dcf, 0xd91149f4, 0x2c020b31, 0xfdc9f1ec, 
    0x35f70abe, 0xfe0271f3, 0xcabb339c, 0xf0eadce8, 0xecf232db, 0xe637e51e, 0x1200fdcc, 0x29051acb, 
    0x35efe2f9, 0xd1ae0dea, 0xd5e414f0, 0xe5e4c015, 0xd5c9d408, 0xe911300c, 0xe129d9a5, 0x219f280e, 
    0x1504230e, 0x047fe8cd, 0x73f91415, 0x47fb16a5, 0x11083718, 0x0edd39e7, 0x213d6034, 0xcb09cab9, 
    0xcb12dce7, 0x3e232ce0, 0xcef7ef47, 0x4e47fabc, 0xfbe911ff, 0x0fe1ddcf, 0x0ee1084b, 0x023cebfa, 
    0x0fe2a8de, 0x2057c6d4, 0xd62de54a, 0x715af7e3, 0xe2faba1c, 0xef1cc5dc, 0x47d8cbef, 0x09bd4cfe, 
    0x19245d10, 0xad2627d7, 0x7fd051ed, 0xfdbe16fe, 0x2422de06, 0xe31600f7, 0x4e3d440d, 0x1a14dce8, 
    0x14e10d2b, 0x2dd84c05, 0xc3e70a18, 0xe2e4d3e1, 0xce281309, 0x1aebeaf5, 0x30bacc35, 0xcc19e4fb, 
    0xcc1ad943, 0xec27e815, 0x9300dfce, 0x08160f23, 0xdbe7e52a, 0xdcd6e2f6, 0xefb4d6fe, 0x09ffd2ce, 
    0x06ddf81d, 0x38fbf0ff, 0xfb19e9a3, 0x1c1d14e0, 0x3b192805, 0x197f3000, 0xf31415f1, 0x04f723e9, 
    0x1404dbe8, 0x3a090cf9, 0x1af5fd25, 0x03193fec, 0x1434ef0b, 0xf62e3fe6, 0x042c04e2, 0xf42afaf2, 
    0xf51320da, 0x0f0eed14, 0x29f304f5, 0xdef00e07, 0x07f7f7f5, 0xec554af3, 0xe71b38c5, 0x39ccc9f3, 
    0x13ebde01, 0x1fe3def4, 0xf2a7f281, 0xcb080117, 0xa626dac5, 0xd97f1dd6, 0xd30efebd, 0xd6ecf9b8, 
    0xeb0dc42a, 0x32ca170e, 0x10a94bfc, 0xb4e7cd01, 0x13e21cd1, 0xbd243dce, 0x1613e605, 0xe1c8050c, 
    0xcbc7d9c2, 0x320519eb, 0x28dbf3e2, 0x00172018, 0xb8b7abc2, 0xad755faf, 0x0a253202, 0xf7b2162b, 
    0x2cf15c3f, 0x2316e718, 0xbacd51e5, 0x01c91f15, 0x6368c5f5, 0x34d19255, 0x0f1bd83f, 0x47ce1c7f, 
    0x272eb738, 0x5ab51225, 0xb9b4f0b1, 0xdaf94517, 0x4f59ecf4, 0xff2da203, 0xdd20b640, 0x9dededfe, 
    0xb5e9b650, 0x5d06d1cb, 0xdbf3e505, 0xfec51817, 0x022617fa, 0xf415bb51, 0xc9da15c7, 0x6b48f4d4, 
    0x29fefa05, 0xfcf53359, 0xba3fee23, 0xd714952c, 0xa2a73171, 0x2d60d90a, 0xc22a958a, 0x34002704, 
    0x162bc7c7, 0x1308e805, 0x8135e9e7, 0x1628e84c, 0xc1fa2c66, 0x08d6cf0e, 0x13f8cc06, 0x6fed03ba, 
    0x116b03f9, 0xf2fcbf3e, 0xf80a15e6, 0x3ed2c742, 0x0d95f213, 0x153dca25, 0xad479212, 0x1f211ffe, 
    0xdd2adde5, 0x094781e7, 0x2e2efc54, 0x610f1626, 0xfe1812f3, 0xf4c900f1, 0x2d08dce6, 0xd108dcee, 
    0xeb10f7f6, 0xf2f8bae5, 0xddf8d71d, 0x2760f0d6, 0x470efc5d, 0x31f2d7ac, 0x0fdef92f, 0x0533cf0b, 
    0xd9fc02dd, 0xdd0eab2a, 0xcc4916f5, 0xe536f23a, 0x31e6fe63, 0xdccae695, 0x18e1fa3e, 0x3a5c4cd4, 
    0x7f78edba, 0xbce8e614, 0x5eedade6, 0x093ee732, 0xfb10640e, 0x26b61533, 0x20320ab8, 0x3736e5f1, 
    0x0426b70b, 0xf042b9d8, 0x66cd1712, 0x162cd9fd, 0xd71d550a, 0xe812e721, 0xc721f90b, 0x02e64318, 
    0x381e24db, 0xc8cb241a, 0x5aea611c, 0xc6252639, 0xffca03c9, 0x08082719, 0xddf3dbe2, 0xe354502b, 
    0xec53f91f, 0xe65eb628, 0x0c07a40e, 0x4744edd1, 0x01b714f1, 0x45c9f623, 0x04280e67, 0x05cd19f8, 
    0x255fc3ce, 0xc378e6dc, 0x5c5b8f57, 0x77ecdf1f, 0x090bf4f1, 0x5a2dba5a, 0xd998d14e, 0x44fc64ed, 
    0x0ff2b3e1, 0xe239dd31, 0x0cd7c925, 0xfa4ff519, 0xec25f506, 0x7fa9f53f, 0xebdc1ddd, 0x1c781deb, 
    0xee4f1618, 0x27499551, 0x2b6a81f0, 0xf775456c, 0x7fed5364, 0x64d1d530, 0xbbf9c3e7, 0x375e1dd3, 
    0x5d46f70a, 0xe0d3fefa, 0x2ee09566, 0xd769c831, 0xfb2e5e32, 0x3698d54b, 0x311b11dc, 0xb01aaa05, 
    0x5d680e5d, 0xe6fbfacc, 0xf72ac0d3, 0x1537be65, 0xeb230903, 0xc2a934f3, 0xf02c1209, 0xe22fc1e4, 
    0x3a07cef9, 0x3020e63a, 0x8717ed1b, 0x10f2512a, 0x12040eef, 0x36dad11a, 0xf4ecc30b, 0xf71a2e0b, 
    0x401203f7, 0x0d11fdf4, 0x7f1e6204, 0xf01413e1, 0xc72932d9, 0x430f3fd5, 0x47395008, 0x12ddc921, 
    0xe8f0d406, 0x1c172cf1, 0x890f2cf2, 0xd6ef20e0, 0x2d3a0bfc, 0xf5eaeb09, 0xbcd6e84e, 0xeb5feaff, 
    0xfbf502f1, 0x23150b21, 0x511b2632, 0x0e52572c, 0x0cebdff3, 0x4a082afe, 0x4bd7d860, 0xd2149300, 
    0xe0dfdcfd, 0xf4eac31a, 0xd6182e77, 0x556e13bf, 0xd73cfd18, 0xc8f0d9a0, 0x1310fc2d, 0xc03d1520, 
    0xd8c0cb29, 0x243bd1e2, 0xf23b151e, 0x1c7ceefb, 0x031d2b7f, 0xd6c7dac7, 0xf1f7c407, 0xaa412c08, 
    0xe440190b, 0x23faecfa, 0xea3bdbee, 0x0320ef5a, 0xd7c23c2a, 0xe3e41cba, 0xfbe62ce1, 0xe92af6be, 
    0x3b13d203, 0x114dbc23, 0x36171a18, 0x60321665, 0xd5da11df, 0xb7aae85d, 0x311502f2, 0x0c0937fc, 
    0x0f00fade, 0xe835b71c, 0x2811063a, 0xfd27fd38, 0x0e023c1d, 0xf2e0c97f, 0xfdd6b3e8, 0x0226ed36, 
    0x1b7f203b, 0x1df4ea20, 0xf75ef200, 0xfb3bf249, 0xddcd253d, 0xe3e3bd39, 0x0cbbf5e5, 0xf6fe89e6, 
    0x0b5cd225, 0xe0dc0612, 0xc320c403, 0x1c3aec59, 0xfdc73619, 0xd3b10d2a, 0x111b0032, 0xab001b30, 
    0x1043e5b7, 0xe6d6a337, 0x1858e5ac, 0xb40c2215, 0x2a261838, 0xebdaff0d, 0x19f01814, 0xf16dd716, 
    0x6a73663d, 0xe947b86a, 0xe454f611, 0x487fe905, 0x61f70ae8, 0x52d6944d, 0xf516090c, 0x475e9cd5, 
    0x275635b3, 0xdc0edfea, 0x1c16b4e8, 0xf30fd9fc, 0x4cd5086f, 0x47cfc567, 0x01e5f716, 0x9a43a058, 
    0x2066d8e3, 0xc8bdfe28, 0x154c08e7, 0xa1ec3c2b, 0x21406974, 0x2713ad10, 0x3ceb11e7, 0xd64dac23, 
    0xf555201c, 0x0c3cd740, 0x16f2d923, 0xfc072242, 0xc9b34e3f, 0x440ff225, 0xfecb33f8, 0xe5561f2d, 
    0x670ae007, 0xe2f28d53, 0xf32502dd, 0x0de71a7f, 0xdef8161c, 0x37c508fb, 0x53e0cc12, 0xd140d010, 
    0x2451af1d, 0x181de564, 0x0523eef8, 0x2035fe50, 0xd4c70ada, 0x08e2ab3c, 0x36edcaf1, 0x1027f031, 
    0x15f708e4, 0x46c6f1ed, 0xec2fd816, 0xebd21eeb, 0x192c3be4, 0x10939500, 0xe6f0b4e1, 0xb5f25f19, 
    0xe2ff1fcf, 0xf4d737f9, 0x5fbc1bf0, 0x18d221c3, 0x1ced06dc, 0x16db1a04, 0x54225f0b, 0x12e98109, 
    0xc8e8dd17, 0x54163805, 0xa20b0f00, 0xe3d6ddee, 0x3b1dc8b2, 0xf5e1a6e3, 0x11e0e707, 0xad042cdc, 
    0x36d440da, 0xed6d0eff, 0x7f0f25ff, 0x31dc221d, 0x1bfcfb11, 0xbec23600, 0x4a202ce2, 0x0f34f7fb, 
    0x004bc0eb, 0x1528d203, 0xc31115f9, 0x2329fb13, 0xcbd6241f, 0x06061d2a, 0xdfec1b0e, 0x0231bbbf, 
    0xda20ba43, 0x0609c30d, 0x2028df3c, 0xf5f91207, 0xfdf7ef43, 0xecf50f13, 0xe9dfdcf0, 0xc7d770b5, 
    0x30f1f108, 0xdb12feea, 0xd4b345dc, 0xb881125a, 0x0b2c0c6f, 0xdc0851f2, 0x02e40a25, 0xb238e084, 
    0x4a52b622, 0xf1ebe250, 0xe1f1eeeb, 0x2f26fd27, 0xccfe38f4, 0x6106dcdf, 0xb90cdbf6, 0x2afff8ed, 
    0x0a4db7bf, 0x3525d850, 0xe21ed0cd, 0x2efeb2fa, 0x88bafb13, 0x2513a731, 0xaed6cbb8, 0xe607b609, 
    0xfe5bde15, 0xe3d2b03b, 0xe507142a, 0x2b5a1a72, 0xb2d37f52, 0x30981b1a, 0xe824dca0, 0x243b25ed, 
    0x381ad0d8, 0xd9430c22, 0x6c3a0dc5, 0xc8fb184a, 0xe82cd7e1, 0x99a2f8f3, 0xf5f2d4ca, 0xfeda14f4, 
    0x28f7cbab, 0xecf0d1fb, 0x55c8c4bb, 0x9423bd22, 0xe9ae1c28, 0x694cd564, 0xb030b7bc, 0x45fe49cd, 
    0x393d12c5, 0x1111c5fe, 0x47e5c13b, 0xd01700e8, 0x3bd1ead6, 0x0421e27f, 0xdce2d115, 0x17181ce4, 
    0xdefeced3, 0xe7e51119, 0x3e0a103e, 0xebe7090f, 0xe2c8e000, 0x2526eb27, 0xa5f0e4fd, 0x22c63a04, 
    0xd4063816, 0xe1a5fe1b, 0x1cb24831, 0xcdeafeec, 0xb614ef14, 0x29f43116, 0xb7e04306, 0xf1255833, 
    0x2cf5e80d, 0x08f6a7e5, 0xfcbde1ef, 0xf2250ef8, 0x08e1f646, 0xdee1e881, 0x54080146, 0xcf40c8eb, 
    0x12d5fff5, 0x5cb1da5a, 0x03e2c114, 0x164a282a, 0xde1e2770, 0x41fc3283, 0x08db0205, 0xbd08d6e1, 
    0xd22615db, 0x04bff634, 0xec04e8f4, 0x1d1cfc17, 0xfad4d113, 0x04f70606, 0x77cdfed7, 0x042f2afb, 
    0x0920ea24, 0xfce9cb18, 0xbfbc2a05, 0xec190d1a, 0xe90c0b26, 0x3adde8f5, 0x2a122dfe, 0xe2def1f4, 
    0x0bf7f51a, 0x03a9eb26, 0xdfe9c6d0, 0xd7f4ffd1, 0x26ff5902, 0x2417f2e8, 0x29cadff1, 0xfd07f805, 
    0x13f734da, 0x1a81fb3e, 0xefede2b5, 0xba411002, 0x27163e25, 0x20ffe5c3, 0x46d314e2, 0xffffe422, 
    0x00000004, 0x00000080, 0x0000071c, 0x00000e80, 0xffffe626, 0x00002116, 0xffffd3db, 0x000039f0, 
    0xffffbf9a, 0xffffe4e5, 0x00001071, 0xfffff874, 0x00000ab2, 0x000006c8, 0xffffeb3a, 0x00003177, 
    0x0000303c, 0x00002b37, 0xffffdd24, 0x00000583, 0xffffee88, 0x0000060b, 0x00003a73, 0xffffd5ce, 
    0xffffefda, 0x00001889, 0x0000000c, 0x00002f62, 0x000003a8, 0xfffff859, 0x00000c2b, 0x00002594, 
    0x00003634, 0x0000328e, 0xffffe4ae, 0x00000004, 0x00000900, 0xfd23e5f4, 0x031a137f, 0x37f4d2e5, 
    0xf413f823, 0xcae05204, 0x05041be2, 0xe4dedd32, 0xeefce8f5, 0xf91eb6cc, 0xf407e924, 0x0afcf1ff, 
    0xf92528bd, 0x02e801e3, 0x131bedd3, 0xded4c907, 0xfbe2e70c, 0xcc03e604, 0xfaf115ed, 0xe3fce61d, 
    0xd4f9e4c0, 0xd0233fd6, 0xf7f903ee, 0xfcd3bb25, 0xe00bdd04, 0x10fa1dea, 0xfe13147f, 0x16051aed, 
    0xe0091517, 0x28e409eb, 0xf5050112, 0x241f0fe7, 0x0e032f29, 0x03eac4dd, 0x1be4dc04, 0xbe300dd0, 
    0x23d7a6f9, 0xbfeb2af2, 0xcf0f2b0f, 0xf914c75a, 0xc8341ab7, 0x5665cffc, 0x2f3ac35a, 0x00243413, 
    0xc4c51727, 0xd214fe81, 0x56cbdb21, 0xd91f1306, 0x9d41dd33, 0x015c0bfe, 0xf837071d, 0x05593292, 
    0x25b71fdf, 0x2939d521, 0x89e3e759, 0x03b8a4fb, 0xe3eaee13, 0x10902166, 0xf31ac13e, 0xedf3542f, 
    0x2b1b2ccb, 0x160687f9, 0xb71328a9, 0xe590ab4d, 0x173b8e28, 0xf9c4f840, 0xd613e594, 0x42d329b7, 
    0xb8e1f768, 0x518110ef, 0x3b5487c9, 0xcdc3ffcd, 0x2fddf6aa, 0x5108dff3, 0x0936c81e, 0x301ee0da, 
    0xd0feb610, 0xf7c460d2, 0x31b83fd6, 0x73632c41, 0x44f9ea62, 0xc156080a, 0x1eee04de, 0xf0eb3a02, 
    0xd5170a0d, 0x3bf01625, 0xca1b0ff3, 0xab09240b, 0xd0811ee1, 0x5d25b871, 0x05d71458, 0xfac8d9eb, 
    0x0bf6e82f, 0xec12ffda, 0xe2a6b6b0, 0xca010f9f, 0xbca1dceb, 0x23d1c814, 0x20e4fd63, 0x15212ff4, 
    0xfcbc0f3d, 0xe9ce0cd4, 0x1b05d4be, 0x4042d351, 0xd73aa3c9, 0x16d4fdf2, 0x3de19a34, 0x88c22581, 
    0xe5d71515, 0xc22ab9fa, 0xd73d2f36, 0xe6246be2, 0x2f125501, 0x097fa830, 0xffc8063e, 0x2d6125fc, 
    0xfad2e952, 0xf2f228c4, 0xf051fbf7, 0x575eccec, 0x0b305045, 0x0ebbe81f, 0x44a324da, 0xd53e2bb6, 
    0xf64547c9, 0xfb072350, 0xc02633f0, 0xcbb01bb9, 0x07c723fa, 0xb576e39a, 0x08d94d41, 0x7f3f5a37, 
    0xcf3ea32a, 0xc550be24, 0xe907ebab, 0x8f0e6561, 0xaf041798, 0x6e09b3ee, 0x4328106f, 0xa6fa57cb, 
    0xf7090e4f, 0xbb18bfd4, 0xb0f336e3, 0xee5533c7, 0x9f4046e4, 0x360214d9, 0x33f2c2fd, 0x2a5917e4, 
    0xd82e6981, 0x2963e1ed, 0x2056342d, 0xd5ffdc1d, 0xf4afe3a4, 0xe7dc0319, 0xcdcbefd1, 0x0656d0b4, 
    0xe20333ed, 0x16debada, 0xb22f0705, 0x0826c0cc, 0xf3eab6ef, 0xdae6a685, 0xcd27e843, 0x16d3dd11, 
    0xf9c1da2f, 0x70fbdacb, 0x0dd93f7f, 0xe8f82ef2, 0x1fd60103, 0xe6d419f2, 0x44e9d306, 0x51d9e8e8, 
    0x18ccf63d, 0xd7b531eb, 0xed2823d4, 0xe51dc99b, 0xe3e4d936, 0x201303e4, 0xd510fc06, 0x2b2c27dd, 
    0x0d19eecd, 0xcea0dedd, 0xe40f0cc3, 0xc8b52503, 0xfd04c719, 0xf202c1ea, 0xe903f4c7, 0x20d6e7f1, 
    0xd03340c8, 0xdcfc2d23, 0x0314e8c1, 0x293fed46, 0x7fdcd4e6, 0x1bc93e10, 0xf8eb1c3b, 0x051b3e17, 
    0xe30a3afe, 0x1e47bded, 0x26111b1d, 0x17e1cf54, 0xbe76ad22, 0x02d93903, 0x0102c6dd, 0xd40430b3, 
    0x39de1dde, 0x5b072858, 0xa66bcdda, 0xd03dcbaf, 0x6f34a0a8, 0xc10f92c6, 0x24c33de0, 0x7face73b, 
    0xbd29eed1, 0x36c7430f, 0xdfce102c, 0x0bcea22c, 0x573f13ed, 0x2f81f51b, 0x9e49d952, 0x23981ff9, 
    0x9579f3d9, 0x222d9c48, 0x76ec569b, 0x07004de6, 0x22fe2170, 0xfdd79be0, 0xd85dc4c4, 0xde28bef5, 
    0x2fd3faa8, 0xd56755ad, 0xe60b036d, 0xef6291d3, 0x20a1470a, 0xdc464f19, 0xb1d9cd24, 0xd1a4c6e9, 
    0x6192b721, 0x5bbca7c0, 0x09b2c353, 0xcaeb17a8, 0x1dcc07d7, 0x31ed0393, 0x0c93e41c, 0x49e48120, 
    0x16132434, 0x0ad71003, 0xfe38fbc3, 0x2ff51717, 0x1da3d6c5, 0xd010a9ec, 0xde1e2ffc, 0xfe324dc2, 
    0xcdf6d6da, 0xb0132cff, 0x060f3beb, 0xad1b1515, 0xe0982abc, 0xd9452257, 0xedc39f06, 0xbbe01e41, 
    0xdac21ad9, 0xbf1bfe1e, 0xf6811f00, 0xd130fd50, 0xb1f0c0f5, 0xbfefff43, 0xe7e9f2fd, 0xd2ed3129, 
    0xe2bf29c7, 0x16ebcd49, 0xca1ffe02, 0xc4f4edc3, 0xfec7dea2, 0xa6f437c1, 0xefc909c4, 0xe1f3ad2b, 
    0xafdcf609, 0xe4e8f303, 0x0c08077f, 0x2d192709, 0xca1dda54, 0x0ce400f0, 0x27eb1cd0, 0x1af763f4, 
    0x0ed7ee04, 0x20d6c613, 0x02d0d047, 0xa10c39df, 0x0df5dad0, 0xf9de12c8, 0xb7e5d90e, 0xf519bf9b, 
    0xf7b8381d, 0x55f0c34b, 0xe9ffa65c, 0x114f1704, 0xf5d7dc17, 0x17f13cfc, 0x9cfd25dc, 0x577bd9d0, 
    0xafdeb55a, 0xe52cece8, 0xf93b04e6, 0x20c83781, 0x0d6d6618, 0xfd26fd3d, 0xd247d36b, 0x5409d23d, 
    0x0938faf0, 0xb8fd19ef, 0x3f35ef13, 0x1bd10ef9, 0xfbdd31b3, 0x7f012623, 0xe94e1627, 0x23fdb6ed, 
    0xeff8cdf9, 0xf1d3e4cc, 0xfcf10aa9, 0x4244514f, 0x9b75bfa3, 0xd3c9320b, 0x3a1ae3a8, 0xa9d5bfae, 
    0x11d020d4, 0xebbd457f, 0xfd3d31d3, 0x10fd0514, 0x20fd34ae, 0x426f260e, 0x13d0d038, 0xf7f2405a, 
    0x2af0f5dc, 0xc0eea4f3, 0x1eb0f8cf, 0xe23e2925, 0x08a8fd31, 0x1a4e0c4f, 0xaf25f0ea, 0xd246dae0, 
    0x02f22ecc, 0xdc010fea, 0xa7bad246, 0xb61bc7ec, 0x38e71cf5, 0xb0fed165, 0xd60cb916, 0xf5eeed41, 
    0x422aa206, 0xdccfe92f, 0xe136420d, 0x1bc4c873, 0xd51ad5dc, 0xd3c60c38, 0x341135b5, 0x21063446, 
    0x23eb6906, 0xa754c77f, 0xf11e1ae0, 0xbf5acc39, 0x59e4a7b5, 0x3909df3b, 0xfade0e15, 0xc9f99cee, 
    0x2b9ec6ed, 0x0a05c6f7, 0x15b31802, 0xf25dec0c, 0xdb3dfe1c, 0xc10ff6d7, 0x43b33ef6, 0x3a43fde9, 
    0xdfa38140, 0xd002d24a, 0xfcd6c8ec, 0x99fb1fba, 0x41932e8c, 0xeb49ee07, 0x85b98cfe, 0x2a402b25, 
    0x44591814, 0x152e462c, 0x4be33b2b, 0x6d4cd9cd, 0x4135dd4c, 0xa5e1eed7, 0xddc2facc, 0x0b623637, 
    0xaeeb2110, 0x5149e1ee, 0x1fd2cc7f, 0xe6292806, 0x02ade6b7, 0x2bbc90ba, 0xded64030, 0x3a0bbec9, 
    0x971cf0e3, 0x21e9162d, 0x2355d92a, 0xed01e8b1, 0x1e05d531, 0xddfb2392, 0x322345dd, 0x651e2940, 
    0xf87ff007, 0x2a25eadc, 0x26cfced4, 0x45b911d5, 0xeeda5dd1, 0x4df6355b, 0x8b4bd1b2, 0xe20a26c3, 
    0xfd42c2db, 0xf3ddfcfe, 0x4dc30bb7, 0xf5db0eee, 0x14bfa91c, 0x0e32fd2f, 0xf5beaa35, 0xd0bbe8c2, 
    0x0fd2eeb7, 0x4321ea0f, 0xe05337f7, 0xef2fbf25, 0xdc18cbf1, 0xfc9b07ef, 0x2fc90395, 0x6926ce0e, 
    0x1e7fbe0e, 0x1614a9fe, 0x5933ef3c, 0xd8c3e99e, 0xd7d932e2, 0x13fac304, 0x1242d4f4, 0xdac54c1c, 
    0x13481207, 0x2406ba2e, 0xdefee8af, 0x173fa5f0, 0xdb4f01cb, 0x2ce64d1f, 0xe4f506f0, 0x3c12b0fb, 
    0x03f200aa, 0x1717aadd, 0x25ca8149, 0x48192c8c, 0x145004ec, 0xcc8ee92d, 0x98ebac0f, 0x160812e1, 
    0xe3dfedc2, 0xa933b6dc, 0xd781f9d0, 0xc3d6173b, 0x39ffd0ef, 0x34043ee4, 0x23a51b3d, 0x1225f734, 
    0x140715ef, 0x1bbd04b6, 0x05daccd1, 0xd6e102d6, 0x53bccf2e, 0x4fe311d0, 0xd4aae834, 0x972559c6, 
    0x11f2a8d0, 0x3505fef4, 0x071b1081, 0xe30af5e9, 0x23fccf36, 0x05da43d1, 0x0418d422, 0x020502e2, 
    0x0febe701, 0x06f5e412, 0xd1faf3ef, 0xe61f16fb, 0x1012fc14, 0xddc018c8, 0x1dc4e828, 0x2c1210e3, 
    0xdbf5f929, 0xfcc75012, 0x20fbcff7, 0x7f4ef521, 0x9704ecc3, 0xae3f57fd, 0x1921ebd8, 0x7d159aec, 
    0xdf2d3b4e, 0x150f2b14, 0xfc13144a, 0xaf171be2, 0xf14a46c4, 0xebe8d2bf, 0xcb1e0222, 0xefb62428, 
    0xccdd0bfd, 0x27489e02, 0x4b16cbf1, 0xdf2ac5de, 0xd6efcac0, 0x1f9cd91f, 0x3eed0335, 0x01ead0c9, 
    0xf7e7b717, 0xc309000b, 0x45e8bee8, 0x081a3c55, 0xe273fddd, 0x34dc2606, 0x2ff1ca3c, 0xc4e72102, 
    0xebebcae8, 0x6d5c020a, 0x9854baf3, 0x811d14af, 0x67ca15b6, 0x1a4dd5fa, 0xeca03bd6, 0x9bd50e07, 
    0x9dffb78d, 0xecd7fcc1, 0xf39c1484, 0xd5a30daa, 0xf7b813ee, 0xc4dc46e4, 0x4db6157f, 0x6bf7f5ee, 
    0x150ff057, 0x04181a0d, 0xd41adfcc, 0x04e920fc, 0x0c28e9d2, 0x47079ff5, 0x229cb926, 0xab0c10e4, 
    0x7008c2e5, 0xe5fcc611, 0xd3d6c781, 0xfee9cadb, 0xf4de13d6, 0x15b8f8a8, 0xdfec4df5, 0xead6df34, 
    0xd9bdb831, 0x3211f7ec, 0xf9fcbc20, 0x09b80cee, 0xc9230ed3, 0x32241b1b, 0x0bdfd7db, 0xda0de8e4, 
    0x180fbf54, 0xccc862e0, 0x0525b9ac, 0xef81041e, 0xd5e9ccbf, 0xb726fdc6, 0x8f9c14b3, 0x00cab2ea, 
    0x080afa1f, 0xd0bf0d0e, 0xd8be394b, 0x3d231d1d, 0x893a0ded, 0xf8dceade, 0x15d21804, 0x00102bf3, 
    0xee1658bb, 0xd4f6ef5d, 0x35f1ca3a, 0xb5d8f5d1, 0x170bd4d2, 0xffffedba, 0x00000004, 0x00000060, 
    0x00001bd4, 0x00000671, 0x000035e8, 0x000040ff, 0x00001c5d, 0xffffd052, 0x00002726, 0xfffffe72, 
    0xffffe7a6, 0xffffe660, 0x00003bbd, 0x000026a4, 0x00000ba8, 0xfffffd84, 0x00005156, 0x00002f36, 
    0xfffff1ac, 0x000005e7, 0x000030ab, 0x00000023, 0xffffedb3, 0x00004a3c, 0x00002f15, 0x00001430, 
    0xffffee26, 0x00000004, 0x000006c0, 0x06e60c1f, 0xe8efd0f9, 0xfd2e22ac, 0x2a573699, 0xc0f2c111, 
    0x2aff2307, 0xcc09ded9, 0xf8f626e2, 0x0e0f10ad, 0x20391e1f, 0xd630f8fe, 0x0cbce023, 0x1ff3b409, 
    0x2fd9c4e0, 0x0ff2dec1, 0xc435e021, 0xd7ceeac7, 0xfc81e90b, 0x081fee11, 0x36e9210a, 0x47f70006, 
    0xda19e4fa, 0x4f031f12, 0x00d3f3e7, 0xd1fdef02, 0x30d1c6f7, 0x3de4d803, 0xaa1bde3e, 0xe1c017bb, 
    0xdff414eb, 0xec3ad8bc, 0x4104c819, 0xfccff2e2, 0xc519ed7f, 0xd9f3f71f, 0x1dd50005, 0xd044f4e2, 
    0xc5bcfada, 0xf2051ef5, 0xadf6cebc, 0x9ecd09c2, 0x003585d1, 0x03252704, 0x2ca9e906, 0x0de3c808, 
    0x811ab033, 0xa92444aa, 0xded8cadf, 0x4f04c735, 0x1415f906, 0x3dd3f2d1, 0xbfd4ecc2, 0xec0cf3c4, 
    0x04e25b49, 0xe90ee7ab, 0xfa81a1bc, 0xdee218a0, 0xe9241702, 0xc015f32a, 0xb51eb628, 0x9bdbf0b5, 
    0x14f0d302, 0x0e1a49be, 0xcc3c32d5, 0x9e27c7c8, 0xe1071904, 0xdbcbdbea, 0xf2b7ff23, 0xf9eb1126, 
    0xd123d446, 0xc4c9d1c7, 0x19d720f2, 0xf708b424, 0xdc25461f, 0xcafdcf04, 0x8bd7edc7, 0xf9c6d0d2, 
    0xf5a9cecd, 0xfd26d6e6, 0x01d0d5fa, 0x0cf4f1fe, 0x7f9dfbd1, 0xe332f8e9, 0x2b4cf51d, 0x1bd422d7, 
    0x101bc9f7, 0xd7cc3809, 0xedb9def0, 0x151c163a, 0x2167dbec, 0x26034402, 0xf7fed3d2, 0x230f1438, 
    0x1edc5e61, 0x570cc42a, 0xeff7ddc9, 0xd9292faf, 0x491216a0, 0x2ad10645, 0x34284c20, 0x460038c4, 
    0xdd1cf601, 0x212d13e9, 0x1bdac715, 0x43a4c87f, 0x6fdb6858, 0x68e8f333, 0x02c8d3e3, 0xe4a729a5, 
    0x0ae508bd, 0xea2708b1, 0x4202bbae, 0x0649d7f5, 0xef0bb13f, 0xdc36d5b1, 0x2cdf264c, 0x24edff01, 
    0xd63cd644, 0xd34c25e6, 0x4cbff22e, 0x0fd19129, 0x2ee5e04f, 0x1a130aa0, 0xde421dd7, 0xc9a8c104, 
    0x0d81de11, 0xc7f4551d, 0x12df0013, 0x26094781, 0xa008eba7, 0xe8f731c4, 0x211da612, 0xeed13425, 
    0xc8e7affe, 0xcada1312, 0x1d1806bb, 0xa10713e2, 0x1c32f8e1, 0x0a0a4cd5, 0xcde5dac0, 0xcdf52feb, 
    0x1030a249, 0xf445c731, 0x4c54bbec, 0xcc360e25, 0x15da2d7a, 0xebf7b016, 0x1fd6f4e8, 0x5734d144, 
    0xcaf50267, 0x1bf0d918, 0xc5c1ca17, 0x0112c023, 0xf90238ce, 0x0d30ee56, 0xf3bb9bf8, 0x50530e41, 
    0xc5bc29f1, 0x64e7f865, 0x7f4c0925, 0x5ffb0035, 0xb50d9a49, 0xbdd88200, 0xba744467, 0x2fc51c48, 
    0xe707be41, 0x10e8d633, 0x7fca55e9, 0x24ecd028, 0xd65b0c47, 0xde04cacf, 0xaa9de321, 0x541ffdab, 
    0x57ed9015, 0x2741094b, 0xe10eda37, 0x08602cfe, 0xc8163ac3, 0xcff67bed, 0x38221766, 0xec480de3, 
    0x4981ddf2, 0xe2a34286, 0xc349ec25, 0xefcb01d3, 0x2302ad3f, 0x3c351cc5, 0x2ec088e2, 0x37b6c3d4, 
    0xd4e4c940, 0x921f28d1, 0x02b4d10d, 0x433de52f, 0xfaaea29c, 0x9bc71293, 0xd708f4a2, 0xf911bc03, 
    0xdef5042d, 0x0624d727, 0xd0d34df4, 0xef070ac1, 0xafbbd8e1, 0xbfee0526, 0xb2acb821, 0xdfad13ee, 
    0x1906c3bc, 0x382a3e02, 0x7fc42dd1, 0xf02f1417, 0x0803f922, 0xf805200e, 0xf0afe0a6, 0xc7114703, 
    0x9dddf213, 0xe61aa7fe, 0xf5508ee4, 0xceb755cd, 0xeba3c4ea, 0x13fd52b9, 0x43112702, 0xe5322f10, 
    0xe508b412, 0xc9b158cc, 0xf2010dd0, 0xeb047fe9, 0xc381e4ad, 0xcf45de27, 0x0252d2e9, 0xc1133005, 
    0x28d8faea, 0xda1f4bcb, 0x07a3f527, 0xf6fbcbef, 0x1c070af9, 0x724d36d4, 0x1a795914, 0x86fe9eac, 
    0xaeea44b7, 0x17115ffb, 0x5005128f, 0x4c34a506, 0xec0e00d7, 0x900481cc, 0x23a8bf10, 0xba006917, 
    0x2b867c43, 0x50d8d153, 0xe11a1df3, 0xba1d2936, 0x132bbfde, 0xc8bf08d3, 0x3c0029c7, 0xaaefb2f1, 
    0x17e0c96f, 0x0dfbe415, 0xfa100511, 0xf4fa2da0, 0x57c9e94c, 0xe117f7c3, 0xf6a614f6, 0xddc113f7, 
    0xfce4f781, 0xe1e6ebaa, 0xcac3a5df, 0xb7c3c7fe, 0x02e6e7d0, 0xd22af6e8, 0xfcde2a1b, 0xb21cddb8, 
    0xa7fcb316, 0x8922c4e9, 0x4998b9db, 0xf6cc1404, 0x9d5faec5, 0xd221f02d, 0x0c230501, 0x10e23dc6, 
    0x0edee9cd, 0xc40fb79c, 0x12f0813d, 0xb6d8cd10, 0x8ad00317, 0xbbc3253b, 0x1b30ba2d, 0x3b1da407, 
    0xef39a324, 0xcae3a8af, 0xc9bc4a04, 0xe82f11e5, 0x12181dd7, 0xe3c32521, 0x0ea62ae7, 0xd430e224, 
    0x10e404e4, 0x08e2f514, 0xf6673c0a, 0x0b1ae007, 0xc9ee261f, 0xd515d5f7, 0x7f9a63f0, 0xcc1ed624, 
    0x27ef3d33, 0xd84009ef, 0xefcfed1f, 0x25b4d9fe, 0x4a91c621, 0xcba52ad3, 0xdef8cfb0, 0xbe043dd5, 
    0xa59fd759, 0x1c7eb42e, 0xdb7fdb0c, 0xf13869ee, 0xded8d0e4, 0x90e9731d, 0xcbacc5c2, 0xc2f9fd2f, 
    0xea66f4cc, 0x40f35ff7, 0xfa21ecc0, 0xbd402024, 0x54d814ac, 0x9ec6dae3, 0x004beee6, 0x173bbf1e, 
    0xc3d3dcdc, 0x27d78f57, 0x3dadf11c, 0x1603fad5, 0x81d0f29a, 0x1868ab3b, 0x44c9d9f1, 0xcfcd9d0c, 
    0x181519fa, 0x1bff0d32, 0xd4b0ce3c, 0x514f255b, 0xb56011e6, 0xacceb301, 0xbdda18f0, 0xadb2e301, 
    0xcb1874f6, 0x2adaaf16, 0xad7f3600, 0xb1d010e7, 0xad2af144, 0xe73c2bec, 0x25e551ce, 0x371eae59, 
    0xe3081e35, 0xc1259abf, 0x0c9a0cb8, 0x34be5c18, 0x44f60a20, 0x5cf6be26, 0xb5fbcbea, 0x043bb106, 
    0x08aef204, 0x3dd83161, 0x5406deef, 0x72110018, 0xea0d27df, 0xddbcc0b7, 0x00dc2e06, 0xd24971d8, 
    0xdec05cf9, 0x7877e6e3, 0xe850c814, 0xd53bb5d0, 0x5723f53e, 0x4ced4dd2, 0x0e9f7ff6, 0x514ac06b, 
    0x2ae0bde7, 0xc425ffbe, 0x1cebd133, 0xcc1317f4, 0x1104d0e7, 0xddf539ce, 0x9e31ed7f, 0xca12c8f8, 
    0xbae54017, 0xcafe9dc1, 0xe7ee1868, 0xde9c1aa1, 0xd2bbbf51, 0x2247c6a9, 0x1f0bcff9, 0xb13ddbca, 
    0x32b497f2, 0xd8a6cdf5, 0x07aa15e2, 0xddefd1be, 0x1411bfcb, 0xa129c702, 0x14bbf606, 0xe21bedef, 
    0x0617f705, 0x5d3b2c13, 0x9e4cbec0, 0x9304aac8, 0x30ecc941, 0xa781dabc, 0xb903fe08, 0xfb2b1806, 
    0xd8fbfdf6, 0xa9e701c0, 0x13b71a5d, 0xe8fc0ea6, 0x05129901, 0xe22f3900, 0x18dc19be, 0xc444b5a7, 
    0xdd1c84d2, 0xc2c044e6, 0x30074c3c, 0xf9df1a20, 0x3543d363, 0xde3ce01c, 0xe14209e0, 0xe7ddf793, 
    0xefbfcd3b, 0x10ae1a3e, 0x20f31d29, 0x42e9e347, 0x11e08dbc, 0x0cda3ea9, 0xb9b4e9d0, 0xeaf0f146, 
    0x0ce74311, 0xd523ade8, 0xffdd8116, 0xfffff4f2, 0x00000004, 0x00000060, 0xfffffd59, 0xffffe559, 
    0x00000b31, 0x0000052a, 0x00002251, 0x00000797, 0x000000ba, 0x00002416, 0xfffff50e, 0x00001e1e, 
    0x00000e97, 0x00001859, 0x00001e38, 0xffffe25f, 0x00003682, 0xffffee77, 0xffffd3c0, 0xffffec00, 
    0x000024d4, 0x000003c1, 0x00001a2e, 0x00002007, 0xffffdd29, 0xffffff45, 0xfffff55e, 0x00000004, 
    0x00000360, 0x0617d53a, 0xe2f11933, 0x10c8eaf5, 0xf1ebf40d, 0xde420a5d, 0x08fcf5d9, 0xc8efa203, 
    0x81415953, 0x390c13ba, 0x5fcc65c3, 0x5dc4fcc1, 0x2d0e41c4, 0xe7d511f0, 0x3e03ea96, 0xfd1f724b, 
    0x24014d5f, 0xddf4f152, 0xca817664, 0x071fce2c, 0x1ddccce7, 0x0a5afee4, 0x05c21473, 0xa4171220, 
    0xbed993f3, 0xa3f2b731, 0x8194f26e, 0xe860ef0b, 0xcb0d816d, 0xdb02b2e2, 0xf036bcde, 0x2ca3d14d, 
    0x3ba25643, 0xe7bddf1a, 0xc90c4638, 0xe8ccce72, 0xf13653f2, 0x50169f17, 0x29612cdf, 0x4cefb5b2, 
    0xe3ada0b8, 0xb13cae2a, 0x1ff5b426, 0x30cbe2ad, 0x398a8389, 0x0b093881, 0x70bbf4e2, 0xeef81a16, 
    0x7710e608, 0xae29e59f, 0x94064a81, 0x4cb6fb31, 0x541bd5a8, 0xf31ad6bd, 0x3803bcfa, 0x21dd19bb, 
    0xf3fa5333, 0xef01e1b2, 0xcee1bf27, 0x815c4a0b, 0x73f607c1, 0x240bafdc, 0xd149bd1e, 0x7eb6121f, 
    0xc62d04b0, 0x0aa7beac, 0xd6fae300, 0x143bcb0f, 0xc0cda804, 0xe5ff0b1a, 0xe51e81e1, 0x0f38162b, 
    0xed0718cd, 0x43cf8327, 0x1dc3baa6, 0x02eaf57f, 0x6412b7ff, 0xf24fdc2b, 0x6ef2cf6d, 0x032500eb, 
    0xb6e1e2dc, 0x1516e148, 0x0a09448b, 0x190f901c, 0xd814630c, 0x15e36b22, 0x374dbb94, 0x9de01c95, 
    0xaecf05e0, 0x536da181, 0x9f9015b6, 0xf503b800, 0x0b502ef8, 0x4d353a85, 0x333cb0b9, 0x22f1c185, 
    0xf5bf0e81, 0xde60dbd3, 0xcafedbe5, 0x3516e126, 0x2ae2d8d4, 0xd70144c3, 0x072b122e, 0x01df3dad, 
    0x46c21cd9, 0xaf10817d, 0x9bfbd4b8, 0x4d9828ae, 0xc30aa3f0, 0xa9ab02f9, 0x52b08ba1, 0xde00310f, 
    0xd52c8101, 0xee44fa0b, 0x34dcda09, 0x9efde94a, 0xe09ede4a, 0x1d1ad5fe, 0x5658bf27, 0xd2f3ac2a, 
    0x0858ce00, 0x4a2fd199, 0x132c05fa, 0xda75a57f, 0xe43bc3db, 0x75348eb0, 0x291f194a, 0x1436fb08, 
    0x0899b397, 0x814e31b0, 0xebbd9902, 0x1c34bca9, 0xf675c133, 0xb40ebf48, 0x9ff0b6d9, 0xb5f7c7bb, 
    0x81a6a5e8, 0xdcbc1e21, 0xe9c9adfc, 0x4a554544, 0x6bf1acf6, 0xc871f930, 0x560f44d6, 0x39541220, 
    0xdd1a6239, 0x1d2b1ada, 0x0fdf19b9, 0x36fe6c09, 0x53fa701a, 0x7f52cacd, 0xe996120e, 0xe5d13cc6, 
    0x4d50bf0f, 0x4e1e024c, 0xd7df35fb, 0x29002bdd, 0xf9e3da19, 0xde211866, 0xeee8f765, 0xd524c7f3, 
    0x03edfd36, 0x4dbf137f, 0xc9bf3302, 0xf2e9ef26, 0x1fbaebf5, 0xd9c33e81, 0x11382fb1, 0x61e206fa, 
    0x1758fb84, 0xcbc64da8, 0x1af1cbaa, 0xd8bbd9b1, 0xfdf4b0cd, 0xb0160633, 0x0af2f764, 0xcdf1c21f, 
    0x2176cada, 0x0930d36a, 0xefc8d4db, 0xfdd909c8, 0xe102ff7f, 0xcc40afe0, 0x24dc14d7, 0x295116d3, 
    0xfac9fde0, 0xd2e38197, 0xfa3c1b2b, 0xed1cfdaf, 0x42dabcca, 0x0e36d6d6, 0xa709a6e8, 0x0f815710, 
    0xa12aed0d, 0xefb2de18, 0xa8e6e4ef, 0x4ab8c515, 0xc11dd82a, 0xa32c0e30, 0x442a10d3, 0x34ed25e5, 
    0x16efe4f5, 0xd3da37c9, 0x0ae63628, 0x3a071dd9, 0x2ff55a03, 0x7fff55e1, 0x20f34114, 0xf5e34f28, 
    0x0dc9f8e2, 0x09ea243f, 0x519fffe6, 0x0acd40d8, 0x0173f2ef, 0x47d0a8a5, 0x1506d83d, 0x114ff003, 
    0x7fbdeff6, 0xfffff8ca, 0x00000004, 0x00000030, 0xfffff6ac, 0x0000234f, 0x00002778, 0x000038db, 
    0xfffff6d9, 0xffffe87b, 0x000004f9, 0x00003450, 0x00001f80, 0x00002bd6, 0x0000282d, 0xfffffc0c, 
    0xfffff906, 0x00000004, 0x000005a0, 0xe5fc06f6, 0x0d7f393f, 0xf50ecd43, 0xe4b7eafe, 0x45091312, 
    0xf4c6e7d5, 0xecbdd5ba, 0x0aeefe02, 0x21cf0ae9, 0xc529d82e, 0x15d609b9, 0x603c4061, 0x41f6e303, 
    0x0301d36d, 0xe12fff22, 0xf9110c1d, 0xda15a009, 0xf4f2def3, 0xdd16f4f8, 0x0d0cd82a, 0x09fdc8f4, 
    0x534d5006, 0x31e31931, 0xcef53328, 0xf5fbae12, 0x0cebc303, 0xe2cdd7ed, 0x26120cd3, 0xffd42520, 
    0xfe06c4be, 0xd0a5c381, 0xcbdedce9, 0xe9d20df5, 0x102b20f1, 0xefe6dddd, 0x2726e301, 0x14e3c3d9, 
    0xe53308d3, 0x2649170e, 0xfa0725fb, 0x14c8beb1, 0xc804ea07, 0x04e216f0, 0x0b23eff0, 0xb5090e14, 
    0x34c6b8ba, 0xe0fa13fe, 0x27e5d232, 0xcf302cce, 0x20e82826, 0xdc1a17ef, 0x2b1734ec, 0x181637e4, 
    0xef302510, 0xe0d1db17, 0xc42110c8, 0xcc05e201, 0xffd82bd3, 0xeb17d514, 0xebd9fd1e, 0xd1931f9b, 
    0x15eb9ac7, 0xd500f2d8, 0xaca4f2d6, 0x05f8a7b6, 0x471ac00f, 0x2ce53723, 0xec23574b, 0x052723c7, 
    0x9fe84ed8, 0xf181ad09, 0x76f807a9, 0x20e11d56, 0xa82be3e9, 0x2aeac30c, 0xed193223, 0xe024d8b1, 
    0xe6fc6339, 0xddedc9ac, 0xfef3ca09, 0x0fb637a9, 0xfedbae35, 0xb8d0ab18, 0xd7e721eb, 0x4cc634d9, 
    0x27c90865, 0x0153dce5, 0x135ee5ea, 0xb9ed48b3, 0xf7e9e136, 0xcb0bd8fc, 0xd3ebffd1, 0xefa2cd06, 
    0x33d31bf5, 0xd60ef7e4, 0x1a0a2ccd, 0x362f1337, 0xfc12dee8, 0x2224da0e, 0x292322cb, 0x07c8d117, 
    0xd0de08bc, 0xa3b7d803, 0x25b0fda1, 0xae8abab9, 0x00ee159b, 0xeb01260a, 0xd32417cd, 0x2330e1df, 
    0x23ce0019, 0xf2d0c8fb, 0xb91e090d, 0xd4121126, 0x00e7eef1, 0x81a9b299, 0x1017f70a, 0x1e02fafa, 
    0xb5da2cc8, 0xfc22f21d, 0xefbfe526, 0xe92746d2, 0x044de936, 0x2b2afdfa, 0x1c18f567, 0xb2c412fd, 
    0x30320ce9, 0x81db01df, 0x1cccf6d3, 0xe70e1fd2, 0xbbe8ae95, 0xf414ddf2, 0x201028d2, 0x13c5c61b, 
    0x0927406a, 0xf72124fd, 0xe0deeac5, 0xb7f4e51d, 0x260306b3, 0xdef13332, 0x172af9a6, 0xf0393af4, 
    0xef34f80c, 0x2113d212, 0x2fd8f66d, 0x91f7b1fd, 0x2114cdb5, 0xbb0a10ef, 0x2f3832ab, 0xe92cd22c, 
    0xddec03bc, 0x1310e955, 0xe03be9db, 0x192ce21e, 0x7f772401, 0x0d43d0f1, 0x132e2124, 0xd6c61fda, 
    0xf3d1e001, 0xfb2fd5dd, 0xfbfcf2d3, 0xdf35fd3a, 0x031f2905, 0xe911ede9, 0x5067fe62, 0xb9181216, 
    0xdfe21fe6, 0x0528f641, 0xecf33e08, 0xce022530, 0xbdbbb8c1, 0x3e2a2938, 0x49de2e4d, 0x1ac020ce, 
    0x3ef7f91b, 0xdebcf420, 0x21f03907, 0xf7ef1d3c, 0x2306ec0f, 0x18c10be9, 0xc4f2f1d9, 0xd54c7402, 
    0x0ea9d4a9, 0x8ff413f1, 0xfc0733cf, 0xea15fed9, 0x4f66301c, 0x17ed3b44, 0x3db316dd, 0xf340272f, 
    0x5504ac08, 0x09def41e, 0x1105149a, 0xf2f4b3d4, 0x3d305a07, 0xc476f3bd, 0x2f51e90e, 0x0e303022, 
    0x18c8c3e5, 0x1b50e725, 0x4517bef6, 0xeae62e16, 0xf5acc1c0, 0xa9e0a5e4, 0xc9ef17ee, 0x1a4bccf8, 
    0x5a7f46fd, 0x3a11045e, 0x56e8e82b, 0x0aef24fb, 0x1622f2fb, 0xabf2818c, 0xd9f007bf, 0xff21b474, 
    0x411700fa, 0xe9ac471e, 0x33301c0b, 0xdfecccf6, 0xc96a0a48, 0xf86016c9, 0xf5b220f0, 0xc486ea99, 
    0x37d34fb1, 0x2624d2e9, 0x02c1f1f5, 0x01edb7c6, 0x2d1f1735, 0x29c83721, 0xd930d537, 0x5de7ce3e, 
    0xedc45671, 0xd2aa9b99, 0xfec2eef6, 0x2ecdef0c, 0x010c444b, 0xe7f2f4d3, 0xc4a6fcd4, 0x48c8fe1a, 
    0xc265693c, 0xda6e6ff2, 0xd6d84102, 0x31f21c39, 0xfc0fc4be, 0xbcb8d0e0, 0xb6c994a9, 0xe72b0396, 
    0xd106f52b, 0xa8e4fbdb, 0xe530291d, 0x20214152, 0xdf01fe2d, 0x2bc8e3ff, 0x14d81ed4, 0xb8e5b619, 
    0xebd2abab, 0xcff69f91, 0xbfc9ea02, 0x172bf88b, 0x062d0d1d, 0x3f1a2d4f, 0x4a041edd, 0xfef7fe31, 
    0xeebc23f2, 0xe50c1302, 0x06ccd9dd, 0xd612fcd7, 0xbdeec710, 0xe53502f7, 0x2a4e1b43, 0x44490021, 
    0x477f1d02, 0xfc00e9df, 0x17f0d5dd, 0x03183d28, 0x1e0ed4d4, 0x8fdff011, 0xf7da9b07, 0xe43c2730, 
    0xfdfce7ee, 0x11ed3d2e, 0x271e32f7, 0xfcf1ec1e, 0xeadbd2cf, 0xf32d02e7, 0x20fe13f3, 0x83bee3e5, 
    0x3209819f, 0x11daf8f2, 0xc332d5ec, 0xf3e2dac5, 0x0ff3f2e4, 0xf520df0e, 0x011cf311, 0x17cde225, 
    0xed20dff1, 0x959cf7d5, 0xf3fd8cb7, 0x13de0e06, 0xefe21cd3, 0x11ec03e2, 0xef0ada10, 0x8fc69293, 
    0x05b3d88b, 0x2ac70a02, 0x0891e241, 0x6d0a3b0f, 0xddbd0549, 0xd72b2020, 0xb2094ffd, 0xd6d6cd25, 
    0x9ba3ebd3, 0x110609f7, 0xc5e3a308, 0x133e9ed3, 0x08958e07, 0x2b1e3e02, 0x34891054, 0xdfe9aa0a, 
    0xd8bfe72c, 0xd528b8e4, 0x83ed0c14, 0x273012a6, 0x4d1d05d4, 0xd51304ce, 0x8f8eae5d, 0xf2fb59d9, 
    0xfe95ca41, 0xd2e81aea, 0x993019d5, 0xdb010ba4, 0x81e41c2d, 0x24f44b35, 0xe3b0f0ff, 0xdfecf9e0, 
    0x26e7e8bb, 0x1aff12d2, 0x77503f1a, 0x0f3c5811, 0x4cbd4d54, 0xaf0e28eb, 0xe2bbedcd, 0xfb16484c, 
    0xe5b416ce, 0xcfe7e5c5, 0x0c0529ee, 0xc13413b7, 0x051b3f01, 0x79e54745, 0x72fbe957, 0x07f5de4a, 
    0x29dbcacb, 0xeaebfefc, 0xc9fe1dff, 0x8f12dcd0, 0x221040e8, 0xf64dcee2, 0x70351eda, 0x7fcc2b57, 
    0x29b8ed0d, 0x0dd7232e, 0x2bf7e3c8, 0xfffffeb2, 0x00000004, 0x00000010, 0x00000001, 0x00000001, 
    0x000000c8, 0x00000028, 0xfffffece, 0x00000004, 0x00000010, 0x00000001, 0x00000064, 0x00000001, 
    0x00000018, 0xfffffeea, 0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x00000018, 
    0xffffff06, 0x00000004, 0x00000010, 0x00000001, 0x00000032, 0x00000001, 0x00000020, 0xffffff22, 
    0x00000004, 0x0000000c, 0x00000001, 0x00000019, 0x00000020, 0xffffff3a, 0x00000004, 0x00000004, 
    0x00000001, 0xffffcc0c, 0xffffcc10, 0x0000000f, 0x52494c4d, 0x6e6f4320, 0x74726576, 0x002e6465, 
    0x00000001, 0x00000014, 0x000e0000, 0x00140018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000014, 
    0x0000001c, 0x0000045c, 0x00000460, 0x00000464, 0x00000004, 0x6e69616d, 0x00000000, 0x00000010, 
    0x00000420, 0x000003c4, 0x00000370, 0x0000032c, 0x00000308, 0x000002b4, 0x00000290, 0x0000024c, 
    0x00000208, 0x000001e4, 0x000001a0, 0x0000017c, 0x000000c4, 0x00000078, 0x00000040, 0x00000004, 
    0xfffffc86, 0x0000001c, 0x09000000, 0x0000001c, 0x00000020, 0x00000006, 0x00060000, 0x00040008, 
    0x00000006, 0x3f800000, 0x00000001, 0x00000035, 0x00000001, 0x00000034, 0xfffffcbe, 0x00000014, 
    0x08000000, 0x00000010, 0x00000014, 0x00000005, 0xffffccf8, 0x00000001, 0x00000034, 0x00000003, 
    0x00000033, 0x00000012, 0x00000011, 0xfffffcf2, 0x00000014, 0x1b000000, 0x00000010, 0x00000014, 
    0x00000004, 0xffffcd2c, 0x00000001, 0x00000033, 0x00000002, 0x00000032, 0x00000001, 0x00160000, 
    0x0018001c, 0x00100014, 0x0008000f, 0x00000000, 0x00040000, 0x00000016, 0x00000018, 0x00000034, 
    0x47000000, 0x00000038, 0x0000003c, 0x00000003, 0x00000005, 0x0000002d, 0x0000002e, 0x0000002f, 
    0x00000030, 0x00000031, 0x000c0008, 0x0004000b, 0x00000008, 0x41200000, 0x04000000, 0x00000001, 
    0x00000032, 0x00000018, 0x0000002a, 0x0000001e, 0x0000001d, 0x0000001c, 0x0000001b, 0x0000001a, 
    0x00000019, 0x00000018, 0x00000017, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000016, 0x00000015, 
    0x00000014, 0x00000013, 0xffffffff, 0xffffffff, 0x0000002b, 0x0000002c, 0xffffffff, 0xffffffff, 
    0xffffffff, 0xffffffff, 0xfffffd92, 0x00000008, 0x0000000c, 0x00000001, 0x0000002a, 0x00000002, 
    0x00000029, 0x00000002, 0xfffffe0e, 0x00000014, 0x05000000, 0x00000024, 0x00000028, 0x00000002, 
    0xfffffefe, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x01000000, 0x00000001, 0x00000029, 
    0x00000001, 0x00000028, 0xfffffdf2, 0x00000008, 0x0000000c, 0x00000001, 0x00000028, 0x00000002, 
    0x00000027, 0x00000003, 0xfffffe6e, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xfffffe60, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x00000027, 0x00000003, 0x00000026, 
    0x0000000f, 0x00000010, 0xfffffeae, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xfffffea0, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x00000026, 0x00000003, 0x00000025, 
    0x0000000d, 0x0000000e, 0xfffffe92, 0x00000008, 0x0000000c, 0x00000001, 0x00000025, 0x00000002, 
    0x00000024, 0x00000004, 0xffffff0e, 0x00000024, 0x05000000, 0x00000034, 0x00000038, 0x00000002, 
    0x000e0000, 0x00170018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000002, 0x00000001, 0x00000002, 
    0x00000001, 0x01000000, 0x00000001, 0x00000024, 0x00000001, 0x00000023, 0xffffff02, 0x00000008, 
    0x0000000c, 0x00000001, 0x00000023, 0x00000002, 0x00000022, 0x00000005, 0xffffff7e, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffff70, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x00000022, 0x00000003, 0x00000021, 0x0000000b, 0x0000000c, 0xffffffbe, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffffb0, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x00000021, 0x00000003, 0x00000020, 0x00000009, 0x0000000a, 0x000e0000, 0x00140018, 
    0x000c0010, 0x0004000b, 0x0000000e, 0x00000020, 0x01000000, 0x00000028, 0x0000002c, 0x00000001, 
    0x0010000c, 0x000c0000, 0x00070008, 0x0000000c, 0x01000000, 0x00000001, 0x00000002, 0x00000001, 
    0x00000020, 0x00000003, 0x0000001f, 0x00000007, 0x00000008, 0x000a0000, 0x0000000c, 0x00040008, 
    0x0000000a, 0x00000008, 0x0000000c, 0x00000001, 0x0000001f, 0x00000002, 0x00000000, 0x00000006, 
    0x00000001, 0x00000035, 0x00000001, 0x00000000, 0x00000036, 0x00002fb4, 0x00002f24, 0x00002ebc, 
    0x00002e50, 0x00002de0, 0x00002d78, 0x00002d08, 0x00002b44, 0x00002a38, 0x000027ac, 0x00002610, 
    0x000023bc, 0x00002220, 0x00001f2c, 0x00001d30, 0x00001a74, 0x00001878, 0x000017e4, 0x00001758, 
    0x000016fc, 0x000016a0, 0x00001644, 0x000015e8, 0x00001584, 0x00001520, 0x000014bc, 0x00001458, 
    0x000013f4, 0x00001390, 0x0000132c, 0x000012c8, 0x0000122c, 0x00001040, 0x00000e1c, 0x00000c30, 
    0x00000b9c, 0x00000b08, 0x00000a6c, 0x00000840, 0x0000064c, 0x000005b8, 0x00000524, 0x00000498, 
    0x00000438, 0x000003bc, 0x00000380, 0x00000328, 0x000002ec, 0x000002ac, 0x00000240, 0x000001b0, 
    0x0000012c, 0x00000070, 0x00000004, 0xffffd13a, 0x01000000, 0x00000014, 0x00000030, 0x00000031, 
    0x09000000, 0x00000044, 0xffffd124, 0x00000008, 0x00000010, 0x00000001, 0xffffff80, 0xffffffff, 
    0x00000001, 0x3b800000, 0x00000019, 0x74617453, 0x6c756665, 0x74726150, 0x6f697469, 0x4364656e, 
    0x3a6c6c61, 0x00000030, 0x00000002, 0x00000001, 0x00000003, 0xffffd1a2, 0x01000000, 0x00000014, 
    0x00000030, 0x00000030, 0x09000000, 0x00000094, 0xffffd18c, 0x00000008, 0x00000010, 0x00000001, 
    0xffffffd9, 0xffffffff, 0x00000001, 0x3d5b9f69, 0x0000006a, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 
    0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 
    0x614d2f39, 0x6c754d74, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6964656d, 
    0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 0x422f3931, 0x41736169, 0x00006464, 
    0x00000002, 0x00000001, 0x00000003, 0xffffd25a, 0x01000000, 0x00000014, 0x00000030, 0x0000002f, 
    0x09000000, 0x0000005c, 0xffffd244, 0x00000008, 0x00000010, 0x00000001, 0x00000000, 0x00000000, 
    0x00000001, 0x3c000e41, 0x00000032, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 
    0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x654d2f38, 0x00006e61, 
    0x00000002, 0x00000001, 0x00000010, 0xffffd2da, 0x01000000, 0x00000014, 0x00000030, 0x0000002e, 
    0x09000000, 0x0000004c, 0xffffd2c4, 0x00000008, 0x00000010, 0x00000001, 0xffffffff, 0xffffffff, 
    0x00000001, 0x3c008081, 0x00000020, 0x2e6c6674, 0x64696e75, 0x63657269, 0x6e6f6974, 0x735f6c61, 
    0x65757165, 0x5f65636e, 0x6d74736c, 0x00000000, 0x00000003, 0x00000001, 0x00000019, 0x00000010, 
    0x00160000, 0x00140018, 0x00000013, 0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 
    0x00000010, 0x0000002c, 0x09000000, 0x0000004c, 0xffffd34c, 0x00000008, 0x00000010, 0x00000001, 
    0xffffffff, 0xffffffff, 0x00000001, 0x3c008081, 0x00000023, 0x65666665, 0x76697463, 0x69685f65, 
    0x6e656464, 0x6163735f, 0x695f656c, 0x7265746e, 0x6964656d, 0x00657461, 0x00000001, 0x00000000, 
    0xffffff4e, 0x01000000, 0x00000008, 0x00000028, 0x0000001c, 0x75706e69, 0x6f745f74, 0x74756f5f, 
    0x5f747570, 0x65746e69, 0x64656d72, 0x65746169, 0x00000000, 0x00000001, 0x00000000, 0xffffff8a, 
    0x01000000, 0x00000008, 0x00000024, 0x0000001a, 0x75706e69, 0x6f745f74, 0x6c65635f, 0x6e695f6c, 
    0x6d726574, 0x61696465, 0x00006574, 0x00000001, 0x00000000, 0xffffffc2, 0x01000000, 0x00000008, 
    0x00000028, 0x0000001c, 0x75706e69, 0x6f745f74, 0x726f665f, 0x5f746567, 0x65746e69, 0x64656d72, 
    0x65746169, 0x00000000, 0x00000001, 0x00000000, 0x00160000, 0x000c0010, 0x00000000, 0x00000008, 
    0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000008, 0x00000024, 0x0000001b, 0x75706e69, 
    0x6f745f74, 0x706e695f, 0x695f7475, 0x7265746e, 0x6964656d, 0x00657461, 0x00000001, 0x00000000, 
    0xffffff9e, 0x01010000, 0x00000010, 0x00000030, 0x07000000, 0x00000040, 0xffffd4b4, 0x00000008, 
    0x00000014, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3a000000, 0x00000012, 
    0x2e6c6674, 0x75657370, 0x715f6f64, 0x736e6f63, 0x00003174, 0x00000002, 0x00000001, 0x00000010, 
    0x00160000, 0x00140018, 0x00000013, 0x0008000c, 0x00000007, 0x00060000, 0x00000016, 0x01010000, 
    0x00000010, 0x0000002c, 0x09000000, 0x0000003c, 0xffffd52c, 0x00000008, 0x00000010, 0x00000001, 
    0xffffffff, 0xffffffff, 0x00000001, 0x3c008081, 0x00000011, 0x2e6c6674, 0x75657370, 0x715f6f64, 
    0x736e6f63, 0x00000074, 0x00000002, 0x00000001, 0x00000010, 0xffffd5a2, 0x01000000, 0x00000014, 
    0x00000030, 0x0000002b, 0x09000000, 0x00000060, 0xffffd58c, 0x00000008, 0x00000010, 0x00000001, 
    0xffffff80, 0xffffffff, 0x00000001, 0x3d1827b7, 0x00000036, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 
    0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 
    0x71532f36, 0x7a656575, 0x00003165, 0x00000003, 0x00000001, 0x00000019, 0x00000020, 0xffffd62a, 
    0x01000000, 0x00000014, 0x00000034, 0x0000002a, 0x09000000, 0x00000064, 0xffffd614, 0x00000008, 
    0x00000014, 0x00000001, 0xffffff80, 0xffffffff, 0x00000000, 0x00000001, 0x3d1827b7, 0x00000035, 
    0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 
    0x302d7963, 0x79616c2f, 0x315f7265, 0x614d2f36, 0x6f6f5078, 0x0000006c, 0x00000004, 0x00000001, 
    0x00000019, 0x00000001, 0x00000020, 0xffffd6ba, 0x01000000, 0x00000014, 0x00000030, 0x00000029, 
    0x09000000, 0x00000064, 0xffffd6a4, 0x00000008, 0x00000010, 0x00000001, 0xffffff80, 0xffffffff, 
    0x00000001, 0x3d1827b7, 0x00000039, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 
    0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x78452f36, 0x646e6170, 
    0x736d6944, 0x00000031, 0x00000004, 0x00000001, 0x00000032, 0x00000001, 0x00000020, 0xffffd74a, 
    0x01000000, 0x00000014, 0x00000030, 0x00000028, 0x09000000, 0x000001c4, 0xffffd734, 0x00000008, 
    0x00000010, 0x00000001, 0xffffff80, 0xffffffff, 0x00000001, 0x3d1827b7, 0x00000198, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x315f7265, 0x65522f35, 0x6d3b756c, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 
    0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 0x34315f72, 0x7461622f, 
    0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 
    0x6964656d, 0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 0x432f3331, 0x31766e6f, 
    0x71532f44, 0x7a656575, 0x6f6d3b65, 0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 
    0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 0x2f34315f, 0x63746162, 0x726f6e68, 
    0x756d2f6d, 0x3b315f6c, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 
    0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x61622f34, 0x6e686374, 0x2f6d726f, 
    0x3b6c756d, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 
    0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x61622f34, 0x6e686374, 0x2f6d726f, 0x3b627573, 
    0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 
    0x302d7963, 0x79616c2f, 0x315f7265, 0x6f432f33, 0x4431766e, 0x00000000, 0x00000004, 0x00000001, 
    0x00000001, 0x00000032, 0x00000020, 0xffffd93a, 0x01000000, 0x00000014, 0x00000034, 0x00000027, 
    0x09000000, 0x000001fc, 0xffffd924, 0x00000008, 0x00000014, 0x00000001, 0xffffff80, 0xffffffff, 
    0x00000000, 0x00000001, 0x3ce8baf1, 0x000001cd, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 
    0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x65522f32, 
    0x6d3b756c, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 
    0x63617275, 0x2f302d79, 0x6579616c, 0x31315f72, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 
    0x646f6d3b, 0x315f6c65, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6964656d, 0x612d6d75, 0x72756363, 
    0x2d796361, 0x616c2f30, 0x5f726579, 0x432f3031, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 
    0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 0x2d6d7569, 0x75636361, 0x79636172, 
    0x6c2f302d, 0x72657961, 0x2f31315f, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x315f7265, 0x61622f31, 0x6e686374, 0x2f6d726f, 0x3b6c756d, 0x65646f6d, 0x2f315f6c, 
    0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 
    0x315f7265, 0x61622f31, 0x6e686374, 0x2f6d726f, 0x3b627573, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 
    0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 
    0x6f432f33, 0x4431766e, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6964656d, 
    0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 0x432f3031, 0x31766e6f, 0x00000044, 
    0x00000004, 0x00000001, 0x00000001, 0x00000032, 0x00000020, 0xffffdb62, 0x01000000, 0x00000014, 
    0x00000030, 0x00000026, 0x09000000, 0x0000006c, 0xffffdb4c, 0x00000008, 0x00000010, 0x00000001, 
    0xffffff80, 0xffffffff, 0x00000001, 0x3cf863c0, 0x00000040, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 
    0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 
    0x6f432f30, 0x4431766e, 0x7078452f, 0x44646e61, 0x31736d69, 0x00000000, 0x00000004, 0x00000001, 
    0x00000001, 0x00000032, 0x00000018, 0xffffdbfa, 0x01000000, 0x00000014, 0x00000034, 0x00000025, 
    0x09000000, 0x00000064, 0xffffdbe4, 0x00000008, 0x00000014, 0x00000001, 0xffffff80, 0xffffffff, 
    0x00000000, 0x00000001, 0x3cf863c0, 0x00000034, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 
    0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x395f7265, 0x78614d2f, 
    0x6c6f6f50, 0x00000000, 0x00000004, 0x00000001, 0x00000032, 0x00000001, 0x00000018, 0xffffdc8a, 
    0x01000000, 0x00000014, 0x00000030, 0x00000024, 0x09000000, 0x00000064, 0xffffdc74, 0x00000008, 
    0x00000010, 0x00000001, 0xffffff80, 0xffffffff, 0x00000001, 0x3cf863c0, 0x00000038, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x395f7265, 0x7078452f, 0x44646e61, 0x31736d69, 0x00000000, 0x00000004, 0x00000001, 
    0x00000064, 0x00000001, 0x00000018, 0xffffdd1a, 0x01000000, 0x00000014, 0x00000030, 0x00000023, 
    0x09000000, 0x000001bc, 0xffffdd04, 0x00000008, 0x00000010, 0x00000001, 0xffffff80, 0xffffffff, 
    0x00000001, 0x3cf863c0, 0x00000191, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 
    0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x385f7265, 0x6c65522f, 0x6f6d3b75, 
    0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 0x2d6d7569, 0x75636361, 0x79636172, 
    0x6c2f302d, 0x72657961, 0x622f375f, 0x68637461, 0x6d726f6e, 0x6464612f, 0x6d3b315f, 0x6c65646f, 
    0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 
    0x6579616c, 0x2f365f72, 0x766e6f43, 0x532f4431, 0x65657571, 0x6d3b657a, 0x6c65646f, 0x632f315f, 
    0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 
    0x2f375f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 
    0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x375f7265, 
    0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x6d3b6c75, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 
    0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 0x2f375f72, 0x63746162, 
    0x726f6e68, 0x75732f6d, 0x6f6d3b62, 0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 
    0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 0x432f365f, 0x31766e6f, 0x00000044, 
    0x00000004, 0x00000001, 0x00000001, 0x00000064, 0x00000018, 0xffffdf02, 0x01000000, 0x00000014, 
    0x00000034, 0x00000022, 0x09000000, 0x000001f4, 0xffffdeec, 0x00000008, 0x00000014, 0x00000001, 
    0xffffff80, 0xffffffff, 0x00000000, 0x00000001, 0x3cef9d9d, 0x000001c5, 0x65646f6d, 0x2f315f6c, 
    0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 
    0x355f7265, 0x6c65522f, 0x6f6d3b75, 0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 
    0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 0x622f345f, 0x68637461, 0x6d726f6e, 
    0x6464612f, 0x6d3b315f, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 
    0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 0x2f335f72, 0x766e6f43, 0x532f4431, 0x65657571, 
    0x6d3b657a, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 
    0x63617275, 0x2f302d79, 0x6579616c, 0x2f345f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 
    0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 
    0x302d7963, 0x79616c2f, 0x345f7265, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x6d3b6c75, 0x6c65646f, 
    0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 
    0x6579616c, 0x2f345f72, 0x63746162, 0x726f6e68, 0x75732f6d, 0x6f6d3b62, 0x5f6c6564, 0x6f632f31, 
    0x6431766e, 0x6d74736c, 0x64656d2d, 0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 
    0x432f365f, 0x31766e6f, 0x6f6d3b44, 0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 
    0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 0x432f335f, 0x31766e6f, 0x00000044, 
    0x00000004, 0x00000001, 0x00000001, 0x00000064, 0x00000018, 0xffffe122, 0x01000000, 0x00000014, 
    0x00000030, 0x00000021, 0x09000000, 0x000001bc, 0xffffe10c, 0x00000008, 0x00000010, 0x00000001, 
    0xffffff80, 0xffffffff, 0x00000001, 0x3ccc2be8, 0x00000191, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 
    0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x325f7265, 
    0x6c65522f, 0x6f6d3b75, 0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 0x2d6d7569, 
    0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 0x622f315f, 0x68637461, 0x6d726f6e, 0x6464612f, 
    0x6d3b315f, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 
    0x63617275, 0x2f302d79, 0x6579616c, 0x2f305f72, 0x766e6f43, 0x532f4431, 0x65657571, 0x6d3b657a, 
    0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 
    0x2f302d79, 0x6579616c, 0x2f315f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x315f7265, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x6d3b6c75, 0x6c65646f, 0x632f315f, 
    0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 
    0x2f315f72, 0x63746162, 0x726f6e68, 0x75732f6d, 0x6f6d3b62, 0x5f6c6564, 0x6f632f31, 0x6431766e, 
    0x6d74736c, 0x64656d2d, 0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 0x432f305f, 
    0x31766e6f, 0x00000044, 0x00000004, 0x00000001, 0x00000001, 0x00000064, 0x0000000c, 0xffffe30a, 
    0x01000000, 0x00000014, 0x00000034, 0x00000020, 0x09000000, 0x0000006c, 0xffffe2f4, 0x00000008, 
    0x00000014, 0x00000001, 0xffffff80, 0xffffffff, 0x00000000, 0x00000001, 0x3bdfc335, 0x0000003f, 
    0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 
    0x302d7963, 0x79616c2f, 0x305f7265, 0x6e6f432f, 0x2f443176, 0x61707845, 0x6944646e, 0x0031736d, 
    0x00000004, 0x00000001, 0x00000001, 0x000000c8, 0x00000028, 0xffffe3a2, 0x01000000, 0x00000014, 
    0x00000034, 0x0000001f, 0x09000000, 0x0000003c, 0xffffe38c, 0x00000008, 0x00000014, 0x00000001, 
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3ba31f18, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0038746e, 0x00000002, 0x00000010, 0x00000020, 0xffffe402, 0x01000000, 0x00000014, 
    0x00000034, 0x0000001e, 0x09000000, 0x0000003c, 0xffffe3ec, 0x00000008, 0x00000014, 0x00000001, 
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3bb62245, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0039746e, 0x00000002, 0x00000010, 0x00000020, 0xffffe462, 0x01000000, 0x00000014, 
    0x00000030, 0x0000001d, 0x09000000, 0x0000003c, 0xffffe44c, 0x00000008, 0x00000010, 0x00000001, 
    0x00000000, 0x00000000, 0x00000001, 0x3b8cd29c, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x3031746e, 0x00000000, 0x00000002, 0x00000010, 0x00000020, 0xffffe4c2, 0x01000000, 0x00000014, 
    0x00000030, 0x0000001c, 0x09000000, 0x0000003c, 0xffffe4ac, 0x00000008, 0x00000010, 0x00000001, 
    0x00000000, 0x00000000, 0x00000001, 0x3bcefd01, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x3131746e, 0x00000000, 0x00000002, 0x00000010, 0x00000020, 0xffffe522, 0x01000000, 0x00000014, 
    0x00000034, 0x0000001b, 0x09000000, 0x0000003c, 0xffffe50c, 0x00000008, 0x00000014, 0x00000001, 
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3c00827c, 0x0000000e, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0000746e, 0x00000002, 0x00000010, 0x00000010, 0xffffe582, 0x01000000, 0x00000014, 
    0x00000034, 0x0000001a, 0x09000000, 0x0000003c, 0xffffe56c, 0x00000008, 0x00000014, 0x00000001, 
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3b874eac, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0031746e, 0x00000002, 0x00000010, 0x00000010, 0xffffe5e2, 0x01000000, 0x00000014, 
    0x00000034, 0x00000019, 0x09000000, 0x0000003c, 0xffffe5cc, 0x00000008, 0x00000014, 0x00000001, 
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3bce2277, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0032746e, 0x00000002, 0x00000010, 0x00000010, 0xffffe642, 0x01000000, 0x00000014, 
    0x00000034, 0x00000018, 0x09000000, 0x0000003c, 0xffffe62c, 0x00000008, 0x00000014, 0x00000001, 
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3b9d2322, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0033746e, 0x00000002, 0x00000010, 0x00000010, 0xffffe6a2, 0x01000000, 0x00000014, 
    0x00000030, 0x00000017, 0x02000000, 0x00000038, 0xffffe68c, 0x00000008, 0x00000010, 0x00000001, 
    0x00000000, 0x00000000, 0x00000001, 0x3941e789, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0034746e, 0x00000001, 0x00000010, 0xffffe6fa, 0x01000000, 0x00000014, 0x00000030, 0x00000016, 
    0x02000000, 0x00000038, 0xffffe6e4, 0x00000008, 0x00000010, 0x00000001, 0x00000000, 0x00000000, 
    0x00000001, 0x39588135, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0035746e, 0x00000001, 
    0x00000010, 0xffffe752, 0x01000000, 0x00000014, 0x00000030, 0x00000015, 0x02000000, 0x00000038, 
    0xffffe73c, 0x00000008, 0x00000010, 0x00000001, 0x00000000, 0x00000000, 0x00000001, 0x392765cb, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 0x00000010, 0xffffe7aa, 
    0x01000000, 0x00000014, 0x00000030, 0x00000014, 0x02000000, 0x00000038, 0xffffe794, 0x00000008, 
    0x00000010, 0x00000001, 0x00000000, 0x00000000, 0x00000001, 0x39760caa, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0037746e, 0x00000001, 0x00000010, 0xffffe802, 0x01000000, 0x00000014, 
    0x00000034, 0x00000013, 0x09000000, 0x00000064, 0xffffe7ec, 0x00000008, 0x00000014, 0x00000001, 
    0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x3c009c57, 0x00000034, 0x65646f6d, 0x2f315f6c, 
    0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 
    0x315f7265, 0x614d2f39, 0x6c754d74, 0x00000000, 0x00000002, 0x00000003, 0x00000010, 0xffffe88a, 
    0x01000000, 0x00000014, 0x00000030, 0x00000012, 0x02000000, 0x00000070, 0xffffe874, 0x00000008, 
    0x00000010, 0x00000001, 0x00000000, 0x00000000, 0x00000001, 0x3880aaa9, 0x00000044, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x315f7265, 0x69422f39, 0x64417361, 0x65522f64, 0x61566461, 0x62616972, 0x704f656c, 
    0x00000000, 0x00000001, 0x00000003, 0xffffe91a, 0x01000000, 0x00000014, 0x000001a4, 0x00000011, 
    0x02000000, 0x000001d8, 0xffffe904, 0x00000008, 0x00000108, 0x00000020, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x3813fc90, 
    0x38a77e98, 0x386f49b1, 0x38a9acc6, 0x38a097b1, 0x380d4571, 0x386db7a6, 0x382c9e05, 0x3863ec7e, 
    0x384ac08f, 0x38bb11e1, 0x38ec108c, 0x3807edd9, 0x385b2196, 0x37f5d934, 0x382b4f39, 0x3827aea0, 
    0x37e60d5d, 0x37bc3027, 0x38cf02f7, 0x384943f8, 0x3807286d, 0x3802c51e, 0x37bbf92b, 0x37d900f2, 
    0x3882f2cd, 0x3860856b, 0x38500fe6, 0x37f41a02, 0x388b17a3, 0x3874db02, 0x388b4228, 0x0000003b, 
    0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 
    0x302d7963, 0x79616c2f, 0x315f7265, 0x61622f34, 0x6e686374, 0x2f6d726f, 0x00627573, 0x00000001, 
    0x00000020, 0xffffeb12, 0x01000000, 0x00000014, 0x000001a8, 0x00000010, 0x09000000, 0x0000028c, 
    0xffffeafc, 0x00000008, 0x0000010c, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000020, 0x3aa2c87d, 0x3b383dda, 
    0x3b039b4d, 0x3b3aa3d8, 0x3b30a649, 0x3a9b657a, 0x3b02be2e, 0x3abde067, 0x3afab686, 0x3adf0649, 
    0x3b4dc632, 0x3b81d57a, 0x3a958525, 0x3af10a8f, 0x3a873705, 0x3abc7021, 0x3ab872b0, 0x3a7d0de0, 
    0x3a4f0117, 0x3b63b5b8, 0x3add63a5, 0x3a94abfc, 0x3a8fd85c, 0x3a4ec49c, 0x3a6eb376, 0x3b100a9c, 
    0x3af6f85b, 0x3ae4dd8b, 0x3a864111, 0x3b18ffe7, 0x3b06ab37, 0x3b192eac, 0x000000eb, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x315f7265, 0x61622f34, 0x6e686374, 0x2f6d726f, 0x5f6c756d, 0x6f6d3b31, 0x5f6c6564, 
    0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 
    0x72657961, 0x2f33315f, 0x766e6f43, 0x532f4431, 0x65657571, 0x6d3b657a, 0x6c65646f, 0x632f315f, 
    0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 
    0x34315f72, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x6d3b6c75, 0x6c65646f, 0x632f315f, 0x31766e6f, 
    0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 0x33315f72, 
    0x6e6f432f, 0x00443176, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 0x00000020, 0xffffedca, 
    0x01000000, 0x00000014, 0x000001a4, 0x0000000f, 0x02000000, 0x000001d8, 0xffffedb4, 0x00000008, 
    0x00000108, 0x00000020, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000020, 0x3860dc7e, 0x3915fbb9, 0x38565f61, 0x3811f46a, 0x38a1b10b, 
    0x38546e56, 0x3849b11f, 0x381c89d5, 0x388c6db7, 0x387687fe, 0x38982694, 0x38612f38, 0x388a1be6, 
    0x38403ba6, 0x384fbba7, 0x38ca7e41, 0x38204db1, 0x3828ae52, 0x38937462, 0x384015d5, 0x3868d522, 
    0x3834ac69, 0x383a2b39, 0x3816cfab, 0x38a7620c, 0x38ad1029, 0x390bdebd, 0x38881328, 0x3890f6bf, 
    0x3894dbcb, 0x38370d22, 0x38af0b7a, 0x0000003b, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 
    0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x61622f31, 
    0x6e686374, 0x2f6d726f, 0x00627573, 0x00000001, 0x00000020, 0xffffefc2, 0x01000000, 0x00000014, 
    0x000001a8, 0x0000000e, 0x09000000, 0x000002c4, 0xffffefac, 0x00000008, 0x0000010c, 0x00000020, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000020, 0x3ae7c032, 0x3b9a941f, 0x3adcf0d1, 0x3a966d37, 0x3b26a546, 0x3adaf08b, 
    0x3acfdf19, 0x3aa155a5, 0x3b10bb2b, 0x3afe15aa, 0x3b1ccffa, 0x3ae81575, 0x3b0e5729, 0x3ac61f6f, 
    0x3ad61903, 0x3b50b284, 0x3aa53709, 0x3aadd960, 0x3b17f8f2, 0x3ac5f875, 0x3aeff75c, 0x3aba3587, 
    0x3abfdf71, 0x3a9b6e8f, 0x3b2c82eb, 0x3b325d96, 0x3b9027d0, 0x3b0c3e76, 0x3b1567c6, 0x3b196b5e, 
    0x3abca8e6, 0x3b346872, 0x00000120, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 
    0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x61622f31, 0x6e686374, 
    0x2f6d726f, 0x5f6c756d, 0x6f6d3b31, 0x5f6c6564, 0x6f632f31, 0x6431766e, 0x6d74736c, 0x64656d2d, 
    0x2d6d7569, 0x75636361, 0x79636172, 0x6c2f302d, 0x72657961, 0x2f30315f, 0x766e6f43, 0x532f4431, 
    0x65657571, 0x6d3b657a, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 
    0x6363612d, 0x63617275, 0x2f302d79, 0x6579616c, 0x31315f72, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 
    0x6d3b6c75, 0x6c65646f, 0x632f315f, 0x31766e6f, 0x74736c64, 0x656d2d6d, 0x6d756964, 0x6363612d, 
    0x63617275, 0x2f302d79, 0x6579616c, 0x30315f72, 0x6e6f432f, 0x3b443176, 0x65646f6d, 0x2f315f6c, 
    0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 
    0x315f7265, 0x6f432f33, 0x4431766e, 0x00000000, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 
    0x00000018, 0xfffff2b2, 0x01000000, 0x00000014, 0x00000144, 0x0000000d, 0x02000000, 0x00000178, 
    0xfffff29c, 0x00000008, 0x000000c8, 0x00000018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000018, 0x38925dcd, 0x389cbda9, 0x3851f8a1, 
    0x3823717c, 0x39241444, 0x3835516f, 0x389e51f1, 0x3862d955, 0x3878ecae, 0x384bfe7a, 0x380c4d04, 
    0x389e8d0f, 0x385fd04e, 0x381835ce, 0x38789026, 0x3837dd16, 0x38530a7f, 0x385e04f8, 0x3881c23e, 
    0x382a2f4a, 0x3821b5a1, 0x384d8aca, 0x38303c46, 0x382cde1c, 0x0000003a, 0x65646f6d, 0x2f315f6c, 
    0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 
    0x375f7265, 0x7461622f, 0x6f6e6863, 0x732f6d72, 0x00006275, 0x00000001, 0x00000018, 0xfffff44a, 
    0x01000000, 0x00000014, 0x00000144, 0x0000000c, 0x09000000, 0x00000224, 0xfffff434, 0x00000008, 
    0x000000c8, 0x00000018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000018, 0x3b1c5fe4, 0x3b27755a, 0x3ae0541a, 0x3aae9e80, 0x3baf4c6a, 
    0x3ac1b758, 0x3b292547, 0x3af25c3e, 0x3b04f902, 0x3ad9f152, 0x3a95e4ef, 0x3b296470, 0x3aef1e15, 
    0x3aa29e30, 0x3b04c794, 0x3ac46f8d, 0x3ae178b1, 0x3aed3357, 0x3b0aa19f, 0x3ab5d250, 0x3aacc44c, 
    0x3adb98bb, 0x3abc4936, 0x3ab8b018, 0x000000e7, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 
    0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x375f7265, 0x7461622f, 
    0x6f6e6863, 0x6d2f6d72, 0x315f6c75, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 
    0x6964656d, 0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 0x6f432f36, 0x4431766e, 
    0x7571532f, 0x657a6565, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6964656d, 
    0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 0x61622f37, 0x6e686374, 0x2f6d726f, 
    0x3b6c756d, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 
    0x61727563, 0x302d7963, 0x79616c2f, 0x365f7265, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000018, 
    0x00000001, 0x00000003, 0x00000018, 0xfffff69a, 0x01000000, 0x00000014, 0x00000144, 0x0000000b, 
    0x02000000, 0x00000178, 0xfffff684, 0x00000008, 0x000000c8, 0x00000018, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000018, 0x386e6b1b, 
    0x38cb60cb, 0x3892a572, 0x389d1e4f, 0x38a84e69, 0x388dcb70, 0x3892944e, 0x38e747e1, 0x38c9127c, 
    0x3864419f, 0x38a405d0, 0x38bdfaf9, 0x39298f46, 0x388c72e0, 0x38aee598, 0x393b6df0, 0x389cbae6, 
    0x38a7d552, 0x389d91e4, 0x38c37705, 0x386c0abc, 0x38e82116, 0x3937c72f, 0x389ca476, 0x0000003a, 
    0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 
    0x302d7963, 0x79616c2f, 0x345f7265, 0x7461622f, 0x6f6e6863, 0x732f6d72, 0x00006275, 0x00000001, 
    0x00000018, 0xfffff832, 0x01000000, 0x00000014, 0x00000148, 0x0000000a, 0x09000000, 0x0000025c, 
    0xfffff81c, 0x00000008, 0x000000cc, 0x00000018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000018, 0x3b15785e, 0x3b7f0154, 
    0x3b37df42, 0x3b4500a7, 0x3b5307cd, 0x3b31c9f9, 0x3b37c9c5, 0x3b90fed6, 0x3b7c1d2b, 0x3b0f196f, 
    0x3b4da8d6, 0x3b6e34db, 0x3bd49a1e, 0x3b3019f1, 0x3b5b4b46, 0x3beb020c, 0x3b448402, 0x3b526ff9, 
    0x3b459194, 0x3b751551, 0x3b13faf7, 0x3b918702, 0x3be66e02, 0x3b4467e0, 0x0000011b, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x345f7265, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x315f6c75, 0x646f6d3b, 0x315f6c65, 
    0x6e6f632f, 0x6c643176, 0x2d6d7473, 0x6964656d, 0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 
    0x5f726579, 0x6f432f33, 0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 
    0x6c643176, 0x2d6d7473, 0x6964656d, 0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 
    0x61622f34, 0x6e686374, 0x2f6d726f, 0x3b6c756d, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 
    0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x335f7265, 0x6e6f432f, 
    0x3b443176, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 
    0x61727563, 0x302d7963, 0x79616c2f, 0x365f7265, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000018, 
    0x00000001, 0x00000003, 0x0000000c, 0xfffffaba, 0x01000000, 0x00000014, 0x000000b4, 0x00000009, 
    0x02000000, 0x000000e8, 0xfffffaa4, 0x00000008, 0x00000068, 0x0000000c, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000c, 0x38a4d496, 
    0x38a67163, 0x38407328, 0x38770524, 0x38b6e0b8, 0x388c303b, 0x389dfe55, 0x3826c04a, 0x386df256, 
    0x38d01bcd, 0x387bc00f, 0x38b867ef, 0x0000003a, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 
    0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x7461622f, 
    0x6f6e6863, 0x732f6d72, 0x00006275, 0x00000001, 0x0000000c, 0xfffffbc2, 0x01000000, 0x00000014, 
    0x000000b4, 0x00000008, 0x09000000, 0x00000194, 0xfffffbac, 0x00000008, 0x00000068, 0x0000000c, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x0000000c, 0x3c3c93d9, 0x3c3e6c1f, 0x3bdc2d14, 0x3c0d4ddc, 0x3c51399b, 0x3c2062a6, 0x3c34c170, 
    0x3bbec664, 0x3c081d22, 0x3c6e173f, 0x3c10028c, 0x3c52f92f, 0x000000e7, 0x65646f6d, 0x2f315f6c, 
    0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 
    0x315f7265, 0x7461622f, 0x6f6e6863, 0x6d2f6d72, 0x315f6c75, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 
    0x6c643176, 0x2d6d7473, 0x6964656d, 0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 
    0x6f432f30, 0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 0x315f6c65, 0x6e6f632f, 0x6c643176, 
    0x2d6d7473, 0x6964656d, 0x612d6d75, 0x72756363, 0x2d796361, 0x616c2f30, 0x5f726579, 0x61622f31, 
    0x6e686374, 0x2f6d726f, 0x3b6c756d, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 
    0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x305f7265, 0x6e6f432f, 0x00443176, 
    0x00000004, 0x0000000c, 0x00000001, 0x00000003, 0x00000028, 0xfffffd82, 0x01000000, 0x00000014, 
    0x00000014, 0x00000007, 0x02000000, 0x0000004c, 0xfffffdf8, 0x0000003e, 0x65646f6d, 0x2f315f6c, 
    0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 
    0x305f7265, 0x6e6f432f, 0x2f443176, 0x61707845, 0x6944646e, 0x0000736d, 0x00000001, 0x00000004, 
    0xfffffdee, 0x01000000, 0x00000014, 0x00000014, 0x00000006, 0x02000000, 0x00000044, 0xfffffe64, 
    0x00000037, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 
    0x61727563, 0x302d7963, 0x79616c2f, 0x395f7265, 0x7078452f, 0x44646e61, 0x00736d69, 0x00000001, 
    0x00000004, 0xfffffe52, 0x01000000, 0x00000014, 0x00000014, 0x00000005, 0x02000000, 0x0000004c, 
    0xfffffec8, 0x0000003f, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 
    0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x6f432f30, 0x4431766e, 0x7078452f, 
    0x44646e61, 0x00736d69, 0x00000001, 0x00000004, 0xfffffebe, 0x01000000, 0x00000014, 0x00000014, 
    0x00000004, 0x02000000, 0x00000048, 0xffffff34, 0x00000038, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 
    0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 
    0x78452f36, 0x646e6170, 0x736d6944, 0x00000000, 0x00000001, 0x00000004, 0xffffff26, 0x01000000, 
    0x00000014, 0x00000014, 0x00000003, 0x02000000, 0x00000044, 0xffffff9c, 0x00000035, 0x65646f6d, 
    0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 0x61727563, 0x302d7963, 
    0x79616c2f, 0x315f7265, 0x71532f36, 0x7a656575, 0x00000065, 0x00000001, 0x00000003, 0xffffff8a, 
    0x01000000, 0x00000018, 0x00000018, 0x00000002, 0x02000000, 0x00000058, 0x00040004, 0x00000004, 
    0x00000044, 0x65646f6d, 0x2f315f6c, 0x766e6f63, 0x736c6431, 0x6d2d6d74, 0x75696465, 0x63612d6d, 
    0x61727563, 0x302d7963, 0x79616c2f, 0x315f7265, 0x654d2f38, 0x722f6e61, 0x63756465, 0x6e6f6974, 
    0x646e695f, 0x73656369, 0x00000000, 0x00000000, 0x00160000, 0x0018001c, 0x00100017, 0x0008000c, 
    0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000020, 0x0000003c, 0x00000001, 0x09000000, 
    0x00000050, 0x000c000c, 0x00000000, 0x00040008, 0x0000000c, 0x00000008, 0x00000010, 0x00000001, 
    0xffffff80, 0xffffffff, 0x00000001, 0x3bdfc335, 0x00000019, 0x76726573, 0x5f676e69, 0x61666564, 
    0x5f746c75, 0x75706e69, 0x3a325f74, 0x00000030, 0x00000003, 0x00000001, 0x000000c8, 0x00000028, 
    0x00000007, 0x00000090, 0x00000070, 0x00000050, 0x00000040, 0x0000002c, 0x00000018, 0x00000004, 
    0xffffffb4, 0x00000019, 0x00000002, 0x19000000, 0xffffffc4, 0x00000009, 0x00000004, 0x09000000, 
    0xffffffd4, 0x00000028, 0x00000002, 0x28000000, 0xffffffc8, 0x0000002c, 0x2c000000, 0xfffffff0, 
    0x00000011, 0x00000002, 0x11000000, 0x0010000c, 0x0000000f, 0x00040008, 0x0000000c, 0x00000003, 
    0x00000003, 0x03000000, 0x000c000c, 0x0000000b, 0x00040000, 0x0000000c, 0x00000016, 0x16000000
};

static const uint32_t _K11[] = {
    0x3da3d70a, 0x3da3e945, 0x3da41ff6, 0x3da47b1a, 0x3da4faae, 0x3da59ead, 0x3da66711, 0x3da753d1, 
    0x3da864e6, 0x3da99a43, 0x3daaf3de, 0x3dac71a8, 0x3dae1393, 0x3dafd990, 0x3db1c38b, 0x3db3d173, 
    0x3db60333, 0x3db858b5, 0x3dbad1e2, 0x3dbd6ea1, 0x3dc02eda, 0x3dc3126f, 0x3dc61946, 0x3dc9433f, 
    0x3dcc903c, 0x3dd0001c, 0x3dd392bc, 0x3dd747fa, 0x3ddb1fb0, 0x3ddf19b9, 0x3de335ed, 0x3de77423, 
    0x3debd432, 0x3df055ed, 0x3df4f929, 0x3df9bdb7, 0x3dfea369, 0x3e01d506, 0x3e0468b9, 0x3e070cb2, 
    0x3e09c0d8, 0x3e0c8510, 0x3e0f593f, 0x3e123d48, 0x3e15310f, 0x3e183476, 0x3e1b4760, 0x3e1e69af, 
    0x3e219b42, 0x3e24dbfc, 0x3e282bba, 0x3e2b8a5d, 0x3e2ef7c4, 0x3e3273cb, 0x3e35fe51, 0x3e399733, 
    0x3e3d3e4d, 0x3e40f37b, 0x3e44b697, 0x3e48877d, 0x3e4c6608, 0x3e50520f, 0x3e544b6e, 0x3e5851fc, 
    0x3e5c6591, 0x3e608606, 0x3e64b330, 0x3e68ece8, 0x3e6d3302, 0x3e718555, 0x3e75e3b6, 0x3e7a4df9, 
    0x3e7ec3f3, 0x3e81a2bc, 0x3e83e92d, 0x3e863537, 0x3e8886c2, 0x3e8addb8, 0x3e8d3a02, 0x3e8f9b87, 
    0x3e920232, 0x3e946de9, 0x3e96de94, 0x3e99541c, 0x3e9bce69, 0x3e9e4d61, 0x3ea0d0ec, 0x3ea358f1, 
    0x3ea5e557, 0x3ea87604, 0x3eab0ae0, 0x3eada3d1, 0x3eb040bc, 0x3eb2e189, 0x3eb5861c, 0x3eb82e5d, 
    0x3ebada30, 0x3ebd897b, 0x3ec03c23, 0x3ec2f20e, 0x3ec5ab21, 0x3ec86741, 0x3ecb2653, 0x3ecde83b, 
    0x3ed0acdf, 0x3ed37422, 0x3ed63de9, 0x3ed90a1a, 0x3edbd897, 0x3edea945, 0x3ee17c09, 0x3ee450c6, 
    0x3ee72760, 0x3ee9ffbb, 0x3eecd9bb, 0x3eefb544, 0x3ef29239, 0x3ef5707e, 0x3ef84ff6, 0x3efb3086, 
    0x3efe1210, 0x3f007a3c, 0x3f01ebd1, 0x3f035db8, 0x3f04cfe4, 0x3f064245, 0x3f07b4ce, 0x3f09276f, 
    0x3f0a9a1c, 0x3f0c0cc5, 0x3f0d7f5c, 0x3f0ef1d3, 0x3f10641b, 0x3f11d626, 0x3f1347e6, 0x3f14b94c, 
    0x3f162a4a, 0x3f179ad3, 0x3f190ad7, 0x3f1a7a48, 0x3f1be918, 0x3f1d5739, 0x3f1ec49d, 0x3f203136, 
    0x3f219cf5, 0x3f2307cc, 0x3f2471ae, 0x3f25da8c, 0x3f274259, 0x3f28a906, 0x3f2a0e86, 0x3f2b72ca, 
    0x3f2cd5c6, 0x3f2e376a, 0x3f2f97ab, 0x3f30f679, 0x3f3253c7, 0x3f33af88, 0x3f3509af, 0x3f36622d, 
    0x3f37b8f7, 0x3f390dfd, 0x3f3a6134, 0x3f3bb28d, 0x3f3d01fd, 0x3f3e4f76, 0x3f3f9aea, 0x3f40e44e, 
    0x3f422b95, 0x3f4370b1, 0x3f44b397, 0x3f45f439, 0x3f47328c, 0x3f486e82, 0x3f49a811, 0x3f4adf2b, 
    0x3f4c13c5, 0x3f4d45d2, 0x3f4e7547, 0x3f4fa219, 0x3f50cc3a, 0x3f51f3a1, 0x3f531841, 0x3f543a0f, 
    0x3f555901, 0x3f56750a, 0x3f578e20, 0x3f58a437, 0x3f59b746, 0x3f5ac742, 0x3f5bd420, 0x3f5cddd5, 
    0x3f5de457, 0x3f5ee79d, 0x3f5fe79c, 0x3f60e44a, 0x3f61dd9d, 0x3f62d38c, 0x3f63c60e, 0x3f64b518, 
    0x3f65a0a2, 0x3f6688a3, 0x3f676d11, 0x3f684de4, 0x3f692b13, 0x3f6a0495, 0x3f6ada62, 0x3f6bac72, 
    0x3f6c7abd, 0x3f6d453a, 0x3f6e0be2, 0x3f6ecead, 0x3f6f8d94, 0x3f70488f, 0x3f70ff97, 0x3f71b2a4, 
    0x3f7261b1, 0x3f730cb6, 0x3f73b3ac, 0x3f74568d, 0x3f74f553, 0x3f758ff8, 0x3f762676, 0x3f76b8c6, 
    0x3f7746e3, 0x3f77d0c8, 0x3f78566f, 0x3f78d7d4, 0x3f7954f0, 0x3f79cdc0, 0x3f7a423f, 0x3f7ab267, 
    0x3f7b1e35, 0x3f7b85a5, 0x3f7be8b3, 0x3f7c475a, 0x3f7ca197, 0x3f7cf767, 0x3f7d48c6, 0x3f7d95b2, 
    0x3f7dde26, 0x3f7e2221, 0x3f7e619f, 0x3f7e9c9f, 0x3f7ed31e, 0x3f7f051a, 0x3f7f3290, 0x3f7f5b80, 
    0x3f7f7fe7, 0x3f7f9fc5, 0x3f7fbb17, 0x3f7fd1dd, 0x3f7fe416, 0x3f7ff1c2, 0x3f7ffadf, 0x3f7fff6e, 
    0x3f7fff6e, 0x3f7ffadf, 0x3f7ff1c2, 0x3f7fe416, 0x3f7fd1dd, 0x3f7fbb17, 0x3f7f9fc5, 0x3f7f7fe7, 
    0x3f7f5b80, 0x3f7f3290, 0x3f7f051a, 0x3f7ed31e, 0x3f7e9c9f, 0x3f7e619f, 0x3f7e2221, 0x3f7dde26, 
    0x3f7d95b2, 0x3f7d48c6, 0x3f7cf767, 0x3f7ca197, 0x3f7c475a, 0x3f7be8b3, 0x3f7b85a5, 0x3f7b1e35, 
    0x3f7ab267, 0x3f7a423f, 0x3f79cdc0, 0x3f7954f0, 0x3f78d7d4, 0x3f78566f, 0x3f77d0c8, 0x3f7746e3, 
    0x3f76b8c6, 0x3f762676, 0x3f758ff8, 0x3f74f553, 0x3f74568d, 0x3f73b3ac, 0x3f730cb6, 0x3f7261b1, 
    0x3f71b2a4, 0x3f70ff97, 0x3f70488f, 0x3f6f8d94, 0x3f6ecead, 0x3f6e0be2, 0x3f6d453a, 0x3f6c7abd, 
    0x3f6bac72, 0x3f6ada62, 0x3f6a0495, 0x3f692b13, 0x3f684de4, 0x3f676d11, 0x3f6688a3, 0x3f65a0a2, 
    0x3f64b518, 0x3f63c60e, 0x3f62d38c, 0x3f61dd9d, 0x3f60e44a, 0x3f5fe79c, 0x3f5ee79d, 0x3f5de457, 
    0x3f5cddd5, 0x3f5bd420, 0x3f5ac742, 0x3f59b746, 0x3f58a437, 0x3f578e20, 0x3f56750a, 0x3f555901, 
    0x3f543a0f, 0x3f531841, 0x3f51f3a1, 0x3f50cc3a, 0x3f4fa219, 0x3f4e7547, 0x3f4d45d2, 0x3f4c13c5, 
    0x3f4adf2b, 0x3f49a811, 0x3f486e82, 0x3f47328c, 0x3f45f439, 0x3f44b397, 0x3f4370b1, 0x3f422b95, 
    0x3f40e44e, 0x3f3f9aea, 0x3f3e4f76, 0x3f3d01fd, 0x3f3bb28d, 0x3f3a6134, 0x3f390dfd, 0x3f37b8f7, 
    0x3f36622d, 0x3f3509af, 0x3f33af88, 0x3f3253c7, 0x3f30f679, 0x3f2f97ab, 0x3f2e376a, 0x3f2cd5c6, 
    0x3f2b72ca, 0x3f2a0e86, 0x3f28a906, 0x3f274259, 0x3f25da8c, 0x3f2471ae, 0x3f2307cc, 0x3f219cf5, 
    0x3f203136, 0x3f1ec49d, 0x3f1d5739, 0x3f1be918, 0x3f1a7a48, 0x3f190ad7, 0x3f179ad3, 0x3f162a4a, 
    0x3f14b94c, 0x3f1347e6, 0x3f11d626, 0x3f10641b, 0x3f0ef1d3, 0x3f0d7f5c, 0x3f0c0cc5, 0x3f0a9a1c, 
    0x3f09276f, 0x3f07b4ce, 0x3f064245, 0x3f04cfe4, 0x3f035db8, 0x3f01ebd1, 0x3f007a3c, 0x3efe1210, 
    0x3efb3086, 0x3ef84ff6, 0x3ef5707e, 0x3ef29239, 0x3eefb544, 0x3eecd9bb, 0x3ee9ffbb, 0x3ee72760, 
    0x3ee450c6, 0x3ee17c09, 0x3edea945, 0x3edbd897, 0x3ed90a1a, 0x3ed63de9, 0x3ed37422, 0x3ed0acdf, 
    0x3ecde83b, 0x3ecb2653, 0x3ec86741, 0x3ec5ab21, 0x3ec2f20e, 0x3ec03c23, 0x3ebd897b, 0x3ebada30, 
    0x3eb82e5d, 0x3eb5861c, 0x3eb2e189, 0x3eb040bc, 0x3eada3d1, 0x3eab0ae0, 0x3ea87604, 0x3ea5e557, 
    0x3ea358f1, 0x3ea0d0ec, 0x3e9e4d61, 0x3e9bce69, 0x3e99541c, 0x3e96de94, 0x3e946de9, 0x3e920232, 
    0x3e8f9b87, 0x3e8d3a02, 0x3e8addb8, 0x3e8886c2, 0x3e863537, 0x3e83e92d, 0x3e81a2bc, 0x3e7ec3f3, 
    0x3e7a4df9, 0x3e75e3b6, 0x3e718555, 0x3e6d3302, 0x3e68ece8, 0x3e64b330, 0x3e608606, 0x3e5c6591, 
    0x3e5851fc, 0x3e544b6e, 0x3e50520f, 0x3e4c6608, 0x3e48877d, 0x3e44b697, 0x3e40f37b, 0x3e3d3e4d, 
    0x3e399733, 0x3e35fe51, 0x3e3273cb, 0x3e2ef7c4, 0x3e2b8a5d, 0x3e282bba, 0x3e24dbfc, 0x3e219b42, 
    0x3e1e69af, 0x3e1b4760, 0x3e183476, 0x3e15310f, 0x3e123d48, 0x3e0f593f, 0x3e0c8510, 0x3e09c0d8, 
    0x3e070cb2, 0x3e0468b9, 0x3e01d506, 0x3dfea369, 0x3df9bdb7, 0x3df4f929, 0x3df055ed, 0x3debd432, 
    0x3de77423, 0x3de335ed, 0x3ddf19b9, 0x3ddb1fb0, 0x3dd747fa, 0x3dd392bc, 0x3dd0001c, 0x3dcc903c, 
    0x3dc9433f, 0x3dc61946, 0x3dc3126f, 0x3dc02eda, 0x3dbd6ea1, 0x3dbad1e2, 0x3db858b5, 0x3db60333, 
    0x3db3d173, 0x3db1c38b, 0x3dafd990, 0x3dae1393, 0x3dac71a8, 0x3daaf3de, 0x3da99a43, 0x3da864e6, 
    0x3da753d1, 0x3da66711, 0x3da59ead, 0x3da4faae, 0x3da47b1a, 0x3da41ff6, 0x3da3e945, 0x3da3d70a
};

static const uint32_t _K23[] = {
    0x000b0009, 0x000f000d, 0x00130011, 0x00170015, 0x001d001a, 0x0022001f, 0x00290025, 0x0030002c, 
    0x00380034, 0x0040003c, 0x004a0045, 0x0055004f, 0x0061005b, 0x006e0067, 0x007d0076, 0x008e0085, 
    0x00a00097, 0x00b400aa, 0x00cb00bf, 0x00e400d7, 0x010000f2
};

// Memory mapped buffers
#define _K11             ((float *)_K11)                     // f32[512] (2048 bytes)
#define _K23             ((int16_t *)_K23)                   // s16[42] (84 bytes)
#define _K7              ((uint8_t *)_K7)                    // u8[28192] (28192 bytes)
#define _K10             ((int8_t *)(_state + 0x000086a0))   // s8[8] (8 bytes)
#define _K18             ((int32_t *)(_state + 0x0000dea8))  // s32[24] (96 bytes)
#define _K19             ((float *)(_state + 0x0000df08))    // f32[258] (1032 bytes)
#define _K2              ((int8_t *)(_state + 0x00000000))   // s8[2256] (2256 bytes)
#define _K5              ((int8_t *)(_state + 0x000008d0))   // s8[32208] (32208 bytes)
#define _K6              ((uint8_t *)(_state + 0x000086a8))  // u8[22528] (22528 bytes)
#define _K1              ((float *)(_buffer + 0x00000000))   // f32[512] (2048 bytes)
#define _K15             ((float *)(_buffer + 0x00000800))   // f32[512] (2048 bytes)
#define _K16             ((float *)(_buffer + 0x00001000))   // f32[257,2] (2056 bytes)
#define _K20             ((float *)(_buffer + 0x00001808))   // f32[1026] (4104 bytes)
#define _K22             ((float *)(_buffer + 0x00000000))   // f32[257] (1028 bytes)
#define _K27             ((float *)(_buffer + 0x00000404))   // f32[40] (160 bytes)
#define _K28             ((float *)(_buffer + 0x00000000))   // f32[40] (160 bytes)
#define _K29             ((float *)(_buffer + 0x000000a0))   // f32[40] (160 bytes)
#define _K3              ((float *)(_buffer + 0x00000000))   // f32[40] (160 bytes)
#define _K4              ((float *)(_buffer + 0x00000000))   // f32[200,40] (32000 bytes)
#define _K9              ((uint8_t *)(_buffer + 0x00007d00)) // u8[8000] (8000 bytes)

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

// Represents a Circular Buffer
// https://en.wikipedia.org/wiki/Circular_buffer
typedef struct
{
	char *buf;
	int size;		// total bytes allocated in *buf
	int used;		// current bytes used in buffer.
	int read;
	int write;
} cbuffer_t;

#define CBUFFER_SUCCESS 0
#define CBUFFER_NOMEM -1

// Initializes a cbuffer handle with given memory and size.
static inline void cbuffer_init(cbuffer_t *dest, void *mem, int size) {
	dest->buf = mem;
	dest->size = size;
	dest->used = 0;
	dest->read = 0;
	dest->write = 0;
}

// Returns the number of free bytes in buffer.
static inline int cbuffer_get_free(cbuffer_t *buf) {
	return buf->size - buf->used;
}

// Returns the number of used bytes in buffer.
static inline int cbuffer_get_used(cbuffer_t *buf) {
	return buf->used;
}

// Writes given data to buffer.
// Returns CBUFFER_SUCCESS or CBUFFER_NOMEM if out of memory.
static inline int cbuffer_enqueue(cbuffer_t *buf, const void *data, int data_size) {
	int free = cbuffer_get_free(buf);

	// Out of memory?
	if (free < data_size)
		return CBUFFER_NOMEM;

	// Is the data split in the end?
	if (buf->write + data_size > buf->size) {
		int first_size = buf->size - buf->write;
		memcpy(buf->buf + buf->write, data, first_size);
		memcpy(buf->buf, ((char *)data) + first_size, data_size - first_size);
	}
	else {
		memcpy(buf->buf + buf->write, data, data_size);
	}
	buf->write += data_size;
	if (buf->write >= buf->size)
		buf->write -= buf->size;

	buf->used += data_size;
	return CBUFFER_SUCCESS;
}

// Advances the read pointer by given count.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data
static inline int cbuffer_advance(cbuffer_t *buf, int count) {
	int used = cbuffer_get_used(buf);

	if (count > used)
		return CBUFFER_NOMEM;

	buf->read += count;
	if (buf->read >= buf->size)
		buf->read -= buf->size;

	// Reset pointers to 0 if buffer is empty in order to avoid unwanted wrapps.
	if (buf->read == buf->write) {
		buf->read = 0;
		buf->write = 0;
	}

	buf->used -= count;
	return CBUFFER_SUCCESS;
}

// Reset instance (clear buffer)
static inline void cbuffer_reset(cbuffer_t *buf) {
	buf->read = 0;
	buf->write = 0;
	buf->used = 0;
}

// Copies given "count" bytes to the "dst" buffer without advancing the buffer read offset.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data.
static inline int cbuffer_copyto(cbuffer_t *buf, void *dst, int count, int offset) {
	
	if (count > cbuffer_get_used(buf))
		return CBUFFER_NOMEM;

	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;

	int c0 = count;
	if (a0 + c0 > buf->size)
		c0 = buf->size - a0;
	
	memcpy(dst, buf->buf + a0, c0);
	
	int c1 = count - c0;

	if (c1 > 0)
		memcpy(((char *)dst) + c0, buf->buf, c1);

	return CBUFFER_SUCCESS;
}

// Returns a read pointer at given offset and  
// updates *can_read_bytes (if not NULL) with the number of bytes that can be read.
// 
// Note! Byte count written to can_read_bytes can be less than what cbuffer_get_used() returns.
// This happens when the read has to be split in two since it's a circular buffer.
static inline void *cbuffer_readptr(cbuffer_t* buf, int offset, int *can_read_bytes)
{
	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;
	if (can_read_bytes != NULL)
	{
		int c0 = buf->used;
		if (a0 + c0 > buf->size)
			c0 = buf->size - a0;

		*can_read_bytes = c0;
	}
	return buf->buf + a0;
}

typedef struct {
	cbuffer_t data_buffer;			// Circular Buffer for features
	int input_size;					// Number of bytes in each input chunk
} fixwin_t;

#ifdef _MSC_VER
static_assert(sizeof(fixwin_t) <= 64, "Data structure 'fixwin_t' is too big");
#endif

/*
* Try to dequeue a window.
*
* @param handle Pointer to an initialized handle.
* @param dst Pointer where to write window.
* @param stride_count Number of items (of size handle->input_size) to stride window.
* @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1) is no data is available.
*/
static inline int fixwin_dequeue(void* restrict handle, void* restrict dst, int count, int stride_count)
{
	fixwin_t* fep = (fixwin_t*)handle;

	const int stride_bytes = stride_count * fep->input_size;
	const int size = count * fep->input_size;
	if (cbuffer_get_used(&fep->data_buffer) >= size) {
		if (cbuffer_copyto(&fep->data_buffer, dst, size, 0) != 0)
			return IPWIN_RET_ERROR;

		if (cbuffer_advance(&fep->data_buffer, stride_bytes) != 0)
			return IPWIN_RET_ERROR;

		return IPWIN_RET_SUCCESS;
	}
	return IPWIN_RET_NODATA;
}

// input array (any shape >= 1D)
// output array (same shape as input array)
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void hammingmul_f32(const float* restrict input, const float* restrict w, int d0, int d1, int d2, float* restrict output)
{
	const int d3 = d0 * d1;

	const float* ip = input;
	float* op = output;
 
	for (int j = 0; j < d2; j++) {
		for (int i = 0; i < d0; i++) {
			for (int k = 0; k < d1; k++) {
				op[k * d0 + i] = ip[k * d0 + i] * w[k];
			}
		}

		ip += d3;
		op += d3;
	}
}

static void makeipt(int nw, int *ip)
{
    int j, l, m, m2, p, q;
    
    ip[2] = 0;
    ip[3] = 16;
    m = 2;
    for (l = nw; l > 32; l >>= 2) {
        m2 = m << 1;
        q = m2 << 3;
        for (j = m; j < m2; j++) {
            p = ip[j] << 2;
            ip[m + j] = p;
            ip[m2 + j] = p + q;
        }
        m = m2;
    }
}

static void makewt(int nw, int *ip, float *w)
{
    void makeipt(int nw, int *ip);
    int j, nwh, nw0, nw1;
    float delta, wn4r, wk1r, wk1i, wk3r, wk3i;
    
    ip[0] = nw;
    ip[1] = 1;
    if (nw > 2) {
        nwh = nw >> 1;
        delta = atan(1.0) / nwh;
        wn4r = cos(delta * nwh);
        w[0] = 1;
        w[1] = wn4r;
        if (nwh == 4) {
            w[2] = cos(delta * 2);
            w[3] = sin(delta * 2);
        } else if (nwh > 4) {
            makeipt(nw, ip);
            w[2] = 0.5 / cos(delta * 2);
            w[3] = 0.5 / cos(delta * 6);
            for (j = 4; j < nwh; j += 4) {
                w[j] = cos(delta * j);
                w[j + 1] = sin(delta * j);
                w[j + 2] = cos(3 * delta * j);
                w[j + 3] = -sin(3 * delta * j);
            }
        }
        nw0 = 0;
        while (nwh > 2) {
            nw1 = nw0 + nwh;
            nwh >>= 1;
            w[nw1] = 1;
            w[nw1 + 1] = wn4r;
            if (nwh == 4) {
                wk1r = w[nw0 + 4];
                wk1i = w[nw0 + 5];
                w[nw1 + 2] = wk1r;
                w[nw1 + 3] = wk1i;
            } else if (nwh > 4) {
                wk1r = w[nw0 + 4];
                wk3r = w[nw0 + 6];
                w[nw1 + 2] = 0.5 / wk1r;
                w[nw1 + 3] = 0.5 / wk3r;
                for (j = 4; j < nwh; j += 4) {
                    wk1r = w[nw0 + 2 * j];
                    wk1i = w[nw0 + 2 * j + 1];
                    wk3r = w[nw0 + 2 * j + 2];
                    wk3i = w[nw0 + 2 * j + 3];
                    w[nw1 + j] = wk1r;
                    w[nw1 + j + 1] = wk1i;
                    w[nw1 + j + 2] = wk3r;
                    w[nw1 + j + 3] = wk3i;
                }
            }
            nw0 = nw1;
        }
    }
}

static void makect(int nc, int *ip, float *c)
{
    int j, nch;
    float delta;
    
    ip[1] = nc;
    if (nc > 1) {
        nch = nc >> 1;
        delta = atan(1.0) / nch;
        c[0] = cos(delta * nch);
        c[nch] = 0.5 * c[0];
        for (j = 1; j < nch; j++) {
            c[j] = 0.5 * cos(delta * j);
            c[nc - j] = 0.5 * sin(delta * j);
        }
    }
}

static void bitrv2(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    }
}

static void bitrv216(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x7r, x7i, x8r, x8i, x10r, x10i, 
        x11r, x11i, x12r, x12i, x13r, x13i, x14r, x14i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    a[2] = x8r;
    a[3] = x8i;
    a[4] = x4r;
    a[5] = x4i;
    a[6] = x12r;
    a[7] = x12i;
    a[8] = x2r;
    a[9] = x2i;
    a[10] = x10r;
    a[11] = x10i;
    a[14] = x14r;
    a[15] = x14i;
    a[16] = x1r;
    a[17] = x1i;
    a[20] = x5r;
    a[21] = x5i;
    a[22] = x13r;
    a[23] = x13i;
    a[24] = x3r;
    a[25] = x3i;
    a[26] = x11r;
    a[27] = x11i;
    a[28] = x7r;
    a[29] = x7i;
}

static void bitrv208(float *a)
{
    float x1r, x1i, x3r, x3i, x4r, x4i, x6r, x6i;
    
    x1r = a[2];
    x1i = a[3];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x6r = a[12];
    x6i = a[13];
    a[2] = x4r;
    a[3] = x4i;
    a[6] = x6r;
    a[7] = x6i;
    a[8] = x1r;
    a[9] = x1i;
    a[12] = x3r;
    a[13] = x3i;
}

static void cftf1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = a[j + 3] + a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = a[j + 3] - a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = a[j0 - 1] + a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = a[j0 - 1] - a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = a[j0 - 1] + a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = a[j0 - 1] - a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i + x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = a[j0 + 3] + a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = a[j0 + 3] - a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i + x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftmdl1(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    k = 0;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
    }
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
}

static void cftmdl2(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, kr, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i, wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, y0r, y0i, y2r, y2i;
    
    mh = n >> 3;
    m = 2 * mh;
    wn4r = w[1];
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] - a[j2 + 1];
    x0i = a[1] + a[j2];
    x1r = a[0] + a[j2 + 1];
    x1i = a[1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wn4r * (x2r - x2i);
    y0i = wn4r * (x2i + x2r);
    a[0] = x0r + y0r;
    a[1] = x0i + y0i;
    a[j1] = x0r - y0r;
    a[j1 + 1] = x0i - y0i;
    y0r = wn4r * (x3r - x3i);
    y0i = wn4r * (x3i + x3r);
    a[j2] = x1r - y0i;
    a[j2 + 1] = x1i + y0r;
    a[j3] = x1r + y0i;
    a[j3 + 1] = x1i - y0r;
    k = 0;
    kr = 2 * m;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        kr -= 4;
        wd1i = w[kr];
        wd1r = w[kr + 1];
        wd3i = w[kr + 2];
        wd3r = w[kr + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] - a[j2 + 1];
        x0i = a[j + 1] + a[j2];
        x1r = a[j] + a[j2 + 1];
        x1i = a[j + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wk1r * x0r - wk1i * x0i;
        y0i = wk1r * x0i + wk1i * x0r;
        y2r = wd1r * x2r - wd1i * x2i;
        y2i = wd1r * x2i + wd1i * x2r;
        a[j] = y0r + y2r;
        a[j + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wk3r * x1r + wk3i * x1i;
        y0i = wk3r * x1i - wk3i * x1r;
        y2r = wd3r * x3r + wd3i * x3i;
        y2i = wd3r * x3i - wd3i * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] - a[j2 + 1];
        x0i = a[j0 + 1] + a[j2];
        x1r = a[j0] + a[j2 + 1];
        x1i = a[j0 + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wd1i * x0r - wd1r * x0i;
        y0i = wd1i * x0i + wd1r * x0r;
        y2r = wk1i * x2r - wk1r * x2i;
        y2i = wk1i * x2i + wk1r * x2r;
        a[j0] = y0r + y2r;
        a[j0 + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wd3i * x1r + wd3r * x1i;
        y0i = wd3i * x1i - wd3r * x1r;
        y2r = wk3i * x3r + wk3r * x3i;
        y2i = wk3i * x3i - wk3r * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
    }
    wk1r = w[m];
    wk1i = w[m + 1];
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] - a[j2 + 1];
    x0i = a[j0 + 1] + a[j2];
    x1r = a[j0] + a[j2 + 1];
    x1i = a[j0 + 1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wk1r * x0r - wk1i * x0i;
    y0i = wk1r * x0i + wk1i * x0r;
    y2r = wk1i * x2r - wk1r * x2i;
    y2i = wk1i * x2i + wk1r * x2r;
    a[j0] = y0r + y2r;
    a[j0 + 1] = y0i + y2i;
    a[j1] = y0r - y2r;
    a[j1 + 1] = y0i - y2i;
    y0r = wk1i * x1r - wk1r * x1i;
    y0i = wk1i * x1i + wk1r * x1r;
    y2r = wk1r * x3r - wk1i * x3i;
    y2i = wk1r * x3i + wk1i * x3r;
    a[j2] = y0r - y2r;
    a[j2 + 1] = y0i - y2i;
    a[j3] = y0r + y2r;
    a[j3 + 1] = y0i + y2i;
}

static int cfttree(int n, int j, int k, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    int i, isplt, m;
    
    if ((k & 3) != 0) {
        isplt = k & 1;
        if (isplt != 0) {
            cftmdl1(n, &a[j - n], &w[nw - (n >> 1)]);
        } else {
            cftmdl2(n, &a[j - n], &w[nw - n]);
        }
    } else {
        m = n;
        for (i = k; (i & 3) == 0; i >>= 2) {
            m <<= 2;
        }
        isplt = i & 1;
        if (isplt != 0) {
            while (m > 128) {
                cftmdl1(m, &a[j - m], &w[nw - (m >> 1)]);
                m >>= 2;
            }
        } else {
            while (m > 128) {
                cftmdl2(m, &a[j - m], &w[nw - m]);
                m >>= 2;
            }
        }
    }
    return isplt;
}

static void cftf161(float *a, float *w)
{
    float wn4r, wk1r, wk1i, 
        x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    x0r = a[0] + a[16];
    x0i = a[1] + a[17];
    x1r = a[0] - a[16];
    x1i = a[1] - a[17];
    x2r = a[8] + a[24];
    x2i = a[9] + a[25];
    x3r = a[8] - a[24];
    x3i = a[9] - a[25];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y4r = x0r - x2r;
    y4i = x0i - x2i;
    y8r = x1r - x3i;
    y8i = x1i + x3r;
    y12r = x1r + x3i;
    y12i = x1i - x3r;
    x0r = a[2] + a[18];
    x0i = a[3] + a[19];
    x1r = a[2] - a[18];
    x1i = a[3] - a[19];
    x2r = a[10] + a[26];
    x2i = a[11] + a[27];
    x3r = a[10] - a[26];
    x3i = a[11] - a[27];
    y1r = x0r + x2r;
    y1i = x0i + x2i;
    y5r = x0r - x2r;
    y5i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y9r = wk1r * x0r - wk1i * x0i;
    y9i = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y13r = wk1i * x0r - wk1r * x0i;
    y13i = wk1i * x0i + wk1r * x0r;
    x0r = a[4] + a[20];
    x0i = a[5] + a[21];
    x1r = a[4] - a[20];
    x1i = a[5] - a[21];
    x2r = a[12] + a[28];
    x2i = a[13] + a[29];
    x3r = a[12] - a[28];
    x3i = a[13] - a[29];
    y2r = x0r + x2r;
    y2i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y10r = wn4r * (x0r - x0i);
    y10i = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y14r = wn4r * (x0r + x0i);
    y14i = wn4r * (x0i - x0r);
    x0r = a[6] + a[22];
    x0i = a[7] + a[23];
    x1r = a[6] - a[22];
    x1i = a[7] - a[23];
    x2r = a[14] + a[30];
    x2i = a[15] + a[31];
    x3r = a[14] - a[30];
    x3i = a[15] - a[31];
    y3r = x0r + x2r;
    y3i = x0i + x2i;
    y7r = x0r - x2r;
    y7i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y11r = wk1i * x0r - wk1r * x0i;
    y11i = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y15r = wk1r * x0r - wk1i * x0i;
    y15i = wk1r * x0i + wk1i * x0r;
    x0r = y12r - y14r;
    x0i = y12i - y14i;
    x1r = y12r + y14r;
    x1i = y12i + y14i;
    x2r = y13r - y15r;
    x2i = y13i - y15i;
    x3r = y13r + y15r;
    x3i = y13i + y15i;
    a[24] = x0r + x2r;
    a[25] = x0i + x2i;
    a[26] = x0r - x2r;
    a[27] = x0i - x2i;
    a[28] = x1r - x3i;
    a[29] = x1i + x3r;
    a[30] = x1r + x3i;
    a[31] = x1i - x3r;
    x0r = y8r + y10r;
    x0i = y8i + y10i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    x3r = y9r - y11r;
    x3i = y9i - y11i;
    a[16] = x0r + x2r;
    a[17] = x0i + x2i;
    a[18] = x0r - x2r;
    a[19] = x0i - x2i;
    a[20] = x1r - x3i;
    a[21] = x1i + x3r;
    a[22] = x1r + x3i;
    a[23] = x1i - x3r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x3r = wn4r * (x0r - x0i);
    x3i = wn4r * (x0i + x0r);
    x0r = y4r - y6i;
    x0i = y4i + y6r;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    a[8] = x0r + x2r;
    a[9] = x0i + x2i;
    a[10] = x0r - x2r;
    a[11] = x0i - x2i;
    a[12] = x1r - x3i;
    a[13] = x1i + x3r;
    a[14] = x1r + x3i;
    a[15] = x1i - x3r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    x3r = y1r - y3r;
    x3i = y1i - y3i;
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x0r - x2r;
    a[3] = x0i - x2i;
    a[4] = x1r - x3i;
    a[5] = x1i + x3r;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftf162(float *a, float *w)
{
    float wn4r, wk1r, wk1i, wk2r, wk2i, wk3r, wk3i, 
        x0r, x0i, x1r, x1i, x2r, x2i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[4];
    wk1i = w[5];
    wk3r = w[6];
    wk3i = -w[7];
    wk2r = w[8];
    wk2i = w[9];
    x1r = a[0] - a[17];
    x1i = a[1] + a[16];
    x0r = a[8] - a[25];
    x0i = a[9] + a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y0r = x1r + x2r;
    y0i = x1i + x2i;
    y4r = x1r - x2r;
    y4i = x1i - x2i;
    x1r = a[0] + a[17];
    x1i = a[1] - a[16];
    x0r = a[8] + a[25];
    x0i = a[9] - a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y8r = x1r - x2i;
    y8i = x1i + x2r;
    y12r = x1r + x2i;
    y12i = x1i - x2r;
    x0r = a[2] - a[19];
    x0i = a[3] + a[18];
    x1r = wk1r * x0r - wk1i * x0i;
    x1i = wk1r * x0i + wk1i * x0r;
    x0r = a[10] - a[27];
    x0i = a[11] + a[26];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y1r = x1r + x2r;
    y1i = x1i + x2i;
    y5r = x1r - x2r;
    y5i = x1i - x2i;
    x0r = a[2] + a[19];
    x0i = a[3] - a[18];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[10] + a[27];
    x0i = a[11] - a[26];
    x2r = wk1r * x0r + wk1i * x0i;
    x2i = wk1r * x0i - wk1i * x0r;
    y9r = x1r - x2r;
    y9i = x1i - x2i;
    y13r = x1r + x2r;
    y13i = x1i + x2i;
    x0r = a[4] - a[21];
    x0i = a[5] + a[20];
    x1r = wk2r * x0r - wk2i * x0i;
    x1i = wk2r * x0i + wk2i * x0r;
    x0r = a[12] - a[29];
    x0i = a[13] + a[28];
    x2r = wk2i * x0r - wk2r * x0i;
    x2i = wk2i * x0i + wk2r * x0r;
    y2r = x1r + x2r;
    y2i = x1i + x2i;
    y6r = x1r - x2r;
    y6i = x1i - x2i;
    x0r = a[4] + a[21];
    x0i = a[5] - a[20];
    x1r = wk2i * x0r - wk2r * x0i;
    x1i = wk2i * x0i + wk2r * x0r;
    x0r = a[12] + a[29];
    x0i = a[13] - a[28];
    x2r = wk2r * x0r - wk2i * x0i;
    x2i = wk2r * x0i + wk2i * x0r;
    y10r = x1r - x2r;
    y10i = x1i - x2i;
    y14r = x1r + x2r;
    y14i = x1i + x2i;
    x0r = a[6] - a[23];
    x0i = a[7] + a[22];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[14] - a[31];
    x0i = a[15] + a[30];
    x2r = wk1i * x0r - wk1r * x0i;
    x2i = wk1i * x0i + wk1r * x0r;
    y3r = x1r + x2r;
    y3i = x1i + x2i;
    y7r = x1r - x2r;
    y7i = x1i - x2i;
    x0r = a[6] + a[23];
    x0i = a[7] - a[22];
    x1r = wk1i * x0r + wk1r * x0i;
    x1i = wk1i * x0i - wk1r * x0r;
    x0r = a[14] + a[31];
    x0i = a[15] - a[30];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y11r = x1r + x2r;
    y11i = x1i + x2i;
    y15r = x1r - x2r;
    y15i = x1i - x2i;
    x1r = y0r + y2r;
    x1i = y0i + y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    a[0] = x1r + x2r;
    a[1] = x1i + x2i;
    a[2] = x1r - x2r;
    a[3] = x1i - x2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r - y3r;
    x2i = y1i - y3i;
    a[4] = x1r - x2i;
    a[5] = x1i + x2r;
    a[6] = x1r + x2i;
    a[7] = x1i - x2r;
    x1r = y4r - y6i;
    x1i = y4i + y6r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[8] = x1r + x2r;
    a[9] = x1i + x2i;
    a[10] = x1r - x2r;
    a[11] = x1i - x2i;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[12] = x1r - x2i;
    a[13] = x1i + x2r;
    a[14] = x1r + x2i;
    a[15] = x1i - x2r;
    x1r = y8r + y10r;
    x1i = y8i + y10i;
    x2r = y9r - y11r;
    x2i = y9i - y11i;
    a[16] = x1r + x2r;
    a[17] = x1i + x2i;
    a[18] = x1r - x2r;
    a[19] = x1i - x2i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    a[20] = x1r - x2i;
    a[21] = x1i + x2r;
    a[22] = x1r + x2i;
    a[23] = x1i - x2r;
    x1r = y12r - y14i;
    x1i = y12i + y14r;
    x0r = y13r + y15i;
    x0i = y13i - y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[24] = x1r + x2r;
    a[25] = x1i + x2i;
    a[26] = x1r - x2r;
    a[27] = x1i - x2i;
    x1r = y12r + y14i;
    x1i = y12i - y14r;
    x0r = y13r - y15i;
    x0i = y13i + y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[28] = x1r - x2i;
    a[29] = x1i + x2r;
    a[30] = x1r + x2i;
    a[31] = x1i - x2r;
}

static void cftf081(float *a, float *w)
{
    float wn4r, x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    x0r = a[0] + a[8];
    x0i = a[1] + a[9];
    x1r = a[0] - a[8];
    x1i = a[1] - a[9];
    x2r = a[4] + a[12];
    x2i = a[5] + a[13];
    x3r = a[4] - a[12];
    x3i = a[5] - a[13];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y2r = x0r - x2r;
    y2i = x0i - x2i;
    y1r = x1r - x3i;
    y1i = x1i + x3r;
    y3r = x1r + x3i;
    y3i = x1i - x3r;
    x0r = a[2] + a[10];
    x0i = a[3] + a[11];
    x1r = a[2] - a[10];
    x1i = a[3] - a[11];
    x2r = a[6] + a[14];
    x2i = a[7] + a[15];
    x3r = a[6] - a[14];
    x3i = a[7] - a[15];
    y4r = x0r + x2r;
    y4i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    x2r = x1r + x3i;
    x2i = x1i - x3r;
    y5r = wn4r * (x0r - x0i);
    y5i = wn4r * (x0r + x0i);
    y7r = wn4r * (x2r - x2i);
    y7i = wn4r * (x2r + x2i);
    a[8] = y1r + y5r;
    a[9] = y1i + y5i;
    a[10] = y1r - y5r;
    a[11] = y1i - y5i;
    a[12] = y3r - y7i;
    a[13] = y3i + y7r;
    a[14] = y3r + y7i;
    a[15] = y3i - y7r;
    a[0] = y0r + y4r;
    a[1] = y0i + y4i;
    a[2] = y0r - y4r;
    a[3] = y0i - y4i;
    a[4] = y2r - y6i;
    a[5] = y2i + y6r;
    a[6] = y2r + y6i;
    a[7] = y2i - y6r;
}

static void cftf082(float *a, float *w)
{
    float wn4r, wk1r, wk1i, x0r, x0i, x1r, x1i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    y0r = a[0] - a[9];
    y0i = a[1] + a[8];
    y1r = a[0] + a[9];
    y1i = a[1] - a[8];
    x0r = a[4] - a[13];
    x0i = a[5] + a[12];
    y2r = wn4r * (x0r - x0i);
    y2i = wn4r * (x0i + x0r);
    x0r = a[4] + a[13];
    x0i = a[5] - a[12];
    y3r = wn4r * (x0r - x0i);
    y3i = wn4r * (x0i + x0r);
    x0r = a[2] - a[11];
    x0i = a[3] + a[10];
    y4r = wk1r * x0r - wk1i * x0i;
    y4i = wk1r * x0i + wk1i * x0r;
    x0r = a[2] + a[11];
    x0i = a[3] - a[10];
    y5r = wk1i * x0r - wk1r * x0i;
    y5i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] - a[15];
    x0i = a[7] + a[14];
    y6r = wk1i * x0r - wk1r * x0i;
    y6i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] + a[15];
    x0i = a[7] - a[14];
    y7r = wk1r * x0r - wk1i * x0i;
    y7i = wk1r * x0i + wk1i * x0r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y4r + y6r;
    x1i = y4i + y6i;
    a[0] = x0r + x1r;
    a[1] = x0i + x1i;
    a[2] = x0r - x1r;
    a[3] = x0i - x1i;
    x0r = y0r - y2r;
    x0i = y0i - y2i;
    x1r = y4r - y6r;
    x1i = y4i - y6i;
    a[4] = x0r - x1i;
    a[5] = x0i + x1r;
    a[6] = x0r + x1i;
    a[7] = x0i - x1r;
    x0r = y1r - y3i;
    x0i = y1i + y3r;
    x1r = y5r - y7r;
    x1i = y5i - y7i;
    a[8] = x0r + x1r;
    a[9] = x0i + x1i;
    a[10] = x0r - x1r;
    a[11] = x0i - x1i;
    x0r = y1r + y3i;
    x0i = y1i - y3r;
    x1r = y5r + y7r;
    x1i = y5i + y7i;
    a[12] = x0r - x1i;
    a[13] = x0i + x1r;
    a[14] = x0r + x1i;
    a[15] = x0i - x1r;
}

static void cftleaf(int n, int isplt, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 512) {
        cftmdl1(128, a, &w[nw - 64]);
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
        cftmdl2(128, &a[128], &w[nw - 128]);
        cftf161(&a[128], &w[nw - 8]);
        cftf162(&a[160], &w[nw - 32]);
        cftf161(&a[192], &w[nw - 8]);
        cftf162(&a[224], &w[nw - 32]);
        cftmdl1(128, &a[256], &w[nw - 64]);
        cftf161(&a[256], &w[nw - 8]);
        cftf162(&a[288], &w[nw - 32]);
        cftf161(&a[320], &w[nw - 8]);
        cftf161(&a[352], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(128, &a[384], &w[nw - 64]);
            cftf161(&a[480], &w[nw - 8]);
        } else {
            cftmdl2(128, &a[384], &w[nw - 128]);
            cftf162(&a[480], &w[nw - 32]);
        }
        cftf161(&a[384], &w[nw - 8]);
        cftf162(&a[416], &w[nw - 32]);
        cftf161(&a[448], &w[nw - 8]);
    } else {
        cftmdl1(64, a, &w[nw - 32]);
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
        cftmdl2(64, &a[64], &w[nw - 64]);
        cftf081(&a[64], &w[nw - 8]);
        cftf082(&a[80], &w[nw - 8]);
        cftf081(&a[96], &w[nw - 8]);
        cftf082(&a[112], &w[nw - 8]);
        cftmdl1(64, &a[128], &w[nw - 32]);
        cftf081(&a[128], &w[nw - 8]);
        cftf082(&a[144], &w[nw - 8]);
        cftf081(&a[160], &w[nw - 8]);
        cftf081(&a[176], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(64, &a[192], &w[nw - 32]);
            cftf081(&a[240], &w[nw - 8]);
        } else {
            cftmdl2(64, &a[192], &w[nw - 64]);
            cftf082(&a[240], &w[nw - 8]);
        }
        cftf081(&a[192], &w[nw - 8]);
        cftf082(&a[208], &w[nw - 8]);
        cftf081(&a[224], &w[nw - 8]);
    }
}

static void cftrec4(int n, float *a, int nw, float *w)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m;
    
    m = n;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
}

static void cftfx41(int n, float *a, int nw, float *w)
{
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 128) {
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
    } else {
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
    }
}

static void cftf040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r - x3i;
    a[3] = x1i + x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftx020(float *a)
{
    float x0r, x0i;
    
    x0r = a[0] - a[2];
    x0i = a[1] - a[3];
    a[0] += a[2];
    a[1] += a[3];
    a[2] = x0r;
    a[3] = x0i;
}

#ifdef USE_CDFT_THREADS
struct cdft_arg_st {
    int n0;
    int n;
    float *a;
    int nw;
    float *w;
};
typedef struct cdft_arg_st cdft_arg_t;


static void cftrec4_th(int n, float *a, int nw, float *w)
{
    void *cftrec1_th(void *p);
    void *cftrec2_th(void *p);
    int i, idiv4, m, nthread;
    cdft_thread_t th[4];
    cdft_arg_t ag[4];
    
    nthread = 2;
    idiv4 = 0;
    m = n >> 1;
    if (n > CDFT_4THREADS_BEGIN_N) {
        nthread = 4;
        idiv4 = 1;
        m >>= 1;
    }
    for (i = 0; i < nthread; i++) {
        ag[i].n0 = n;
        ag[i].n = m;
        ag[i].a = &a[i * m];
        ag[i].nw = nw;
        ag[i].w = w;
        if (i != idiv4) {
            cdft_thread_create(&th[i], cftrec1_th, &ag[i]);
        } else {
            cdft_thread_create(&th[i], cftrec2_th, &ag[i]);
        }
    }
    for (i = 0; i < nthread; i++) {
        cdft_thread_wait(th[i]);
    }
}


static void *cftrec1_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    m = n0;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}


static void *cftrec2_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl2(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    k = 1;
    m = n0;
    while (m > 512) {
        m >>= 2;
        k <<= 2;
        cftmdl2(m, &a[n - m], &w[nw - m]);
    }
    cftleaf(m, 0, &a[n - m], nw, w);
    k >>= 1;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}
#endif /* USE_CDFT_THREADS */

static void cftfsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2(int n, int *ip, float *a);
    void bitrv216(float *a);
    void bitrv208(float *a);
    void cftf1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftf1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216(a);
        } else {
            cftf081(a, w);
            bitrv208(a);
        }
    } else if (n == 8) {
        cftf040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void bitrv2conj(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += nm;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    }
}

static void bitrv216neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i, x8r, x8i, 
        x9r, x9i, x10r, x10i, x11r, x11i, x12r, x12i, 
        x13r, x13i, x14r, x14i, x15r, x15i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x9r = a[18];
    x9i = a[19];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    x15r = a[30];
    x15i = a[31];
    a[2] = x15r;
    a[3] = x15i;
    a[4] = x7r;
    a[5] = x7i;
    a[6] = x11r;
    a[7] = x11i;
    a[8] = x3r;
    a[9] = x3i;
    a[10] = x13r;
    a[11] = x13i;
    a[12] = x5r;
    a[13] = x5i;
    a[14] = x9r;
    a[15] = x9i;
    a[16] = x1r;
    a[17] = x1i;
    a[18] = x14r;
    a[19] = x14i;
    a[20] = x6r;
    a[21] = x6i;
    a[22] = x10r;
    a[23] = x10i;
    a[24] = x2r;
    a[25] = x2i;
    a[26] = x12r;
    a[27] = x12i;
    a[28] = x4r;
    a[29] = x4i;
    a[30] = x8r;
    a[31] = x8i;
}

static void bitrv208neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    a[2] = x7r;
    a[3] = x7i;
    a[4] = x3r;
    a[5] = x3i;
    a[6] = x5r;
    a[7] = x5i;
    a[8] = x1r;
    a[9] = x1i;
    a[10] = x6r;
    a[11] = x6i;
    a[12] = x2r;
    a[13] = x2i;
    a[14] = x4r;
    a[15] = x4i;
}

static void cftb1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = -a[1] - a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = -a[1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    a[j2] = x1r + x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r - x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = -a[j + 1] - a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = -a[j + 1] + a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = -a[j + 3] - a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = -a[j + 3] + a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i - x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = -a[j0 + 1] - a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = -a[j0 + 1] + a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = -a[j0 - 1] - a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = -a[j0 - 1] + a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i - x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = -a[j0 - 1] - a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = -a[j0 - 1] + a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i - x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = -a[j0 + 1] - a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = -a[j0 + 1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = -a[j0 + 3] - a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = -a[j0 + 3] + a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i - x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftb040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r + x3i;
    a[3] = x1i - x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r - x3i;
    a[7] = x1i + x3r;
}

static void cftbsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2conj(int n, int *ip, float *a);
    void bitrv216neg(float *a);
    void bitrv208neg(float *a);
    void cftb1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftb040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftb1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2conj(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216neg(a);
        } else {
            cftf081(a, w);
            bitrv208neg(a);
        }
    } else if (n == 8) {
        cftb040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void rftfsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr - wki * xi;
        yi = wkr * xi + wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rftbsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr + wki * xi;
        yi = wkr * xi - wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rdft(int n, int isgn, float *a, int *ip, float *w)
{
    void makewt(int nw, int *ip, float *w);
    void makect(int nc, int *ip, float *c);
    void cftfsub(int n, float *a, int *ip, int nw, float *w);
    void cftbsub(int n, float *a, int *ip, int nw, float *w);
    void rftfsub(int n, float *a, int nc, float *c);
    void rftbsub(int n, float *a, int nc, float *c);
    int nw, nc;
    float xi;
    
    nw = ip[0];
    if (n > (nw << 2)) {
        nw = n >> 2;
        makewt(nw, ip, w);
    }
    nc = ip[1];
    if (n > (nc << 2)) {
        nc = n >> 2;
        makect(nc, ip, w + nw);
    }
    if (isgn >= 0) {
        if (n > 4) {
            cftfsub(n, a, ip, nw, w);
            rftfsub(n, a, nc, w + nw);
        } else if (n == 4) {
            cftfsub(n, a, ip, nw, w);
        }
        xi = a[0] - a[1];
        a[0] += a[1];
        a[1] = xi;
    } else {
        a[1] = 0.5 * (a[0] - a[1]);
        a[0] -= a[1];
        if (n > 4) {
            rftbsub(n, a, nc, w + nw);
            cftbsub(n, a, ip, nw, w);
        } else if (n == 4) {
            cftbsub(n, a, ip, nw, w);
        }
    }
}

// input array (any shape >= 1D)
// output array (shape = input.shape.replace(axis, n).insert(0,2))
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void rfft_libfft_f32(
    const float* restrict input, 
    float* restrict output, 
    int d0, int d1, int d2,
    int32_t* restrict temp_ip, float* restrict temp_w, float* restrict temp_a)
{
    void rdft(int n, int isgn, float* a, int* ip, float* w);

    int d3 = d0 * d1;
    int d_out = (d1 >> 1) + 1;

    for (int k = 0; k < d2; k++)
    {
        int dk = k * d3;
        int dm = k * 2 * d_out * d0;
        for (int i = 0; i < d0; i++)
        {                	           
            for (int j = 0; j < d1; j++)
            {
                temp_a[j] = input[dk + j * d0 + i];
            }
            rdft(d1, 1, temp_a, (int *)temp_ip, temp_w);

            for (int m = 2; m < d1; m+=2)
            {
                int index = (m * d0) + 2 * i + dm;
                output[index] = temp_a[m];
                output[index + 1] = -temp_a[m + 1];
            }
            int beta = dm + 2 * i;
            output[beta] = temp_a[0];
            output[beta + 1] = 0;
            output[beta + d3] = temp_a[1];
            output[beta + d3 + 1] = 0;
        }
    }
}

static inline float __norm_sqrt_sum_f32(const float* restrict input, int count)
{
	float sum = 0;
	for (int j = 0; j < count; j++) {
		float item = *input++;
		sum += item * item;
	}
	return sqrtf(sum);
}

static inline void norm_f32(const float* restrict input, int d1, int d2, float* restrict output)
{
	for (int k = 0; k < d2; k++) {
		*output++ = __norm_sqrt_sum_f32(input, d1);
		input += d1;
	}
}

static inline float __mel_f32(const float* restrict input, const short* restrict filter_points, int filter)
{
	short n0 = filter_points[filter];
	short n1 = filter_points[filter+1];
	short n2 = filter_points[filter+2];
	short c0 = n1 - n0;
	short c1 = n2 - n1;
	float sum = 0;
	
	for (int i = 0; i <= c0; i++) {
		float rate = i / (float)c0;
		float value = input[i + n0];
		sum += value * rate;
	}

	for (int i = 1; i <= c1; i++) {
		float rate = i / (float)c1;
		float value = input[i + n1];
		sum += value * (1.0 - rate);
	}

	return sum;
}

// input array (any shape >= 1D)
// output array (same shape as input array except with 0 replaced with num_filter)
// size = input.shape.size(0)
// slot = input.shape.slot(0)
static inline void mel_f32(const float* restrict input, const short* restrict filter_points, int size, int slot, int num_filter, float* restrict output)
{	
	for (int k = 0; k < slot; k++) {
		const float *ip = input + k * size;
		for (int i = 0; i < num_filter; i++) {
			*output++ = __mel_f32(ip, filter_points, i);
		}
	}
}

static inline void addi_f32(
	const float* restrict x,
	int count,
	float immediate,
	float* restrict output)
{
	for (int i = 0; i < count; i++) {
		output[i] = x[i] + immediate;
	}
}

static inline void ln_f32(const float* restrict x, int count, float* restrict result)
{
	for (int i = 0; i < count; i++) {
		*result++ = logf(*x++);
	}
}

static inline void clip_f32(const float* restrict input, int count, float min, float max, float* restrict output)
{	
	for (int i = 0; i < count; i++) {
		float value = input[i];
		if (value > max)
			value = max;
		if (value < min)
			value = min;

		output[i] = value;
	}
}

/**
 * Enqueue handle->input_size values from given *data pointer to internal window buffer.
 *
 * @param handle Pointer to an initialized handle.
 * @param data Data to enqueue.
 * @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_ERROR (-2) if internal buffer is out of memory.
 */
static inline int fixwin_enqueue(void* restrict handle, const void* restrict data)
{
	fixwin_t* fep = (fixwin_t*)handle;

	if (cbuffer_enqueue(&fep->data_buffer, data, fep->input_size) != 0)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

static inline void mtb_model_int8_f32(const void* handle, const float* restrict src, int src_count, float* restrict dst, int dst_count, int8_t* tmp)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;

	int in_offset = model->input_zero_point;
	float in_scale = model->input_scale;
	 
	for (int i = 0; i < src_count; i++) {
		float value = (src[i] / in_scale) + in_offset;
		if (value > 127)
			tmp[i] = 127;
		else if (value < -128)
			tmp[i] = -128;
		else
			tmp[i] = (int8_t)value;
	}

	mtb_ml_model_run(model, tmp);
	
	int out_offset = model->output_zero_point;
	float out_scale = model->output_scale;
	int8_t* out_data = model->output;
	for (int i = 0; i < dst_count; i++) {
		dst[i] = (out_data[i] - out_offset) * out_scale;
	}
}

static inline void mtb_model_free(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_deinit(model);
}

/**
* Initializes a fixwin sampler handle.
*
* @param handle Pointer to a preallocated memory area of fixwin_handle_size() bytes to initialize.
*
* @param input_size Number of bytes to enqueue.
* @param count Number of items (of size input_size) in each window
*/
static inline void fixwin_init(void* restrict handle, int input_size, int count)
{
	fixwin_t* fep = (fixwin_t*)handle;
	fep->input_size = input_size;

	char* mem = ((char*)handle) + sizeof(fixwin_t);

	int data_buffer = input_size * count;
	
	cbuffer_init(&fep->data_buffer, mem, data_buffer);
}

int mtb_init(const void *handle, uint8_t* model_bin, unsigned int model_size, uint8_t* arena_buffer, int arena_size) {
	
	mtb_ml_model_t** model_obj = (mtb_ml_model_t**)handle;
	
	mtb_ml_model_bin_t model = { "model", model_bin, model_size, arena_size };
	mtb_ml_model_buffer_t buffer = { arena_buffer, arena_size };
	if (mtb_ml_model_init(&model, &buffer, model_obj) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

	return 0;
}

#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) return __ret; } while(0)
#define __RETURN_ALWAYS(_exp) return (_exp)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) return __ret; }
#define __RETURN_ERROR_BREAK_EMPTY_END(_exp) {  int __ret = (_exp); if(__ret == -1 || __ret == -3) break; if(__ret < 0) return __ret; }
#define __RETURN_ERROR_CANCEL_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) return 0; if(__ret < 0) return __ret; }
#define __BREAK_ERROR(_exp) {  int __ret = (_exp); if(__ret < 0) break; }

/*
* Try read data from model.
* 
*  @param data_out Output features. Output float[3].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_dequeue(float *restrict data_out) {    
    while(1) {
        __RETURN_ERROR_BREAK_EMPTY(fixwin_dequeue(_K2, _K1, 512, 160));
        hammingmul_f32(_K1, _K11, 1, 512, 1, _K15);
        rfft_libfft_f32(_K15, _K16, 1, 512, 1, _K18, _K19, _K20);
        norm_f32(_K16, 2, 257, _K22);
        mel_f32(_K22, _K23, 257, 1, 40, _K27);
        addi_f32(_K27, 40, 1, _K28);
        ln_f32(_K28, 40, _K29);
        clip_f32(_K29, 40, 0, 4, _K3);
        __RETURN_ERROR_BREAK_EMPTY(fixwin_enqueue(_K5, _K3));
    }
    __RETURN_ERROR(fixwin_dequeue(_K5, _K4, 200, 10));
    mtb_model_int8_f32(_K10, _K4, 8000, data_out, 3, _K9);
    return 0;
}

/*
* Try write data to model.
* 
*  @param data_in Input features. Input float[1].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_enqueue(const float *restrict data_in) {    
    __RETURN_ERROR(fixwin_enqueue(_K2, data_in));
    return 0;
}

/*
* Closes and flushes streams, free any heap allocated memory.
* 
*/
void IMAI_finalize(void) {    
    mtb_model_free(_K10);
}

/*
* Initializes buffers to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_init(void) {    
    fixwin_init(_K2, 4, 512);
    fixwin_init(_K5, 160, 200);
    __RETURN_ERROR(mtb_init(_K10, _K7, 28192, _K6, 22528));
    return 0;
}

#ifdef IMAI_REFLECTION

static IMAI_api_def _IMAI_api_def = {
    api_ver: 1,
    id: {0xfd, 0xc9, 0xdc, 0xa6, 0x6e, 0x11, 0xfa, 0x46, 0x85, 0x61, 0xe6, 0x66, 0x62, 0x64, 0x72, 0x23},
    api_type: IMAI_API_TYPE_QUEUE,
    prefix: "IMAI_",
    buffer_mem: {
        size: 40000,
        peak_usage: 40000,
    },
    static_mem: {
        size: 58128,
        peak_usage: 58128,
    },
    readonly_mem: {
        size: 30324,
        peak_usage: 30324,
    },
    func_count: 4,
    func_list: (IMAI_func_def[]) {
        {
            name: "IMAI_dequeue",
            description: "Try read data from model.",
            fn_ptr: IMAI_dequeue,
            attrib: 3,
            param_count: 1,
            param_list: (IMAI_param_def[]) {
                {
                    name: "data_out",
                    attrib: IMAI_PARAM_OUTPUT,
                    rank: 1,
                    shape: (IMAI_shape_dim[]) {
                        {
                            name: "Labels",
                            size: 3,
                            labels: (label_text_t[]) { "unlabelled","background","wake" },
                        },
                    },
                    count: 3,
                    type_id: IMAGINET_TYPES_FLOAT32,
                    frequency: 10,
                    shift: 3,
                    scale: 1,
                    offset: 0,
                },
            },
        },
        {
            name: "IMAI_enqueue",
            description: "Try write data to model.",
            fn_ptr: IMAI_enqueue,
            attrib: 3,
            param_count: 1,
            param_list: (IMAI_param_def[]) {
                {
                    name: "data_in",
                    attrib: IMAI_PARAM_INPUT,
                    rank: 1,
                    shape: (IMAI_shape_dim[]) {
                        {
                            name: "",
                            size: 1,
                        },
                    },
                    count: 1,
                    type_id: IMAGINET_TYPES_FLOAT32,
                    frequency: 16000,
                    shift: 0,
                    scale: 1,
                    offset: 0,
                },
            },
        },
        {
            name: "IMAI_finalize",
            description: "Closes and flushes streams, free any heap allocated memory.",
            fn_ptr: IMAI_finalize,
            attrib: 10,
            param_count: 0,
            param_list: (IMAI_param_def[]) {
            },
        },
        {
            name: "IMAI_init",
            description: "Initializes buffers to initial state.",
            fn_ptr: IMAI_init,
            attrib: 7,
            param_count: 0,
            param_list: (IMAI_param_def[]) {
            },
        },
    },
};

IMAI_api_def *IMAI_api(void) {
    return &_IMAI_api_def;
}

#endif /* IMAI_REFLECTION */

