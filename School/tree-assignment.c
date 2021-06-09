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
	struct _treeNode *left; //���� child ���
	struct _treeNode *right; //���� child ���
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

TreeNode *initTree(int id, char data) { //data�� id�� �Է¹ް� �� ������ �ʱ�ȭ
	TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
	new->id = id;
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

TreeNode *findNode(TreeNode *n, int num) {  //�Է¹��� id�� ���� ��� ã��
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

void *makeTree(TreeNode *root, int p, int l, int r) {
	TreeNode *s;
	if (l == 0 && r == 0) return;// �Ѵ� 0�̸� �ǳʶٱ�
	else {
		if (root->id != p) {
			s = findNode(root, p);
		}
		else {
			s = root;
		}

		if (l != 0) {
			s->left = initTree(l, NULL);
		}
		if (r != 0) {
			s->right = initTree(r, NULL);
		}
	}

}
void preorder(TreeNode *t) { //������ȸ
	if (t != NULL) {
		printf(" %c", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(TreeNode *t) { //������ȸ
	if (t != NULL) {
		inorder(t->left);
		printf(" %c", t->data);
		inorder(t->right);
	}
}
void postorder(TreeNode *t) { //������ȸ
	if (t != NULL) {
		postorder(t->left);
		postorder(t->right);
		printf(" %c", t->data);
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
	char ch;
	int searchCnt, search, startId;
	char sArr[100] = { NULL }, *c;
	TreeList *tree = (TreeList *)malloc(sizeof(TreeList));
	TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *rn;
	rn = tree->root;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d %d %c", &s, &l, &r, &ch);
		getchar();
		if (i == 0) {
			rn = initTree(s, ch);
		}
		makeTree(rn, s, l, r);
	}

	scanf("%d", &searchCnt); //��ȸȽ��

	rn = tree->root;
	for (i = 0; i < searchCnt; i++) {
		scanf("%d %d", &search, &startId);
		if (search == 1) { //����
			preorder(findNode(rn, startId));
		}
		else if (search == 2) {//����
			inorder(findNode(rn, startId));
		}
		else {//����
			postorder(findNode(rn, startId));
		}
	}
	return 0;
}