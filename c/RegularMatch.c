/* 
问题描述：
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
typedef struct StackNode{
    int value;
    char c;
    struct StackNode* next;
    
}StackNode;

bool match(char* str, char* pattern){
    StackNode* stack;
    bool match_re=false;
    int state=0;
    int star=0;
    int i=0;
    while(1){
        if((state==strlen(pattern)  || pattern[state+1]=='*') && i==strlen(str) ){
            match_re=true;
            break;
        }else if((str[i]!=pattern[i] || state==strlen(pattern) || i==strlen(str)) && star>0){
            star--;
            while(!(stack->c=='*' && stack->value==star)){
                i--;
                if(stack->c=='*'){
                    state-=2;
                    stack=stack->next->next;
                }else{
                    state--;
                    stack=stack->next;
                }
                
            }
            if(str[i]==stack->next->c){
                i++;
            }else{
                break;
            }
        }else if(str[i]!=pattern[i] && star==0){
            break;
        }
        if((str[i]==pattern[state]  || pattern[state]=='.') && (pattern[state+1]!='*')){
            i++;
            state++;
            StackNode* node=(StackNode*)malloc(sizeof(StackNode));
            node->value=0;
            node->c=str[i];
            node->next=stack;
            stack=node;
        }else if(pattern[state+1]=='*'){
            state++;
            star++;
            StackNode* node=(StackNode*)malloc(sizeof(StackNode));
            node->value=0;
            node->c=str[i];
            node->next=stack;
            stack=node;
            state++;
            StackNode* node1=(StackNode*)malloc(sizeof(StackNode));
            node1->value=star;
            node1->c='*';
            node1->next=stack;
            stack=node1;
        }
    }
    return match_re;
}

int main(){
    char* str="aaaa";
    char* pattern="aa*a";
    int result=match(str,pattern);
    printf("%d",result);
    return 0;
}