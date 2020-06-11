#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
    public:
        bool isMatched(string s,string p){
            int n=p.length();
            int m=s.length();
            vector<vector<bool>> dp=vector<vector<bool>>(n+1,vector<bool>(m+1,false));
            dp[0][0]=true;
            for(int i=1;i<=n;i++){
                if(i==2 && p[i-1]=='*'){
                    dp[i][0]=true;
                }
                char c=p[i-1];
                if(c=='.'){
                    for(int j=1;j<=m;j++){
                        if(dp[i-1][j-1]==true){
                            dp[i][j]=true;
                        }else{
                            dp[i][j]=false;
                        }
                    }
                }else if(c=='*'){
                    for(int j=1;j<=m;j++){
                        if(dp[i-2][j]==true){
                            dp[i][j]=true;
                        }else if(p[i-2]=='.' || p[i-2]==s[j-1]){
                            int local_c=s[j-1];
                            dp[i][j]=false;
                            int k=j;
                            while(k>0){
                                if(dp[i-2][k-1]==true){
                                    dp[i][j]=true;
                                }
                                if(k>1 && (s[k-2]==local_c || p[i-2]=='.' )){
                                    k--;
                                }else{
                                    break;
                                }
                            }
                        }else{
                            dp[i][j]=false;
                        }
                    }
                }else{
                    for(int j=1;j<=m;j++){
                        if(s[j-1]==c && dp[i-1][j-1]==true){
                            dp[i][j]=true;
                        }else{
                            dp[i][j]=false;
                        }
                    }
                }
            }
            return dp[n][m];
        }
};

int main(){
    Solution solutino;
    string s="ipp";
    string p="p*";
    bool ans=solutino.isMatched(s,p);
    if(ans){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    
    return 0;
}