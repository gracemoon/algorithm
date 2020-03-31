/* 
问题描述：
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

Example 2:

    Input: "cbbd"
    Output: "bb"

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

char* longestPalindrome1(char* s){
    if(strlen(s)==0){
        return s;
    }
    char* str1=(char*)malloc(sizeof(char)*(strlen(s)));
    char* str2=(char*)malloc(sizeof(char)*(strlen(s)));
    int i=0;
    int j=strlen(s)-1;
    if(i==j){
        return s;
    }
    if(s[i]==s[j]){
        for(;i<j;i++,j--){
            if(s[i]!=s[j]){
                break;
            }
        }
        if(i>=j){
            return s;
        }
    }
    int k=0;
    for(;k<strlen(s)-1;k++){
        str1[k]=s[k];
        str2[k]=s[k+1];
    }
    str1[k]='\0';
    str2[k]='\0';

    str1=longestPalindrome1(str1);
    str2=longestPalindrome1(str2);
    if(strlen(str1)>=strlen(str2)){
        return str1;
    }else{
        return str2;
    }
    return s;
}

char* longestPalindrome(char* s){
    int size=strlen(s);
    if(size<=1){
        return s;
    }
    int start=0;
    int end=0;
    for(int i=0;i<size;i++){
        int local_s,local_e;
        if(i==size-1){
            local_e=local_s=i;
        }else{
            local_e=local_s=i;
            for(int j=i-1,k=i+1;j>=0,k<size;j--,k++){
                if(s[j]!=s[k]){
                    break;
                }else{
                    local_s--;
                    local_e++;
                }
            }
            if((local_e-local_s)>(end-start)){
                start=local_s;
                end=local_e;
            }
            if(s[i]==s[i+1]){
                local_s=i;
                local_e=i+1;
                for(int j=i-1,k=i+2;j>=0,k<size;j--,k++){
                    if(s[j]!=s[k]){
                        break;
                    }else{
                        local_s--;
                        local_e++;
                    }
                }
                if((local_e-local_s)>(end-start)){
                    start=local_s;
                    end=local_e;
                }
            }
        }
        
    }
    char* str1=(char*)malloc(sizeof(char)*(end-start+1));
    // char* str1=s;
    int x=0;
    for(;x<end-start+1;x++){
        str1[x]=s[start+x];
    }
    str1[x]='\0';
    return str1;
}

int main(){
    char str[]={'c','a','a','d','\0'};
    char* s="cbbd";
    char* str1=longestPalindrome(s);
    printf("%s",str1);
    return 0;
}