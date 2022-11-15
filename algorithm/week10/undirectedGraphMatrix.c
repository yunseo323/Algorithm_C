/*무방향 가중그래프-인접행렬*/
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
   int **matrix; //행렬
   int size; //정점 개수
}GRAPH;


void insertEdge(GRAPH *g, int a, int b, int weight);
void printAdj(GRAPH *g, int number);
//void modifyWeight(GRAPH *g, int a, int b, int weight); ->insertEdge로 가능

int main(){
   char command;
   int number, a, b, w;
   //그래프 생성, 할당
   GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
   g->size = 6;
   g->matrix = (int **)malloc(sizeof(int *) * (g->size+1));
   for (int i = 0; i <= g->size; i++) {
         g->matrix[i] = (int *)malloc(sizeof(int) * (g->size+1));//i행 메모리 할당
      for(int j=0;j<=g->size;j++) g->matrix[i][j]=0;//초기화
      }
   //값 넣기
   insertEdge(g, 1, 2, 1);
   
   insertEdge(g, 1, 3, 1);
   
   insertEdge(g, 1, 4, 1);
   
   insertEdge(g, 1, 6, 2);
   
   insertEdge(g, 2, 3, 1);
   
   insertEdge(g, 3, 5, 4);
   
   insertEdge(g, 5, 5, 4); //loop
   
   insertEdge(g, 5, 6, 3);
   
   //command
   while (1) {
      scanf("%c", &command);
      if (command == 'a') {
         scanf("%d", &number);
         if(number>=1 && number<=6) printAdj(g, number);
         else printf("-1\n");
      }
      else if (command == 'm') {
         scanf("%d %d %d", &a, &b, &w);
         if(a>=1 && a<=6 && b>=1 && b<=6) insertEdge(g, a, b, w);
         else printf("-1\n");
      }
      else if (command == 'q') {
         break;
      }
      getchar();
   }
   return 0;
}

void insertEdge(GRAPH *g, int a, int b, int weight){ //a<->b
   g->matrix[a][b] = weight;
   g->matrix[b][a] = weight;
}

void printAdj(GRAPH *g, int number) {
   for(int i=1;i<=g->size;i++){
      if(g->matrix[number][i]!=0) printf(" %d %d", i, g->matrix[number][i]);
   }
   printf("\n");
}
/*
void modifyWeight(GRAPH *g, int a, int b, int weight){
   insertEdge(g, a, b, weight);
}
*/



