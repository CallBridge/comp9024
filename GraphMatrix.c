#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "GraphMatrix.h"

typedef int Vertex;

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

void freeGraph(Graph g){
    free(g->edges);
    free(g);
}
