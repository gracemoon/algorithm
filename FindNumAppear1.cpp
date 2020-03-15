/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        vector<int> index;
        for(int i=0;i<data.size();i++){
            int j=0;
            for(;j<data.size();j++){
                if(data[i]==data[j] && i!=j){
                    break;
                }
            }
            if(j==data.size()){
                index.push_back(i);
            }
        }
        num1=&data[index[0]];
        num2=&data[index[1]];
    }
};

int main(){
    Solution s;
    vector<int> data={2,4,3,6,3,2,5,5};
    int* num1;
    int* num2;
    s.FindNumsAppearOnce(data,num1,num2);
    cout<<*num1<<endl;
    cout<<*num2<<endl;
    return 0;
}