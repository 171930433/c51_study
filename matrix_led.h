#ifndef MATRIX_LED_H
#define MATRIX_LED_H

void MatrixLedInit();

void LightMatrixLedColumn(unsigned char col, unsigned char index);

// demo 按列显示led,需要扫描执行
void MatrixLedDemo();

#endif