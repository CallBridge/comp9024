//
//  main.c
//  Graph
//
//  Created by Keqiao.Qian on 30/1/18.
//  Copyright © 2018 Keqiao.Qian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "GraphMatrix.h"

int main(){
    Graph g = newGraph(4);
//    insertEdge(g, newEdge(0, 1));
//    insertEdge(g, newEdge(3, 2));
    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            if(j>i){
                Edge e = newEdge(i, j, i+j);
                insertEdge(g, e);
            }
        }
    }
    showGraph(g);
//    printf(hasPath(g, 1, 1)?"There is a path.\n":"There is no such Path.\n");
//    printf(hasCycle(g)?"There is a Cycle.\n":"There is no such Cycle.\n");
//    printf("There is %d component.\n",compute_components(g));
//    printf(hasHamiltonianPath(g, 0, 1)?"There is a hamiltonian path\n":"There is no such hamiltonian path.\n");
    showGraph(kruskalMST(g));
    freeGraph(g);
    return 0;
}
