#include <iostream>

using namespace std;


class Solution {
public:
    int getDigit(char c){
        
        int i=2;
        if(c==' '){
            i=0;
        }else if(c>=48 && c<=57){
            i=1;
        }else if(c=='+' || c=='-'){
            i=3;
        }
        cout<<i<<endl;
        return i;
    }
    int myAtoi(string str) {
        //有限状态自动机DFA
        //start:0
        // signed=1
        // number=2
        // end: 3
        long long ans=0;
        vector<vector<int>> table=vector<vector<int>>(4,vector<int>(4,0));
        // 0 : 空格
        // 1 : 数值
        // 2 : 其他字符
        // 3 : 符号
        table[0][0]= 0;
        table[0][1]= 2;
        table[0][2]= 3;
        table[0][3]= 1;
        table[1][0]= 3;
        table[1][1]= 2;
        table[1][2]= 3;
        table[1][3]= 3;
        table[2][0]= 3;
        table[2][1]= 2;
        table[2][2]=3;
        table[2][3]=3;
        table[3][0]= 3;
        table[3][1]= 1;
        table[3][2]= 3;
        table[3][3]= 3;

        int state=0;
        int sign=1;
        for(char c: str){
            int i=getDigit(c);
            state=table[state][i];
            if(state==3){
                break;
            } 
            if(i==3){
                if(c=='-'){
                   sign=-sign; 
                }
            }else if(i==1){
                ans=ans*10+(long long)(c-48);
                if(ans>INT_MAX){
                    break;
                }
            }

        }
        if(sign==-1){
            ans=-ans;
        }
        ans=max((long long)INT_MIN,ans);
        ans=min((long long)INT_MAX,ans);
        
        return ans;
    }
};

int main(){
    
    return 0;
}