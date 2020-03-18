/* 
问题描述：
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。
其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,
并且不再回到圈中,从他的下一个小朋友开始,
继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

如果没有小朋友，请返回-1

解题思路:


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int LastRemaining_Solution(int n, int m){
        int l=0;
        if(n==0){
            return -1;
        }
        vector<int> p;
        for(int i=0;i<n;i++){
            p.push_back(i);
        }
        int d=0;
        int r=m;
        int flag=0;
        while(p.size()>1){
            if(r==1 && d==p.size()){
                r=m;
                d=0;
                p.erase(p.begin()+d);
            }else if(r==1 && d!=p.size()){
                r=m;
                p.erase(p.begin()+d);
            }else if(r!=1 &&d==p.size()){
                d=0;
            }else{
                r--;
                d++; 
            }
           
        }
        l=p[0];
        return l;
    }
};


int main(){
    int n=0;
    int m=0;
    Solution s;
    int l=s.LastRemaining_Solution(7,3);
    printf("%d",l);
    return 0;
}