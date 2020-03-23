/* 
问题描述：
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

int* moveCount(int rows,int cols,int x,int y,int* arr){
    // int m=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d",arr[i*cols+j]);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
    //判断是否已经统计过 && 是否超过阈值
    if(arr[x*cols+y]==1 && x >=0 && x<rows && y>=0 && y<cols){
        // m+=1;
        arr[x*cols+y]=2;
        if(y-1>=0){
            arr=moveCount(rows,cols,x,y-1,arr);
        }
        if(y+1<cols){
            arr=moveCount(rows,cols,x,y+1,arr);
        }
        if(x-1>=0){
            arr=moveCount(rows,cols,x-1,y,arr);
        }
        if(x+1<rows){
            arr=moveCount(rows,cols,x+1,y,arr);
        }
    }
    return arr;
}

int movingCount(int threshold, int rows, int cols)
{
    int* arr=(int*)malloc(sizeof(int)*rows*cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int sum=0;
            int t=i;
            do{
                int b=t%10;
                sum+=b;
                t=t/10;
            }while(t>0);

            t=j;
            do{
                int b=t%10;
                sum+=b;
                t=t/10;
            }while(t>0);
            if(sum<=threshold){
                arr[i*cols+j]=1;
            }else{
                arr[i*cols+j]=0;
            }
            
        }
    }
    arr=moveCount(rows,cols,0,0,arr);
    int count=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i*cols+j]==2){
                count++;
            }
        }
    }
    return count;
}


int main(){

    int res=movingCount(1, 2, 2);
    printf("%d",res);
    return 0;
}