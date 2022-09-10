//1번 배열로 구현
/*
4
10
POP
PUSH s
PUSH t
PUSH a
PUSH r
PRINT
UpR 3
PRINT
PUSH s
PEEK

5
11
PUSH s
PUSH r
PUSH a
PUSH t
PUSH s
PRINT
DownR 4
PRINT
POP
POP
PRINT

3
5
PUSH d
DUP
PUSH a
PRINT
PUSH s

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _stack {
	char *top;
	char *arr;
	int cnt;
	int size;
}Stack;

void init(Stack *stack, int N);
void push(Stack *stack, char ch);
void pop(Stack *stack);
void peek(Stack *stack);
void duplicate(Stack *stack);
void upRotate(Stack *stack, int n);
void downRotate(Stack *stack, int n);
void print(Stack *stack);

int main() {
	int N, calnum, i, num;
	char command[6] = { NULL }, ch;
	Stack *stack;
	stack = (Stack *)malloc(sizeof(Stack));
	scanf("%d", &N);
	init(stack, N);
	scanf("%d", &calnum);
	getchar();

	for (i = 0; i < calnum; i++) {
		scanf("%s", command);
		getchar();
		if (strcmp(command, "POP") == 0) {
			pop(stack);
		}
		else if (strcmp(command, "PUSH") == 0) {
			scanf("%c", &ch);
			push(stack, ch);
			getchar();
		}
		else if (strcmp(command, "PEEK") == 0) {
			peek(stack);
		}
		else if (strcmp(command, "DUP") == 0) {
			duplicate(stack);
		}
		else if (strcmp(command, "UpR") == 0) {
			scanf("%d", &num);
			upRotate(stack, num);
		}
		else if (strcmp(command, "DownR") == 0) {
			scanf("%d", &num);
			downRotate(stack, num);
		}
		else if (strcmp(command, "PRINT") == 0) {
			print(stack);
		}
	}
	return 0;
}
void init(Stack *stack, int N) {
	stack->arr = (char *)malloc(N * sizeof(char));
	stack->size = N;
	stack->top = stack->arr;
	stack->cnt = 0;
}

void push(Stack *stack, char ch) {
	if (stack->cnt == stack->size) {
		printf("Stack FULL\n");
	}
	else {
		if (stack->cnt > 0) (stack->top)++; //top을 증가시키고 대입함
		*(stack->top) = ch;

		stack->cnt++;
	}
}

void pop(Stack *stack) {
	char ch = *(stack->top);
	ch = stack->top;
	if (stack->cnt == 0) printf("Stack Empty\n");
	else {
		(stack->top)--;
		stack->cnt--;
	}
	return ch;
}

void peek(Stack *stack) { //top 출력
	if (stack->cnt == 0) printf("Stack Empty\n");
	printf("%c\n", *(stack->top));
}
void duplicate(Stack *stack) {
	char ch = *(stack->top);

	if (stack->cnt == stack->size) {
		printf("Stack FULL\n");
	}
	else {
		pop(stack);
		push(stack, ch);
		push(stack, ch);
	}
}
void upRotate(Stack *stack, int n) {
	int i;
	char tmp;
	if (n <= stack->cnt) {
		tmp = *(stack->top);
		for (i = stack->cnt - 2; i >= stack->cnt - n; i--) {
			stack->arr[i + 1] = stack->arr[i];
		}
		stack->arr[stack->cnt - n] = tmp;
	}
}
void downRotate(Stack *stack, int n) {
	int i;
	char tmp;
	if (n <= stack->cnt) {
		tmp = stack->arr[stack->cnt - n];
		for (i = stack->cnt - n + 1; i < stack->cnt; i++) {
			stack->arr[i - 1] = stack->arr[i];
		}
		*(stack->top) = tmp;
	}
}
void print(Stack *stack) {
	int i;
	char *p = stack->top;
	for (i = 0; i < stack->cnt; i++) {
		printf("%c", *p);
		p--;
	}
	printf("\n");
}