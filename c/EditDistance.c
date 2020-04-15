/* 
问题描述：
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>


int distance(char* word1,int y1, char* word2,int y2){
    
    if(y1==0 || y2==0){
        return abs(y2-y1);
    }
    if(word1[y1-1]==word2[y2-1]){
        return distance(word1,y1-1,word2,y2-1);
    }
    int a=distance(word1,y1-1,word2,y2-1)+1;
    int b=distance(word1,y1,word2,y2-1)+1;
    int c=distance(word1,y1-1,word2,y2)+1;

    if(a>b){
        a=b;
    }
    if(a>c){
        a=c;
    }
    return a;
}

int minDistance1(char * word1, char * word2){

    return distance(word1,strlen(word1),word2,strlen(word2));
}

int minDistance(char * word1, char * word2){
    int** record=(int**)malloc(sizeof(int*)*(strlen(word1)+1));
    for(int i=0;i<=strlen(word1);i++){
        record[i]=(int*)malloc(sizeof(int)*(strlen(word2)+1));
    }
    for(int i=0;i<=strlen(word1);i++){
        for(int j=0;j<=strlen(word2);j++){
            if(i==0 || j==0){
                record[i][j]=abs(j-i);
            }else{
                if(word1[i-1]==word2[j-1]){
                    record[i][j]=record[i-1][j-1];
                }else{
                    int a=record[i-1][j];
                    int b=record[i][j-1];
                    int c=record[i-1][j-1];
                    if(a>b){
                        a=b;
                    }
                    if(a>c){
                        a=c;
                    }
                    record[i][j]=a+1;
                }
            }
        }
    }
    return record[strlen(word1)][strlen(word2)];
}

int main(){
    char* word1="intention";
    char* word2="execution";
    int distance=minDistance(word1,word2);
    printf("%d",distance);
    return 0;
}