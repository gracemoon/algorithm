/* 
问题描述：
Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

char * multiply(char * num1, char * num2){
    char* str=(char*)malloc(sizeof(char)*(strlen(num1)+strlen(num2)+1));
    for(int i=0;i<strlen(num1)+strlen(num2)+1;i++){
        str[i]='0';
    }
    int index=strlen(num1);
    for(int i=0;i<strlen(num2);i++){
        char c=num2[i];
        int d=0;
        int k=index;
        for(int j=strlen(num1)-1;j>=0;j--){
            char a=num1[j];
            int b=(a-48)*(c-48)+d+(str[k]-48);
            int e=b%10;
            str[k--]=(char)(e+48);
            d=b/10;
        }
        while(d>0){
            int b=d+(str[k]-48);
            int e=b%10;
            str[k--]=(char)(e+48);
            d=b/10;
        }
        index++;
    }
    str[index]='\0';
    return str;
}

int main(){
    char* num1="123";
    char* num2="456";
    char* str=multiply(num1,num2);
    printf("%s",str);
    return 0;
}