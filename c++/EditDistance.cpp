/* 
问题描述：


解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> record;
        vector<int> record1;
        for(int i=0;i<=word2.length();i++){
            record1.push_back(i);
        }
        record.push_back(record1);
        for(int i=1;i<=word1.length();i++){
            vector<int> row_record;
            row_record.push_back(i);
            record.push_back(row_record);
            for(int j=1;j<=word2.length();j++){
                int a=0;
                if(word1[i-1]==word2[j-1]){
                    a=record[i-1][j-1];
                }else{
                    a=record[i-1][j-1]+1;
                }  
                int local_max=min(record[i][j-1]+1,record[i-1][j]+1);
                record[i].push_back(min(a,local_max));
            }
        }
        return record[word1.length()][word2.length()];
    }
};

int main(){
    Solution s;
    int ans=s.minDistance("horse","ros");
    cout<<ans<<endl;
    return 0;
}
