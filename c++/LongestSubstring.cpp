/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> map1;
        int ans=0;
        int end=-1;
        for(int i=0;i<s.length();i++){
            if(map1.find(s[i])==map1.end()){
                map1[s[i]]=i;
            }else{
                if(map1[s[i]]>end){
                    end=map1[s[i]];
                }
                map1[s[i]]=i;
            }
            if(ans<(i-end)){
                ans=i-end;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    int ans=s.lengthOfLongestSubstring("");
    cout<<ans<<endl;
    return 0;
}
