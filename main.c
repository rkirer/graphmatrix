#include <stdio.h>
#include "function.h"

int main(){
    int a, i, arr[20][2];
    int edge, vertice;
    do{
        printf("1.Please enter 1 to read the information of an undirected graph.\n");
        printf("2.Please enter 2 to find and print the adjacency matrix of the graph.\n");
        printf("3.Please enter 3 to find and print the indicence matrix of the graph.\n");
        printf("4.Please enter 4 to find and print the degree of the graph (largest vertex degree).\n");
        printf("5.Please enter 5 to exit the program.\n");
        scanf("%d",&a);
        if(a==1){
            printf("The number of vertices: ");
            scanf("%d", &vertice);
            printf("The number of edges: ");
            scanf("%d", &edge);
            printf("The endpoints (vertices) of each edge: ");
            for(i=0;i<edge;i++){
                scanf("%d,%d", &arr[i][0], &arr[i][1]);
            }
        }
        else if(a==2)
            adjacency_matrix(vertice, edge, arr);
        else if(a==3)
            incidence_matrix(vertice, edge, arr);
        else if(a==4)
            max_degree(vertice, edge, arr);
        else
            break;
    }while(a!=5);

    return 0;
}


