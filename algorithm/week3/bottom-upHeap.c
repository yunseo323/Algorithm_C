//상향식 힙 생성
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int H[100]; //힙 배열
int n;

void rBuildHeap(int i);//재귀
void buildHeap();//비재귀
void downHeap(int i);//하향이동
void printHeap();


int main(){
    int N;
    scanf("%d",&N);
    n=N;
    for(int i=1;i<=N;i++) scanf("%d",&H[i]);
    //rBuildHeap(1);
    buildHeap(1);
    printHeap();
    return 0;
}
void rBuildHeap(int i){ //재귀방식
    if(i>n) return;
    rBuildHeap(2*i); //왼쪽 부트리
    rBuildHeap(2*i+1); //오른쪽 부트리
    downHeap(i);
}
void buildHeap(){ //비재귀 방식
    for(int i=n/2;i>=1;i--){
        downHeap(i);
    }
}

void downHeap(int i){//하향이동
    int tmp,lc,big;//leftchild
    if(2*i>n)return; //종료조건
    big=lc=2*i;
    if(lc+1<=n&&H[lc+1]>H[lc]){ //범위 안에 있고 왼쪽 오른쪽노드중 큰 값 big에 담음
        big=lc+1;
    }
    if(H[i]>H[big]) return;//종료
    tmp=H[i];
    H[i]=H[big];
    H[big]=tmp;
    downHeap(big);
}

void printHeap(){
    for(int i=1;i<=n;i++){
        printf(" %d",H[i]);
    }
}

