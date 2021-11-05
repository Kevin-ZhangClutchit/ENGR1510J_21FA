//
// Created by LENOVO on 2021/11/5.
//

#ifndef L7_PREP_TREE_H
#define L7_PREP_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 1024
#define NON 114514
typedef struct Node_t Node;

typedef struct Country_t Country;

Node * Node_create();
Node * Node_create_par(FILE * fid);
void world_cup_tree_init(Node* root,size_t level,FILE * fid);
void get_winner(Node* root,const Node* a,const Node* b, int k);
void sim(Node* root,int k);
void print_champion(Node* root);
void tree_destroy(Node* root);
#endif //L7_PREP_TREE_H
