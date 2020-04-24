/* 
问题描述：
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

 

示例 1:

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
 

提示:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
输入的字符串只含有小写英文字符。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int longestCommonSubsequence(char * text1, char * text2){
    int length1=strlen(text1);
    int length2=strlen(text2);
    int** record=(int*)malloc(sizeof(int)*(length1+1));
    for(int i=0;i<length1+1;i++){
        record[i]=(int*)malloc(sizeof(int)*(length2+1));
        for(int j=0;j<length2+1;j++){
            record[i][j]=0;
        }
    }
    
    int max_seq=0;
    for(int i=1;i<=length1;i++){
        for(int j=1;j<=length2;j++){
            if(text1[i]==text2[j]){
                record[i][j]=record[i-1][j-1]+1;
            }else{
                int local_max=record[i-1][j-1];
                if(local_max<record[i-1][j]){
                    local_max=record[i-1][j];
                }
                if(local_max<record[i][j-1]){
                    local_max=record[i][j-1];
                }
            }
        }
    }
    return record[length1][length2];
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}