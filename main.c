
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    char prog;
    char cp;
    int v = 0;
    int k = 0;
    int new_v = 0;
    int start = 0;
    int del_v = 0;
    int short1 = 0;
    int src = -1; 
    int dest = -1;
    pnode temp = NULL;
    pnode *head = &temp;

    while (scanf("%c", &prog) != EOF){
        if(prog == 'A'){
            scanf("%d", &v);
            *head = build_graph_cmd(v);
           int c = scanf("%c", &cp);
             while(c != 0){
             c = scanf("%c", &cp);    
                if(cp == 'n'){
                scanf("%d",&start);
                addEdge(head,start);   
                }else{
                break;
                }    
            }   
            prog = cp;
        }
        if(prog == 'B'){
        scanf("%d", &new_v);
            addNode(head, new_v); 
        }
        if(prog == 'D'){
            
            scanf("%d",&del_v);
            delete_node_cmd(head, del_v);
        }
        if(prog == 'S'){
            scanf("%d %d", &src, &dest);
            short1 = shortsPath_cmd(*head, src, dest);
            printf("Dijsktra shortest path: %d ",short1);
            printf("\n");
        }
        if(prog == 'T'){
            scanf("%d", &k);
            TSP_cmd(*head,k);
        }    
    }
    deleteGraph_cmd(head);
    return 0;
}