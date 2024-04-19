/*
 * LIS3MDLTR_internalDefines.h
 *
 *  Created on: Jan 15, 2024
 *      Author: dell
 */
#ifndef LIS3MDLTR_DEVICEDRIVER_LIS3MDLTR_INTERNALDEFINES_H_
#define LIS3MDLTR_DEVICEDRIVER_LIS3MDLTR_INTERNALDEFINES_H_


#include <stdint.h>




/** general typess used **/
#define NULL 0
/*
typedef unsigned char        uint8_t ;

typedef unsigned short int   uint16_t ;
typedef signed short int     sint16_t ;
*/

/** if the SA1 pin connected to ground then use the LOW addresses
 *
 * if connected to Volt supplier use the high addresse for read/write via I2C
 */

#define LIS3MDLTR_ADDRESS_SA1_LOW        0x38




/** maximoum output dat rate according to data sheet **/

#define MAX_DATA_RATE                         0x07


/*** device registers **/

#define LIS3MDLTR_CTRL_REG1                   0x20

#define LIS3MDLTR_CTRL_REG2                   0x21

#define LIS3MDLTR_DATA_FIELDX_LOW             0x28

#define LIS3MDLTR_DATA_FIELDX_HIGH            0x29

#define LIS3MDLTR_DATA_FIELDY_LOW             0x2A

#define LIS3MDLTR_DATA_FIELDY_HIGH            0x2B

#define LIS3MDLTR_DATA_FIELDZ_LOW             0x2C

#define LIS3MDLTR_DATA_FIELDZ_HIGH            0x2D

#define LIS3MDLTR_INTERRUPT_CONFIG_REG        0x30


/** sensitivity of scale variable **/
//int16_t SensOfScale = 6842 ;

#endif /* LIS3MDLTR_DEVICEDRIVER_LIS3MDLTR_INTERNALDEFINES_H_ */
