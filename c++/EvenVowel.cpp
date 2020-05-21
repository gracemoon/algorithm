/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int findTheLongestSubstring(string s) {
        int ans=0;
        int index=0;
        int status=0;
        vector<int> pos(1<<5,-1);
        pos[0]=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                status^=(1<<0);
            }else if(s[i]=='e'){
                status^=(1<<1);
            }else if(s[i]=='i'){
                status^=(1<<2);
            }else if(s[i]=='o'){
                status^=(1<<3);
            }else if(s[i]=='u'){
                status^=(1<<4);
            }
            if(~pos[status]){
                ans=max(ans,i+1-pos[status]);
            }else{
                pos[status]=i+1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    // int ans=s.findTheLongestSubstring("eleetminicoworoep");
    int ans=-1;
    cout<<~ans<<endl;
    if(~ans){
        cout<<"ok";
    }
    return 0;
}
