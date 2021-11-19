#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000
#define SMALLER_SIZE 200
#define MAX 2000

int main () {
    /*FILE * fid=fopen("input.txt","w");
    fprintf(fid,"%d\n",SIZE);
    int n=0;
    while (n<=SIZE-1){
        fprintf(fid,"%d\n",2*n);
        n++;

    }
    fclose(fid);*/
#ifdef L_S
    int i, n, k=0;
    size_t arr_len=0;
    int* data;

    FILE * fid=fopen("input.txt","r");
    if (fid==NULL){
        perror("input.txt");
        exit(-1);
    }
    char* buf=malloc(sizeof(char)*MAX);
    char** endptr=NULL;
    if (fgets(buf,MAX,fid)){
        arr_len=(size_t)strtol(buf,endptr,10);
        data=(int*)malloc(sizeof(int)*(arr_len+1));
    }
    i=0;
    while (fgets(buf,MAX,fid)!=NULL){
        *(data+i)=(int)strtol(buf,endptr,10);
        i++;
    }
    fclose(fid);
    fprintf(stdout,"Input the number you want to find!\n");
    fgets(buf,MAX,stdin);
    n=(int)strtol(buf,endptr,10);

    for(size_t j=0; j<arr_len; j++) {
        if(data[j]==n) {
            printf("%d found at position %zu\n",n,j);
            free(buf);
            free(data);
            exit(0);
            k++;
            }
        }
    if(k==0) printf("%d not found\n",n);
    free(buf);
    free(data);
#endif
#ifdef B_S
    int i, n, low=0, high=SIZE-1, mid;
    int data[SIZE];
    srand((unsigned int)time(NULL));
    for(i=0;i<SIZE;i++) data[i]=2*i;
    char* buf=malloc(sizeof(char)*MAX);
    char** endptr=NULL;
    fprintf(stdout,"Input the number you want to find!\n");
    fgets(buf,MAX,stdin);
    n=(int)strtol(buf,endptr,10);
    while(high >= low) {
        mid=(low + high)/2;
        if(n < data[mid]) high = mid - 1;
        else if(n> data[mid]) low = mid + 1;
        else {printf("%d found at position %d\n",n,mid);
            free(buf);
            exit(0);}
        }
    printf("%d not found\n",n);
    free(buf);
#endif
#ifdef S_S
    int data[SMALLER_SIZE];
    srand((unsigned)time(NULL));
    for(int i=0; i<SMALLER_SIZE; i++) data[i]=rand()%MAX;
    for(int i=0; i<SMALLER_SIZE; i++) {
        int t, min = i;
        for(int j=i; j<SMALLER_SIZE; j++) if(data[min]>data[j]) min = j;
        t = data[i];
        data[i] = data[min];
        data[min] = t;
        }
    printf("Sorted array: ");
    for(int i=0; i<SMALLER_SIZE; i++) printf("%d ",data[i]);
    printf("\n");
#endif
    return 0;
}
