/* 
问题描述：
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

解题思路:


*/

#include <stdio.h>
#include <string.h>

void replaceSpace(char *str,int length) {
    char s[3*length];
    int j=0;
    for(int i=0;i<length;i++){
        printf("%c\n",str[i]);
        if(str[i]==32){
            s[j++]='%';
            s[j++]='2';
            s[j++]='0';
        }else{
            s[j++]=str[i];
        }
    }
    strcpy(str,s);
}

int main(){
    char str1[80]="ab cd ef";
    for(int i=0;i<strlen(str1);i++){
        printf("the n = %d : %c \n",i,str1[i]);
    }
    replaceSpace(str1,strlen(str1));
    for(int i=0;i<strlen(str1);i++){
        printf("the n = %d : %c \n",i,str1[i]);
    }
    return 0;
}