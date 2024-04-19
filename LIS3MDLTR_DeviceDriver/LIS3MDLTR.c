/*
 * LIS3MDLTR.c
 *
 *  Created on: Jan 15, 2024
 *      Author: dell
 */

#include "../I2C_Driver/i2c.h"
#include "LIS3MDLTR.h"



/**** this function will set init config passed by user like operative mode
 *
 * and data rate selection
 */


error_status LIS3MDLTR_Init(LIS3MDLTR_Configuration dev)
{


	return NO_ERROR ;
}
/***
 *
 * @param data
 * @return
 *
 * config scales possible values
 *  0 --- > +- 4 gauss
 *  1 --->  +- 8 gauss
 *  2 --->  +- 12 gauss
 *  3 --->  +- 16 gauss
 */

error_status LIS3MDLTR_GetFullScaleConfig(uint8_t * data)
{
	error_status status =NO_ERROR;
	uint8_t register_data;

	if(data!=NULL){

		if(i2c_read(LIS3MDLTR_ADDRESS_SA1_LOW,LIS3MDLTR_CTRL_REG2 , 1,&register_data)==STATUS_OK)
		{
			*data = (register_data >> 5) & 0x3;
		}

		else
		{
			return ERROR;
		}


	}

	else
	{
		status =ERROR;
	}

	return status;
}



/********/

error_status LIS3MDLTR_SetDatRate( data_rate data)
{
	error_status status =NO_ERROR;
	uint8_t register_data=0;

	if(i2c_read(LIS3MDLTR_ADDRESS_SA1_LOW, LIS3MDLTR_CTRL_REG1, 1, &register_data)==STATUS_OK)
	{
		return ERROR;

	}
	if(data<RATE_80)
	{
		register_data&= ~(1 << 1);   // clear ODR bit

		register_data|=(data<<2);        // set output data rate

	}

	else if(data>RATE_80&& data<RATE_1000)
	{
		register_data|= (1 << 1);   // set ODR bit

		register_data|=((data-8)<<5); //set op mode
	}

	/** set the register data  **/


	i2c_write(LIS3MDLTR_ADDRESS_SA1_LOW,LIS3MDLTR_CTRL_REG1,1,&register_data);






	return status;}


/**********
 *
 *
 * @param data
 * @return
 *
 * odr data meaning
 *
 * 0 --> 0.625 HZ
 * 1 ---> 1.25 HZ
 * 2--->   2.5 HZ
 * 3 --->  5 HZ
 * 4 ---->  10 HZ
 * 5 --->  20 HZ
 * 6 --->  40 HZ
 * 7 --->  80HZ
 * 8 ---> 155hz
 * 9 ---> 300hz
 * 10 --->500hz
 * 11 --->1000hz
 */

error_status LIS3MDLTR_GetDataRate(uint8_t * data){

	error_status status =NO_ERROR;
	uint8_t reg_data=0;

	if(data==NULL){

		return ERROR ;

	}

		if(i2c_read(LIS3MDLTR_ADDRESS_SA1_LOW,LIS3MDLTR_CTRL_REG1,1,&reg_data)==STATUS_ERROR)
		{
            return ERROR;

		}

// get the op data
		uint8_t op_data=(reg_data>>5)&0x03;

//check on fast ODR

		if(reg_data&0x02)
		{
			*data=op_data+8 ;    // adding 8 when fast odr is enabled
		}

		else
		{
			*data=(reg_data>>2)&0x07;
		}



	return status;

}
/*******
 * axis_num =0 for x_axis
 * 1 for y_axis
 *  2 for z_axis
 */
error_status LIS3MDLTR_ReadDataAxis(int16_t  *data,uint8_t axis_num)
{
	error_status status =NO_ERROR;
    uint8_t base_addr=LIS3MDLTR_DATA_FIELDX_LOW+2*axis_num;
    uint8_t lower_data ,higher_data;
	if(data==NULL){

		return ERROR ;
	}

   if(i2c_read(LIS3MDLTR_ADDRESS_SA1_LOW,base_addr,1,&lower_data)==STATUS_ERROR)

   {
	   return ERROR ;
   }
   if(i2c_read(LIS3MDLTR_ADDRESS_SA1_LOW,base_addr+1,1,&higher_data)==STATUS_ERROR)

     {
  	   return ERROR ;
     }

   *data=(lower_data)|(higher_data<<8);


		return status;

}


/*******
 *
 *
 */


void LIS3MDLTR_DisableInterruptPin(void )
{
	uint8_t reg_data=0;


	/** get the register data  **/
	i2c_read(LIS3MDLTR_ADDRESS_SA1_LOW,LIS3MDLTR_INTERRUPT_CONFIG_REG,1,&reg_data);
	/** perserve the other bits **/
	reg_data&=~(0x01);

	/** set the odr bits in the register **/
	i2c_write(LIS3MDLTR_ADDRESS_SA1_LOW,LIS3MDLTR_INTERRUPT_CONFIG_REG,1,&reg_data);

}

/********************/

void LIS3MDLTR_EnableInterruptPin(void )
{
	uint8_t reg_data=0;


	/** get the register data  **/
	i2c_read(LIS3MDLTR_ADDRESS_SA1_LOW,LIS3MDLTR_INTERRUPT_CONFIG_REG,1,&reg_data);
	/** perserve the other bits **/
	reg_data|=0x01;

	/** set the odr bits in the register **/
	i2c_write(LIS3MDLTR_ADDRESS_SA1_LOW,LIS3MDLTR_INTERRUPT_CONFIG_REG,1,&reg_data);

}

