#include <stdio.h>
#include <stdlib.h>

void adjacency_matrix(int vertice,int edge, int (*arr)[2]){
    int **matrix = (int**)malloc(sizeof(int*)*vertice);
    int i, j, k, exist=0;
    for(i=0;i<vertice;i++)
        *(matrix+i) = (int*)malloc(sizeof(int)*vertice);
    for(i=1;i<(vertice+1);i++){
        for(j=0;j<edge;j++){
            if(arr[j][0] == i){
                if(arr[j][1] == i)
                    exist++;
            }
        }
        matrix[i-1][i-1] = exist;
        exist =0;
    }
    for(i=1;i<vertice;i++){
        for(j=i+1;j<=vertice;j++){
            for(k=0;k<edge;k++){
                if((arr[k][0] == i && arr[k][1] == j) || (arr[k][1] == i && arr[k][0] == j))
                    exist++;
            }
            matrix[i-1][j-1] = exist;
            matrix[j-1][i-1] = exist;
            exist =0;
        }
    }
    printf("   ");
    for(i=1;i<=vertice;i++)
        printf("%d ",i);
    printf("\n");
    printf("   ");
    for(i=1;i<=vertice;i++)
        printf("- ",i);
    printf("\n");
    for(i=1;i<=vertice;i++){
        printf("%d| ",i);
        for(j=0;j<vertice;j++){
            printf("%d ",matrix[i-1][j]);
        }
        printf("\n");
    }
}

void incidence_matrix(int vertice,int edge, int (*arr)[2]){
    int **matrix = (int**)malloc(sizeof(int*)*vertice);
    int i, j;
    for(i=0;i<vertice;i++)
        *(matrix+i) = (int*)malloc(sizeof(int)*edge);
    for(i=0;i<vertice;i++){
        for(j=0;j<edge;j++){
            matrix[i][j] = 0;
        }
    }
    for(j=0;j<edge;j++){
        matrix[(arr[j][0]-1)][j] += 1;
        matrix[(arr[j][1]-1)][j] += 1;
    }
    printf("   ");
    for(i=1;i<=edge;i++)
        printf("e%d ",i);
    printf("\n");
    printf("   ");
    for(i=1;i<=edge;i++)
        printf("-- ",i);
    printf("\n");
    for(i=1;i<=vertice;i++){
        printf("%d| ",i);
        for(j=0;j<edge;j++){
            printf("%d  ",matrix[i-1][j]);
        }
        printf("\n");
    }
}

void max_degree(int vertice,int edge, int (*arr)[2]){
    int i, j, k=0, max = 0;
    for(i=1;i<=vertice;i++){
        for(j=0;j<edge;j++){
            if(arr[j][0]==i)
                k++;
            else if(arr[j][1]==i)
                k++;
            else if(arr[j][0]==i && arr[j][1]==i)
                k--;
        }
        max = k>max? k: max;
        k =0;
    }
    printf("%d\n", max);
}

















