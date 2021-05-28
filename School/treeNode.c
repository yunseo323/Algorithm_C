
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//���� Ʈ�� ��� ��� ����
typedef struct _treeNode {
	int id;
	int data;
	struct _treeNode *left; //���� child ���
	struct _treeNode *right; //���� child ���
}TreeNode;


TreeNode *initTree(int id, int data) { //data�� �Է¹ް� �� ������ �ʱ�ȭ
	TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
	new->id = id;
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}
TreeNode *leftChild(TreeNode *t) {
	return t->left;
}
TreeNode *rightChild(TreeNode *t) {
	return t->right;
}
TreeNode *findNode(TreeNode *root, int id) { //�Է¹��� id�� ���� ��� ã��
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	node = root;
	if (node != NULL) {
		if (node->id == id) return node;
		node = findNode(leftChild(root), id);
		if (node != NULL) return node;
		node = findNode(rightChild(root), id);
		if (node != NULL) return node;
	}

	return NULL;
}
void preorder(TreeNode *t) { //������ȸ
	if (t != NULL) {
		printf(" %d", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(TreeNode *t) { //������ȸ
	if (t != NULL) {
		inorder(t->left);
		printf(" %d", t->data);
		inorder(t->right);
	}
}
void postorder(TreeNode *t) { //������ȸ
	if (t != NULL) {
		postorder(t->left);
		postorder(t->right);
		printf(" %d", t->data);
	}
}
int cal(TreeNode *t) { //������ȸ�� ������ ���ϱ�
	int left = 0, right = 0;
	if (t == NULL) return 0;
	else {
		left = cal(t->left);
		right = cal(t->right);
		return left + right + t->data;
	}
}


TreeNode *makeTree() { //Ư�� Ʈ�� ����
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	root = initTree(1, 20);
	root->left = initTree(2, 30);
	root->left->left = initTree(4, 70);
	root->left->right = initTree(5, 90);
	root->right = initTree(3, 50);
	root->right->right = initTree(6, 120);
	root->right->right->left = initTree(7, 130);
	root->right->right->right = initTree(8, 80);
	return root;
}

int main() {
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *search = (TreeNode *)malloc(sizeof(TreeNode));
	int nodeId;
	root = makeTree();

	scanf("%d", &nodeId);
	search = findNode(root, nodeId);
	if (search == NULL)  printf("-1");
	else {
		printf("%d", cal(search));
	}

	return 0;
}