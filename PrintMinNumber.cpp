/* 
问题描述：
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

解题思路： 
1、首字母最小放在前面。

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
public:
    string PrintMinNumber(vector<int> numbers) {
        string str="";
        return str;
    }
    string FirstChar(int num){
        return to_string(num);
    }

};

int main(){
    // Solution s;
    int i=32;
    string s=to_string(i);
    cout<<"ok"<<endl;
    return 0;
}
