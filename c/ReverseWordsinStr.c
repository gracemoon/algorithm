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

void reverseString(char* s,int low,int high){
    int x=low;
    int y=high-1;
    while(x<y){
        char t=s[x];
        s[x]=s[y];
        s[y]=t;
        x++;
        y--;
    }
}

char * reverseWords(char * s){
    int x=0;
    int y=0;
    while(y<=strlen(s)){
        if(s[y]==' ' || y==strlen(s)){
            reverseString(s,x,y);
            x=y;
        }
        y++;
    }
    return s;
}


int main(){
    char m[]={'h','e','l','l','o'};
    // reverseString(m,5);
    printf("%s",m);
    return 0;
}