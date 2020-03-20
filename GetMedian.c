/* 
问题描述：
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>

int arr[256]={0};
int count=0;

void quickSort(int x,int y){
    int i=x;
    int j=y;
    while(i<=j){
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
    // for(int k=0;k<10;k++){
    //     printf("%d",arr[k]);
    // }
    // printf("\n");
    if(x<j-1){
       quickSort(x,j-1); 
    }
    if(j+1<y){
       quickSort(j+1,y);  
    }
    
}



void Insert(int num){
    arr[count++]=num;
    // printf("%d\n",arr[count-1]);
}

double GetMedian(){ 
    if(count-1>0){
        quickSort(0,count-1);
    }
    
    for(int j=0;j<count;j++){
        printf("%d",arr[j]);
    }
    printf("\n");
    double medianNum;
    if(count%2==0){
        medianNum=(double)(arr[count/2-1]+arr[count/2])/2;
    }else{
        medianNum=(double)arr[(count-1)/2];
    }
    return medianNum;
}

int main(){
    int m[9]={5,2,3,4,1,6,7,0,8};
    for(int i=0;i<9;i++){
        Insert(m[i]);
        printf("%f\n",GetMedian());
    }
    
    return 0;
}