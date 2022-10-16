//제자리 퀵 정렬 알고리즘 + 배열 이용

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elements{ //인덱스
   int a;
   int b;
}Elem;

void inPlaceQuickSort(int *arr, int l, int r);
int findPivot(int l, int r);
Elem inPlacePartition(int *arr, int l, int r, int k);

int main(){
   int n;
   int *arr;
   
   scanf("%d",&n);
   arr = malloc(sizeof(int)*n);
   for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
   }
   inPlaceQuickSort(arr, 0, n-1);
   for(int i=0;i<n;i++){
      printf(" %d",arr[i]);
   }
   return 0;
}

void inPlaceQuickSort(int *arr, int l, int r){ //제자리 퀵 정렬
   if(l>=r) return; //종료
   Elem elem;
   
   int k = findPivot(l, r);
   elem = inPlacePartition(arr, l, r, k); //a,b 구하기
   inPlaceQuickSort(arr, l, elem.a - 1); //pivot보다 작은:l~a-1
   inPlaceQuickSort(arr, elem.b+1, r);//pivot보다 큰:b+1~r
}
int findPivot(int l, int r){
   int p;
   srand(time(NULL));
   p = rand()%(r-l+1)+l; //l~r
   return p;
}
Elem inPlacePartition(int *arr, int l, int r, int k){ //배열,l,r,pivot -> a,b(Elem) 반환
   /*
    l~a-1: pivot보다 작음
    a~b: pivot
    b+1~r: pivot보다 큼
    */
   Elem elem;
   int p = arr[k]; //pivot
   int tmp = p;
   int i = l, j= r-1; //r-1!!!
   arr[k] = arr[r]; //둘 교환
   arr[r] = tmp;
   
   while(i<=j){
      while(i<=j && arr[i]<=p) i++; //왼쪽에서 p보다 큰게 있으면 정지
      while(i<=j && arr[j]>=p) j--; //오른쪽에서 p보다 작은게 있으면 정지
      
      if(i<j){ //swap
         tmp=arr[i];
         arr[i]=arr[j];
         arr[j]=tmp;
      }
   }
   tmp=arr[i];
   arr[i]=arr[r];
   arr[r]=tmp; //r에 담아줌
   
   elem.a=i;
   j=r-1;
   while(i+1<=j&&arr[i+1]==p) i++;
   elem.b=i;
   return elem; //a,b 담은 elem 반환8
}
