/* 
问题描述：
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。


解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

void quickSort(int** envelops,int low,int high){
    int x=low+1;
    int y=high;
    while(x<=y){
        if(envelops[x][0]<=envelops[0][0]){
            x++;
        }
        if(envelops[y][0]>=envelops[0][0]){
            y--;
        }
        if(envelops[x][0]>envelops[0][0] && envelops[y][0]<envelops[0][0]){
            int* temp=envelops[x][0];
            envelops[x][0]=envelops[y][0];
            envelops[y][0]=temp;
        }
    }
    int* temp=envelops[y][0];
    envelops[y][0]=envelops[0][0];
    envelops[0][0]=temp;
    if(y-1>low){
        quickSort(envelops,low,y-1);
    }
    if(high>x){
        quickSort(envelops,x,high);
    }
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    if(envelopesSize==0){
        return 0;
    }
    for(int i=0;i<envelopesSize;i++){
        envelopesColSize[i]=2;
    }
    quickSort(envelopes,0,envelopesSize-1);
    int max;
    max=1;
    int* record=(int*)malloc(sizeof(int)*envelopesSize);
    record[0]=1;
    for(int i=1;i<envelopesSize;i++){
        int local_max=1;
        for(int j=0;j<i;j++){
            if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                if(local_max<record[j]+1){
                    local_max=record[j]+1;
                }
            }
        }
        record[i]=local_max;
        if(max<local_max){
            max=local_max;
        }
    }
    return max;
}

int main(){
    int m;
    for(int i=0;i<10;i++){

        printf("the n = %d : %d \n",i,m);
    }
    return 0;
}