#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution{
    public:
        string dictSortedTree(int n,int m,int k,int x,int y,int* index,string path,char c){
            cout<<"---------"<<endl;
            path=path+c;
            cout<<path<<":"<<*index<<endl;
            if(*index==k){
                return path;
            }
            if(x<n){
                *index=*index+1;
                string left_ans=dictSortedTree(n,m,k,x+1,y,index,path,'a');
                if(left_ans.length()>0){
                    return left_ans;
                }
            }
            if(y<m){
                *index=*index+1;
                string right_ans=dictSortedTree(n,m,k,x,y+1,index,path,'b');
                if(right_ans.length()>0){
                    return right_ans;
                }
            }
            return "";
        }
};
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<n<<":"<<m<<":"<<k<<endl;
    Solution s;
    int index=1;
    string ans=s.dictSortedTree(n,m,k,1,0,&index,"",'a');
    if(ans.length()>0){
        cout<<ans<<endl;
    }else{
        index++;
        string ans=s.dictSortedTree(n,m,k,0,1,&index,"",'b');
        cout<<ans<<endl;
    }
    return 0;
}