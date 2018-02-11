//
//  Stack.c
//  Graph
//
//  Created by Keqiao.Qian on 2018/2/6.
//  Copyright © 2018年 Keqiao.Qian. All rights reserved.
//


#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

/* helper functions*/
Node* newNode(int val){
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->prev = NULL;
    return node;
}

/* interface functions */


Stack newStack(){
    Stack s = malloc(sizeof(StackRep));
    s->nb_of_elems = 0;
    s->top = s->bottom = NULL;
    return s;
}

void push(Stack s, int val){
    Node *node = newNode(val);
    if(node!=NULL){
        if(s->nb_of_elems==0){
            s->top = s->bottom = node;
        }else{
            node->prev = s->bottom;
            s->bottom = node;
        }
        s->nb_of_elems++;
    }
}

int pop(Stack s){
    if(s->nb_of_elems<=0){
        return -1;
    }else{
        int ret = s->bottom->val;
        s->bottom = s->bottom->prev;
        s->nb_of_elems--;
        if(s->nb_of_elems==0){
            s->top = NULL;
        }
        return ret;
    }
}
