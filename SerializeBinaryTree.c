/* 
问题描述：
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，
序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。

解题思路:


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "utils/Tree.h"


// int current=0;
char* IntToString(int a){
    char* str=(char*)malloc(sizeof(char)*16);
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int t=a;
    int i=0;
    if(a<0){
        str[i++]='-';
        t=-a;
    }
    do{
        int b=t%10;
        str[i++]=index[b];
        t=t/10;
    }while(t>0);
    int j=0;
    if(a<0){
        j=1;
    }
    for(int k=i-1;j<k;j++,k--){
        int temp=str[j];
        str[j]=str[k];
        str[k]=temp;
    }

    // str[i++]='!';
    str[i++]='\0';
    return str;
}

int StringToInt(char* str){
    int a=0;
    int low=0;
    bool neg=false;
    if(str[0]=='-'){
        neg=true;
        low=1;
    }
    for(int i=strlen(str)-1;i>=low;i--){

        int local_a=str[i]-48;
        for(int k=0;k<strlen(str)-i-1;k++){
            local_a*=10;
        }
        a+=local_a;
    }
    if(neg){
        a=-a;
    }
    return a;
}

char* Serialize(TreeNode *root) {    
    char* sequence=(char*)malloc(sizeof(char)*256);
    int i=0;
    if(root!=NULL){
        strcpy(sequence,IntToString(root->val));

        char* left_str=Serialize(root->left);
        strcat(sequence,left_str);

        char* right_str=Serialize(root->right);
        strcat(sequence,right_str);

    }else{
        return "#";
    }
    return sequence;
}


TreeNode* createTreeNodeLocal(int value){
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->val=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}


TreeNode* createTreeLocal(char *str){
    TreeNode* node;
    if(strlen(str)>current){
        if(str[current]!='#'){
            char* str_num=(char*)malloc(sizeof(char)*16);
            int i=0;
            while(str[current]!='!'){
                str_num[i++]=str[current];
                current++;
            }
            str_num[i]='\0';
            current++;
            node=createTreeNodeLocal(StringToInt(str_num)); 
            // current+=1;
            node->left=createTreeLocal(str);
            // current+=1;
            node->right=createTreeLocal(str);
        }else{
            current++;
            return NULL;
        }       
    }else{
        return NULL;
    }
    return node;
}
TreeNode* Deserialize(char *str) {
    current=0;
    return createTreeLocal(str);
}
void traveralTreeLocal(TreeNode* root){
    if(root){
        printf("%d",root->val);
        traveralTreeLocal(root->left);
        traveralTreeLocal(root->right);
    }
}
int main(){
    int m=10;
    char* str=IntToString(m);
    printf("%s\n",str);
    int a=StringToInt(str);
    printf("%d\n",a);
    // TreeNode* root=createTree();
    // traveralTree(root);
    // char* sequence=Serialize(root);
    // printf("%s\n",sequence);
    // TreeNode* root_re=Deserialize(sequence);
    // traveralTreeLocal(root_re);
    return 0;
}