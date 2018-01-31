//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include "GraphList.h"
//
//typedef int Vertex;
//
//// actual Vertex
//typedef struct Node{
//    Vertex val;
//    struct Node *next;
//}Node;
//
//// in adjacent list repr, edges helps not much, mainly on helping with clearify your relation of insert/remove
//typedef struct EdgeRep{
//	Vertex v1;
//	Vertex v2;
//	// if weighted graph, plus int weight
//}EdgeRep;
//
//typedef struct GraphRep{
//	int nV;
//	int nE;
//	struct Node **edges;
//}GraphRep;
//
///* helper functions */
//bool isValid(Graph g, Vertex v){
//    if(v>=0 && v<g->nV){
//        return true;
//    }
//    return false;
//}
//
//Node *newNode(Vertex v){
//    Node *node = malloc(sizeof(Node));
//    assert(node!=NULL);
//    node->val = v;
//    node->next = NULL;
//    return node;
//}
//
//void insertNode(Node *node, Vertex v){
//    while(node->next!=NULL){
//        node=node->next;
//    }
//    Node *new = newNode(v);
//    assert(new!=NULL);
//    node->next = new;
//}
//
//void delNode(Node *node, Vertex v){
//    while(node->next != NULL){
//        if(node->next->val==v){
//            // delete
//            Node *target = node->next;
//            node->next = node->next->next;
//            free(target);
//        }
//        node=node->next;
//    }
//}
//
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
//void freeList(Node *node){
//    if(node==NULL){
//        return;
//    }
//    Node *next = node->next;
//    while(next!=NULL){
//        free(node);
//        node = next;
//        next = next->next;
//    }
//    free(node);
//}
//
///* end of helper functions */
//
//Edge newEdge(int v1, int v2){
//    Edge e = malloc(sizeof(Edge));
//    assert(e!=NULL);
//    e->v1 = v1;
//    e->v2 = v2;
//    return e;
//}
//
//Graph newGraph(int V){
//	Graph g = malloc(sizeof(GraphRep));
//	assert(g!=NULL);
//	g->nV = V;
//	g->nE = 0;
//    g->edges = malloc(sizeof(Vertex) * V);
//    assert(g->edges!=NULL);
//    for(int i=0;i<g->nV;i++){
//        g->edges[i] = newNode(i);
//    }
//    return g;
//}
//
//bool isAdjacent(Graph g, Edge e){
//    // get the head of linkedlist for e->v1
//    // logically that is, from v1 to other vertex in the graph
//    Node *node = g->edges[e->v1];
//    while(node!=NULL){
//        if(node->val==e->v2)
//            return true;
//        node = node->next;
//    }
//    return false;
//}
//
//bool insertEdge(Graph g, Edge e){
//    assert(isValid(g, e->v1) && isValid(g, e->v2));
//    if(!isAdjacent(g, e)){
//        Node *node = g->edges[e->v1];
//        insertNode(node, e->v2);
//        g->nE++;
//        return true;
//    }else{
//        return false;
//    }
//}
//
//bool removeEdge(Graph g, Edge e){
//    if(isAdjacent(g, e)){
//        Node *node = g->edges[e->v1];
//        delNode(node, e->v2);
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
//    for(int i=0;i<g->nV;i++){
//        Node *node = g->edges[i];
//        Vertex head = node->val;
//        while(node->next!=NULL){
//            node = node->next;
//            printf("Vertex %d ---> Vertex %d\n", head, node->val);
//        }
//    }
//    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
//}
//
//void freeGraph(Graph g){
//    for(int i=0;i<g->nV;i++){
//        Node *node = g->edges[i];
//        freeList(node);
//    }
//    free(g->edges);
//    free(g);
//}
