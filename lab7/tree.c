//
// Created by LENOVO on 2021/11/5.
//

#include "tree.h"

struct Country_t{
    char name[4];
    unsigned int rank;
};

struct Node_t{
Country* country;
Node* left;
Node* right;
};

Node * Node_create(){
    Node * new_node=malloc(sizeof(Node));
    new_node->country=malloc(sizeof(Country));
    new_node->country->rank=NON;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
Node * Node_create_par(FILE * fid){
    Node * new_node=malloc(sizeof(Node));
    new_node->country=malloc(sizeof(Country));

    char* buf=malloc(sizeof(char)*LINE_MAX);
    char** end_ptr=NULL;
    if (fgets(buf,sizeof(char)*LINE_MAX,fid)!=NULL){
        char* head_token=strtok(buf," ");
        char* end_token=strtok(NULL,"\n");
        strcpy(new_node->country->name,head_token);
        new_node->country->rank=(unsigned )strtod(end_token,end_ptr);
    }
    free(buf);
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}


void world_cup_tree_init(Node* root,size_t level,FILE * fid){
    if ((root->left!=NULL&&root->right!=NULL)||level==0){
        return;
    } else if (level==1){
        root->left=Node_create_par(fid);
        root->right=Node_create_par(fid);
        return;
    }else{
        root->left=Node_create();
        root->right=Node_create();
        world_cup_tree_init(root->left,level-1,fid);
        world_cup_tree_init(root->right,level-1,fid);
    }

}

void get_winner(Node* root,const Node* a,const Node* b, int k){
    double rate=((double)(a->country->rank + (unsigned int) k) / (double)(a->country->rank + b->country->rank + (unsigned int) (2 * k)));
    double rand_res=(double )(rand()%100);
    FILE* fid=fopen("l7_output.txt","a");
    if (rand_res<(rate*100)){
        root->country->rank=b->country->rank;
        strcpy(root->country->name,b->country->name);
        fprintf(fid,"%s LOSE %s\n",a->country->name,b->country->name);
        fprintf(stdout,"%s LOSE %s\n",a->country->name,b->country->name);
    }else{
        root->country->rank=a->country->rank;
        strcpy(root->country->name,a->country->name);
        fprintf(fid,"%s WIN %s\n",a->country->name,b->country->name);
        fprintf(stdout,"%s WIN %s\n",a->country->name,b->country->name);
    }
    fclose(fid);
}

void sim(Node* root,int k){
    if (root==NULL||(root->left==NULL&&root->right==NULL)){return;}
    else if (root->left->country->rank!=NON&&root->right->country->rank!=NON){
        get_winner(root,root->left,root->right,k);
        return;
    } else{
        sim(root->left,k);
        sim(root->right,k);
        sim(root,k);


    }
}

void print_champion(Node* root){
    printf("%s WIN the world cup!\n",root->country->name);
    fflush(stdout);
}

void tree_destroy(Node* root){
    if (root==NULL){
        return;
    }else{
        tree_destroy(root->left);
        tree_destroy(root->right);
        free(root->country);
        free(root);
    }
}
