/* 
问题描述：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

解题思路:
1、数值的表示方法：正负数(+/-)、科学计数法(e/E)、小数(.)

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isNumeric(char* string)
{
    bool result=false;
    bool scientific=false;
    bool decimal=false;
    int i=0;
    while(i<strlen(string)){
        if(string[i]=='e' || string[i]=='E'){
            if(scientific==false && i<(strlen(string)-1)){
                scientific=true;
                i++;
            }else{
                break;
            } 
        }else if(string[i]=='.'){
            if(decimal==false && scientific==false){
                decimal=true;
                i++;
            }else{
                break;
            } 
        }else if(string[i]=='+' || string[i]=='-'){
            if(i==0 || (string[i-1]=='e' || string[i-1]=='E')){
                i++;
            }else{
                break;
            }
        }else if(string[i]>=48 && string[i]<=57){
            i++;
        }else{
            break;
        }
    }
    if(i==strlen(string)){
        result=true;
    }
    return result;
}

int main(){
    char* string[10]={"+100","5e2","-123","3.1416","-1E-16","12e","1a3.14","1.2.3","+-5","12e+4.3"};
    for(int i=0;i<10;i++){
        bool r=isNumeric(string[i]);
        if(r){
            printf("%s is true\n",string[i]);
        }else{
            printf("%s is false\n",string[i]);
        }
    }
    
    return 0;
}