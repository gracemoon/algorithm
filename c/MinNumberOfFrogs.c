/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int minNumberOfFrogs(char * croakOfFrogs){
    
    int c=0;
    int r=0;
    int o=0;
    int a=0;
    int k=0;
    int runing=0;
    int count=0;
    for(int i=0;i<strlen(croakOfFrogs);i++){
        int m;
        switch(croakOfFrogs[i]){
            case 'c':c++;
            if(runing==count){
                count++;
                runing++;
            }else{
                runing++;
            }
            break;
            case 'r':
            if(c<=r){
                return -1;
            }
            r++;
            break;
            case 'o':
            if(r<=o){
                return -1;
            }
            o++;break;
            case 'a':
            if(o<=a){
                return -1;
            }
            a++;break;
            case 'k':
            if(a<=k){
                return -1;
            }
            k++;
            runing--;
            break;
        }
    }
    if(c==r && c==o &&c==a &&c==k){
        return count;
    }else{
        return -1;
    }
    return c;
    // int arr[]={0};
    // int index=0;
    // for(int i=0;i<strlen(croakOfFrogs);i++){
    //     int m;
    //     switch(croakOfFrogs[i]){
    //         case 'c':m=1;break;
    //         case 'r':m=2;break;
    //         case 'o':m=3;break;
    //         case 'a':m=4;break;
    //         case 'k':m=5;break;
    //     }
    //     int j=0;
    //     for(;j<index;j++){
    //         if(arr[j]+1==m){
    //             arr[j]=(arr[j]+1)%5;
    //             break;
    //         }
    //     }
    //     if(j==index){
    //         if(arr[j]+1==m){
    //             arr[j]=(arr[j]+1)%5;
    //         }else{
    //             return -1;
    //         }
    //     }
    // }
    // for(int i=0;i<index;i++){
    //     if(arr[i]!=0){
    //         return -1;
    //     }
    // }
    // return index;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}