//상향식 힙 생성
#include <stdio.h>

int H[100]; //힙 배열
int n;

void inPlaceHeapSort();
void printArray();
void downHeap(int i, int end);//하향이동
void buildHeap();//비재귀


int main(){
    int N;
    scanf("%d",&N); //키 개수
    n=N;
    for(int i=1;i<=N;i++) scanf("%d",&H[i]); //키
    //1.힙생성: 최대힙 생성
    buildHeap(); //상향식-비재귀 힙 생성
    //힙 정렬: 오름차순 정렬 O(nlogn)
    inPlaceHeapSort(); //제자리 정렬
    printArray(); //출력
    return 0;
}
void inPlaceHeapSort(){ //제자리 힙 정렬
    int tmp;
    for(int i=n;i>=2;i--){ //
        tmp = H[1]; //H[1] <-> H[i] 값 바꾸기
        H[1] = H[i];
        H[i] = tmp;
        //최대힙 만들기
        downHeap(1,i-1);
    }
}
void printArray(){
    for(int i=1;i<=n;i++){
        printf(" %d",H[i]);
    }
}
void downHeap(int i, int end){//하향이동
    int tmp,lc,big;//leftchild
    if(2*i>end)return; //종료조건
    big=lc=2*i;
    if(lc+1<=end&&H[lc+1]>H[lc]){ //범위 안에 있고 왼쪽 오른쪽노드중 큰 값 big에 담음
        big=lc+1;
    }
    if(H[i]>=H[big]) return;//(중복키이므로 같으면)종료
    tmp=H[i];
    H[i]=H[big];
    H[big]=tmp;
    downHeap(big,end);
}


void buildHeap(){ //비재귀 방식
    for(int i=n/2;i>=1;i--){
        downHeap(i,n);
    }
}
