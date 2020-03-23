/* 
问题描述：
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
        {[2,3,4],2,6,2,5,1}， 
        {2,[3,4,2],6,2,5,1}， 
        {2,3,[4,2,6],2,5,1}， 
        {2,3,4,[2,6,2],5,1}， 
        {2,3,4,2,[6,2,5],1}， 
        {2,3,4,2,6,[2,5,1]}。

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)    {
        vector<int> m;
        if(size<=0 || size > num.size()){
            return m;
        }else if(size==num.size()){
            int max=num[0];
            for(int i=0;i<num.size();i++){
                if(num[i]>max){
                    max=num[i];
                }
            }
            m.push_back(max);
        }else{
            int local_max=num[0];
            int local_max_index=-1;
            int window_low=0;
            int window_high=window_low+size-1;
            while(window_high<num.size()){
                if(local_max_index>=window_low){
                    if(num[window_high]>=local_max){
                        m.push_back(num[window_high]);
                        local_max_index=window_high;
                        local_max=num[window_high];
                    }else{
                        m.push_back(local_max);
                    }
                }else{
                    local_max=num[window_low];
                    local_max_index=window_low;
                    for(int i=window_low;i<=window_high;i++){
                        if(num[i]>=local_max){
                            
                            local_max=num[i];
                            local_max_index=i;
                        }
                    }
                    m.push_back(local_max);
                }
                window_high++;
                window_low++;                
            }
        }
        return m;
    }
};

int main(){
    Solution s;
    vector<int> m={2,3,4,2,6,2,5,1};
    // for(int i=0;i<8;i++){
    //     m.push_back(i);
    // }
    vector<int> res=s.maxInWindows(m,3);
    for(int j=0;j<res.size();j++){
        cout<<res[j]<<endl;
    }
    return 0;
}
