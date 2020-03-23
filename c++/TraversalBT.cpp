/* 
#题目描述
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此
二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

#输入描述:
输入包括1行字符串，长度不超过100。

#输出描述:
可能有多组测试数据，对于每组数据，
输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
每个输出结果占一行。

#示例
输入
>abc##de#g##f###
输出
>c b e g d f a  

*/


#include <stdio.h>
#include <malloc.h> 
#include <string.h>
struct Tree{
    char value;
    Tree *left;
    Tree *right;
};
    char array[100];
    int count;
    int in;
Tree * createTree(){
    
    if(array[in]!='#'){
        Tree* node=(Tree*)malloc(sizeof(Tree));
        node->value=array[in];
        in++;
        if(in<count){
            node->left=createTree();
        }
        if(in<count){
            node->right=createTree();
        }
        return node;
    }
    in++;
    return NULL;
};
void printTree(Tree *tree){
    if(tree->left!=NULL)
    {
        printTree(tree->left);
    }
        
        printf("%c ",tree->value);
    if(tree->right!=NULL){
        printTree(tree->right);
    }
        
}
int main(){
    Tree *tree;
    in=0;
    while(scanf("%s",array)!=EOF){
        count=strlen(array);
        tree=createTree();
        printTree(tree);
    }
    
    return 0;
}
