#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int id;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct NodeD {
    pnode node;
    int weight;
    int visit;
    struct NodeD *next;
} nodeD, *pnodeD;


node* build_graph_cmd(int v);
void addEdge(pnode *head, int start);
void deleteGraph_cmd(pnode *head);
void delete_node_cmd(pnode *head, int del_v);
void addNode(pnode *head, int new_v);
void deleteEdge(pnode head);
int shortsPath_cmd(pnode head,int src,int dest);
void TSP_cmd(pnode head, int k);
 

#endif