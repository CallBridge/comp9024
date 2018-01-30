#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "GraphList.h"

typedef int Vertex;

// in adjacent list repr, edges helps not much, mainly on helping with clearify your relation of insert/remove
typedef struct EdgeRep{
	Vertex v1;
	Vertex v2;
	// if weighted graph, plus int weight
}EdgeRep;

typedef struct GraphRep{
	int nV;
	int nE;
	struct Node **edges;
}GraphRep;


Graph newGraph(int V){
	Graph g = malloc(sizeof(GraphRep));
	assert(g!=NULL);

	g->nV = V;
	g->nE = 0;
	g->edges = 
}

bool isAdjacent(Graph g, Edge e){

}

bool insertEdge(Graph g, Edge e){

}

bool removeEdge(Graph g, Edge e){

}

void showGraph(Graph g){

}
