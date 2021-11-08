#include <stdio.h>
#include <time.h>
#include "tree.h"

int main() {
    srand((unsigned )time(NULL));
    FILE * clear=fopen("l7_output.txt","w");
    if (clear==NULL){
        perror("l7_output.txt");
        exit(-1);
    }
    fclose(clear);
    Node * root=Node_create();
    FILE * fid=fopen("l7_input.txt","r");
    if (fid==NULL){
        perror("l7_input.txt");
        exit(-1);
    }
    char* buf=malloc(sizeof(char)*LINE_MAX);
    if(fgets(buf,sizeof(char)*LINE_MAX,fid)){

    };
    char** end_ptr=NULL;
    int k=(int)strtol(buf,end_ptr,10);
    free(buf);
    world_cup_tree_init(root,4,fid);
    //post-order DFS
    sim(root,k);
    fclose(fid);
    print_champion(root);
    tree_destroy(root);
    return 0;
}
