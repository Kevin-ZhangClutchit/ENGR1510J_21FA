//
// Created by LENOVO on 2021/10/25.
//


#include "calculator.h"

void cli_parse(int argc,char** argv,int* mode,char* str_evl){
    for (int i = 1; i <argc ; i++) {
        if (!strncmp(argv[i], "-h", 2)||!strcmp(argv[i],"--help")) {
            printf("usage: ./calculator [option | file | -]\n");
            printf("\n");
            printf("Options:\n");
            printf("-h : print this help message and exit (also --help)\n");
            printf("-c str : evaluate str and print the result to stdout\n");
            printf("\n");
            printf("Modes:\n");
            printf("- : read expressions from stdin and print results interactively (default)\n");
            printf("file : read expressions from file and print all results\n");
            free(str_evl);
            exit(0);
        }
        if (!strncmp(argv[i],"-",1)){
            *mode=INTERACT;
            return;
        }
        if (!strcmp(argv[i],"file")){
            *mode=FILE_T;
            return;
        }
        if (!strcmp(argv[i],"-c")){
            *mode=STRING_T;
            i++;
            if (i>=argc){
                printf("Missing argument behind -c!\n");
                free(str_evl);
                exit(8);
            }
            strcpy(str_evl,argv[i]);
            return;
        }else{
            printf("Unknown syntax at location %d\n",i);
            free(str_evl);
            exit(6);
        }

    }
}
double evaluate(int operand1, char operator, int operand2){
    double result=0;
    switch (operator) {
        case '+': result=(double )(operand1+operand2);break;
        case '-': result=(double )(operand1-operand2);break;
        case '*': result=(double )(operand1*operand2);break;
        case '/': result=(double ) operand1 / operand2;break;
        case '^': result=pow((double )operand1,(double )operand2);break;
        case 'l': result=log((double )operand2)/log((double )operand1);break;
        case 'm': result=(double )(operand1%operand2);break;
        default: printf("Invalid Operator!\n");fflush(stdout);exit(-1);
    }
    return result;
}