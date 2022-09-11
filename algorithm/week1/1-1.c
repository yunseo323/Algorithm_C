#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
5
A 1 S
A 2 t
A 3 r
A 3 a
P

9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
*/
typedef struct _node {//노드 구조체
   char elem;
   struct _node *prev; //이전노드
   struct _node *next; //이후노드
}Node;

typedef struct _list { //이중리스트 구조체
   int size;
   Node *header; //헤더
   Node *trailer; //트레일러
}List;

List *listInit() { //리스트 초기화(할당, 값 초기화)
   List *newList;
   newList = (List *)malloc(sizeof(List)); //리스트 할당
   newList->header = (Node *)malloc(sizeof(Node)); //헤더 할당
   newList->trailer = (Node *)malloc(sizeof(Node)); //트레일러 할당
    //헤더와 트레일러 연결
   newList->header->next = newList->trailer;
   newList->header->prev = NULL;
   newList->trailer->prev = newList->header;
   newList->trailer->next = NULL;

   newList->size = 0; //list size 초기화
   return newList;
}

void add(List *list, int r, char e) { //인덱스 r에 e값 넣기
   int i;
   Node *newNode = (Node *)malloc(sizeof(Node)); //새로운 노드 할당
   Node *s = list->header; //포인터 s는 리스트 헤더에서 시작

   newNode->elem = e;
   for (i = 0; i < r - 1; i++) {
      s = s->next; //s 이동
   }
   s->next->prev = newNode;
   newNode->next = s->next;
   s->next = newNode;
   newNode->prev = s;

   list->size++;
}
void delete(List *list, int r) {// 인덱스 r 값 삭제
   int i;
   Node *s = list->header;

   for (i = 0; i < r - 1; i++) { //이전까지만 도달
      s = s->next;
   }
   s->next = s->next->next; //다음다음에 연결
   s->next->prev = s;

   list->size--;
}
char get(List *list, int r) { //해당 인덱스 값 갖기
   int i;
   Node *s = list->header;

   for (i = 0; i < r; i++) {
      s = s->next;
   }
   return s->elem;
}
void print(List *list) { //전체 출력
   int i;
   Node *s = list->header->next;
   for (i = 0; i < list->size; i++) {
      printf("%c", s->elem);
      s = s->next;
   }
}
int main() {
   int N, i, index;
   char command, ch;
   List *list = listInit();

   scanf("%d", &N);
   getchar();
   for (i = 0; i < N; i++) {
      scanf("%c", &command);
      if (command == 'A') {
         scanf("%d %c", &index, &ch);
         if (list->size + 1 < index || index < 1) {
            printf("invalid position\n");
            getchar();
            continue;
         }
         add(list, index, ch);
      }
      else if (command == 'D') {
         scanf("%d", &index);
         if (list->size < index || index < 1) {
            printf("invalid position\n");
            getchar();
            continue;
         }
         delete(list, index);
      }
      else if (command == 'G') {
         scanf("%d", &index);
         if (list->size < index || index < 1) {
            printf("invalid position\n");
            getchar();
            continue;
         }
         printf("%c", get(list, index));
      }
      else if (command == 'P') {
         print(list);
         printf("\n");
      }
      getchar();
   }
   return 0;
}
