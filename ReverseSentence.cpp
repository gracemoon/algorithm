/* 
问题描述：
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    string ReverseSentence(string str) {
        vector<string> splits;
        string m;
        int i=0,j=0;
        for(;j<str.length();j++){
            if(str[j]==32){
                splits.push_back(str.substr(i,(j-i)));
                i=j+1;
            }
            
        }
        if(j==str.length()){
            splits.push_back(str.substr(i,(j-i)));
        }
        for(int i=0,j=splits.size()-1;i<j;i++,j--){
            string c=splits[i];
            splits[i]=splits[j];
            splits[j]=c;
        }
        for(int i=0;i<splits.size();i++){
            if(i!=0){
                m+=" ";
            }
            m+=splits[i];
        }
        return m;
    }
};

int main(){
    Solution s;
    string str="I am a student.";
    cout<<s.ReverseSentence(str);
    return 0;
}
