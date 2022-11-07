//분리연쇄법 해시테이블
/*
 13
 i 34
 i 23
 i 26
 i 21
 s 36
 s 26
 s 34
 s 21
 p
 d 21
 s 34
 d 8
 e
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
   int data;
   struct _Node *next; //next로 연결
} Node;

typedef struct _HashTable {
   Node *node;
} HashTable;

void initHashtable(HashTable *hash, int M);
int hashFunction(int x, int M); //h(x) = x % M
Node *getNode(int data);
void insertItem(HashTable *hash, int M, int data);
void searchItem(HashTable *hash, int M, int data);
void deleteItem(HashTable *hash, int M, int data);
void deleteAllItem(HashTable *hash, int M);
void print_hashtable(HashTable *hash, int M);

int main(){
   int M, data;
   HashTable *hash;
   char command;

   scanf("%d", &M);
   hash = (HashTable *)malloc(sizeof(HashTable) * M); //노드 배열
   initHashtable(hash, M);

   while (1) {
      scanf("%c", &command);

      if (command == 'i') {
         scanf("%d", &data);
         insertItem(hash, M, data);
         getchar();
      }
      else if (command == 's') {
         scanf("%d", &data);
         searchItem(hash, M, data);
         getchar();
      }
      else if (command == 'd') {
         scanf("%d", &data);
         deleteItem(hash, M, data);
         getchar();
      }
      else if (command == 'p') print_hashtable(hash, M);
      else if (command == 'e') break;
   }

   deleteAllItem(hash, M);

   free(hash);
   return 0;
}

void initHashtable(HashTable *hash, int M){
   for(int i=0;i<M;i++) hash[i].node=NULL;
}
int hashFunction(int x, int M){
   return x % M;
}
Node *getNode(int data){
   Node *new = NULL;
   new = (Node *)malloc(sizeof(Node));
   new->data = data;
   new->next = NULL;
   return new;
}
void insertItem(HashTable *hash, int M, int data){
   Node *new = getNode(data);
   int num = hashFunction(data, M);
   if (hash[num].node == NULL) { //새로들어왔다면
      hash[num].node = new;
   }
   else{
      new->next = hash[num].node;
      hash[num].node = new;
   }
}
void searchItem(HashTable *hash, int M, int data){
   int num = hashFunction(data, M);
   int cnt = 0;
   Node *p = hash[num].node;

   while (p != NULL) {
      cnt++;
      if (p->data == data) {
         printf("%d\n", cnt);
         return;
      }
      p = p->next;
   }

   printf("0\n");
}
void deleteItem(HashTable *hash, int M, int data){
   int num = hashFunction(data, M);
   Node *p = hash[num].node, *tmp;
   int cnt = 0;

   if (p == NULL) { //예외처리
      printf("%d\n", cnt);
      return;
   }
   
   cnt++;
   if (p->data == data) {
         tmp = p;
         hash[num].node = p->next;
         free(tmp);
         printf("%d\n", cnt);
         return;
      }
   while (p->next != NULL) {
      tmp = p;
      p = p->next;
      cnt++;
      if (p->data == data) {
         tmp->next = p->next;
         free(p);
         printf("%d\n", cnt);
         return;
      }
   }

   printf("0\n");
}
void deleteAllItem(HashTable *hash, int M){
   Node *p, *tmp;
   for (int i = 0; i < M; i++) {
      p = hash[i].node;
      while (p != NULL) {
         tmp = p;
         p = p->next;
         free(tmp);
      }
   }
}
void print_hashtable(HashTable *hash, int M){
   Node *p;
   for (int i = 0; i < M; i++) {
      if (hash[i].node == NULL) continue;
      p = hash[i].node;
      while (p != NULL) {
         printf(" %d", p->data);
         p = p->next;
      }
   }
   printf("\n");
}
