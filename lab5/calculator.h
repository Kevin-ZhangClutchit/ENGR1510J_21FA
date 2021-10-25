//
// Created by LENOVO on 2021/10/25.
//

#ifndef L5_CODE_CALCULATOR_H
#define L5_CODE_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INTERACT 0
#define FILE 1
void cli_parse(int argc,char** argv,int* mode);
double evaluate(int operand1, char operator, int operand2);
#endif //L5_CODE_CALCULATOR_H
