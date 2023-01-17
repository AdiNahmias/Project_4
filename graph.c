#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"


static pnode temp = NULL;
static pnode *head = &temp;

//--------------------------------------------------

node* creat_graph(int v){

    //delete the graph
    freeGraph(head);
    //create the first node

    pnode head = NULL;
    pnode *n = &head;
    
    *n = (pnode)malloc(sizeof(node));
    if(head == NULL){
        exit(1);
    } 
    int id = 0;
    pnode temp = NULL; 
    head->id = id; 
    head->edges = NULL;
    head->next = NULL;
    temp = head;

    //create v-1
    for(int i=1; i<v; i++){
        

        pnode new_node = NULL;
        pnode *n2 = &new_node;

        *n2 = (pnode)malloc(sizeof(node));
        if(new_node == NULL){
            exit(1);
        }
        new_node->id = i; 
        new_node->next = NULL;  
        new_node->edges = NULL;
        temp->next = new_node; 
        temp = temp->next;    
    }
    return head;
}

//--------------------------------------------------

pnode getNode(int id, pnode *head){
    pnode temp = *head;
    while (temp){
        if(temp -> id != id){
        temp = temp->next; 
        }else{
            return temp;
        }   
    }
    temp = NULL;
    return temp;
}

//--------------------------------------------------


void add_adge(pnode *head, int start){

    pnode temp = NULL;
    temp = getNode(start,head);
    int des1 = 0;
    int weight2 = 0;
    
    while(scanf("%d",&des1)!=0){
        if(scanf("%d",&weight2)!=0){
        
            if(temp->edges == NULL){
            temp->edges = (pedge)malloc(sizeof(edge));
            if(temp->edges == NULL){
                exit(1);
            }
            temp->edges->next =NULL;
            temp->edges->weight = weight2;
            temp->edges->endpoint = &(*(getNode(des1,head)));
            }else{
            while(temp->edges->next!=NULL){
                temp->edges = temp->edges->next;
            }
            temp->edges->next = (pedge)malloc(sizeof(edge));
            if(temp->edges == NULL){
                exit(1);
            }
            temp->edges->next->next = NULL;
            temp->edges->next->endpoint = &(*(getNode(des1,head)));
            temp->edges->next->weight = weight2;
            }
        }
    }
}

//--------------------------------------------------


// void print_graph(pnode head){// for self debug
//     pnode tempNode = head;
//     while (tempNode != NULL)
//     {
//         printf("Node: %d {", tempNode->id);
//         pedge tempEdge = tempNode->edges;
//         while (tempEdge != NULL)
//         {
//             printf("dest: %d weight: %d ", tempEdge->endpoint->id,tempEdge->weight);
//             tempEdge = tempEdge->next;
//         }
//         printf("}");
//         tempNode = tempNode->next;
//     }
// }

//--------------------------------------------------


void freeGraph(pnode *head){
    if(head==NULL){
        return;
    }
    pnode cur = *head;
    while (cur){
        pedge e = cur->edges;
        //free all the edges of cur
        while (e) {
            pedge e_cur_free = e;
            e = e->next;
            free(e_cur_free);
        }
        //free all the nodes in the graph
        node *temp = cur;
        cur = cur->next;
        free(temp);
    }
}


//--------------------------------------------------

void swap_for_free(pnode free_node){
    node *temp = NULL;
    temp = free_node;
    free_node = free_node->next;
    free_edges(temp);
    free(temp);    

}

//--------------------------------------------------

void del_node(pnode *head, int del_v){
    //node *p = NULL;
    del_edge(head,del_v);
    pnode tempNode = *head;
    
    //if head id not the node that we want to delete
    if(tempNode->id != del_v){

        while (tempNode->next->id != del_v){
        tempNode = tempNode->next;
        }

        swap_for_free(tempNode->next);
        // p = tempNode->next;
        // tempNode->next=tempNode->next->next;
        // free_edges(p);
        // free(p);    
    }
    //if we want to remove head
    else{
    swap_for_free(*head);
    // p = *head;
    // *head = p->next;
    // free_eges(p);
    // free(p);
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

//--------------------------------------------------

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