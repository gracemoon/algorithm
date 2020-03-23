/* 
问题描述：
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

解题思路:


*/

#include <stdio.h>
#include <malloc.h>
#include <vector> 

using namespace std;

typedef struct Node{
    int value;
    struct Node* next;
}Node;

int primeJudge(int num){
    int i=2;
    while(i*2<=num){
        int a=num%i;
        if(a==0){
            return 0;
        }else{
            i++;
        } 
    }
    return num;
}

int GetUglyNumber_Solution(int index) {
    int num=1;
    Node* prime=NULL;
    Node* p=prime;
    while(index){
        if(num==1){
            num++;
            index--;
        }else{
            if(primeJudge(num)>0){
                Node* n=(Node*)malloc(sizeof(Node));
                n->value=num;
                n->next=NULL;
                if(prime==NULL){
                    prime=p=n;
                }else{
                    p->next=n;
                    p=n;
                }
            } 
            Node* q=prime;
            while(q){
                printf("prime : %d\n",q->value);
                int a=num%(q->value);
                if(a==0 && q->value>5){
                    break;
                }else{
                    q=q->next;
                }
            }
            if(q==NULL){
                index--;
            }
            num++;
        }
    }
    return num-1;
}

int minNum(int a,int b,int c){
    int d=a;
    if(b<d){
        d=b;
    }
    if(c<d){
        d=c;
    }
    return d;
}

int GetUglyNumber(int index){
    vector<int> arr;
    int p1=0,p2=0,p3=0;
    int local_min=1;
    arr.push_back(local_min);
    while(arr.size()<index){
        local_min=minNum(arr[p1]*2,arr[p2]*3,arr[p3]*5);
        if(arr[p1]*2==local_min){
            p1++;
        }
        if(arr[p2]*3==local_min){
            p2++;
        }
        if(arr[p3]*5==local_min){
            p3++;
        }
        arr.push_back(local_min);
    }
    return local_min;
}

int main(){
    int m=1500;
    int a=GetUglyNumber(m);
    printf("%d",a);
    return 0;
}