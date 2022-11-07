//선택정렬
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr=NULL;
    int n,*max=NULL,tmp;
    
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        max=&arr[i];
        for(int j=0;j<i;j++){
            if(*max<arr[j])max=&arr[j];
        }
        tmp=arr[i];
        arr[i]=*max;
        *max=tmp;
    }
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    free(arr);
}
