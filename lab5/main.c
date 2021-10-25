#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calculator.h"
int main(int argc,char** argv) {
    int mode=INTERACT;

    cli_parse(argc,argv,&mode);
    int operand_a,operand_b;
    char operator;
    double result;
    printf("Input your calculation:\n");
    scanf("%d%c%d",&operand_a,&operator,&operand_b);
    getchar();
    result=evaluate(operand_a,operator,operand_b);
    printf("The result of your input calculation:%d %c %d is %lf.\n",operand_a,operator,operand_b,result);
    return 0;
}