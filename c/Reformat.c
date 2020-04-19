/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

char * reformat(char * s){
    if(strlen(s)==0){
        return "";
    }
    char* str1=(char*)malloc(sizeof(char)*(strlen(s)+1));
    int index1=0;
    int index2=0;
    char* str2=(char*)malloc(sizeof(char)*(strlen(s)+1));
    for(int i=0;i<strlen(s);i++){
        if(s[i]>=48 && s[i]<=57){
            str1[index1++]=s[i];
        }else{
            str2[index2++]=s[i];
        }
    }
    
    if(abs(index1-index2)>1){
        return "";
    }else if(index1>=index2){
        index1=0;
        index2=0;
        int flag=0;
        for(int i=0;i<strlen(s);i++){
            if(flag==0){
                s[i]=str1[index1++];
            }else{
                s[i]=str2[index2++];
            }
            flag=(flag+1)/2;
        }
    }else{
        index1=0;
        index2=0;
        int flag=1;
        for(int i=0;i<strlen(s);i++){
            if(flag==0){
                s[i]=str1[index1++];
            }else{
                s[i]=str2[index2++];
            }
            flag=(flag+1)/2;
        }
    }
    return s;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}