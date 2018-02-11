#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "GraphMatrix.h"

typedef struct EdgeRep{
    Vertex v1;
    Vertex v2;
    int weight;
}EdgeRep;

typedef struct GraphRep{
	int nV;
	int nE;
    /* save space of memory */
    /* v1 column index */
    /* v2 row index */
	int *edges;
}GraphRep;

/* helper functions */
char *getStatus(Graph g){
    if(g->nE<(g->nV*g->nV/2)){
        // closer to nV
        char *ret = malloc(sizeof(char) * 7);
        ret = "sparse";
        return ret;
    }else{
        //closer to nV^2
        char *ret = malloc(sizeof(char) * 5);
        ret = "dense";
        return ret;
    }
}

int getRealIndex(Edge e, int V){
    int sum = 0;
    int v1 = e->v1;
    while(v1>0){
        sum+=V--;
        v1--;
    }
    sum+=e->v2-e->v1;
    return sum;
}

Edge getLogicalIndex(Graph g, int sum){
    int column = 0, row = 0;
    int len_curr_row = g->nV;
    while(len_curr_row>0 && len_curr_row<sum){
        sum-=len_curr_row;
        column++;
        len_curr_row--;
    }
    row = sum+column;
    // create an Edge no necessarily weight message
    return newEdge(column, row, 0);
}

Edge *getSortedEdges(Graph g){
    Edge *edges = malloc(sizeof(Edge) * g->nE);
    //getedges
    int i,index = 0;
    for(i=0;i<1+(g->nV*g->nV+g->nV)/2;i++){
        if(g->edges[i]>0){
            edges[index] = getLogicalIndex(g, i);
            edges[index++]->weight = g->edges[i];
        }
    }
    //sort
    int j;
    for(i=0;i<g->nE;i++){
        for(j=i;j<g->nE;j++){
            if(edges[i]->weight > edges[j]->weight){
                //swap
                Edge tmp = edges[i];
                edges[i] = edges[j];
                edges[j] = tmp;
            }
        }
    }
    return edges;
}

bool checkCycle(Graph g, Vertex v, int *read){
    // check vertice if has been visited, using new edges
    // if use old edges as well, forever true.
    if(read==NULL){
        read = calloc(sizeof(int), g->nV);
        assert(read!=NULL);
    }
    read[v] = 1;
    int i;
    for(i=v;i<g->nV;i++){
        if(isAdjacent(g, newEdge(v, i, 0))){
            if(read[i]){
                // vertex i has been visited.
                return true;
            }else if(checkCycle(g, i, read)){
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(Graph g){
    return checkCycle(g, 0, NULL);
}

/* end of helper functions */

Graph newGraph(int V){
    Graph g = malloc(sizeof(GraphRep));
    assert(g!=NULL);
    g->nV = V;
    g->nE = 0;
    g->edges = calloc((V*V+V)/2, sizeof(int));
    return g;
}

Edge newEdge(int v1, int v2, int weight){
    Edge e = malloc(sizeof(EdgeRep));
    assert(e!=NULL);
    e->v1 = v1;
    e->v2 = v2;
    e->weight = weight;
    return e;
}

bool isAdjacent(Graph g, Edge e){
    int index = getRealIndex(e, g->nV);
    return (g->edges[index]!=0);
}

bool insertEdge(Graph g, Edge e){
    if(!isAdjacent(g, e)){
        assert(e->v1>=0 && e->v2>=0);
        int index = getRealIndex(e, g->nV);
        g->edges[index] = e->weight;
        g->nE++;
        return true;
    }else{
        return false;
    }
}

bool removeEdge(Graph g, Edge e){
    if(isAdjacent(g, e)){
        int index = getRealIndex(e, g->nV);
        g->edges[index] = 0;
        g->nE--;
        return true;
    }else{
        return false;
    }
}

void showGraph(Graph g){
    char *status = getStatus(g);
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("This is a \'%s\' graph.\n", status);
    for(int i=0;i<1+(g->nV*g->nV+g->nV)/2;i++){
        Edge e = getLogicalIndex(g, i);
        if(g->edges[i]>0){
            printf("Sum %d,Vertex %d ---> Vertex %d, distance: %d\n",i,e->v1, e->v2, g->edges[i]);
        }
        free(e);
    }
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
}

Graph kruskalMST(Graph g){
    // 1.getsortedEdges
    Graph mst = newGraph(g->nV);
    Edge *sortedEdges = getSortedEdges(g);
    // 2.iteratively get one edge and check if there is a cycle, if not, use it
    int index = 0;
    for(int i=0;i<g->nE;i++){
        printf("Edge:\n %d->%d\nweight: %d\n",sortedEdges[i]->v1,sortedEdges[i]->v2,sortedEdges[i]->weight);
    }
    while(mst->nE < mst->nV-1){
        Edge e = sortedEdges[index++];
        insertEdge(mst, e);
        if(hasCycle(mst)){
            removeEdge(mst, e);
        }
    }
    return mst;
}
/* todo boruvka's algorithm 
        the oldest MST algorithm
        start with V separate components
        join components using min cost links
        continue until only a single component
    Karger, Klein, and Tarjan ... complexity O(E)
    based on Boruvka, but non-deterministic
    randomly selects subset of edges to consider
    for the keen, here's the paper describing the algorithm
 */

void freeGraph(Graph g){
    free(g->edges);
    free(g);
}
