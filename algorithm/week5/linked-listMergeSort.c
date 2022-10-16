#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*단일 연결리스트*/
//노드
typedef struct node {
   int number;
   struct node *next;
}Node;

//연결리스트
typedef struct _list{
   Node *head;  //머리 노드에 대한 포인터 -> 데이터 값이 바로 들어감
}List;


Node *make_node(int data);
void add(List *list, int data); //리스트에 data 넣기
void printList(List list); //출력
void freeList(List list); //free
void mergeSort(List *list, int size); //합병된것을 오름차순으로 정렬
List merge(List *L1,List *L2); //두개의 단일연결리스트를 합병한 하나의 단일연결리스트 반환: 추가 공간 사용가능
void partition(List L, int k, List *L1, List *L2); //L1과 L2로 반환


int main(){
   int n, data;
   List list, *pl = &list;
   list.head=NULL;//초기화
   scanf("%d",&n); //크기 n 입력
   for(int i=0;i<n;i++){
      scanf("%d",&data);
      add(pl,data);
   }
   mergeSort(pl,n);
   printList(list);
   freeList(list);
   return 0;
}

Node *make_node(int data) {
   Node *p = NULL;
   p = (Node *)malloc(sizeof(Node));
   p->number = data;
   p->next = NULL;
   return p;
}
void add(List *list, int data){
   Node *selectNode = list->head;
   
   if (list->head == NULL) {// 리스트에 노드가 없는 경우
      list->head = make_node(data);
   }
   else {// 리스트에 노드가 있는 경우
       while (selectNode->next != NULL) {
           selectNode = selectNode->next;
       }
      selectNode->next = make_node(data);
   }
}
void printList(List list){
   Node *p = list.head;

   while (p != NULL) {
      printf(" %d", p->number);
      p = p->next;
   }
}
void freeList(List list) {

	Node *node = list.head;
	Node *tmp;

	while (node != NULL) {
		tmp = node;
		node = node->next;
		free(tmp);
	}
}
void mergeSort(List *list, int size){
   List l1, l2;
   if(size>1){ //basecase
      partition(*list, size / 2, &l1, &l2); //l1과 l2로 반환
      mergeSort(&l1, size/2);
      mergeSort(&l2, size-(size/2));
      *list = merge(&l1, &l2); //다시 합치기
   }
}
List merge(List *L1,List *L2){
   //정렬하며 합병
   Node *node1, *node2; //L1, L2
   Node *tmp, *sL;
   List sortedList; //리턴할 합병 리스트
   
   //작은걸 먼저 sortedList 에 넣기
   if (L1->head->number > L2->head->number) {
         sortedList.head = L2->head;
         node1 = sortedList.head->next;
         L2->head->next = NULL;
         node2 = L1->head;
     }
     else {
         sortedList.head = L1->head;
         node1 = sortedList.head->next;
         L1->head->next = NULL;
         node2 = L2->head;
     }
     sL = sortedList.head; //sL 노드 포인터
   //크기순대로 반복문으로 넣기
   while (node1 != NULL && node2 != NULL) {
         if (node1->number >= node2->number) {
             tmp = node2->next;
             node2->next = NULL;
             sL->next = node2;
             node2 = tmp;
         }
         else {
             tmp = node1->next;
             node1->next = NULL;
             sL->next = node1;
             node1 = tmp;
         }
         sL = sL->next;
     }
   //남은것 넣기
   while (node1 != NULL) {
      tmp = node1->next;
      node1->next = NULL;
      sL->next = node1;
      node1 = tmp;
      sL = sL->next;
    }

    while (node2 != NULL) {
       tmp = node2->next;
       node2->next = NULL;
       sL->next = node2;
       node2 = tmp;
       sL = sL->next;
    }
   return sortedList;
}
void partition(List L, int k, List *L1, List *L2){ //L을 L1과 L2 로 나누기
   Node *p = L.head;
   for (int i = 1; i < k; i++){
      p = p->next;
   }
   L1->head = L.head;
   L2->head = p->next;
   p->next = NULL; //L1 끝
}

