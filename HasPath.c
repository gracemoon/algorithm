/* 
问题描述：
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

bool move(char* matrix, int* m, int rows, int cols, char* str,int x,int y,int i){
    bool res=false;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d",m[i*cols+j]);
        }
        printf("\n");
    }
    printf("---------------------------------------\n");
    if(matrix[x*cols+y]==str[i] && m[x*cols+y]==1){
        int length=strlen(str)-1;
        if(i==length){
            res=true;
        }else{
            m[x*cols+y]=0;
            i++;
            // int* m1=(int*)malloc(sizeof(int)*rows*cols);
            // for(int k=0;k<rows;k++){
            //     for(int z=0;z<cols;z++){
            //         m1[k*cols+z]=m[k*cols+z];
            //     }
            // }
            bool up=false;
            if(x-1>=0){
                up=move(matrix, m, rows, cols, str, x-1, y, i);
            }
            bool down=false;
            if(x+1<rows){
                down=move(matrix, m, rows, cols, str, x+1, y, i);
            }
            bool left=false;
            if(y-1>=0){
                left=move(matrix, m, rows, cols, str, x, y-1, i);
            }
            bool right=false;
            if(y+1<cols){
                right=move(matrix, m, rows, cols, str, x, y+1, i);
            }
            if(up || down || left || right){
                res=true;
            }
        }
        
    }
    return res;
}



bool hasPath(char* matrix, int rows, int cols, char* str){
    bool res=false;
    int* m=(int*)malloc(sizeof(int)*rows*cols);

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i*cols+j]==str[0]){
                for(int i=0;i<rows;i++){
                    for(int j=0;j<cols;j++){
                        m[i*cols+j]=1;
                    }
                }
                int local_bool=move(matrix,m,rows,cols,str,i,j,0);
                if(local_bool){
                    res=true;
                    break;
                }
            }
        }
    }
    return res;
};

int main(){
    // char m[]={'a','b','c','e','s','f','c','s','a','d','e','e'};
    // char* matrix="ABCESFCSADEE";
    char* matrix="ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";

    // char* str="ABCCED";
    char* str="SGGFIECVAASABCEHJIGQEM";
    bool res=hasPath(matrix,5,8,str);
    if(res){
        printf("%s : True",str);
    }else{
        printf("%s : False",str);
    }
    return 0;
}