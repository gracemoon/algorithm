/* 
问题描述：
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct Node{
    char c;
    struct Node* next;
}Node;

bool isValid(char * s){
    Node* top=(Node*)malloc(sizeof(Node));
    top->next=NULL;
    for(int i=0;i<strlen(s);i++){
        switch(s[i]){
            case '{':
{                Node* node=(Node*)malloc(sizeof(Node));
                node->c=s[i];
                node->next=top->next;
                top->next=node;
                break;}
            case '[':
{                Node* node=(Node*)malloc(sizeof(Node));
                node->c=s[i];
                node->next=top->next;
                top->next=node;
                break;}
            case '(':
{                Node* node=(Node*)malloc(sizeof(Node));
                node->c=s[i];
                node->next=top->next;
                top->next=node;
                break;}
            case '}':
{                if(top->next==NULL){
                    return false;
                }else{
                    if(top->next->c=='{'){
                        top->next=top->next->next;
                    }else{
                        return false;
                    }
                }
                break;}
            case ']':
{                if(top->next==NULL){
                    return false;
                }else{
                    if(top->next->c=='['){
                        top->next=top->next->next;
                    }else{
                        return false;
                    }
                }
                break;}
            case ')':
{                if(top->next==NULL){
                    return false;
                }else{
                    if(top->next->c=='('){
                        top->next=top->next->next;
                    }else{
                        return false;
                    }
                }
                break;}
            default:
                return false;
        }
    }
    if(top->next==NULL){
        return true;
    }
    return false;
}

int main(){
    char* s="[]({}";
    if(isValid(s)){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}