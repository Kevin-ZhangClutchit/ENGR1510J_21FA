//
// Created by LENOVO on 2021/10/25.
//

#ifndef L5_CODE_CALCULATOR_H
#define L5_CODE_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#define INTERACT 0
#define FILE_T 1
#define STRING_T 2
#define LINE_MAX 1024
void cli_parse(int argc,char** argv,int* mode,char* str_evl);
double evaluate(int operand1, char operator, int operand2);
#endif //L5_CODE_CALCULATOR_H
