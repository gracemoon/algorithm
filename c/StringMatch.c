/* 
问题描述：
给你一个字符串数组 words ，数组中的每个字符串都可以看作是一个单词。请你按 任意 顺序返回 words 中是其他单词的子字符串的所有单词。

如果你可以删除 words[j] 最左侧和/或最右侧的若干字符得到 word[i] ，那么字符串 words[i] 就是 words[j] 的一个子字符串。

 

示例 1：

输入：words = ["mass","as","hero","superhero"]
输出：["as","hero"]
解释："as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
["hero","as"] 也是有效的答案。
示例 2：

输入：words = ["leetcode","et","code"]
输出：["et","code"]
解释："et" 和 "code" 都是 "leetcode" 的子字符串。
示例 3：

输入：words = ["blue","green","bu"]
输出：[]

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int match(char* word1,char* word2){
    int length1=strlen(word1);
    int length2=strlen(word2);
    if(length1>length2){
        for(int k=0;k<length1-length2+1;k++){
            int x=k;
            int y=0; 
            while(x<length1 && y<length2){
                if(word1[x]==word2[y]){
                    x++;
                    y++;
                }else{
                    break;
                }
            }
            if(y==length2){
                return 2;
            }
        }
    }else{
        for(int k=0;k<length2-length1+1;k++){
            int x=k;
            int y=0; 
            while(x<length2 && y<length1){
                if(word2[x]==word1[y]){
                    x++;
                    y++;
                }else{
                    break;
                }
            }
            if(y==length1){
                return 1;
            }
        }
    }
    return 0;
}


char ** stringMatching(char ** words, int wordsSize, int* returnSize){
    int* words_arr=(int*)malloc(sizeof(int)*wordsSize);
    char** return_words_arr=(char**)malloc(sizeof(char*)*wordsSize);
    int index=0;
    for(int i=0;i<wordsSize;i++){
        words_arr[i]=0;
    }
    for(int i=0;i<wordsSize-1;i++){
        for(int j=i+1;j<wordsSize;j++){
            int match_index=match(words[i],words[j]);
            if(match_index==1){
                if(words_arr[i]==0){
                    return_words_arr[index++]=words[i];
                    words_arr[i]=1;
                }
            }else if(match_index==2){
                if(words_arr[j]==0){
                    return_words_arr[index++]=words[j];
                    words_arr[j]=0;
                }
            }
        }
    }
    *returnSize=index;
    return return_words_arr;
}

int main(){
    char* arr[]={"mass","as","hero","superhero"};
    int size=0;
    char** result=stringMatching(arr,4,&size);
    for(int i=0;i<size;i++){
        printf("%s\n",result[i]);
    }
    return 0;
}