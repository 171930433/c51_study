#ifndef AT24C02_H
#define AT24C02_H

void AT24C02_WriteByte(unsigned char WordAddress, Data);
unsigned char AT24C02_ReadByte(unsigned char WordAddress);

#endif