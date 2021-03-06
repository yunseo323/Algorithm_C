//���� Ʈ�� ��� ��� ����
typedef struct _treeNode {
	int id; //���� id
	int data;
	struct _treeNode *left; //���� child ���
	struct _treeNode *right; //���� child ���
}TreeNode;

TreeNode *initTree(int id, int num) { //data�� �Է¹ް� �� ������ �ʱ�ȭ
	TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
	new->id = id;
	new->data = num;
	new->left = NULL;
	new->right = NULL;
	return new;
}
/*��ȸ �޼ҵ�*/

void postOrder(TreeNode *root) { //������ȸ
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d", root->data);
	}
}

void inOrder(TreeNode *root) { //������ȸ
	if (root != NULL) {
		inOrder(root->left);
		printf(" %d", root->data);
		inOrder(root->right);
	}
}

void preOrder(TreeNode *root) { //������ȸ
	if (root != NULL) {
		printf(" %d", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
/*���� �޼ҵ�*/

TreeNode *leftChild(TreeNode *p) {
	return p->left;
}

TreeNode *rightChild(TreeNode *p) {
	return p->right;
}

TreeNode *findSamdID(TreeNode *root, int id) { //���� ���� ��Ʈ ���, ã�� ���� id
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
//��� ����

TreeNode *createParentNode(int id, int data, TreeNode *n1, TreeNode *n2) {
	TreeNode *parent;
	parent = initTree(id, data);
	parent->left = n1;
	parent->right = n2;

	return parent;
}
