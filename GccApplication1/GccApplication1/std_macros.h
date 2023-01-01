/*
 * std_macros.h
 *
 * Created: 7/22/2022 3:34:30 PM
 *  Author: happy
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)  reg^=(1<<bit)
#define READ_BIT(reg,bit)  ((reg&(1<<bit))>>bit)
#define ROR(reg,number_of_shift)  reg=(reg>>number_of_shift)|(reg<<(REGISTER_SIZE-number_of_shift)) 
#define ROL(reg,number_of_shift)  reg=(reg<<number_of_shift)|(reg>>(REGISTER_SIZE-number_of_shift))


#endif /* STD_MACROS_H_ */