/*
 * LIS3MDLTR.h
 *
 *  Created on: Jan 15, 2024
 *      Author: Aya Hassan
 */

#ifndef LIS3MDLTR_DEVICEDRIVER_LIS3MDLTR_H_
#define LIS3MDLTR_DEVICEDRIVER_LIS3MDLTR_H_

#include "LIS3MDLTR_internalDefines.h"

typedef enum
{
	NO_ERROR=0,

	ERROR=1

}error_status;

typedef enum {

	RATE_0_625 =0 ,

	RATE_1_25 ,

	RATE_2_5,

	RATE_5,

	RATE_10,

	RATE_20,

	RATE_40,

	RATE_80,

	RATE_155,

	RATE_300,

	RATE_560,

	RATE_1000


}data_rate;

typedef enum {
 OM_LP =0,
OM_MP ,
 OM_HP ,
 OM_UHP

}op_mode;
typedef enum
{
  DISABLED=0,

  ENABLED=1

}pin_status;

/** this struct contains essentials config needed to use the sensor **/
typedef struct
{

/** this struct is to hold essential data loke operative mode and scale config**/

}LIS3MDLTR_Configuration;



/** LIS3MDLTR functions **/

/** function for init the sensor to be ready for usage **/

error_status LIS3MDLTR_Init(LIS3MDLTR_Configuration dev);

error_status LIS3MDLTR_ReadDataX(int16_t *data);

error_status LIS3MDLTR_ReadDataY(int16_t *data);

error_status LIS3MDLTR_ReadDataZ(int16_t *data);

error_status LIS3MDLTR_GetFullScaleConfig(uint8_t * data);

error_status LIS3MDLTR_GetDataRate(uint8_t * data);

error_status LIS3MDLTR_SetDatRate(data_rate data);

void LIS3MDLTR_DisableInterruptPin(void);

void LIS3MDLTR_EnableInterruptPin(void);



#endif /* LIS3MDLTR_DEVICEDRIVER_LIS3MDLTR_H_ */
