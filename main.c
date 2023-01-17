
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    pnode temp = NULL;
    pnode *head = &temp;
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

    while (scanf("%c", &prog) != EOF){
 
        if(prog == 'A'){
            scanf("%d", &v);
            *head = creat_graph(v);
            //creat_graph(v);
            
           int c = scanf("%c", &cp);
            
             while(c != 0){
             c = scanf("%c", &cp);    
                if(cp == 'n'){
                scanf("%d",&start);
                add_adge(head,start);   
                }else{
                break;
                }    

            }
            // print_graph(*head);
            
            prog = cp;
        }

        if(prog == 'B'){
        scanf("%d", &new_v);
            add_node(head, new_v);
            // print_graph(*head);
            continue;
        }
        if(prog == 'D'){
            
            scanf("%d",&del_v);
            del_node(head, del_v);
            // print_graph(*head);
            continue;
        }
        if(prog == 'S'){
            // shortsPath(*head);
            scanf("%d %d", &src, &dest);
            short1 = shortest_Path(*head, src, dest);
            printf("Dijsktra shortest path: %d ",short1);
            printf("\n");
            continue;
        }
        if(prog == 'T'){
            scanf("%d", &k);
            TSP(*head,k);
            continue;
        }
       
    
    }
    freeGraph(head);
}