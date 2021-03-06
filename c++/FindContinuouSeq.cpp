/* 
问题描述：
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列?

输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> m;
        for(int i=0;i<sum;i++){
            int local_sum=0;
            int local_i=i+1;
            while(local_sum<sum){
                local_sum+=local_i;
            }
            if(local_sum==sum){
                vector<int> local_vector;
                for(int j=i;j<=local_i;j++){
                    local_vector.push_back(j);
                }
                m.push_back(local_vector);
            }
        }
        return m;
    }
};

int main(){
    Solution s;
    return 0;
}
