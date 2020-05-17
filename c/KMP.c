/* 
问题描述：


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int* nextArray(char* str,int size){
    int* next=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        next[i]=-1;
    }
    for(int i=1;i<size;i++){
        int j=next[i-1];
        while(j!=-1 && str[j]!=str[i]){
            j=next[j];           
        }
        next[i]=j+1;
    }
    for(int i=size-1;i>0;i--){
        if(next[i-1]==-1){
            next[i]=0;
        }else{
            next[i]=next[i-1];
        }
        
    }

    return next;
}

void getNext(char * p, int * next)
{
	next[0] = -1;
	int i = 0, j = -1;

	while (i < strlen(p))
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}

int strStr(char * haystack, char * needle){
    int x=0;
    int y=0;
    int* next=nextArray(needle,strlen(needle));
    while(x<strlen(haystack) && y<strlen(needle)){
        
        if(y==-1 || haystack[x]==needle[y]){
            x++;
            y++;
        }else{
            y=next[y];
        }
    }
    if(y==strlen(needle)){
        return x-y;
    }
    return -1;
}

int main(){
    // int* next=nextArray("ll",2);
    // for(int i=0;i<2;i++){
    //     printf("%d\t",next[i]);
    // }
    // printf("\n");
    int* next=(int*)malloc(sizeof(int)*(strlen("aabaaac")+1));
    getNext("aabaaac",next);
    for(int i=0;i<=strlen("aabaaac");i++){
        printf("%d\t",next[i]);
    }
    char* haystack="hello";
    char* needle="ll";
    int m=strStr(haystack,needle);
    printf("\n%d",m);
    return 0;
}