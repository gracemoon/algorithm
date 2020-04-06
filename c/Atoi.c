/* 
问题描述：
https://leetcode.com/problems/string-to-integer-atoi/

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.

Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.

解题思路:
1、int的range是 (-2147483648,2147483647)
2、数字的ASCII是48-57.

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int myAtoi(char * str){
    int i=0;
    int data=0;
    int flag=0;
    int decimal=1;
    int MAX=2147483647;
    int MIN=-2147483648;
    while(i<strlen(str)){
        if(str[i]>=48 && str[i]<=57){
            if(data>MAX/10 || (data==MAX/10 && str[i]-48 >7)){
                return MAX;
            }else if(data<MIN/10 || (data==MIN/10 && str[i]-48 >=8)){
                return MIN;
            }
            if(decimal==1){
                data=data*10+(str[i]-48);
            }else{
                data=-(-data*10)-(str[i]-48);
            }
            flag=1;
            i++;
        }else if(str[i]==' '){
            if(flag==1){
                break;
            }
            i++;
        }else if(str[i]=='-'){
            if(flag==1){
                break;
            }else{
                if(i+1<strlen(str)){
                    if(str[i+1]>=48 && str[i+1]<=57){
                        decimal=-decimal;
                        i++;
                    }else{
                        return 0;
                    }
                }else{
                    return 0;
                }
            }
        }else if(str[i]=='+'){
            if(flag==1){
                break;
            }else{
                if(i+1<strlen(str)){
                    if(str[i+1]>=48 && str[i+1]<=57){
                        i++;
                    }else{
                        return 0;
                    }
                }else{
                    return 0;
                }
            }
        }else{
            if(flag==0){
                return 0;
            }else{
                break;
            }
        }
    }
    return data;
}

int main(){
    char* str="-2147483648";
    int data=myAtoi(str);
    printf("%d",data);
    return 0;
}