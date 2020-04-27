/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>


int maxScore(char * s){
    int one_count=0;
    int zero_count=0;
    for(int i=1;i<strlen(s);i++){
        if(s[i]=='1'){
            one_count++;
        }
    }
    if(s[0]='0'){
        zero_count++;
    }
    int max=0;
    for(int i=1;i<strlen(s)-1;i++){
        if(s[i]=='0'){
            zero_count++;
        }else{
            one_count--;
        }
        if(max<zero_count+one_count){
            max=zero_count+one_count;
        }
    }
    return max;
}


int Score(int* cardPoints,int k,int x,int y){
    int a=cardPoints[x];
    int b=cardPoints[y]; 
    if(x<=y){
        if(k>0){
            a=Score(cardPoints,k-1,x+1,y)+a;
            b=Score(cardPoints,k-1,x,y-1)+b;            
        }
    }
    if(a<b){
        a=b;
    }
    return a;
}

int maxScore(int* cardPoints, int cardPointsSize, int k){
    int ans=Score(cardPoints,k,0,cardPointsSize-1);
}


int maxScore(int* cardPoints, int cardPointsSize, int k){
    int left=0;
    int right=0;
    int x=k-1;
    int y=cardPointsSize-1;
    for(int i=0;i<k;i++){
        left+=cardPoints[i];
    }
    int max=left;
    while(x>=0){
        right+=cardPoints[y];
        left-=cardPoints[x];
        if(max<left+right){
            max=left+right;
        }
        x--;
        y--;
    }
    return max;
}


int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}