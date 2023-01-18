#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define INF 1000000

int mini = INF;


int isEmpty(pnode p){
    if(p==NULL){
    return 1;
    }
    return 0;
}

int isEmpty_d(pnodeD p){
    if(p==NULL){
    return 1;
    }
    return 0;
}

pnodeD getD(pnodeD head, int id) {
    while (!(isEmpty_d(head))) {
        if (head->node->id == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


pnodeD getD_wet(pnodeD head, int wet) {
    while (!(isEmpty_d(head))) {
        if(head->visit==0){
            if (head->weight == wet) {
                head->visit =1;
                return head;
            }
        }
        head = head->next;
    }
    return NULL;
}



void deleteD(pnodeD p) {
    while (!(isEmpty_d(p))){
        pnodeD temp = p;
        p = p->next;
        free(temp);
    }
}



pnode GetNode2(int id,pnode head ){
    pnode cur =head;
    while (!(isEmpty(cur))){
        if(cur->id == id){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}


int relax(pnodeD src,pnodeD dest, pedge e){
    
    int Wedge = e->weight;
    int Wsrc = src->weight;
    int Wdest = dest->weight;
    if (Wdest > Wsrc + Wedge) {
        dest->weight = Wsrc + Wedge;
    }
return dest->weight;
}

pnodeD reset(pnode first, int src) {
    pnodeD head = NULL;
    pnodeD *d = &head;
    while (!(isEmpty(first))) {
        (*d) = (pnodeD) malloc(sizeof(nodeD));
        if ((*d) == NULL) {
            exit(0);
        }
        
        (*d)->node = first;
        (*d)->visit = 0;
        (*d)->next = NULL;
 
        if (first == GetNode2(src, first))
        {
            (*d)->weight = 0;
        } 
        else {
            (*d)->weight = INF;
        }
        d = &((*d)->next);
        first = first->next;
    }
    return head;
}


int shortsPath_cmd(pnode head, int src, int des) {
    // GET SRC
    pnodeD headD = reset(head, src);
    pnodeD temp = getD_wet(headD,0);
     while (!(isEmpty_d(temp))) {
        pedge E_ind = temp->node->edges;

        while (E_ind) {
            //faind dest
           pnodeD n = getD(headD, E_ind->endpoint->id);
        
            // apdayt the min 
            int relax1 = relax(temp, n, E_ind);
             if(relax1 < mini){
                  mini = relax1;
              }
            E_ind = E_ind->next;

        }

        // find the node of min
        temp = getD_wet(headD,mini);
        mini = INF; 
    }
    int w = 0;
    w = getD(headD, des)->weight;
    if (w == INF){
        w = -1;
    }
   deleteD(headD);

    return w;
}



pnode p_g;
int weight;
int len;

void permotion(int start ,int* arr, int k){
    int temp_w = 0;
    int min = 0; 
    
    if (start +1 == k){
        for (int i = 0; i < k-1; ++i)  {
            min = shortsPath_cmd(p_g,arr[i], arr[i+1]);
            if (min != -1){
                temp_w += min;
            }else{
                temp_w = INF;
                return;
            }     
        }
        if (temp_w < weight){
            weight = temp_w;
        }  
    return;
    }
    for (int i = start; i < k; ++i) {
        int* arrCopy = (int*)(calloc(k, sizeof(int)));

        for (int i = 0; i < k; ++i) {
        arrCopy[i] = arr[i];
        }
       
        int temp = arrCopy[start];
        arrCopy[start]= arr[i];
        arrCopy[i] = temp;

        permotion(start + 1, arrCopy, k);
        free(arrCopy);
    }
}




void TSP_cmd(pnode head, int k){
    weight = INF;
	len = -1;
    p_g = head;
   
    int *arr = (int *) (calloc(k, sizeof(int)));
    int n = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        arr[i] = n;
    }
    int *arrCopy = (int *) (calloc(k, sizeof(int)));

    for (int i = 0; i < k; ++i) {
        arrCopy[i] = arr[i];
    }

    permotion(0,arrCopy,k);
    free(arr);
    free(arrCopy);
    if (weight == INF){
        weight = -1;
    }

    printf("TSP shortest path: %d ",weight);
    printf("\n");
   
}  
    


 
 
    


 

