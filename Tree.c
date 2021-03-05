//���� Ʈ�� ��� ��� ����
typedef struct _treeNode {
	int index;
	int data;
	struct _treeNode *left; //���� child ���
	struct _treeNode *right; //���� child ���
}TreeNode;

TreeNode *initTree(int num) { //data�� �Է¹ް� �� ������ �ʱ�ȭ
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

	root->data = num;
	root->left = NULL;
	root->right = NULL;
	return root;
}


/*���� �޼ҵ�*/

TreeNode *leftChild(TreeNode *p) {
	return p->left;
}

TreeNode *rightChild(TreeNode *p) {
	return p->right;
}

//��� ����
TreeNode *createParentNode(int data, TreeNode *n1, TreeNode *n2) {
	TreeNode *parent = init(data);
	parent->left = n1;
	parent->right = n2;

	return parent;
}