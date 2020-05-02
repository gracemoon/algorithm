/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set1;
        for(int num:nums){
            set1.insert(num);
        }
        int max=0;
        for(int num:nums){
            int x=num;
            int local_max=0;
            while(set1.find(x)!=set1.end()){
                local_max++;
                x++;
            }
            if(max<x){
                max=x;
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    return 0;
}
