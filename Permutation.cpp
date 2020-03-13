/* 
问题描述：
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

解题思路： 
1、排列组合。

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    vector<string> Permutation(string str) {
        vector<string> m;       
        string dict_char=str;
        // for(int i=0;i<str.length();i++){
        //     int j=0;
        //     for(;j<dict_char.length();j++){
        //         if(dict_char[j]==str[i]){
        //             break;
        //         }
        //     }
        //     if(j==dict_char.length()){
        //         dict_char=dict_char+str[i];
        //     }
           
        // }
        // cout<<dict_char<<endl;
        for(int i=0;i<dict_char.length();i++){
            char c=dict_char[i];
            string temp=dict_char;
            if(dict_char.length()>1){
                vector<string> rest=Permutation(temp.erase(i,1));
                for(int j=0;j<rest.size();j++){
                    m.push_back(c+rest[j]);
                }
            }else{
                m.push_back(dict_char);
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=i+1;j<m.size();j++){
                if(m[i]==m[j]){
                    m.erase(m.begin()+j,m.begin()+j+1);
                    j--;
                }
            }
        }

        return m;
    }
    string dict(string str){
        string dict_char="";
        for(int i=0;i<str.length();i++){
            int j=0;
            for(;j<dict_char.length();j++){
                if(dict_char[j]==str[i]){
                    break;
                }
            }
            if(j==dict_char.length()){
                dict_char=dict_char+str[i];
            }
           
        }
        return dict_char;
    }

};

int main(){
    string str="abc";
    Solution s;

    // vector<string> t;
    
    // t.push_back("abc");
    // t.push_back("abc");
    // t.push_back("abcd");
    // t.push_back("abc");

    // t.erase(t.begin()+2,t.begin()+3);
    // for(int i=0;i<t.size();i++){
    //     cout<<t[i]<<endl;
    // }
    // string dic_char=s.dict(str);
    // cout<<dic_char<<endl;
    vector<string> permutation=s.Permutation(str);
    for(int i=0;i<permutation.size();i++){
        cout<<i+1<<" : "<<permutation[i]<<endl;
    }
    return 0;
}
