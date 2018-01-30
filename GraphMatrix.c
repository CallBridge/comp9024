#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "GraphList.h"

typedef int Vertex;

typedef struct Edges{
	Vertex v1;
	Vertex v2;
	// if weighted graph, plus int weight
}Edges;

typedef struct GraphRep{
	int nV;
	int nE;
	struct Edges **edges;
}GraphRep;