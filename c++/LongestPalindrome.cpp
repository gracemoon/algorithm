/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    string longestPalindrome(string s) {
        
        vector<vector<int>> record;
        record.push_back(vector<int>(s.length(),1));
        int start=0;
        int end=0;
        for(int i=1;i<s.length();i++){
            record.push_back(vector<int>(s.length()-i,0));
            int x=0;
            int y=x+i;
            while(y<s.length()){
                if(i>2){
                    if(record[i-2][x+1]>0 && s[x]==s[y]){
                        record[i][x]=record[i-2][x+1]+2;
                        if(i>(end-start)){
                            end=y;
                            start=x;
                        }
                    }
                }else{
                    if(s[x]==s[y]){
                        record[i][x]=i+1;
                        if(i>(end-start)){
                            end=y;
                            start=x;
                        }
                    }
                }
                x++;y++;
            }
        }

        string ans=s.substr(start,end-start+1);
        return ans;
    }
};

int main(){
    Solution s;
    string ans=s.longestPalindrome("cabbbbad");
    cout<<ans;
    return 0;
}
