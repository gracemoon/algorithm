/* 
问题描述：
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

解题思路:


*/

#include <stdio.h>
// #include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct Node{
    char* val;
    int index;
    struct Node* next;
}Node;

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    int* arr=(int*)malloc(sizeof(int)*wordListSize);
    for(int i=0;i<wordListSize;i++){
        arr[i]=0;
    }
    Node* head=(Node*)malloc(sizeof(Node));
    head->index=1;
    head->val=beginWord;
    head->next=NULL;
    Node* p=head;
    int index=0;
    int length=0;
    int flag=0;
    while(index<wordListSize){
        if(head==NULL){
            break;
        }
        char* current=head->val;
        for(int i=0;i<wordListSize;i++){
            if(arr[i]==0){
                int count=0;
                for(int j=0;j<strlen(current);j++){
                    if(current[j]==wordList[i][j]){
                        count++;
                    }
                }
                if(count==strlen(current)-1){
                    count=0;
                    for(int k=0;k<strlen(current);k++){
                        if(wordList[i][k]==endWord[k]){
                            count++;
                        }
                    }
                    if(count==strlen(current)){
                        length=head->index+1;
                        flag=1;
                        break;
                    }
                    Node* node=(Node*)malloc(sizeof(Node));
                    node->next=NULL;
                    node->index=head->index+1;
                    node->val=wordList[i];
                    p->next=node;
                    p=node;
                    arr[i]=1;
                    index++;
                }
            }
        }
        if(flag==1){
            break;
        }
        head=head->next; 
    }
    return length;
}

// int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
//     int i=0;
//     int beginIndex=-1;
//     int length;
//     for(;i<wordListSize;i++){
//         int local_begin_count=transform(beginWord,wordList[i]);
//         int local_end_count=transform(endWord,wordList[i]);
//         if(local_end_count==1){
//             if(beginIndex==-1){
//                 length=0;
//                 break;
//             }else{
//                 length=i-beginIndex+2;
//                 break;
//             }
//         }
//         if(local_begin_count==1){
//             beginIndex=i;
//         }
//     }
//     if(i==wordListSize){
//         length=0;
//     }
//     return length;
// }

int main(){
    // char* beginWords="hit";
    // char* endWords="cog";
    // char* arr[]={"hot","dot","dog","lot","log","cog"};
    char* beginWords="a";
    char* endWords="c";
    char* arr[]={"a","b","c"};
    char** wordList=arr;
    int wordListSize=3;
    for(int i=0;i<wordListSize;i++){
        printf("%s\t",wordList[i]);
    }
    
    int length=ladderLength(beginWords,endWords,wordList,wordListSize);
    printf("%d",length);
    return 0;
}