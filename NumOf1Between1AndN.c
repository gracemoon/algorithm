/* 
问题描述：
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

解题思路:


*/

#include <stdio.h>
#include <math.h>
int NumberOf1Between1AndN_Solution(int n)
{
    int sum=0;
    int grade=1;
    while(grade<=n){
        int m=0;
        if((grade*10)<=n){
            m=n/(grade*10);
        }
        int l=n%grade;
        int k=0;
        if((n%(grade*10))/grade>1){
            if(grade==1){
                k=1;
            }else{
                k=grade;
                
            }
            sum=sum+(m*grade)+k;
        }else if((n%(grade*10))/grade==1){
            sum=sum+(m*grade)+l+1; 
        }else{
            sum=sum+(m*grade); 
        }
        grade=grade*10;
    }
    return sum;
}

int main(){
    int n=111;
    int m=NumberOf1Between1AndN_Solution(n);
    printf("%d ------ %d",n,m);
    return 0;
}