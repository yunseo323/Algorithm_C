//2��
/*
6
3 7 45 88 99 101
4
7 10 15 45

0
3
9 20 77

3
1 3 5
2
1 7

0
0
*/
#include <stdio.h>

//���
typedef struct __node {
	int data;
	struct __node *next;
}Node;


Node *CreateNode() {//������
	Node *new;
	new = (Node *)malloc(sizeof(Node));
	return new;
}

//n�� ����Ű�� ��忡 data ����
void SetData(Node *n, int x) {
	n->data = x;
}

void InsertNode(Node *header, int x) { //���ο���, ����
	Node *new = CreateNode();
	Node *s = header;
	while (s->next != NULL) {
		s = s->next;
	}
	s->next = new;
	new->data = x;
	new->next = NULL;
}

int SearchData(int num, Node *header) {
	Node *p = header;
	p = p->next;
	while (p != NULL) {
		if (num == p->data) {
			return 1; //ã���� 1 ��ȯ
		}
		else {
			p = p->next;
		}
	}
	return 0;
}
int subset(Node *pA, Node *pB) { //����A�� ����B�� �κ��������� �˻�
	int sameCnt = 0;
	int findMin = 0;
	int flag = 0;
	int aCount = 0;

	while (pA->next != NULL) {
		pA = pA->next;
		aCount++;
		//printf("%d ", pA->data);
		if (SearchData(pA->data, pB) == 0) { //��ġ�ϴ� ���Ұ� ���ٸ�
			if (flag == 0) {//ó��
				findMin = pA->data;
				flag++;
			}
			else
				findMin = findMin < pA->data ? findMin : pA->data;
		}
		else { //��ġ�Ѵٸ�
			sameCnt++;
		}
	}
	if (sameCnt == aCount || aCount == 0) {//0 return �ϴ� ���: listA->cnt==0, �κ�����
		return 0;
	}
	else {
		return findMin;
	}
}
Node *Union(Node *pA, Node *pB) { //���� ����,ū����
	int flag = 0, flag2 = 0;
	int aCount = 0;
	Node *re = CreateNode();
	re->next = NULL;
	Node *sB = pB;
	Node *sr = re;
	Node *p = CreateNode();
	//ū���� �� �Űܴ��
	while (sB->next != NULL) {
		sB = sB->next;
		InsertNode(re, sB->data);
		flag++;
	}
	while (pA->next != NULL) {
		pA = pA->next;
		if (SearchData(pA->data, pB) == 0) { //��ġ�ϴ� ���Ұ� ���ٸ�
			flag2++;
			p = CreateNode(); //��!!!!keypoint
			while (1) {
				if (sr->next == NULL || sr->next->data > pA->data) break; //��������
				sr = sr->next;
			}
			p->data = pA->data;
			p->next = sr->next;
			sr->next = p;
		}
		else { //��ġ�Ѵٸ�
			continue;
		}
		sr = re;//�ʱ�ȭ
	}
	if (flag == 0 && flag2 == 0) { //�������� �������
		InsertNode(re, 0);
		return re;
	}
	else {
		return re;
	}

}
Node *Intersect(Node *pA, Node *pB) { //���� ����, ū����
	int flag = 0;
	int aCount = 0;
	Node *re = CreateNode();
	re->next = NULL;

	while (pA->next != NULL) {
		pA = pA->next;
		aCount++;
		if (SearchData(pA->data, pB) == 0) { //��ġ�ϴ� ���Ұ� ���ٸ�
			continue;
		}
		else { //��ġ�Ѵٸ�
			flag++;
			InsertNode(re, pA->data);
		}
	}
	if (flag == 0) { //�������� �������
		InsertNode(re, 0);
		return re;
	}
	else {
		return re;
	}
}
int main() {
	int aSize, bSize;
	int re = 0;
	int i, a, b;
	Node *n = NULL;
	Node *aHeader = CreateNode();
	Node *bHeader = CreateNode();
	Node *uHeader = CreateNode();//������ ���
	Node *iHeader = CreateNode();//������ ���

	Node *sm, *bi;
	aHeader->next = NULL;
	bHeader->next = NULL;
	//A
	scanf("%d", &aSize);
	for (i = 0; i < aSize; i++) {
		scanf("%d", &a);
		InsertNode(aHeader, a);
	}

	//B
	scanf("%d", &bSize);
	for (i = 0; i < bSize; i++) {
		scanf("%d", &b);
		InsertNode(bHeader, b);
	}
	aSize < bSize ? (sm = aHeader, bi = bHeader) : (sm = bHeader, bi = aHeader);

	uHeader = Union(sm, bi);
	while (uHeader->next != NULL) {
		uHeader = uHeader->next;
		printf(" %d", uHeader->data);
	}
	printf("\n");
	iHeader = Intersect(sm, bi);
	while (iHeader->next != NULL) {
		iHeader = iHeader->next;
		printf(" %d", iHeader->data);
	}
	return 0;
}
