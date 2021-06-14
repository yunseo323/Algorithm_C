#include <stdio.h>
#include <string.h>

typedef struct node {
	char data;
	struct node *next;
}Node;

typedef struct stack {
	struct node *top;
}Stack;

Stack *init() { //���� ���Ḯ��Ʈ �ʱ�ȭ
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}

int isEmpty(Stack *stack) {
	if (stack->top == NULL) {
		return 1; //������� 1 ��ȯ
	}
	return 0;
}

void push(Stack *stack, char ch) { //���ÿ� ��带 ����
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = ch;
	p->next = stack->top;
	stack->top = p;
	return 0;
}
char pop(Stack *stack) { //���ÿ� ��� ����
	if (!isEmpty(stack)) {
		Node *p = stack->top;
		char e = stack->top->data;
		stack->top = stack->top->next;
		free(p);
		p = NULL;
		return e;
	}
}


int isOperand(char s) {//�ǿ�����(����)���� �Ǵ�
	if (s >= '0' && s <= '9') {
		return 1;
	}
	else return 0;
}

void write(int s) {
	printf("%d", s);
}

char top(Stack *S) {//top�� ������� ������ ���� ��ȯ
	if (S->top == NULL) {
		return -1;
	}
	return S->top->data;
}

int charToInt(char s) {
	int a;
	a = s - '0';
	return a;
}
char intToChar(int s) {
	char a;
	a = s + '0';
	return a;
}
int doOperator(char op, int x, int y) {
	if (op == '+') {
		return x + y;
	}
	else if (op == '-') {
		return x - y;
	}
	else if (op == '*') {
		return x * y;
	}
	else if (op == '/') {
		return x / y;
	}

}

void evaluate(char str[]) {
	struct stack *S = NULL;
	S = init();
	int i = 0, x, y;
	int len = strlen(str);
	char s;

	while (i < len) {
		s = str[i];
		if (isOperand(s)) {//���ڸ�
			push(S, s);
		}
		else {
			x = charToInt(pop(S));
			y = charToInt(pop(S));
			push(S, intToChar(doOperator(s, y, x)));
		}
		i++;
	}
	write(charToInt(pop(S)));
}

int main() {
	char str[100];
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%s", str);
		getchar();
		evaluate(str);
		printf("\n");
	}
	return 0;
}
