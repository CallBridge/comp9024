
#ifndef graphlist_h
#define graphlist_h
#include <stdbool.h>

struct Node{
	int val;
	struct Node *next;
};

typedef struct GraphRep *Graph;
typedef struct EdgeRep *Edge;
typedef struct Node *Node;

Graph newGraph(int V);
bool isAdjacent(Graph, Edge);
bool insertEdge(Graph, Edge);
bool removeEdge(Graph, Edge);
void showGraph(Graph);
#endif