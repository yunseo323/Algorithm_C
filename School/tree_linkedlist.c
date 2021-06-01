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

typedef struct _treeNode {
	int data;
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

TreeNode *initTree(int data) { //data를 입력받고 그 값으로 초기화
	TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

TreeNode *findNode(TreeNode *n, int num) {  //입력받은 data로 시작 노드 찾기
	TreeNode *p;
	if (n != NULL) {
		if (n->data == num) {
			return n;
		}
		p = findNode(leftChild(n), num);
		if (p != NULL) return p;
		p = findNode(rightChild(n), num);
		if (p != NULL) return p;
	}
	return NULL;
}

void *makeTree(TreeNode *root, int p, int l, int r) {
	TreeNode *s;
	if (l == 0 && r == 0) return;// 둘다 0이면 건너뛰기
	else {
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

		sArr[0] = '\0';//초기화
		printf("\n");
	}
	return 0;
}