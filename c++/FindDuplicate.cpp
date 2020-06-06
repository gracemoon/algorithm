/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int findDuplicate(vector<int>& nums) {
        int low=1;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            int count=0;
            for(int num : nums){
                if(num<=mid){
                    count++;
                }
            }
            if(count>mid){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }


    int findDuplicateA(vector<int>& nums) {
        int x=0,y=0;
        do{
            x=nums[x];
            y=nums[nums[y]];
        }while(nums[x]!=nums[y]);
        return nums[x];
    }
};

int main(){
    Solution s;
    return 0;
}
