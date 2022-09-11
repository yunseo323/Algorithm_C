#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr=NULL;
    int n,tmp;
    
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
       //뒤에서부터 작은거 switch
        int k=i;
        for(int j=i-1;j>=0;j--){
            if(arr[k]<arr[j]){
                tmp=arr[j];
                arr[j]=arr[k];
                arr[k]=tmp;
                k--;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    
    free(arr);
}
