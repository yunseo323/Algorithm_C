//해시테이블 - 개방주소법(선형 주소법)
#include <stdio.h>
#include <stdlib.h>

typedef struct _HashTable {
   int data;
} HashTable;

void initHashtable(HashTable *hash, int M);
int hashFunction(int x, int i, int M);
void insertItem(HashTable *hash, int M, int data);
void searchItem(HashTable *hash, int M, int data);

int main(void) {
   int M, N, data;
   HashTable *hash = NULL;
   char command;

   scanf("%d %d", &M, &N);
   hash = (HashTable *)malloc(sizeof(HashTable) * M);
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
      else if (command == 'e')
         break;
   }

   free(hash);

   return 0;
}

void initHashtable(HashTable *hash, int M) {
   for (int i = 0; i < M; i++) hash[i].data = 0;
}

int hashFunction(int x, int i, int M) {
   return (x + i) % M;
}

void insertItem(HashTable *hash, int M, int data) {
   int i = 0,num;

   while (i < M) {
      num = hashFunction(data, i, M);
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

void searchItem(HashTable *hash, int M, int data) {
   int i = 0,num;

   while (i < M) {
      num = hashFunction(data, i, M);
      if (hash[num].data == 0) { //없음
         printf("-1\n");
         return;
      }
      else if (hash[num].data == data) {
         printf("%d %d\n", num, data);
         return;
      }
      i++;
   }
   printf("-1\n"); // 없음
}
