#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0

2
2 7 3 0
3
-3 10 3 7 -3 0
*/
typedef struct _node {
	int coef; //항의 계수
	int exp; //항의 차수
	struct _node *next;
}Node;

Node *getNode() {
	Node *new = (Node *)malloc(sizeof(Node));
	new->coef = 0;
	new->exp = 0;
	new->next = NULL;
	return new;
}
void appendTerm(Node *k, int c, int e) {//마지막항, 계수, 차수
	k->coef = c;
	k->exp = e;
	k->next = NULL;
}
Node *addPoly(Node *x, Node *y) { //헤더 입력받음
	Node *n = getNode();
	Node *re;
	int i, max;
	int flag = 0;
	re = n;
	x = x->next;
	y = y->next;
	max = x->exp > y->exp ? x->exp : y->exp;
	//printf("%d %d\n",x->exp,y->exp);
	for (i = max; i >= 0; i--) {
		//printf("I\n");
		if (x == NULL && y == NULL) break;//하나도 안남아있으면 break
		if (x != NULL && i == x->exp) {
			n->next = getNode(); //순서주의
			n = n->next;
			flag++;
			n->coef += x->coef;
			n->exp = i;
			x = x->next;
		}
		if (y != NULL && i == y->exp) {
			if (flag == 0) {
				n->next = getNode(); //순서주의
				n = n->next;
			}
			n->coef += y->coef;
			n->exp = i;
			y = y->next;
		}
		//printf("%d %d\n", n->coef, n->exp);
		flag = 0;
	}
	return re;
}
int main() {
	int a, b, i, j, index;
	int c1, e1, c2, e2;
	Node *header1 = getNode();
	Node *k1, *k2;
	Node *header2 = getNode();
	Node *re;

	scanf("%d", &a);
	header1->next = getNode();
	k1 = header1->next;
	for (i = 0; i < a; i++) {
		scanf("%d %d", &c1, &e1);
		appendTerm(k1, c1, e1);
		if (i == a - 1)break;
		k1->next = getNode(); //순서주의
		k1 = k1->next;
	}
	scanf("%d", &b);
	header2->next = getNode();
	k2 = header2->next;
	for (i = 0; i < b; i++) {
		scanf("%d %d", &c2, &e2);
		appendTerm(k2, c2, e2);
		if (i == b - 1) break;
		k2->next = getNode(); //순서주의
		k2 = k2->next;
	}

	k1 = header1->next;
	k2 = header2->next;
	for (i = 0; i < a; i++) {
		k1 = k1->next;
	}
	for (i = 0; i < b; i++) {
		k2 = k2->next;
	}

	re = addPoly(header1, header2);
	re = re->next;
	while (1) {
		if (re == NULL) break;
		if (re->coef == 0) {
			re = re->next;
			continue;
		}
		printf(" %d %d", re->coef, re->exp);
		re = re->next;
	}
	return 0;
}
