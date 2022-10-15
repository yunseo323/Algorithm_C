//상향식 힙 생성
//1 11 4 2 7 5 6 8 9 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


int *buildList(int n, int min, int max); //최소힙 리스트 만들기
int findKthSmallest(int *L, int n, int k); //리스트 L, n개, k번째 작은 원소 반환
void upHeap(int i, int *L); //상향이동
void downHeap(int i, int end, int *L);


int main() {
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    int *L;
    int karr[4] = { 1, 100, 99900, 99999 };
    //buildList(10, 1, 100)호출, 리스트 L
    L = buildList(10, 1, 100);
    //L 출력
    for (int i = 1; i <= 10; i++)printf("%d ", L[i]);
    printf("\n");
    //for문 이용, k=1,2,3 findKthSmallest 호출, 출력
    for (int k = 1; k <= 3; k++) printf("%d ", findKthSmallest(L, 10, k));
    printf("\n");

    L = buildList(100000, 1, 1000000); // 호출, 리스트 L
    //k = 1, 100, 99900, 99999, x 함수를 총 4회 호출, 출력
    for (int i = 0; i < 4; i++) {
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        printf("%d ", findKthSmallest(L, 100000, karr[i]));
        QueryPerformanceCounter(&end);
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
    }
  return 0;

}

int *buildList(int n, int min, int max) {//무순배열만들기: 난수함수 사용
    srand(time(NULL));
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) { //index 1부터 리스트 생성
        arr[i] = ((((long)rand() << 15) | rand()) % (max + 1 - min)) + min;
    }

    return arr;
}


int findKthSmallest(int *L, int n, int k) {//k번째 숫자 반환
    int tmp;
    int last = n;
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    //힙 생성
    for (int i = 1; i <= n; i++) {
        arr[i] = L[i];
        upHeap(i, arr);
    }
    /*
    for(int i=1;i<=n;i++) printf("%d ",arr[i]);
    printf("초기힙출력 \n");
     */
     //힙 정렬
    for (int i = 0; i < k; i++) { //k번 실행
        tmp = arr[1];
        arr[1] = arr[last];
        arr[last] = tmp;
        downHeap(1, last - 1, arr);
        last -= 1;
    }/*
    printf("정렬 출력\n");
    for(int i=1;i<=10;i++)printf("%d ",arr[i]); //출력
    printf("\n");
    */
    return arr[n - k + 1];
}

void upHeap(int i, int *L) {
    int tmp;
    if (i == 1 || L[i] > L[i / 2]) { //종료조건
        return;
    }
    tmp = L[i];
    L[i] = L[i / 2];
    L[i / 2] = tmp;
    upHeap(i / 2, L); //반복호출
}

void downHeap(int i, int end, int *L) {//하향이동
    int tmp, lc, s;//leftchild
    if (2 * i > end)return; //종료조건
    s = lc = 2 * i;
    if (lc + 1 <= end && L[lc + 1] < L[lc]) { //범위 안에 있고 왼쪽 오른쪽노드중 작은 값 small에 담음
        s = lc + 1;
    }
    if (L[i] <= L[s]) return;//종료
    tmp = L[i];
    L[i] = L[s];
    L[s] = tmp;
    downHeap(s, end, L);
}
