/* 
问题描述：
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

解题思路:
1、主要是对下标的操作。

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> m;
    int way=2;
    int x=0;
    int y=-1;
    int length_x=matrix.size()-1;
    int length_y=matrix[0].size();
    while(length_y>=0 && length_x>=0){
        switch(way){
            case 1:
                for(int i=0;i<length_x;i++){
                    --x;
                    m.push_back(matrix[x][y]);
                }
                length_x--;
                break;
            case 2:
                for(int i=0;i<length_y;i++){
                    ++y;
                    m.push_back(matrix[x][y]);
                }
                length_y--;
                break;
            case 3:
                for(int i=0;i<length_x;i++){
                    ++x;
                    m.push_back(matrix[x][y]);
                }
                length_x--;
                break;
            case 4:
                for(int i=0;i<length_y;i++){
                    --y;
                    m.push_back(matrix[x][y]);
                }
                length_y--;
                break;
        }
        ++way;
        if(way==5){
            way=1;
        }        
    }
    
    return m;
}


int main(){
    vector<vector<int> > matrix;
    int n=1;
    for(int i=0;i<4;i++){
        vector<int> list;
        for(int j=0;j<4;j++){
            list.push_back(n++);
        }
        matrix.push_back(list);
    }
    
    for(int i=0;i<4;i++){
        // vector<int> list=matrix[i];
        for(int j=0;j<4;j++){
            cout<<matrix[i][j]<<endl;
        }
    }
    vector<int> sequence=printMatrix(matrix);
    for(int i=0;i<16;i++){
        cout<<sequence[i]<<endl;
    }
    
    return 0;
}