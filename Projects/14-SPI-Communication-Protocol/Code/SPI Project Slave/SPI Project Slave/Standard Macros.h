#ifndef STADARD_MACROS
#define STADARD_MACROS

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=~(1<<bit)
#define TOGL_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define ROR(reg,num) reg=(reg>>num)|(reg<<(REGISTER_SIZE-num))
#define ROL(reg,num) reg=(reg<<num)|(reg>>(REGISTER_SIZE-num))

#endif // STADARD_MACROS
