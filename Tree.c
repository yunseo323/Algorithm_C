//이진 트리 노드 요소 정의
typedef struct _treeNode {
	int index;
	int data;
	struct _treeNode *left; //좌측 child 노드
	struct _treeNode *right; //우측 child 노드
}TreeNode;

TreeNode *initTree(int num) { //data를 입력받고 그 값으로 초기화
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

	root->data = num;
	root->left = NULL;
	root->right = NULL;
	return root;
}


/*접근 메소드*/

TreeNode *leftChild(TreeNode *p) {
	return p->left;
}

TreeNode *rightChild(TreeNode *p) {
	return p->right;
}

//노드 삽입
TreeNode *createParentNode(int data, TreeNode *n1, TreeNode *n2) {
	TreeNode *parent = init(data);
	parent->left = n1;
	parent->right = n2;

	return parent;
}