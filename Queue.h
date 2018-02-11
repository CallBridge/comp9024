//
//  Queue.h
//  Graph
//
//  Created by Keqiao.Qian on 2018/2/6.
//  Copyright © 2018年 Keqiao.Qian. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdbool.h>
typedef struct QueueRep{
    int *data;
    // the power of length, e.g. power = (2), then 10*2^(2) = 40
    int pow;
    int nb_of_elems;
}QueueRep;
typedef QueueRep *Queue;

Queue newQueue();
void enqueue(Queue, int);
int dequeue(Queue);


#endif /* Queue_h */
