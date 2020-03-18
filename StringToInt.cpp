/* 
问题描述：
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0

输入描述:
输入一个字符串,包括数字字母符号,可以为空

输出描述:
如果是合法的数值表达则返回该数字，否则返回0

解题思路:


*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution{
public:
    int charConvertToInt(char c){
        switch(c){
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
        }
        return -1;
    }
    int StrToInt(string str) {
        int neg=0;
        string all_num="";
        for(int i=0;i<str.length();i++){
            if(str[i]=='-' && i==0){
                neg=1;
            }else if(str[i]=='+'){
                continue;
            }else if(str[i]>=48 && str[i]<=57){
                all_num+=str[i];
            }else{
                return 0;
            }
        }
        unsigned int num=0;
        for(int i=all_num.length()-1;i>-1;i--){
            int local_number=charConvertToInt(all_num[i]);
            if(local_number!=-1){
                for(int k=0;k<all_num.length()-i-1;k++){
                    local_number=local_number*10;
                }
                int local=local_number;
                num=num+local;
            }else{
                return 0;
            }
        }
        if(neg==1 && num>2147483648){
            return 0;
        }else if(neg==1 && num<=2147483648){
            num=-(int)num;
        }else if(neg==0 && num>2147483647){
            return 0;
        }else{
            num=(int)num;
        }
        return num;
    }
};


int main(){
    Solution s;
    int num=s.StrToInt("2147483648");
    cout<<num<<endl;
    return 0;
}