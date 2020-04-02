/* 
问题描述：
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>

char char_list[256];
int index=0;
//Insert one char from stringstream
void Insert(char ch){
    char_list[index++]=ch;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce(){
    char char_list_local[256];
    for(int i=0;i<256;i++){
        char_list_local[i]=char_list[i];
    }
    for(int i=0;i<index;i++){
        if(char_list[i]==' '){
            continue;
        }
        int j=i+1;
        for(;j<index;j++){
            if(char_list[i]==char_list[j]){
                char_list[j]=' ';
                break;
            }
        }
        if(j==index){
            return char_list[i];
        }
    }
    return '#';
}

int main(){
    
    return 0;
}