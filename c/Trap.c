/* 
问题描述：

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

int trap2(int* height, int heightSize){
    int* record=(int*)malloc(sizeof(int)*heightSize);
    int* stack=(int*)malloc(sizeof(int)*heightSize);
    int top=-1;
    int bottom=0;
    for(int i=0;i<heightSize;i++){
        if(top>=bottom){
            int x=bottom;
            while(x<=top && height[stack[x]]>height[i]){
                x++;
            }
            int y;
            if(x>top){
                record[i]=height[i];
            }else{
                y=stack[x]+1;
                while(y<i){
                    record[y]=height[stack[x]];
                    y++;
                } 
                record[i]=height[i];             
            }

        }else{
            record[i]=height[i];
        }
        while(top>=bottom-1){
            if(top==bottom-1 || record[stack[top]]>height[i]){
                stack[++top]=i;
                break;
            }
            top--;
        }
    }
    int sum=0;  
    for(int i=0;i<heightSize;i++){
        printf("%d",record[i]);
        sum=sum+(record[i]-height[i]);
    }
    return sum;
}

int trap1(int* height, int heightSize){
    int* stack=(int*)malloc(sizeof(int)*heightSize);
    int top=-1;
    int sum=0;
    for(int i=0;i<heightSize;i++){
        while(top>=0 && height[i]>height[stack[top]]){
            int pre_top=top;
            top--;
            if(top>=0){
                int distance=i-stack[top]-1;
                int high=height[i]<height[stack[top]]?height[i]-height[stack[pre_top]]:height[stack[top]]-height[stack[pre_top]];
                sum+=(distance*high);
            }
        }
        stack[++top]=i;
    }
    return sum;
}

int trap(int* height, int heightSize){
    int sum=0;
    int x=0;
    int y=heightSize-1;
    int left_max=-1;
    int right_max=-1;
    while(x<y){
        if(height[x]<left_max){
            sum+=(left_max-height[x]);
        }else{
            left_max=height[x];
        }
        if(height[y]<right_max){
            sum+=(right_max-height[y]);
        }else{
            right_max=height[y];
        }
        if(height[x]>height[y]){
            y--;
        }else{
            x++;
        }
    }
    return sum;
}

int main(){
    int m[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans=trap(m,12);
    printf("%d",ans);
    return 0;
}