
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//이진 트리 노드 요소 정의
typedef struct _treeNode {
	int id;
	int data;
	struct _treeNode *left; //좌측 child 노드
	struct _treeNode *right; //우측 child 노드
}TreeNode;


TreeNode *initTree(int id, int data) { //data를 입력받고 그 값으로 초기화
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
TreeNode *findNode(TreeNode *root, int id) { //입력받은 id로 시작 노드 찾기
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
void preorder(TreeNode *t) { //전위순회
	if (t != NULL) {
		printf(" %d", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(TreeNode *t) { //중위순회
	if (t != NULL) {
		inorder(t->left);
		printf(" %d", t->data);
		inorder(t->right);
	}
}
void postorder(TreeNode *t) { //후위순회
	if (t != NULL) {
		postorder(t->left);
		postorder(t->right);
		printf(" %d", t->data);
	}
}
int cal(TreeNode *t) { //후위순회로 데이터 구하기
	int left = 0, right = 0;
	if (t == NULL) return 0;
	else {
		left = cal(t->left);
		right = cal(t->right);
		return left + right + t->data;
	}
}


TreeNode *makeTree() { //특정 트리 제작
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