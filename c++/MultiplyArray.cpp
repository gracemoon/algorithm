/* 
问题描述：
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        for(int i=0;i<A.size();i++){
            int low;
            int high;
            if(i==0){
                low=1;
                high=A.size()-1;
            }else if(i==A.size()-1){
                low=0;
                high=A.size()-2;
            }else{
                low=0;
                high=A.size()-1;
            }
            int t=1;
            for(int j=low;j<=high;j++){
                if(j!=i){
                    t*=A[j];
                }
            }
            B.push_back(t);
        }
        return B;
    }
};

int main(){
    Solution s;
    vector<int> A={1,2,3,4,5};
    vector<int> B=s.multiply(A);
    for(int i=0;i<B.size();i++){
        cout<<B[i]<<", ";
    }
    return 0;
}
