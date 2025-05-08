# Model performance and validation report
**Source model:** conv1dlstm-medium-accuracy-0.h5  
**Generated:** 2025-05-07 20:46:07

### Memory usage
| Model | Model memory | Scratch memory |
| :--- | :--- | :--- |
| float | 61,008 | 72,704 |
| int8x8 | 28,192 | 22,528 |

### Latency
| Layer | Cycles |
| :--- | :--- |
| CONV_2D | 465,514 |
| CONV_2D | 389,845 |
| CONV_2D | 602,215 |
| MAX_POOL_2D | 38,268 |
| CONV_2D | 396,297 |
| CONV_2D | 490,683 |
| MAX_POOL_2D | 23,382 |
| MEAN | 56,238 |
| FULLY_CONNECTED | 1,623 |
| SOFTMAX | 0 |
| **TOTAL** | **2,464,065** |

### Validation
**Validation data source:** None
