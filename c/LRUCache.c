/* 
问题描述：
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ //);

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

// 解题思路:


// */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

typedef struct Node{
    int key;
    int value;
    struct Node* next;
    struct Node* pre;
}Node;

typedef struct LRUCache{
    int capacity;
    struct Node* top;
    struct Node* current;
    struct Node* tail;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* lruCache=(LRUCache*)malloc(sizeof(LRUCache));
    lruCache->capacity=capacity;
    lruCache->top=lruCache->tail=lruCache->current=NULL;
    for(int i=0;i<capacity;i++){
        Node* node=(Node*)malloc(sizeof(Node));
        node->key=-1; 
        node->value=-1; 
        node->pre=NULL; 
        node->next=NULL; 
        if(lruCache->top==NULL){
            lruCache->top=lruCache->tail=lruCache->current=node;
        }else{
            lruCache->tail->next=node;
            node->pre=lruCache->tail;
            lruCache->tail=node;
        }
    }
    
    return lruCache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* p=obj->top;
    int m=-1;
    while(p!=NULL && p!=obj->current){
        if(p->key==key){
            m=p->value;
            if(p!=obj->top){
                if(p->pre!=NULL){
                    p->pre->next=p->next;
                }
                if(p->next!=NULL){
                    p->next->pre=p->pre;
                }
                if(p==obj->tail){
                    obj->tail=obj->tail->pre;
                }
                p->pre=NULL;
                p->next=obj->top;
                obj->top->pre=p;
                obj->top=p;
            }
            
            break;
        }
        p=p->next;
    }
    return m;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* insert;
    Node* current=obj->top;
    while(current!=NULL){
        if(current->key==key || current==obj->current){
            break;
        }
        current=current->next;
    }
    if(current->key==obj->current){
        if(obj->current==obj->tail->next){
            insert=obj->tail;
            if(obj->tail!=obj->top){
                obj->tail->pre->next=obj->tail->next;
                obj->tail=obj->tail->pre;
                insert->key=key;
                insert->value=value;
                insert->next=obj->top;
                insert->pre=NULL;
                obj->top->pre=insert;
                obj->top=insert;
            }else{
                insert->key=key;
                insert->value=value;
            }
        }else if(obj->current==obj->top){
            obj->current=obj->current->next;
            obj->top->key=key;
            obj->top->value=value;
        }else{
            insert=obj->current;
            obj->current->pre->next=obj->current->next;
            if(obj->current->next!=NULL){
                obj->current->next->pre=obj->current->pre;
            }
            if(obj->current==obj->tail){
                obj->tail=obj->tail->pre;
            }
            obj->current=obj->current->next;
            insert->key=key;
            insert->value=value;
            insert->next=obj->top;
            insert->pre=NULL;
            obj->top->pre=insert;
            obj->top=insert;
        }
    }else{
        Node* p=current;
        p->value=value;
        if(p!=obj->top){
            if(p->pre!=NULL){
                p->pre->next=p->next;
            }
            if(p->next!=NULL){
                p->next->pre=p->pre;
            }
            if(p==obj->tail){
                obj->tail=obj->tail->pre;
            }
            p->pre=NULL;
            p->next=obj->top;
            obj->top->pre=p;
            obj->top=p;
        }
    }

}

void lRUCacheFree(LRUCache* obj) {
    Node* p=obj->top->next;
    while(p!=obj->current){
        Node* q=p->pre;
        free(q);
        p=p->next;
    }
    free(obj->tail);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

int main(){
    LRUCache* cache = lRUCacheCreate(1);
    lRUCacheGet(cache,0);
    // lRUCachePut(cache,1, 1);
    // lRUCachePut(cache,2, 2);
    // lRUCacheGet(cache,1);
    // lRUCachePut(cache,3, 3);
    // lRUCacheGet(cache,2);
    // lRUCachePut(cache,4, 4);
    // lRUCacheGet(cache,1);
    // lRUCacheGet(cache,3);
    // lRUCacheGet(cache,4);
    return 0;
}