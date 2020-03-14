/* 
问题描述：
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int local_sum=0;
        int sum=0;
        for(int i=0;i<array.size();i++){
            
            local_sum+=array[i];
            if(local_sum<0){
                if(local_sum-array[i]>sum){
                    sum=local_sum-array[i];
                }
                local_sum=0;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> array={6,-3,-2,7,-15,1,2,2};
    cout<<s.FindGreatestSumOfSubArray(array)<<endl;
    return 0;
}
