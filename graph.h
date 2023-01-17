#ifndef GRAPH_
#define GRAPH_
#define INFINITY 999999999

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


node* creat_graph(int v);

void add_adge(pnode *head, int start);

void insert_edge(pnode temp,int dest,int w,pnode *head);

pnode getNode(int id, pnode *head);

void freeGraph(pnode *head);

void print_graph(pnode head);

void del_node(pnode *head);

void free_edges(pnode p);

void add_node(pnode *head, int new_v);

void del_edge(pnode *head,int n);

int shortest_Path(pnode head,int src,int dest);

int isEmpty(pnode p);

void TSP(pnode head, int k);
 

#endif