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
typedef struct Automaton{
    char value;
    int circle;
    struct Automaton* next;
    struct Automaton* previous;
}Automaton;

bool match1(char* str, char* pattern){
    Automaton* head=NULL;
    Automaton* p=NULL;
    //构建自动机
    for(int i=0;i<strlen(pattern);i++){
        if(pattern[i]=='*'){
            p->circle=1;
        }else{
            Automaton* node=(Automaton*)malloc(sizeof(Automaton));
            node->value=pattern[i];
            node->circle=0;
            node->next=NULL;
            node->previous=NULL;
            if(head==NULL){
                p=head=node;
            }else{
                node->previous=p;
                p->next=node;
                p=node;
            }
        }
    }
    Automaton* node=(Automaton*)malloc(sizeof(Automaton));
    node->next=NULL;
    node->previous=p;
    p->next=node;
    Automaton* state=head;
    int index=0;
    bool result=true;
    while(1){
        if(strlen(str)==index){
            break;
        }
        if(state->next==NULL && state->previous!=NULL){
            Automaton* pre=state->previous;
            while(pre){
                if((pre->value==str[index] || pre->value=='.') && pre->circle==0){
                    pre=pre->previous;
                    index--;
                }else if(pre->circle==1 && pre->value!=str[index] && pre->value!='.'){
                    pre=pre->previous;
                }else if((pre->value==str[index]|| pre->value=='.') && pre->circle>0){
                    index++;
                    pre->circle++;
                    state=pre->next;
                    break;
                }else{
                    return false;
                }
            }
            if(pre==NULL){
                return false;
            }
        }else{
            if(state->circle==1){
                state=state->next;
            }else{
                if(state->value==str[index] || state->value=='.'){
                    index++;
                    state=state->next;
                }
                // else if(state->value!=str[index]){
                //     return false;
                // }
                else{
                    Automaton* pre=state->previous;
                    while(pre){
                        if((pre->value==str[index] || pre->value=='.') && pre->circle==0){
                            pre=pre->previous;
                            index--;
                        }else if(pre->circle==1 && pre->value!=str[index] && pre->value!='.'){
                            pre=pre->previous;
                        }else if((pre->value==str[index]|| pre->value=='.') && pre->circle>0){
                            index++;
                            pre->circle++;
                            state=pre->next;
                            
                            break;
                        }else{
                            return false;
                        }
                    }
                    if(pre==NULL){
                        return false;
                    }
                }
            }
        }
       
    }
    if(state->next==NULL && strlen(str)==index){
        return true;
    }
    return false;
}



bool match2(char* str, char* pattern){
    Automaton* head=NULL;
    Automaton* p=NULL;
    //构建自动机
    for(int i=0;i<strlen(pattern);i++){
        if(pattern[i]=='*'){
            p->circle=1;
        }else{
            Automaton* node=(Automaton*)malloc(sizeof(Automaton));
            node->value=pattern[i];
            node->circle=0;
            node->next=NULL;
            node->previous=NULL;
            if(head==NULL){
                p=head=node;
            }else{
                node->previous=p;
                p->next=node;
                p=node;
            }
        }
    }
    Automaton* state=head;
    int index=0;
    bool result=true;
    while(1){
        if(strlen(str)==index){
            if(state!=NULL){
                if(state->circle==1 && state->next==NULL){
                    return true;
                }else if(state->circle==1 && index==0){
                    state=state->next;
                }else{
                    Automaton* pre;
                    if(state->circle==1){
                        pre=state;
                    }else{
                        pre=state->previous;
                    }
                    while(1){
                        if(pre==NULL || index==0){
                            return false;
                        }
                        if((pre->value==str[index-1] || pre->value=='.') && pre->circle==0){
                            pre=pre->previous;
                            index--;
                        }else if((pre->value==str[index-1]|| pre->value=='.') && pre->circle==1){
                            index--;
                            state=pre->next;
                            break;
                        }else if(pre->circle==1 && pre->value!=str[index-1] && pre->value!='.'){
                            pre=pre->previous;
                        }else{
                            return false;
                        }
                    }
                }
            }else{
                break;
            }
        }else if(state==NULL){
            return false;
        }else{
            if(state->circle==1){
                if(state->value!=str[index] && state->value!='.'){
                    state=state->next;
                }else{
                    index++;
                }
            }else{
                if(state->value==str[index] || state->value=='.'){
                    index++;
                    state=state->next;
                }else if(index==0){
                    return false;
                }else{
                    Automaton* pre=state->previous;
                    while(1){
                        if(pre==NULL || index==0){
                            return false;
                        }
                        if((pre->value==str[index-1] || pre->value=='.') && pre->circle==0){
                            pre=pre->previous;
                            index--;
                        }else if((pre->value==str[index-1]|| pre->value=='.') && pre->circle==1){
                            index--;
                            state=pre->next;
                            break;
                        }else if(pre->circle==1 && pre->value!=str[index-1] && pre->value!='.'){
                            pre=pre->previous;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
        
    }
    if(index==strlen(str) && state==NULL){
        return true;
    }
    return false;
}

bool regularMatch(char* str,char* pattern,int x,int y){
    if(x==strlen(str) && y==strlen(pattern)){
        return true;
    }else if(x<strlen(str) && y<strlen(pattern)){
        if(y+1<strlen(pattern)){
            if(pattern[y+1]=='*'){
                int local_x=x;
                while(str[local_x]==pattern[y] || pattern[y]=='.'){
                    bool current_match=regularMatch(str,pattern,local_x,y+2);
                    if(current_match){
                        return true;
                    } 
                    local_x++; 
                    if(local_x==strlen(str)){
                        bool current_match=regularMatch(str,pattern,local_x,y+2);
                        if(current_match){
                            return true;
                        }else{
                            return false;
                        } 
                    }
                }
                bool current_match=regularMatch(str,pattern,local_x,y+2);
                if(current_match){
                    return true;
                }else{
                    return false;
                }
            }else{
                if(x==strlen(str)){
                    return false;
                }
                if(str[x]==pattern[y] || pattern[y]=='.'){
                    x++;
                    y++;
                    bool local_match=regularMatch(str,pattern,x,y);
                    if(local_match){
                        return true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }else{
            if(str[x]==pattern[y] || pattern[y]=='.'){
                x++;
                y++;
                bool local_match=regularMatch(str,pattern,x,y);
                if(local_match){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }else if(x==strlen(str) && y<strlen(pattern)){
        if(y+1<strlen(pattern)){
            if(pattern[y+1]=='*'){
                bool local_match=regularMatch(str,pattern,x,y+2);
                if(local_match){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
        
    }
    return false;
}

bool match(char* str, char* pattern){
    bool local_match=regularMatch(str,pattern,0,0);
    if(local_match){
        return true;
    }
    return false;
}

int main(){
    char* str="b";
    char* pattern="b.*";
    bool result=match(str,pattern);
    if(result){
        printf("true"); 
    }else{
        printf("false");
    }
    return 0;
}