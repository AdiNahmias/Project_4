
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    pnode temp = NULL;
    pnode *head = &temp;
    char choise;
    char cp;
    int v = 0;
    //int src = 0;
    int k = 0;
    int new_v = 0;
    int start = 0;
    int del_v = 0;

    while (scanf("%c", &choise) != EOF)
    {
 
        if(choise == 'A')
        {
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
            
            choise = cp;
        }

        if(choise == 'B')
        {
        scanf("%d", &new_v);
            add_node(head, new_v);
            // print_graph(*head);
            continue;
        }
        if(choise == 'D')
        {
            scanf("%d",&del_v);
            del_node(head, del_v);
            // print_graph(*head);
            continue;
        }
        if(choise == 'S')
        {
            // shortsPath(*head);
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortest_Path(*head, src, dest);
            printf("Dijsktra shortest path: %d ",dis);
            printf("\n");
            continue;
        }
        if(choise == 'T')
        {
            scanf("%d", &k);
            TSP(*head,k);
            continue;
        }
       
    
    }
    freeGraph(head);
}