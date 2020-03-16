/* 
问题描述：

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> m;
        for(int i=0,j=array.size()-1;i<j;){
            int current_sum=array[i]+array[j];
            if(current_sum==sum){
                m.push_back(array[i]);
                m.push_back(array[j]);
                return m;
            }else if(current_sum>sum){
                j--;
            }else if(current_sum<sum){
                i++;
            }
            
        }
        return m;
    }
};

int main(){
    Solution s;
    vector<int> array={1,2,3,4,5,6,7,8,9};
    vector<int> m=s.FindNumbersWithSum(array,9);
    cout<<m[0]<<"----"<<m[1]<<endl;
    return 0;
}
