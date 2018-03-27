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
