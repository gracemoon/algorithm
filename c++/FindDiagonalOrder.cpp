/* 
问题描述：
给你一个列表 nums ，里面每一个元素都是一个整数列表。请你依照下面各图的规则，按顺序返回 nums 中对角线上的整数。

 

示例 1：



输入：nums = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,4,2,7,5,3,8,6,9]
示例 2：



输入：nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
输出：[1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
示例 3：

输入：nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
输出：[1,4,2,5,3,8,6,9,7,10,11]
示例 4：

输入：nums = [[1,2,3,4,5,6]]
输出：[1,2,3,4,5,6]
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
nums 中最多有 10^5 个数字。

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> arr;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(i+j>=arr.size()){
                    vector<int> temp;
                    arr.push_back(temp);
                }
                arr[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            for(int j=arr.size()-1;j>=0;j--){
                ans.push_back(arr[i][j]);
            }
        }
        return ans;
    }
    
};

int main(){
    Solution s;
    return 0;
}
