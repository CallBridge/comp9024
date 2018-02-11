//
//  Queue.c
//  Graph
//
//  Created by Keqiao.Qian on 2018/2/6.
//  Copyright © 2018年 Keqiao.Qian. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include "Queue.h"
#define INITLEN 10

/* helper functions */
int pow_two(int pow){
    int ret =1;
    while(pow>0){
        ret*=2;
        pow--;
    }
    return ret;
}

bool isFull(Queue q){
    if(q->nb_of_elems>= INITLEN * pow_two(q->pow) - 1){
        return true;
    }
    return false;
}

void resize(Queue q){
    if(isFull(q)){
        q->pow++;
        q->data = realloc(q->data, pow_two(q->pow) * INITLEN * sizeof(int));
    }
}

/* interface functions */
Queue newQueue(){
    Queue q = malloc(sizeof(QueueRep));
    q->pow = q->nb_of_elems = 0;
    q->data = malloc(INITLEN * pow_two(q->pow) * sizeof(int));
    return q;
}

void enqueue(Queue q, int val){
    resize(q);
    q->data[q->nb_of_elems]=val;
    q->nb_of_elems++;
}

int dequeue(Queue q){
    int ret = 0;
    if(q->nb_of_elems>0){
        ret = q->data[0];
        q->nb_of_elems--;
    }
    return ret;
}


