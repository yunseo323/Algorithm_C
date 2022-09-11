#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
LR

*/

typedef struct _treeNode { //트리노드
   int data;
   struct _treeNode *left;
   struct _treeNode *right;
}TreeNode;
typedef struct _treeList { //트리 리스트
   TreeNode *root; //root
}TreeList;
TreeNode *leftChild(TreeNode *t) { //왼쪽 자식노드 반환
   return t->left;
}
TreeNode *rightChild(TreeNode *t) {//오른쪽 자식노드 반환
   return t->right;
}

TreeNode *initTree(int data) {//트리 초기화
   TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
   new->data = data;
   new->left = NULL;
   new->right = NULL;
   return new;
}

TreeNode *findNode(TreeNode *n, int num) { //트리 노드 검색
   TreeNode *p;
   if (n != NULL) {
      if (n->data == num) {
         return n;
      }
       //재귀사용
      p = findNode(leftChild(n), num);
      if (p != NULL) return p;
      p = findNode(rightChild(n), num);
      if (p != NULL) return p;
   }
   return NULL;
}

void *makeTree(TreeNode *root, int p, int l, int r) { //트리 생성
   TreeNode *s;
   if (!(l == 0 && r == 0)){
      if (root->data != p) {
         s = findNode(root, p);
      }
      else {
         s = root;
      }

      if (l != 0) {
         s->left = initTree(l);
      }
      if (r != 0) {
         s->right = initTree(r);
      }
   }
}

TreeNode *moveLeft(TreeNode *m) {
   TreeNode *p;
   p = m->left;
   return p;
}
TreeNode *moveRight(TreeNode *m) {
   TreeNode *p;
   p = m->right;
   return p;
}
int main() {
   int N, i, j;
   int s, l, r;
   int search, len;
   char sArr[100] = { NULL }, *c;
   TreeList *tree = (TreeList *)malloc(sizeof(TreeList));
   TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
   TreeNode *rn;
   rn = tree->root;
   scanf("%d", &N);

   for (i = 0; i < N; i++) {
      scanf("%d %d %d", &s, &l, &r);
      if (i == 0) {
         rn = initTree(s);
      }
      makeTree(rn, s, l, r);
   }

   scanf("%d", &search);

   for (i = 0; i < search; i++) {
      getchar();
      scanf("%s", sArr);
      len = strlen(sArr);
      c = sArr;
      p = rn;
      printf(" %d", p->data);
      for (j = 0; j < len; j++) {
         if (*c == 'R') {
            p = moveRight(p);
         }
         else if (*c == 'L') {
            p = moveLeft(p);
         }
         printf(" %d", p->data);
         c++;
      }

      sArr[0] = '\0';
      printf("\n");
   }
   return 0;
}
