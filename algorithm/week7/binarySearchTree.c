//이진탐색트리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
i 9
i 2
i 15
i 1
i 7
i 11
i 5
i 8
i 3
i 4
p
d 2
d 13
p
q
 */
typedef struct _Node {
   int key; //키만 존재
   struct _Node *parent, *lChild, *rChild;
} Node;

typedef struct _Tree {
   Node *root;
} Tree;

/*basic*/
Node *getNode();
void initTree(Tree *tree);
void printTree(Node *node);
void freeTree(Node *node);

/*tree*/
int findElement(Tree tree, int key);
void insertItem(Tree tree, int key); //현재 트리에 키 k를 저장한 새 노드를 삽입
Node *treeSearch(Node *node, int key); //현재 트리에서 키 k를 저장한 노드를 반환
int removeElement(Tree *tree, int key); //현재 트리에서 키 k를 저장한 노드를 삭제한 후 원소를 반환
int isExternal(Node *node); //외부노드(자식노드 없음)인지 여부
int isInternal(Node *node); //내부노드인지 여부
Node* inOrderSucc(Node* w); //노드 w의 중위순회 후계자를 반환
Node *sibling(Node *node); //sibling 노드 반환
void reduceExternal(Tree *tree, Node *node);

int main(){
   Tree tree;
   char command;
   int key, result;
   initTree(&tree);
   while(1){
      scanf("%c",&command);
      if(command=='i'){
         scanf("%d", &key);
         insertItem(tree, key);
         getchar();
      }
      else if(command=='d'){
         scanf("%d", &key);
         getchar();
         result = removeElement(&tree, key);
         if (result != NULL) printf("%d\n", result);
         else printf("X\n");
      }
      else if(command=='s'){
         scanf("%d", &key);
         getchar();
         result = findElement(tree, key);
         if (result != NULL) printf("%d\n", result);
         else printf("X\n");
      }
      else if(command=='p'){
         printTree(tree.root);
         printf("\n");
      }
      else if(command=='q'){
         break;
      }
   }
   
   freeTree(tree.root);
   return 0;
}

/*basic*/
Node *getNode(){
   Node *p = (Node *)malloc(sizeof(Node));
   p->parent = NULL;
   p->lChild = NULL;
   p->rChild = NULL;
   return p;
}
void initTree(Tree *tree){
   tree->root = getNode();
}
void printTree(Node *node){
   if (isInternal(node)) printf(" %d", node->key);
   if (isInternal(node->lChild)) printTree(node->lChild);
   if (isInternal(node->rChild)) printTree(node->rChild);
}
void freeTree(Node *node){
   if (node->lChild != NULL) freeTree(node->lChild);
   if (node->rChild != NULL) freeTree(node->rChild);
   free(node);
}


/*tree*/
int isExternal(Node *node){ //자식노드 x
   if (node->lChild == NULL && node->rChild == NULL) return 1;
      else return 0;
}
int isInternal(Node *node){ //자식노드 o
   if (node->lChild != NULL || node->rChild != NULL) return 1;
      else return 0;
}
Node *sibling(Node *node){
   if (node->parent == NULL) return NULL; //루트노드 일경우
   if (node->parent->lChild == node) return node->parent->rChild; //본인이 왼쪽노드일 경우 오른쪽 노드 반환
   else return node->parent->lChild;
}
Node* inOrderSucc(Node* w){
   w = w->rChild;
   if (isExternal(w)) return NULL; //말단일 경우
   while (isInternal(w->lChild)) w = w->lChild;
   return w;
}
void reduceExternal(Tree *tree, Node *node){
   Node *pN = node->parent;
   Node *sN = sibling(node);
   Node *ppN; //node의 parent의 parent
   
   if (pN->parent == NULL) {
      tree->root = sN;
      sN->parent = NULL;
   }
   else {
      ppN = pN->parent;
      sN->parent = ppN;
      if (ppN->lChild == pN) ppN->lChild = sN;
      else ppN->rChild = sN;
   }
   free(node);
   free(pN);
      
}
Node *treeSearch(Node *node, int key){
   if (isExternal(node)) return node;
   
   if (key == node->key) return node;
   else if (key > node->key) return treeSearch(node->rChild, key);
   else return treeSearch(node->lChild, key);
}

void insertItem(Tree tree, int key){
   Node *node = treeSearch(tree.root, key);
   if (isInternal(node)) return;
   else {
      node->key = key;
      node->lChild = getNode();
      node->lChild->parent = node;
      node->rChild = getNode();
      node->rChild->parent = node;
   }

}
int findElement(Tree tree, int key){
   Node *node = treeSearch(tree.root, key);
   if (isExternal(node)) return NULL; //null
   else return key;
}

int removeElement(Tree *tree, int key){
   Node *node = treeSearch(tree->root, key);
   Node *osN, *cN;
   int keyValue;
   
   if (isExternal(tree->root)) return NULL;
   if (isExternal(node)) return NULL;

   keyValue = node->key;
   cN = node->lChild;
   if (!isExternal(cN)) cN = node->rChild;

   if (isExternal(cN)) {
      reduceExternal(tree, cN);
   }
   else {
      osN = inOrderSucc(node);
      cN = osN->lChild;
      node->key = osN->key;
      reduceExternal(tree, cN);
   }

   return keyValue;
      
}




