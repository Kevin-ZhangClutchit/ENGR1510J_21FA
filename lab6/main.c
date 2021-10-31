#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "sims.h"
int main() {
    srand((unsigned )time(NULL));
    int k=1;
    Country res_arr[31];
    memset(res_arr,0,31*sizeof(struct Country));
    //country_init_l6(res_arr);---->lazy & stupid init
    k=file_read(res_arr);//---->init from a file l6_input.txt
    FILE * clr=fopen("l6_output.txt","w");//clean the content of the file
    fclose(clr);
    //lazy way
    /*
    for (int i = 15; i < 30; i+=2) {
        res_arr[(i-1)/2]=get_winner(res_arr[i],res_arr[i+1],k);
    }
    for (int i = 7; i < 14; i+=2) {
        res_arr[(i-1)/2]=get_winner(res_arr[i],res_arr[i+1],k);
    }
    for (int i = 3; i < 6; i+=2) {
        res_arr[(i-1)/2]=get_winner(res_arr[i],res_arr[i+1],k);
    }
    for (int i = 1; i < 2; ++i) {
        res_arr[(i-1)/2]=get_winner(res_arr[i],res_arr[i+1],k);
    }*/
    //another lazy way
    int level=4;
    while (level>0){
        for (int i = (int)(pow(2,(double )level)-1); i < (int)(pow(2,(double )(level+1))-2); i+=2) {
            res_arr[(i-1)/2]=get_winner(res_arr[i],res_arr[i+1],k);
        }
        level--;
    }
    print_result(res_arr);
    return 0;
}
