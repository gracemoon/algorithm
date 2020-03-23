/* 
问题描述：
统计一个数字在排序数组中出现的次数。

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int sum=0;
        int flag=0;
        for(int i=0;i<data.size();i++){
            if(data[i]==k){
                sum++;
                flag=1;
            }else if(data[i]>k && flag){
                return sum;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    return 0;
}