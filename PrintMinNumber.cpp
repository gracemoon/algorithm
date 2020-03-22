/* 
问题描述：
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

解题思路： 
1、首字母最小放在前面。

*/

#include <iostream>
#include <vector>
#include <string>
// #include <sstream> 

using namespace std;


class Solution{
public:
    string intToString(int num){
        string s="";
        string index="0123456789";
        do{
            int b=num%10;
            s+=index[b];
            num=num/10;
        }while(num>0);
        for(int i=0,j=s.length()-1;i<j;i++,j--){
            int t=s[i];
            s[i]=s[j];
            s[j]=t;
        }
        return s;
    }
    double vectorToInt(vector<int> number){
        double m=0;
        int index=0;
        for(int i=number.size()-1;i>=0;i--){
            double local=(double)number[i];
            for(int j=0;j<index;j++){
                local*=10;
            }
            m+=local;
            string local_s=intToString(number[i]);
            index+=local_s.length();
        }
        return m;
    }

    string PrintMinNumber(vector<int> numbers) {
        for(int i=0;i<numbers.size();i++){
            for(int j=0;j<numbers.size()-i-1;j++){
                double t=this->vectorToInt(numbers);
                int temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
                double t1=this->vectorToInt(numbers);
                if(t1>t){
                    int temp=numbers[j];
                    numbers[j]=numbers[j+1];
                    numbers[j+1]=temp;
                }
            }
        }
        // double m=vectorToInt(numbers);
        // cout<<m<<endl;
        string str="";
        for(int i=0;i<numbers.size();i++){
            str+=intToString(numbers[i]);
        }
        return str;
    }
};

int main(){
    Solution s;
    vector<int> numbers={3334,3,3333332};
    cout<<s.PrintMinNumber(numbers)<<endl;
    return 0;
}
