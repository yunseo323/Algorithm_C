//사전-이진탐색-재귀버전
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarySearch(int *arr, int l, int r, int k); //재귀버전

int main(){
   int n, k, *arr;
   scanf("%d %d",&n, &k);
   arr = (int *)malloc(sizeof(int)*n);
   for(int i=0;i<n;i++) scanf("%d",&arr[i]);
   printf("%d",binarySearch(arr,0,n-1,k));
   free(arr);
   return 0;
}
 
int binarySearch(int *arr, int l, int r, int k){ //재귀버전
   int mid; //가운데
   
   if(l>r) return r; //엇갈리면
   mid = (l+r)/2;
   
   if(arr[mid]==k) return mid; //동일하면 반환
   else if(arr[mid]>k) binarySearch(arr, l, mid-1, k);
   else binarySearch(arr, mid+1, r, k); //if(arr[mid]<k)
}
