//해시테이블 - 개방주소법(이중해싱)
#include <stdio.h>
#include <stdlib.h>

typedef struct _HashTable {
   int data;
} HashTable;

void initHashtable(HashTable *hash, int M);
int hashFunction(int x, int i, int M, int q);
int hashSecondFunction(int x, int q); //이중해싱
void insertItem(HashTable *hash, int M, int data, int q);
void searchItem(HashTable *hash, int M, int data, int q);
void printHashTable(HashTable *hash, int M);

int main(void) {
   int M, N, data, q;
   HashTable *hash = NULL;
   char command;

   scanf("%d %d %d", &M, &N, &q);
   hash = (HashTable *)malloc(sizeof(HashTable) * M);
   initHashtable(hash, M);

   while (1) {
      scanf("%c", &command);

      if (command == 'i') {
         scanf("%d", &data);
         insertItem(hash, M, data, q);
         getchar();
      }
      else if (command == 's') {
         scanf("%d", &data);
         searchItem(hash, M, data, q);
         getchar();
      }
      else if (command == 'p'){
         printHashTable(hash, M);
      }
      else if (command == 'e') {
         printHashTable(hash, M); //인쇄후 종료
         break;
      }
   }
   free(hash);
   return 0;
}

void initHashtable(HashTable *hash, int M) {
   for (int i = 0; i < M; i++) hash[i].data = 0;
}

int hashFunction(int x, int i, int M, int q) {
   return (x +  i * hashSecondFunction(x, q)) % M;
}
int hashSecondFunction(int x, int q) {
   return q - (x % q);
}
void insertItem(HashTable *hash, int M, int data, int q) {
   int i = 0,num;

   while (i < M) {
      num = hashFunction(data, i, M, q);
      if (hash[num].data == 0) {
         hash[num].data = data;
         printf("%d", num);
         break;
      }
      else
         printf("C");
      i++;
   }
   printf("\n");
}

void searchItem(HashTable *hash, int M, int data, int q) {
   int i = 0,num;

   while (i < M) {
      num = hashFunction(data, i, M, q);
      if (hash[num].data == data) {
         printf("%d %d\n", num, data);
         return;
      }
      i++;
   }
   printf("-1\n"); // 없음
}

void printHashTable(HashTable *hash, int M) {
   for (int i = 0; i < M; i++) printf(" %d", hash[i].data);
   printf("\n");
}
