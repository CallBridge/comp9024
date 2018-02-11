//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include "GraphAlgorithms.h"
//#include "Stack.h"
//#include "Queue.h"
//
//
//typedef struct EdgeRep{
//    Vertex v1;
//    Vertex v2;
//}EdgeRep;
//
//typedef struct GraphRep{
//	int nV;
//	int nE;
//    /* save space of memory */
//    /* v1 column index */
//    /* v2 row index */
//	int *edges;
//}GraphRep;
//
///* helper functions */
//char *getStatus(Graph g){
//    if(g->nE<(g->nV*g->nV/2)){
//        // closer to nV
//        char *ret = malloc(sizeof(char) * 7);
//        ret = "sparse";
//        return ret;
//    }else{
//        //closer to nV^2
//        char *ret = malloc(sizeof(char) * 5);
//        ret = "dense";
//        return ret;
//    }
//}
//
//int getRealIndex(Edge e, int V){
//    int sum = 0;
//    int v1 = e->v1;
//    while(v1>0){
//        sum+=V--;
//        v1--;
//    }
//    sum+=e->v2-e->v1;
//    return sum;
//}
//
//Edge getLogicalIndex(Graph g, int sum){
//    int column = 0, row = 0;
//    int len_curr_row = g->nV;
//    while(len_curr_row>0 && len_curr_row<sum){
//        sum-=len_curr_row;
//        column++;
//        len_curr_row--;
//    }
//    row = sum+column;
//    return newEdge(column, row);
//}
//
///* end of helper functions */
//
//Graph newGraph(int V){
//    Graph g = malloc(sizeof(GraphRep));
//    assert(g!=NULL);
//    g->nV = V;
//    g->nE = 0;
//    g->edges = calloc((V*V+V)/2, sizeof(int));
//    return g;
//}
//
//Edge newEdge(int v1, int v2){
//    Edge e = malloc(sizeof(EdgeRep));
//    assert(e!=NULL);
//    e->v1 = v1;
//    e->v2 = v2;
//    return e;
//}
//
//bool isAdjacent(Graph g, Edge e){
//    printf("Values at %d\n",g->edges[getRealIndex(e, g->nV)]);
//    int index = getRealIndex(e, g->nV);
//    return (g->edges[index]!=0);
//}
//
//bool insertEdge(Graph g, Edge e){
//    if(!isAdjacent(g, e)){
//        assert(e->v1>=0 && e->v2>=0);
//        int index = getRealIndex(e, g->nV);
//        g->edges[index] = 1;
//        g->nE++;
//        return true;
//    }else{
//        return false;
//    }
//}
//
//bool removeEdge(Graph g, Edge e){
//    if(isAdjacent(g, e)){
//        int index = getRealIndex(e, g->nV);
//        g->edges[index] = 0;
//        g->nE--;
//        return true;
//    }else{
//        return false;
//    }
//}
//
//void showGraph(Graph g){
//    char *status = getStatus(g);
//    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
//    printf("This is a \'%s\' graph.\n", status);
//    printf("There are %d edges in the graph.\n", g->nE);
//    for(int i=0;i<1+(g->nV*g->nV+g->nV)/2;i++){
//        Edge e = getLogicalIndex(g, i);
//        if(g->edges[i]>0){
//            printf("Sum %d,Vertex %d ---> Vertex %d, distance: %d\n",i,e->v1, e->v2, g->edges[i]);
//        }
//        free(e);
//    }
//    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
//}
//
//void freeGraph(Graph g){
//    free(g->edges);
//    free(g);
//}
//
///* graph algorithms */
//
//// DFS path checking algorithm
//bool dfsCheckPathRecursively(Graph g, Vertex v, Vertex dest, int *read){
//    // mark as read
//    if(read==NULL){
//        read = calloc(g->nV, sizeof(Vertex));
//        assert(read!=NULL);
//    }
//    read[v]=1;
//    
//    int i;
//    for(i=0;i<g->nV;i++){
//        Edge e = newEdge(v, i);
//        if(isAdjacent(g, e) && read[i]!=1){
//            if(dest == i){
//                return true;
//            }else if(dfsCheckPathRecursively(g, i, dest, read)){
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//bool dfsCheckPathIteratively(Graph g, Vertex src, Vertex dest){
//    
//    int *read = calloc(g->nV, sizeof(Vertex));
//    assert(read!=NULL);
//    
//    bool flag_found = false;
//    Stack s = newStack();
//    push(s, src);
//    while(!flag_found && s->nb_of_elems!=0){
//        int v = pop(s);
//        read[v]=1;
//        if(v == dest){
//            return true;
//        }else{
//            int i;
//            for(i=0;i<g->nV;i++){
//                Edge e = newEdge(v, i);
//                if(!read[i] && isAdjacent(g, e)){
//                    push(s, i);
//                    printf("pushed %d into stack.\n", i);
//                }
//                free(e);
//            }
//        }
//    }
//    return false;
//}
//
//// BFS path checking algorithm
//bool bfsCheckPath(Graph g, Vertex src, Vertex dest){
//    int *read = malloc( g->nV * sizeof(int));
//    assert(read!=NULL);
//    Queue q = newQueue();
//    enqueue(q, src);
//    read[src]=1;
//    while(q!=NULL){
//        int v = dequeue(q);
//        read[v]=1;
//        int i;
//        for(i=0;i<g->nV;i++){
//            if(isAdjacent(g, newEdge(v, i))){
//                if(i == dest){
//                    return true;
//                }else if(read[i]==0){
//                    enqueue(q, i);
//                }
//            }
//        }
//    }
//    return false;
//}
//
//bool hasPath(Graph g, Vertex src, Vertex dest){
//    /*
//     Input : Graph, source and destination
//     Output: True/False if there is a path
//     */
////    return dfsCheckPathRecursively(g, src, dest, NULL);
////    return dfsCheckPathIteratively(g, src, dest);
//    return bfsCheckPath(g, src, dest);
//}
//
//bool checkCycle(Graph g, Vertex v, int *read){
//    if(read==NULL){
//        read = calloc(sizeof(int), g->nV);
//        assert(read!=NULL);
//    }
//    read[v] = 1;
//    int i;
//    for(i=0;i<g->nV;i++){
//        if(isAdjacent(g, newEdge(v, i))){
//            if(read[i]){
//                // vertex i has been visited.
//                return true;
//            }else if(checkCycle(g, i, read)){
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//bool hasCycle(Graph g){
//    return checkCycle(g, 0, NULL);
//}
//
//int markComponents(Graph g, Vertex v, int *read, int index){
//    if(read==NULL){
//        read = calloc(sizeof(int), g->nV);
//        assert(read!=NULL);
//    }
//    read[v]=index;
//    int i;
//    for(i=0;i<g->nV;i++){
//        if(isAdjacent(g, newEdge(v, i))){
//            read[i] = index;
//        }else if(read[i]==0){
//            markComponents(g, i, read, index+1);
//        }
//    }
//    int flag=0, ret =0;
//    for(i=0;i<g->nV;i++){
//        if(read[i]==0){
//            flag=1;
//        }else if(read[i]>ret){
//            ret = read[i];
//        }
//    }
//    if(!flag){
//        return ret;
//    }
//    return 0;
//}
//
//int compute_components(Graph g){
//    return markComponents(g, 0, NULL, 1);
//}
//
///*
// g: grpah
// v, dest: vertices
// distance: from v to dest
// */
//bool hamiltonR(Graph g, Vertex v, Vertex dest,int *visited, int distance){
//    if(visited==NULL){
//        visited = calloc(sizeof(int), g->nV);
//        assert(visited!=NULL);
//    }
//    
//    if(v==dest){
//        if(distance==0){
//            return true;
//        }else{
//            return false;
//        }
//    }else{
//        visited[v]=1;
//        int i;
//        for(i=0;i<g->nV;i++){
//            if(isAdjacent(g, newEdge(v, i)) && visited[i]==0){
//                if(hamiltonR(g, i, dest, visited, distance-1)){
//                    return true;
//                }
//            }
//        }
//    }
//    // backtracking
//    visited[v]=false;
//    return false;
//}
//
//bool hasHamiltonianPath(Graph g, Vertex src, Vertex dest){
//    return hamiltonR(g, src, dest, NULL, g->nV-1);
//}
//
//bool hasEulerPath(Graph g, Vertex src, Vertex dest){
//    /* use theorem */
//    /* euler path only two vertices have odd degree */
//    /* euler circuit all vertices hace even degree */
//    return false;
//}
