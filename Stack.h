//
//  Stack.h
//  Graph
//
//  Created by Keqiao.Qian on 2018/2/6.
//  Copyright © 2018年 Keqiao.Qian. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdbool.h>

typedef struct Node{
    int val;
    struct Node *prev;
}Node;

typedef struct StackRep{
    int nb_of_elems;
    Node *bottom;
    Node *top;
}StackRep;

typedef struct StackRep *Stack;

Stack newStack();
void push(Stack, int val);
int pop(Stack);

#endif /* Stack_h */
