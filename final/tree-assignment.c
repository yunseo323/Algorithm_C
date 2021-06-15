#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
9
1 2 7 A
2 3 4 B
3 0 0 D
4 5 6 F
5 0 0 C
6 0 0 M
7 8 9 N
8 0 0 Q
9 0 0 K
3
1 1
2 1
2 7
*/

typedef struct _treeNode {
    int id;
    char data;
    struct _treeNode *left; //좌측 child 노드
    struct _treeNode *right; //우측 child 노드
}TreeNode;
typedef struct _treeList {
    TreeNode *root;
}TreeList;
TreeNode *leftChild(TreeNode *t) {
    return t->left;
}
TreeNode *rightChild(TreeNode *t) {
    return t->right;
}

TreeNode *initTree(int id, char data) { //data와 id를 입력받고 그 값으로 초기화
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->id = id;
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

TreeNode *findNode(TreeNode *n, int num) {  //입력받은 id로 시작 노드 찾기
    TreeNode *p;
    if (n != NULL) {
        if (n->id == num) return n;
        p = findNode(leftChild(n), num);
        if (p != NULL) return p;
        p = findNode(rightChild(n), num);
        if (p != NULL) return p;
    }
    return NULL;
}

void *makeTree(TreeNode *root, int p, int l, int r, char ch) {
    TreeNode *s;
    if (root->id != p) {//루트아닐때
        s = findNode(root, p);
        s->data = ch;
    }
    else {
        s = root;
        //s->data = ch;
    }

    if (l != 0) {
        s->left = initTree(l, NULL);
    }
    if (r != 0) {
        s->right = initTree(r, NULL);
    }
    return 0;
}
void preorder(TreeNode *t) { //전위순회
    if (t != NULL) {
        printf("%c", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(TreeNode *t) { //중위순회
    if (t != NULL) {
        inorder(t->left);
        printf("%c", t->data);
        inorder(t->right);
    }
}
void postorder(TreeNode *t) { //후위순회
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%c", t->data);
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
    int N, i;
    int s, l, r;
    char ch;
    int searchCnt, search, startId;
    char sArr[100] = { NULL };
    TreeList *tree = (TreeList *)malloc(sizeof(TreeList));
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *rn;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d %d %d %c", &s, &l, &r, &ch);
        getchar();
        if (i == 0) {
            tree->root = initTree(s, ch);
        }
        makeTree(tree->root, s, l, r, ch);
    }

    scanf("%d", &searchCnt); //순회횟수

    //rn = tree->root;
    for (i = 0; i < searchCnt; i++) {
        scanf("%d %d", &search, &startId);
        p = findNode(tree->root, startId);
        if (p == NULL) { //존재하지 않는 노드
            printf("-1\n");
            continue;
        }
        printf(" ");
        if (search == 1) { //전위
            preorder(p);
        }
        else if (search == 2) {//중위
            inorder(p);
        }
        else {//후위
            postorder(p);
        }
        printf("\n");
    }
    free(tree);
    free(p);
    
    return 0;
}
