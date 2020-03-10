#include <stdio.h>

int rectCover(int number) {
    int m=0;
    if(number>2){
        m=rectCover(number-1)+rectCover(number-2);
    }else{
        m=number;
    }
    return m;
}


int main(){
    int m;
    for(int i=0;i<10;i++){
        m=rectCover(i);
        printf("the n =%d : %d \n",i,m);
    }
    return 0;
}