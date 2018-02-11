//
//  PriorityQueue.h
//  Graph
//
//  Created by Keqiao.Qian on 2018/2/7.
//  Copyright © 2018年 Keqiao.Qian. All rights reserved.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <stdio.h>
/*
 description
 items processed in order of "key"
 rather than in order of entry (FIFO)
 */

typedef struct PQueueRep{
    
}PQueueRep;

typedef PQueueRep *PQueue;

/* take place of enqueue */
void join(PQueue, int);
int leave(PQueue);
#endif /* PriorityQueue_h */
