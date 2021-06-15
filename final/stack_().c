#include <stdio.h>


typedef struct stack {
	int top;
	char arr[1000];
}Stack;

Stack *init();
int isOpenPar(char e);
int isClosedPar(char e);
void push(Stack *stack, char e);
char pop(Stack *stack);
int isEmpty(Stack *stack);
int isCounterPar(char a, char b);
int isBalanced(char str[]);


int main() {
	char str[1000];
	gets(str);
	int cnt = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isOpenPar(str[i])) {
			cnt++;
		}
		else if (isClosedPar(str[i])) {
			cnt++;
		}
	}
	if (isBalanced(str)) {
		printf("OK_%d", cnt);
	}
	else {
		printf("Wrong_%d", cnt);
	}
	return 0;
}

Stack *init() {
	struct stack *S = (struct stack *)malloc(sizeof(struct stack));
	S->top = -1;
	return S;
}
int isOpenPar(char e) {
	if (e == '(') {
		return 1;
	}
	if (e == '{') {
		return 1;
	}
	if (e == '[') {
		return 1;
	}
	return 0;
}
int isClosedPar(char e) {
	if (e == ')') {
		return 1;
	}
	if (e == '}') {
		return 1;
	}
	if (e == ']') {
		return 1;
	}
	return 0;
}
void push(Stack *stack, char e) {
	stack->top += 1;
	stack->arr[stack->top] = e;
}
char pop(Stack *stack) {
	char e = stack->arr[stack->top];
	stack->top -= 1;
	return e;
}
int isEmpty(Stack *stack) {
	if (stack->top == -1) {
		return 1;
	}
	return 0;
}
int isCounterPar(char a, char b) {
	if (b == ')') {
		if (a == '(') {
			return 1;
		}
	}
	else if (b == '}') {
		if (a == '{') {
			return 1;
		}
	}
	else if (b == ']') {
		if (a == '[') {
			return 1;
		}
	}
	return 0;
}
int isBalanced(char str[]) {
	Stack *stack = init();
	for (int i = 0; i < strlen(str); i++) {
		if (isOpenPar(str[i])) {
			push(stack, str[i]);
		}
		else if (isClosedPar(str[i])) {
			if (isCounterPar(stack->arr[stack->top], str[i])) {
				pop(stack);

			}
			else {
				return 0;
			}
		}

	}
	if (isEmpty(stack)) {
		return 1;
	}
	else {
		return 0;
	}
}