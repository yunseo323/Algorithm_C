#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _stack {
	char *top;
	char *arr;
	int cnt;
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
	char str[1000] = { 0 };
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
	Stack *S = (Stack *)malloc(sizeof(Stack));
	S->arr = (char *)malloc(sizeof(char) * 1000);
	S->top = S->arr;
	S->cnt = 0;
	return S;
}
int isOpenPar(char e) {
	if (e == '(' || e == '{' || e == '[') {
		return 1;
	}
	return 0;
}
int isClosedPar(char e) {
	if (e == ')' || e == '}' || e == ']') {
		return 1;
	}
	return 0;
}
void push(Stack *stack, char e) {
	stack->top += 1;
	*(stack->top) = e;
	stack->cnt++;
}
char pop(Stack *stack) {
	char e = *(stack->top);
	stack->top -= 1;
	stack->cnt--;
	return e;
}
int isEmpty(Stack *stack) {
	if (stack->cnt == 0) {
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
		if (isOpenPar(str[i])) { //¿©´Â °ýÈ£ push
			push(stack, str[i]);
		}
		else if (isClosedPar(str[i])) { //´Ý´Â °ýÈ£¿¡ °Ë»ç
			if (isCounterPar(*(stack->top), str[i])) {
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