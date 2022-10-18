//선택정렬
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
       int j=i-1;
       tmp=arr[i];
       while (j >= 0 && arr[j] > tmp) {
                arr[j + 1] = arr[j];
                j--;
             }
      arr[j + 1] = tmp;
    }
    
    for(int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    
    free(arr);
}
