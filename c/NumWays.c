/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int ways(int n, int** relation, int relationSize, int* relationColSize, int k,int start){
    int num=0;
    for(int i=0;i<relationSize;i++){ 
        if(relation[i][0]==start){
            if(relation[i][1]==n-1 && k==1){
                return 1;
            }else{
                int local_level=ways(n,relation,relationSize,relationColSize,k-1,relation[i][1]);
                num+=local_level;
            }
        }
    }
    return num;
}

int numWays(int n, int** relation, int relationSize, int* relationColSize, int k){
    return ways(n,relation,relationSize,relationColSize,k,0);
}

int main(){
    int* m[7]={{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}};
    int** relation=(int**)malloc(sizeof(int*)*7);
    for(int i=0;i<7;i++){
        
    }
    int columnsize[]={2,2,2,2,2,2,2};
    int ans=numWays(5,m,7,columnsize,4);
    return 0;
}