//삽입식 힙 생성
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int H[100]; //힙 배열
int n = 0; //총 개수

void insertItem(int key);
int removeMax();
void upHeap(int i); //상향이동
void downHeap(int i);//하향이동
void printHeap();
/*
i 209
i 400
d
i 77
d
p
q
 */

int main(){
    int inNum;
    char command;
    //초기화
    
    while(1){
        scanf("%c",&command);
        if(command=='i'){
            scanf("%d",&inNum);
            getchar();
            insertItem(inNum);
            printf("0\n"); //삽입완료
        }
        else if(command=='d'){
            printf("%d\n",removeMax());
        }
        else if(command=='p'){
            printHeap();
            printf("\n");
        }
        else if(command=='q') break;
    }
    return 0;
}

void insertItem(int key){
    n++;
    H[n]=key;
    upHeap(n);
}
int removeMax(){
    int re = H[1]; //0은비워둔다
    H[1]=H[n];
    n--;
    downHeap(1);
    return re;
}
void upHeap(int i){ //상향이동(부모와 비교)
    int tmp;
    if(i==1||H[i]<H[i/2]){ //종료조건
        return;
    }
    tmp=H[i];
    H[i]=H[i/2];
    H[i/2]=tmp;
    upHeap(i/2); //반복호출
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

