/*
 * I2C.h
 *
 * Created: 5/23/2026 2:32:54 PM
 *  Author: Cascoo
 */ 


#ifndef I2C_H_
#define I2C_H_


void I2C_master_init(unsigned long SCL_clock);
void OWN_Address_Sett(unsigned char OWN_Address);
void Start_Con(void);
void Repeated_Start_Con(void);
void STOP_Con(void);
void I2C_Transmit_Slave_AddressW(unsigned char AddressW);
void I2C_Master_Transmit_Data(unsigned char data);
void I2C_Transmit_Slave_AddressR(unsigned char AddressR);
unsigned char I2C_Master_Receive_Data(void);
void I2C_Slave_Receive_owm_AddressW(void);
unsigned char I2C_Slave_Receive_Data(void);
void I2C_Slave_Receive_own_AddressR(void);
void I2C_Slave_Transmit_Data(unsigned char data);


void START_ERROR();
void WRITE_ADDRESS_ERROR();
void DATA_Transmit_ERROR();
void DATA_RECEIVE_ERROR();




#endif /* I2C_H_ */