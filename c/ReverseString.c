/* 
问题描述：
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

void reverseString(char* s, int sSize){
    int x=0;
    int y=sSize-1;
    while(x<y){
        char t=s[x];
        s[x]=s[y];
        s[y]=t;
        x++;
        y--;
    }
}

int main(){
    char m[]={'h','e','l','l','o'};
    reverseString(m,5);
    printf("%s",m);
    return 0;
}