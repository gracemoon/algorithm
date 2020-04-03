
/* 
问题描述：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
即输出P%1000000007

输入描述:
题目保证输入的数组中没有的相同的数字, 数据范围：
    对于%50的数据,size<=10^4
    对于%75的数据,size<=10^5
    对于%100的数据,size<=2*10^5

示例1:
    输入 > 1,2,3,4,5,6,7,0
    输出 > 7

解题思路： 
1、使用归并排序。



*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    long sum;
    vector<int> MergeSort(vector<int> data){
        if(data.size()==2){
            if(data[0]>data[1]){
                int temp=data[0];
                data[0]=data[1];
                data[1]=temp;
                this->sum++;
            }
        }else{
            unsigned int mid=data.size()/2;
            vector<int> left;
            for(unsigned int i=0;i<mid;i++){
                left.push_back(data[i]);
            }
            if((mid-0)>1){
                left=MergeSort(left);
            }
            vector<int> right;
            for(unsigned int i=mid;i<data.size();i++){
                right.push_back(data[i]);
            }
            if((data.size()-mid)>1){
                right=MergeSort(right);
            }
            unsigned int x=0;
            unsigned int y=0;
            unsigned int i=0;
            while(x<left.size() || y<right.size()){
                if(x==left.size()){
                    data[i++]=right[y];
                    y++;
                }else if(y==right.size()){
                    data[i++]=left[x];
                    x++;
                }else{
                    if(left[x]>right[y]){
                        data[i++]=right[y];
                        this->sum+=(left.size()-x);
                        y++;
                    }else{
                        data[i++]=left[x];
                        x++;
                    }
                }
                
            }
        }
        return data;
    }
    int InversePairs(vector<int> data) {
        this->sum=0;
        if(data.size()<2){
            return 0;
        }
        MergeSort(data);
        return sum;
    }
};

int main(){
    Solution s;

    vector<int> data={364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
    // vector<int> data={1,2,3,4,7,6,5,0};
    s.InversePairs(data);
    cout<<s.sum<<endl;
    return 0;
}
