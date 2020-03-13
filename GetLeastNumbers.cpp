/* 
问题描述：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

解题思路： 

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        input=quickSort(input,0,input.size()-1);
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(input[i]);
        }
        return result;
    };
    vector<int> quickSort(vector<int> arr,int x,int y){
        int i=x;
        int j=y;
        while(i<j){
            if(arr[i]>arr[x] && arr[j]<arr[x]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            if(arr[i]<=arr[x]){
                i++;
            }
            if(arr[j]>=arr[x]){
                j--;
            }
        }
        int temp=arr[j];
        arr[j]=arr[x];
        arr[x]=temp;
        for(int k=0;k<8;k++){
            printf("%d",arr[k]);
        }
        printf("\n");
        if(x<i-1){
            arr=quickSort(arr,x,j-1); 
        }
        if(j+1<y){
            arr=quickSort(arr,j+1,y);  
        }
        return arr;
    }
    
};

int main(){
    Solution s;
    vector<int> array={4,5,1,6,2,7,3,8};
    // array=s.quickSort(array,0,8);
    array=s.GetLeastNumbers_Solution(array,4);
    for(int i=0;i<array.size();i++){
        printf("%d",array[i]);
    }
    return 0;
}
