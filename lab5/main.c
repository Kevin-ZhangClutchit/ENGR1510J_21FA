#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calculator.h"
int main(int argc,char** argv) {
    if (argc==1){
        printf("Missing arguments! Please type ./main --help for help\n");
        exit(0);
    }
    int mode=INTERACT;
    char* str_evl=malloc(sizeof(char)*LINE_MAX);
    cli_parse(argc,argv,&mode,str_evl);
    int operand_a,operand_b;
    char operator;
    double result;

    if (mode==INTERACT){
        printf("Input your calculation:\n");
        scanf("%d%c%d",&operand_a,&operator,&operand_b);
        getchar();
        result=evaluate(operand_a,operator,operand_b);
        printf("The result of your input calculation: %d %c %d is %lf.\n",operand_a,operator,operand_b,result);
    } else if (mode==STRING_T){
        sscanf(str_evl,"%d%c%d",&operand_a,&operator,&operand_b);
        result=evaluate(operand_a,operator,operand_b);
        printf("The result of your input calculation: %d %c %d is %lf.\n",operand_a,operator,operand_b,result);
    }else{
        char* file_name=malloc(sizeof(char)*LINE_MAX);
        printf("Input the file name MAX SIZE 1024:\n");
        fgets(file_name,LINE_MAX,stdin);
        strtok(file_name,"\n");
        //printf("%s\n",file_name);
        FILE * fid=fopen(file_name,"r");
        if (fid==NULL){
            if (errno==ENOENT){
                perror(file_name);
                fflush(stdout);
            }
            printf("Fail to open file %s\n",file_name);


            free(file_name);
            free(str_evl);
            exit(-2);
        }
            char* file_line=malloc(sizeof(char)*LINE_MAX);
            while (fgets(file_line,LINE_MAX,fid)){
                strtok(file_line,"\r\n");

                sscanf(file_line,"%d%c%d",&operand_a,&operator,&operand_b);
                result=evaluate(operand_a,operator,operand_b);
                printf("The result of your input calculation: %d %c %d is %lf.\n",operand_a,operator,operand_b,result);
            }
            fclose(fid);
            free(file_line);


        free(file_name);
    }
    free(str_evl);

    return 0;
}