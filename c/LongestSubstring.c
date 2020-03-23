/* 
问题描述：
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    if(strlen(s)==0){
        return 0;
    }
    int max=1;
    int high=0;
    for(int i=1;i<=strlen(s);i++){
        if(i==strlen(s)){
            max=i-high>max?i-high:max;
        }
        for(int j=high;j<i;j++){
            if(s[i]==s[j]){
                high=j+1;
                max=i-j>max?i-j:max;
                break;
            }
        }
    }
    return max;
}


int main(){
    int m=lengthOfLongestSubstring("abcabcbb");
    printf("%d",m);
    return 0;
}