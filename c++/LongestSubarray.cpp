/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        int n=nums.size();
        multiset<int> ms;
        for(int L=0,R=0;L<n;L++){
            while(R<n){
                ms.insert(nums[R]);
                if(*ms.rbegin()-*ms.begin()>limit){
                    ms.erase(ms.find(nums[R]));
                    break;
                }
                R++;
            }
            ans=max(R-L,ans);
            ms.erase(ms.find(nums[L]));
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> m={8,2,4,7};
    int limit=4;
    int ans=s.longestSubarray(m,limit);
    cout<<ans<<endl;
    return 0;
}
