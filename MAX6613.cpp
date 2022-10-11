// License       : License.txt
// Specifications: Spec-MAX6613MXK_MAX6613MXKV.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MAX6613.cpp
// Reason for change: 01.00.00 : 10/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MAX6613.h"

#if     iMAX6613_ma == iSMA                             // Simple moving average filter
static float32 MAX6613_sma_buf[iMAX6613_SMA_num];
static sma_f32_t MAX6613_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMAX6613_SMA_num ,                              // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MAX6613_sma_buf[0]                             // buffer
};

#elif   iMAX6613_ma == iEMA                             // Exponential moving average filter
static ema_f32_t MAX6613_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMAX6613_EMA_K                                  // Exponential smoothing factor
};

#elif   iMAX6613_ma == iWMA                             // Weighted moving average filter
static float32 MAX6613_wma_buf[iMAX6613_WMA_num];
static wma_f32_t MAX6613_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMAX6613_WMA_num ,                              // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMAX6613_WMA_num * (iMAX6613_WMA_num + 1)/2 ,   // kn sum
        &MAX6613_wma_buf[0]                             // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MAX6613 =
{
        iMAX6613                ,
        iMAX6613_pin            ,
        iMAX6613_xoff           ,
        iMAX6613_yoff           ,
        iMAX6613_gain           ,
        iMAX6613_max            ,
        iMAX6613_min            ,
        iMAX6613_ma             ,
        
#if     iMAX6613_ma == iSMA                             // Simple moving average filter
        &MAX6613_Phy_SMA        ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMAX6613_ma == iEMA                             // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MAX6613_Phy_EMA        ,
        (wma_f32_t*)iDummy_adr
#elif   iMAX6613_ma == iWMA                             // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MAX6613_Phy_WMA
#else                                                           // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
