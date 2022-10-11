// License       : License.txt
// Specifications: Spec-MAX6613MXK_MAX6613MXKV.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MAX6613.h
// Reason for change: 01.00.00 : 10/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MAX6613_H__
#define __MAX6613_H__

#include "user_define.h"

// Components number
#define iMAX6613                113U                    // Maxim Integrated MAX6613MXK,MAX6613MXK/V

// MAX6613MXK,MAX6613MXK/V System Parts definitions
#define iMAX6613_xoff           1.8455F                 // X offset [V]
#define iMAX6613_yoff           0.0F                    // Y offset [degree celsius]
#define iMAX6613_gain           -0.01123F               // Gain [V/degree celsius]
#define iMAX6613_max            130.0F                  // Temperature Max [degree celsius]
#define iMAX6613_min            -55.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_MAX6613;

#endif /*__MAX6613_H__*/
