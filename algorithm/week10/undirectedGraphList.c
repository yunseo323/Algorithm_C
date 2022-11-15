/*무방향 가중그래프-인접리스트*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int index; //노드 번호
   int weight; //가중치
   struct node *next;
}NODE;

typedef struct graph {
   NODE *list[21]; //NODE 주소 배열
}GRAPH;


void insertEdge(GRAPH* g, int a, int b, int weight);
void printAdjList(GRAPH* g);
void printNode(GRAPH* g, int number);
void modifyWeight(GRAPH* g, int a, int b, int weight);

int main(){
   char command;
   int number, a, b, w;
   //그래프 생성
   GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
   for(int i=1;i<=6;i++){
      g->list[i]=NULL; //초기화
   }
   //값 넣기
   insertEdge(g, 1, 2, 1);
   insertEdge(g, 2, 1, 1);
   
   insertEdge(g, 1, 3, 1);
   insertEdge(g, 3, 1, 1);
   
   insertEdge(g, 1, 4, 1);
   insertEdge(g, 4, 1, 1);
   
   insertEdge(g, 1, 6, 2);
   insertEdge(g, 6, 1, 2);
   
   insertEdge(g, 2, 3, 1);
   insertEdge(g, 3, 2, 1);
   
   insertEdge(g, 3, 5, 4);
   insertEdge(g, 5, 3, 4);
   
   insertEdge(g, 5, 5, 4); //loop
   
   insertEdge(g, 5, 6, 3);
   insertEdge(g, 6, 5, 3);
   //command
   while (1) {
      scanf("%c", &command);
      if (command == 'a') {
         scanf("%d", &number);
         if(number>=1 && number<=6) printNode(g, number);
         else printf("-1\n");
      }
      else if (command == 'm') {
         scanf("%d %d %d", &a, &b, &w);
         if(a>=1 && a<=6 && b>=1 && b<=6) modifyWeight(g, a, b, w);
         else printf("-1\n");
      }
      else if (command == 'q') {
         break;
      }
      getchar();
   }
   return 0;
}

void insertEdge(GRAPH* g, int a, int b, int weight){ //a->b
   NODE* n = (NODE*)malloc(sizeof(NODE));
   n->index = a;
   n->weight = weight;

   n->next = g->list[b]; //연결
   g->list[b] = n;
}
void printAdjList(GRAPH* g){
   for (int i = 1; i <= 6; i++) {
      NODE* n = g->list[i];
      while (n != NULL) {
        printf(" %d", n->index);
         n = n->next;
      }
      printf("\n");
    }
       
}
void printNode(GRAPH* g, int number) {
   NODE* n = g->list[number];
   while (n != NULL) {
      if (n->next == NULL) break;

      NODE* nl = n->next;
      while (nl != NULL) {
       if (n->index > nl->index) { //오름차순 정렬
         int tmp1, tmp2;
         tmp1 = n->index;
         tmp2 = n->weight;
         n->index = nl->index;
         n->weight = nl->weight;
         nl->index = tmp1;
         nl->weight = tmp2;
       }
       nl = nl->next;
     }
     n = n->next;
   }

   n = g->list[number];

   while (n != NULL) {
     printf(" %d %d", n->index, n->weight);
     n = n->next;
   }
   printf("\n");
}
void modifyWeight(GRAPH* g, int a, int b, int weight){
   NODE* n = g->list[a];

    if (weight == 0) { //삭제
      NODE* tmp = NULL;
       NODE* s = n;
      
      while (n != NULL) {
        if (n->index == b) {
          if (tmp == NULL) {
             n = n->next;
             s = n;
          }
          else {
            tmp->next = n->next;
          }
          break;
        }
        tmp = n;
        n = n->next;
      }

      g->list[a] = s;
      n = g->list[b];
      tmp = NULL;
      s = n;

      while (n != NULL) {
        if (n->index == a) {
          if (tmp == NULL) {
              n = n->next;
              s = n;
          }
          else {
            tmp->next = n->next;
          }
          break;
        }
        tmp = n;
        n = n->next;
      }

      g->list[b] = s;
    }
    else { //수정
      while (n != NULL) {
        if (n->index == b) {
          n->weight = weight;
          break;
        }
          n = n->next;
      }

      n = g->list[b];

      while (n != NULL) {
        if (n->index == a) {
          n->weight = weight;
          break;
        }
        n = n->next;
      }

      if (n == NULL) { //간선X
        insertEdge(g, a, b, weight);
        if (a != b) { //싸이클X
          insertEdge(g, b, a, weight);
        }
      }
    }
  }
   


