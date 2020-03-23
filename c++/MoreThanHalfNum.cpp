/* 
问题描述：
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int m=0;
        int arr[numbers.size()]={0};
        for(int i=0;i<numbers.size();i++){
            ++arr[numbers[i]];
            if(arr[numbers[i]]>numbers.size()/2){
                m=numbers[i];
                break;
            }
        }

        return m;
    }
};

int main(){
    Solution s;
    vector<int> num={1,2,3,2,2,2,5,4,2,3,3,3,3,3,3,3,3};
    cout<<s.MoreThanHalfNum_Solution(num);
    return 0;
}
