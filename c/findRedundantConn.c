/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int find(int* parent,int element){
    if(parent[element]==-1){
        return element;
    }
    return find(parent,parent[element]);
}
int unionFunc(int* parent,int element1,int element2){
    int set1=find(parent,element1);
    int set2=find(parent,element2);
    if(set1!=set2){
        parent[set2]=set1;
        return 0;
    }
    return 1;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int* parent=(int*)malloc(sizeof(int)*edgesSize);
    for(int i=0;i<edgesSize;i++){
        parent[i]=-1;
    }
    *returnSize=2;
    for(int i=0;i<edgesSize;i++){
        if(unionFunc(parent,edges[i][0],edges[i][1])==1){
            return edges[i];
        }
    }
    return NULL;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}