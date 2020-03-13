/* 
问题描述：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

解题思路:
1、栈是先进后出，队列是先进先出。

*/

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        int head=stack1.top();
        stack1.pop();
        return head;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution s1;
    for(int i=0;i<10;i++){
        s1.push(i);
    }
    for(int i=0;i<10;i++){
        cout<<s1.pop();
    }

    return 0;
}

