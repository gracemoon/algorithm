/* 
问题描述：
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.


The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int maxArea1(int* height, int heightSize){
    int max=-1;
    for(int i=0;i<heightSize-1;i++){
        for(int j=i+1;j<heightSize;j++){
            int local_low=height[i]<height[j]?height[i]:height[j];
            if(local_low*(j-i)>max){
                max=local_low*(j-i);
            }
        }
    }
    return max;
}

int maxArea(int* height, int heightSize){
    int begin=0;
    int end=heightSize-1;
    int max=0;
    while(begin<end){
        int local_low=height[begin]<height[end]?height[begin]:height[end];
        if(local_low*(end-begin)>max){
                max=local_low*(end-begin);
        }
        if(height[begin]<height[end]){
            begin++;
        }else{
            end--;
        }
    }

}

int main(){
    return 0;
}