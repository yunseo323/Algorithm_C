//이진 트리 노드 요소 정의
typedef struct _treeNode {
	int id; //폴더 id
	int data;
	struct _treeNode *left; //좌측 child 노드
	struct _treeNode *right; //우측 child 노드
}TreeNode;

TreeNode *initTree(int id, int num) { //data를 입력받고 그 값으로 초기화
	TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
	new->id = id;
	new->data = num;
	new->left = NULL;
	new->right = NULL;
	return new;
}
/*순회 메소드*/

void postOrder(TreeNode *root) { //후위순회
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d", root->data);
	}
}

void inOrder(TreeNode *root) { //중위순회
	if (root != NULL) {
		inOrder(root->left);
		printf(" %d", root->data);
		inOrder(root->right);
	}
}

void preOrder(TreeNode *root) { //전위순회
	if (root != NULL) {
		printf(" %d", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
/*접근 메소드*/

TreeNode *leftChild(TreeNode *p) {
	return p->left;
}

TreeNode *rightChild(TreeNode *p) {
	return p->right;
}

TreeNode *findSamdID(TreeNode *root, int id) { //가장 상위 루트 노드, 찾을 폴더 id
	TreeNode *c = NULL;
	if (root != NULL) {
		if (root->id == id) return root;
		c = findSamdID(leftChild(root), id);
		if (c != NULL) return c;
		c = findSamdID(rightChild(root), id);
		if (c != NULL) return c;
	}
	else return NULL;
}
//노드 삽입

TreeNode *createParentNode(int id, int data, TreeNode *n1, TreeNode *n2) {
	TreeNode *parent;
	parent = initTree(id, data);
	parent->left = n1;
	parent->right = n2;

	return parent;
}
