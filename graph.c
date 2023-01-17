#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"


node * creat_graph(int num_of_nodes)
{   
    node *head = NULL;
    pnode newNode, temp = NULL;
    int i;

    head = (pnode)malloc(sizeof(node));

    if(head == NULL)
    {
        exit(0);
    }   

    head->id = 0; 
    head->next = NULL;
    head->edges = NULL;

    temp = head;

    for(i=1; i<num_of_nodes; i++)
    {
        newNode = (pnode)malloc(sizeof(node));

        if(newNode == NULL)
        {
            // printf("Unable to allocate memory.");
            break;
        }
        newNode->id = i; 
        newNode->next = NULL;  
        newNode->edges = NULL;

        temp->next = newNode; 
        temp = temp->next;    
    }
    return head;
}

pnode getNode(int id, pnode *head)
{
    pnode temp = *head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

void insert_node_cmd(pnode *head);


void add_adge(pnode *head,int src){

    int dest;
    // int count = 0;
    int w;
    pnode temp = getNode(src,head);
    while(scanf("%d",&dest)!=0 && scanf("%d",&w)!=0)
    {
        if((dest >= 'A' && dest <= 'Z') || (w >= 'A' && w <= 'Z'))
        {
        break;
        }
        if((dest >= 'a' && dest <= 'z') || (w >= 'a' && w <= 'z'))
        {
        break;
        }
        insert_edge(temp,dest,w,head);
    }
}

void insert_edge(pnode temp,int dest,int w,pnode *head){

    if(temp->edges == NULL)
    {
        temp->edges = (pedge)malloc(sizeof(edge));
        if(temp->edges == NULL)
        {
            exit(0);
        }
        temp->edges->weight = w;
        temp->edges->next =NULL;
        node *D = getNode(dest,head);
        temp->edges->endpoint = &(*D);
    }
    else{
        pedge n = temp->edges;

        while(n->next!=NULL)
        {
            n = n->next;
        }
        n->next = (pedge)malloc(sizeof(edge));
        if(n == NULL)
        {
            exit(0);
        }
        n->next->next = NULL;
        n->next->weight = w;
        node *D = getNode(dest,head);
        n->next->endpoint = &(*D);
    }
}



void print_graph(pnode head){// for self debug
    pnode tempNode = head;
    while (tempNode != NULL)
    {
        printf("Node: %d {", tempNode->id);
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            printf("dest: %d weight: %d ", tempEdge->endpoint->id,tempEdge->weight);
            tempEdge = tempEdge->next;
        }
        printf("}");
        tempNode = tempNode->next;
    }
}

void freeGraph(pnode *head)
{
     pnode tempNode = *head;

    while (tempNode != NULL)
    {
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            pedge tempEdgefree = tempEdge;
            tempEdge = tempEdge->next;
            free(tempEdgefree);
        }
        node *tempFree = tempNode;
        tempNode = tempNode->next;
        free(tempFree);
    }
}

void del_node(pnode *head)
{
    int D = 0;
    scanf("%d",&D);

    del_edge(head,D);

    pnode tempNode = *head;
    node *p = NULL;
    if(tempNode->id != D)
    {
        while (tempNode->next->id!=D)
        {
        tempNode = tempNode->next;
        }
        p = tempNode->next;
        tempNode->next=tempNode->next->next;
        free_edges(p);
        free(p);    
    }
    else
    {
    p = *head;
    *head = p->next;
    free_edges(p);
    free(p);
    }
}

void free_edges(pnode p)
{
    if(p->edges!=NULL)
    {
    pedge temp = p->edges;

    while(temp!=NULL)
    {
        pedge p1 = NULL;
        p1 = temp;
        temp = temp->next;
        free(p1);
    }
    }
    else{
        free(p->edges);
    }
}

void del_edge(pnode *head,int n)
{
    pnode tempNode = *head;

    while (tempNode!= NULL)
    {
        if(tempNode->id != n && tempNode->edges!=NULL){

            if(tempNode->edges->endpoint->id !=n)
            {
                pedge tempEdge = tempNode->edges;

                    while (tempEdge->next!= NULL)
                    {   
                        if(tempEdge->next->endpoint->id == n){
                            pedge p1 = tempEdge->next;
                            tempEdge->next=tempEdge->next->next;
                            free(p1);
                            break;
                        }
                        tempEdge = tempEdge->next;
                    }           
            }
            else
            { 
                if(tempNode->edges->next ==NULL)
                    {
                    pedge p1 = tempNode->edges;
                    tempNode->edges = NULL;
                    free(p1);
                    }
                else{
                    pedge p1 = tempNode->edges;
                    tempNode->edges = p1->next;
                    free(p1);
                    }
            }
        }
        tempNode = tempNode->next; 
    }
}

void add_node(pnode *head, int new_v){
    
    pnode in_graph = NULL;
    in_graph = getNode(new_v,head);
    if(in_graph != NULL){
        free_edges(in_graph);
        in_graph->edges = NULL;

        int des1 = 0;
        int weight2 = 0;
    
        while (scanf("%d",&des1)!=0){
           if(scanf("%d",&weight2)!=0){

                if(in_graph->edges == NULL){
                in_graph->edges = (pedge)malloc(sizeof(edge));
                if(in_graph->edges == NULL){
                    exit(1);
                }
                in_graph->edges->next =NULL;
                in_graph->edges->weight = weight2;
                in_graph->edges->endpoint = &(*(getNode(des1,head)));
                }else{
                while(in_graph->edges->next!=NULL){
                    in_graph->edges = in_graph->edges->next;
                }
                in_graph->edges->next = (pedge)malloc(sizeof(edge));
                if(in_graph->edges == NULL){
                    exit(1);
                }
                in_graph->edges->next->next = NULL;
                in_graph->edges->next->endpoint = &(*(getNode(des1,head)));
                in_graph->edges->next->weight = weight2;
                }
            }
        }
                
      
    } else{

        pnode cur = *head;
        while (cur->next != NULL){
            cur = cur->next;
        }

        pnode new_node = NULL;
        pnode *n2 = &new_node;
        *n2 = (pnode)(malloc(sizeof (node)));
        if(new_node ==  NULL){
            exit(1);
        }
        new_node->id = new_v;
        new_node->edges = NULL;
        new_node->next = NULL;
        cur->next = new_node;

        int des1 = 0;
        int weight2 = 0;
        
        while (scanf("%d",&des1)!=0){   
            if(scanf("%d",&weight2)!=0){

                if(new_node->edges == NULL){
                new_node->edges = (pedge)malloc(sizeof(edge));
                if(new_node->edges == NULL){
                    exit(1);
                }
                new_node->edges->next =NULL;
                new_node->edges->weight = weight2;
                new_node->edges->endpoint = &(*(getNode(des1,head)));
                }else{
                while(new_node->edges->next!=NULL){
                    new_node->edges = new_node->edges->next;
                }
                new_node->edges->next = (pedge)malloc(sizeof(edge));
                if(new_node->edges == NULL){
                    exit(1);
                }
                new_node->edges->next->next = NULL;
                new_node->edges->next->endpoint = &(*(getNode(des1,head)));
                new_node->edges->next->weight = weight2;
                }

            }
        }
       
    }
}