/* 
问题描述：
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

Example:

Input: 4
Output: false 
Explanation: If there are 4 stones in the heap, then you will never win the game;
            No matter 1, 2, or 3 stones you remove, the last stone will always be 
            removed by your friend.

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

bool removeStone(int n,int who){
    if(n<=3 && who==0){
        return true;
    }else if(n<=3 && who==1){
        return false;
    }else{
        who=(who+1)%2;
        for(int i=1;i<4;i++){
            bool a=removeStone(n-i,who);
            if(a){
                return true;
            }
        }
    }
    return false;
}

bool canWinNim(int n){
    return removeStone(n,0);
}

int main(){
    int m=4;
    int a=canWinNim(m);
    return 0;
}