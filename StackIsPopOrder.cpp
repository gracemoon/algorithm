/* 
问题描述：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

解题思路:


*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> stk;
    int x=0;
    int y=0;
    while(true){
        if(!stk.empty()){
            if(stk.top()==popV[y]){
                stk.pop();
                y++;
                continue;
            } 
        }
        if(x==pushV.size()){
            break;
        }else{
            stk.push(pushV[x]);
            x++;
        }
        
    }
    return stk.empty();
}


int main(){
    int a[5] = { 1, 2, 3, 4, 5 };
    int b[5] = { 4, 5, 3, 2, 1 };
    // int b[5] = { 4, 3, 5, 1, 2 };
    vector<int> pushV(a,a+5);
    vector<int> popV(b,b+5);
    cout<<IsPopOrder(pushV,popV)<<endl;
    return 0;
}