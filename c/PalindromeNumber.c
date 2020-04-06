/* 
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    //重点在于将数字倒过来比较是否相等
    int n=x;
    // int MAX=2147483647;
    int m=0;
    while(n>=10){
        // if(m>MAX/10 || (m==MAX/10 && n%10>7)){
        //     x=x/10;
        //     break;
        // }
        m=m*10+n%10;
        n=n/10;
    }
    
    if(x/10==m){
        return true;
    }
    return false;
}

int main(){
    int m=2022552202;
    bool b=isPalindrome(m);
    if(b){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}