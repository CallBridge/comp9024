
#ifndef graphmatrix_h
#define graphmatrix_h
#include <stdbool.h>

typedef struct GraphRep *Graph;
typedef struct EdgeRep *Edge;

/* put the code into main() function so you can use adjacent list repr
 
 Graph g = newGraph(4);
 
 for(int i=0;i<4;i++){
 for(int j=i;j<4;j++){
 if(j>i){
 Edge e = newEdge(i, j, i+j);
 insertEdge(g, e);
 }
 }
 }
 showGraph(g);
 freeGraph(g);
 
 */

/* undirected */
/* memory saving */
/* weighted */
/* graph */
Graph newGraph(int V);
Edge newEdge(int, int, int);
bool isAdjacent(Graph, Edge);
bool insertEdge(Graph, Edge);
bool removeEdge(Graph, Edge);
void showGraph(Graph);
void freeGraph(Graph);
#endif
