/* 
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    int index=0;
    // printf("%d",strlen(strs));
    if(strsSize==0){
        return "";
    }else if(strsSize==1){
        return strs[0];
    }
    while(index<strlen(strs[0])){
        char current=strs[0][index];
        for(int i=1;i<strsSize;i++){
            if(index<strlen(strs[i])){
                // printf("%d",index);
                if(strs[i][index]!=current){
                    if(index>0){
                        // printf("---------------%d",index);
                        char* p=(char*)malloc(sizeof(char)*(index+1));
                        int j=0;
                        for(;j<index;j++){
                            p[j]=strs[0][j];
                        }
                        p[j]='\0';
                        return p;
                    }else{
                        return "";
                    }
                }
            }else{
                if(index>0){
                    // printf("---------------%d",index);
                    char* p=(char*)malloc(sizeof(char)*(index+1));
                    int j=0;
                    for(;j<index;j++){
                        p[j]=strs[0][j];
                    }
                    p[j]='\0';
                    return p;
                }else{
                    return "";
                }
            }
        }
        index++;
    }
    return strs[0];
}

int main(){
    
    char* strs[]={"flower","flow","flight"};
    char* p=longestCommonPrefix(strs,3);
    printf("%s",p);
    return 0;
}

