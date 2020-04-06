/* 
数组去重复
 */


int* unique(int* arr,int size,int* returnSize){
    int* p=(int*)malloc(sizeof(int)*size);
    int index=0;
    for(int i=0;i<size;i++){
        if(i==size-1){
            p[i]=1;
            index++;
        }else if(arr[i]==arr[i+1]){
            p[i]=0;
        }else{
            p[i]=1;
            index++;
        }
    }
    *returnSize=index;
    int* q=(int*)malloc(sizeof(int)*index);
    int x=0;
    for(int i=0;i<size;i++){
        if(p[i]==1){
            q[x]=arr[i];
            x++;
        }
    }
    return q;
}