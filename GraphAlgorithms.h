//
//#ifndef graphmatrix_h
//#define graphmatrix_h
//#include <stdbool.h>
//
//typedef struct GraphRep *Graph;
//typedef struct EdgeRep *Edge;
//typedef int Vertex;
//
///* put the code into main() function so you can use adjacent list repr
// 
// Graph g = newGraph(4);
// 
// for(int i=0;i<4;i++){
// for(int j=i;j<4;j++){
// if(j>i){
// Edge e = newEdge(i, j, i+j);
// insertEdge(g, e);
// }
// }
// }
// showGraph(g);
// freeGraph(g);
// 
// */
//
///* undirected */
///* memory saving */
///* graph */
//Graph newGraph(int V);
//Edge newEdge(Vertex, Vertex);
//bool isAdjacent(Graph, Edge);
//bool insertEdge(Graph, Edge);
//bool removeEdge(Graph, Edge);
//void showGraph(Graph);
//void freeGraph(Graph);
///* graph algorithms */
//bool hasPath(Graph, Vertex, Vertex);
//bool hasCycle(Graph);
//int compute_components(Graph);
//bool hasHamiltonianPath(Graph, Vertex, Vertex);
//Graph kruskalMST(Graph);
//#endif
