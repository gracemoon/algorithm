/* 
问题描述：
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

char * longestPalindrome(char * s){
    int pre=0;
    int next=0;
    int ** record=(int**)malloc(sizeof(int*)*strlen(s));
    for(int i=0;i<strlen(s);i++){
        record[i]=(int*)malloc(sizeof(int)*(strlen(s)-i));
        for(int j=0;j<strlen(s)-i;j++){
            int x=j;
            int y=j+i;
            if(x==y){
                record[i][j]=1;
            }else if(x+1==y){
                if(s[x]==s[y]){
                    record[i][j]=1;
                }else{
                    record[i][j]=0;
                }
            }else{
                if(record[i-2][j+1]==1){
                    if(s[x]==s[y]){
                        record[i][j]=1;
                    }else{
                        record[i][j]=0;
                    }
                }else{
                    record[i][j]=0;
                }
            }
            if(record[i][j]==1 && y-x>next-pre){
                pre=x;
                next=y;
            }
        }
    }
    char* ans=(char*)malloc(sizeof(char)*(next-pre+2));
    int index=0;
    for(int i=pre;i<=next;i++){
        ans[index++]=s[i];
    }
    ans[index]='\0';
    return ans;
}

int main(){
    char str[]="babad";
    char * ans=longestPalindrome(str);
    printf("%s",ans);
    return 0;
}