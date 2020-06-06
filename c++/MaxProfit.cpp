/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        vector<vector<int>> dp=vector<vector<int>>(k+1,vector<int>(2,0));

        for(int i=0;i<prices.size();i++){
            if(i==0){
                dp[0][0]=0;
                dp[0][1]=-prices[0];
                for(int j=1;j<=k;j++){
                    dp[j][0]=0;
                    dp[j][1]=-1e6;
                }
            }else{
                dp[0][0]=0;
                dp[0][1]=max(dp[0][1],-prices[i]);
                for(int j=1;j<=k;j++){
                    dp[j][0]=max(dp[j][0],dp[j-1][1]+prices[i]);
                    dp[j][1]=max(dp[j][1],dp[j][0]-prices[i]);
                }
            }
        }
        int ans=-1e6;
        for(int i=0;i<=k;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    return 0;
}
