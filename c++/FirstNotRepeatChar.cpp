/* 
问题描述：
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

解题思路:


*/

#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
    char c;
    int i;
    int count;
    struct Node* next;
}Node;

class Solution{
public:
    int FirstNotRepeatingChar(string str) {
        Node* h=(Node*)malloc(sizeof(Node));
        h->next=NULL;
        for(int i=0;i<str.size();i++){
            Node* p=h->next;
            Node* q=h;
            while(p){
                if(p->c==str[i]){
                    p->count+=1;
                    break;
                }else{
                    q=p;
                    p=p->next;
                }
            }
            if(p==NULL){
                Node* n=(Node*)malloc(sizeof(Node));
                n->c=str[i];
                n->i=i;
                n->count=1;
                n->next=NULL;
                q->next=n;
            }
        }
        int index=-1;
        Node* p=h->next;
        while(p){
            if(p->count==1){
                index=p->i;
                break;
            }else{
                p=p->next;
            }
        }
        return index;
    }
};


int main(){
    Solution s;
    string str="googgle";
    cout<<s.FirstNotRepeatingChar(str)<<endl;
    return 0;
}