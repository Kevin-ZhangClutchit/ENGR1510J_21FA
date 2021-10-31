//
// Created by LENOVO on 2021/10/31.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sims.h"
struct Country get_winner(const struct Country a,const struct Country b, int k){
    double rate=((double)(a.rank+k)/(double)(a.rank+b.rank+2*k));
    double rand_res=(double )(rand()%100);
    struct Country winner=(rand_res<(rate*100))?b:a;
    FILE* fid=fopen("l6_output.txt","a");
    if (winner.rank==a.rank){
        fprintf(fid,"%s WIN %s\n",a.name,b.name);
    } else{
        fprintf(fid,"%s LOSE %s\n",a.name,b.name);
    }
    fclose(fid);
    return winner;
}

void country_init_l6(struct Country* count_arr){
    (count_arr+15)->rank=14;
    strcpy((count_arr+15)->name,"URU");

    (count_arr+16)->rank=4;
    strcpy((count_arr+16)->name,"POR");

    (count_arr+17)->rank=7;
    strcpy((count_arr+17)->name,"FRA");

    (count_arr+18)->rank=20;
    strcpy((count_arr+18)->name,"CRO");

    (count_arr+19)->rank=2;
    strcpy((count_arr+19)->name,"BRA");

    (count_arr+20)->rank=24;
    strcpy((count_arr+20)->name,"SWE");

    (count_arr+21)->rank=3;
    strcpy((count_arr+21)->name,"BEL");

    (count_arr+22)->rank=8;
    strcpy((count_arr+22)->name,"POL");

    (count_arr+23)->rank=10;
    strcpy((count_arr+23)->name,"ESP");

    (count_arr+24)->rank=70;
    strcpy((count_arr+24)->name,"RUS");

    (count_arr+25)->rank=5;
    strcpy((count_arr+25)->name,"ARG");

    (count_arr+26)->rank=12;
    strcpy((count_arr+26)->name,"DEN");

    (count_arr+27)->rank=1;
    strcpy((count_arr+27)->name,"GER");

    (count_arr+28)->rank=6;
    strcpy((count_arr+28)->name,"SUI");

    (count_arr+29)->rank=16;
    strcpy((count_arr+29)->name,"COL");

    (count_arr+30)->rank=12;
    strcpy((count_arr+30)->name,"ENG");
}

int file_read(struct Country* count_arr){
    FILE * fid=fopen("l6_input.txt","r");
    if (fid==NULL){
        perror("fopen!\n");
        exit(-1);
    }
    char* buf=malloc(sizeof(char)*line_max);
    fgets(buf,sizeof(char)*1024,fid);
    char** end_ptr=NULL;
    int k=strtod(buf,end_ptr);
    int i=0;
    while (fgets(buf,sizeof(char)*1024,fid)!=NULL){
        char* head_token=strtok(buf," ");
        char* end_token=strtok(NULL,"\n");
        strcpy((count_arr+15+i)->name,head_token);
        (count_arr+15+i)->rank=(unsigned )strtod(end_token,end_ptr);
        i++;
    }
    fclose(fid);
    return k;
}
void print_result(struct Country* res_arr){
    int level=4;
    while (level>=0){
        char* buf=malloc(sizeof(char)*line_max);
        memset(buf,0,sizeof(char)*line_max);
        if (level==4) {
            strcpy(buf, "Elimination Round: ");
        }else if (level==3){
            strcpy(buf,"Quarter Finals: ");
        }else if (level==2){
            strcpy(buf,"Semi Finals: ");
        } else if (level==1){
            strcpy(buf,"Finals: ");
        } else{
            strcpy(buf,"Winner: ");
        }
        for (int i = (int)(pow(2,(double )level)-1); i < (int)(pow(2,(double )(level+1))-1); i++) {
            strcat(buf,res_arr[i].name);
            strcat(buf," ");
        }
        strcat(buf,"\n");
        printf("%s",buf);
        fflush(stdout);
        free(buf);
        level--;
    }
}