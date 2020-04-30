#include <stdio.h>
#include <malloc.h>
#include <string.h>
void quickSort(int* arr,char* str,int low,int high){
    int x=low+1;
    int y=high;
    while(x<=y){
        if(arr[low]<arr[x] && arr[low]>arr[y]){
            int temp=arr[x];
            arr[x]=arr[y];
            arr[y]=temp;
            char c=str[x];
            str[x]=str[y];
            str[y]=c;
            x++;
            y--;
        }
        if(arr[low]>=arr[x]){
            x++;
        }
        if(arr[low]<=arr[y]){
            y--;
        }
    }
    int temp=arr[low];
    arr[low]=arr[y];
    arr[y]=temp;
    char c=str[low];
    str[low]=str[y];
    str[y]=c;
    if(y-1>low){
        quickSort(arr,str,low,y-1);
    }
    if(high>x){
        quickSort(arr,str,x,high);
    }
}

void BubbleSort(int* nums,char* str,int numsSize){
    for(int i=0;i<numsSize-1;i++){
        for(int j=0;j<numsSize-i-1;j++){
            if(nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
                char c=str[j];
                str[j]=str[j+1];
                str[j+1]=c;
            }
        }
    }
}

int main(){
    char* s=(char*)malloc(sizeof(char)*100001);
    char* s1=(char*)malloc(sizeof(char)*27);
    char* s2="abcdefghijklmnopqrstuvwxyz";
    int* count=(int*)malloc(sizeof(int)*26);
    for(int i=0;i<26;i++){
        s1[i]=s2[i];
        count[i]=0;
    }
    int k;
    // scanf("%s",s);
    // scanf("%d",&k);
    char sss[]={'b','a','c','a','a'};
    s=sss;
    k=2;
    for(int i=0;i<strlen(s);i++){
        int t=s[i]-s1[0];
        count[t]++;
    }
    s1[26]='\0';
    // quickSort(count,s1,0,25);
    BubbleSort(count,s1,26);
    printf("%s",s1);
    for(int i=0;i<26;i++){
        printf("%d\t",count[i]);
    }
    while(k>0){
        char c;
        for(int j=0;j<26;j++){
            if(count[j]>0){
                c=s1[j];
                count[j]=0;
                break;
            }
        }
        int x=0,y=0;
        for(;y<strlen(s);){
            if(s[y]==c && k>0){
                k--;
                y++;
            }else{
                // char tmp=
                s[x]=s[y];
                x++;
                y++;
            }
        }
        s[x]='\0';
    }
    printf("%s",s);
    return 0;
}