/* 
问题描述：


解题思路： 

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct MinStack{
    struct MinStack* next;
    int min;
    int value;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* minStack=(MinStack*)malloc(sizeof(MinStack));
    minStack->next=NULL;
    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    MinStack* node=(MinStack*)malloc(sizeof(MinStack));
    node->next=NULL;
    node->value=x;
    if(obj->next==NULL){
        node->min=x;
        obj->next=node;
    }else{
        if(obj->next->min<x){
            node->min=obj->next->min;
        }else{
            node->min=x;
        }
        node->next=obj->next;
        obj->next=node;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->next!=NULL){
        obj->next=obj->next->next;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->next==NULL){
        return -1;
    }
    return obj->next->value;
}

int minStackGetMin(MinStack* obj) {
    if(obj->next==NULL){
        return -1;
    }
    int min=obj->next->min;
    return min;
}

void minStackFree(MinStack* obj) {
    MinStack* p;
    while(obj){
        p=obj->next;
        free(obj);
        obj=p;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

int main(){
    MinStack* obj = minStackCreate();
    // MinStack* node=(MinStack*)malloc(sizeof(MinStack));
    // node->next=NULL;
    // node->value=1;
    // obj=node;
    minStackPush(obj,-2);
    minStackPush(obj,0);
    minStackPush(obj,-3);
    int a=minStackGetMin(obj);
    
    minStackFree(obj);
    return 0;
}
