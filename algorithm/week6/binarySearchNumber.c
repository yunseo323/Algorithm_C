//사전-이진탐색응용-재귀버전
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarySearch(char *arr, int a, int b, int idx); //재귀버전

int main(){
   int a, b, size;
   char *arr=NULL;
   scanf("%d %d %d", &a, &b, &size);
   getchar();
   arr = (char *)malloc(sizeof(char) * (size + 1));
   scanf("%s",arr);
   printf("%d",binarySearch(arr,a,b,0));
   free(arr);
   return 0;
}
 
int binarySearch(char *arr, int a, int b, int idx){ //재귀버전
   int mid; //가운데
   mid = (a+b)/2;
   //base
   if(arr[idx]=='\0') return mid;
   //recursion
   if(arr[idx]=='Y') binarySearch(arr, mid+1, b, idx+1); //더 크면 Yes
   else if(arr[idx]=='N') binarySearch(arr, a, mid, idx+1); //a< <=mid
}
