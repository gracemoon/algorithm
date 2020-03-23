/* 
问题描述：
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

解题思路:
1、二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）
它或者是一棵空树，或者是具有下列性质的二叉树： 
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 
它的左、右子树也分别为二叉排序树。

*/

// #include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0){
            return false;
        }
        bool res=true;
        for(int i=0;i<sequence.size();i++){
            cout<<sequence[i]<<endl;
            bool left=true;
            if(i==0){
                left=true;
            }else{
                int low_big[2]={0,0};
                for(int j=0;j<i;j++){
                    if(low_big[1]==0 && sequence[j]<sequence[i]){
                        low_big[0]=1;
                    }else if(sequence[j]>=sequence[i]){
                        low_big[1]=1;
                    }else{
                        left=false;
                        break;
                    }
                }
            }
            bool right=true;
            // if(i==(sequence.size()-1)){
            //     right=true;
            // }else{
            //     for(int j=i+1;j<sequence.size();j++){
            //         if(sequence[j]<=sequence[i] && j>i+1){
            //             right=false;
            //             break;
            //         }
            //     }
            // }
            if(left==false || right==false){
                res=false;
                break;
            }
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<int> sequence={4,8,6,12,16,14,10};
    // for(int i=0;i<sequence.size();i++){
    //     cout<<sequence[i]<<", ";
    // }
    cout<<s.VerifySquenceOfBST(sequence)<<endl;
    return 0;
}