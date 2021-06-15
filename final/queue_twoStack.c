#include <stdio.h>
#include <string.h>

/*
�ΰ� �������� ������ ť
�Է� ->(push)->instack->(pop)->(push)->outstack

*/
typedef struct stack {
	char *top;
	char *arr;
	int cnt;
	int size;
}Stack;

typedef struct queue {
	Stack *inStack;
	Stack *outStack;
}Queue;

void initStack(Stack *stack, int N) {
	stack->arr = (char *)malloc(N * sizeof(char));
	stack->size = N;
	stack->top = stack->arr;
	stack->cnt = 0;
}

Queue *initQueue() { //�� ������ �ʱ�ȭ
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->inStack = (Stack *)malloc(sizeof(Stack));
	q->outStack = (Stack *)malloc(sizeof(Stack));
	initStack(q->inStack, 100);
	initStack(q->outStack, 100);

	return q;
}
void push(Stack *stack, char ch) {
	if (stack->cnt == stack->size) {
		printf("Stack FULL\n");
	}
	else {
		if (stack->cnt > 0) (stack->top)++; //top�� ������Ű�� ������
		*(stack->top) = ch;

		stack->cnt++;
	}
}

void pop(Stack *stack) { //���� ��ȯ
	char ch;
	if (stack->cnt == 0) printf("Stack Empty\n");
	else {
		(stack->top)--;
		stack->cnt--;
	}
}

void transfer(Queue *q) {
	push(q->outStack, *(q->inStack->top));
	pop(q->inStack);
}

void enqueue(Queue *q, char ch) {
	push(q->inStack, ch); //ù��° ���ÿ��� �߰�
}
void dequeue(Queue *q) {
	if (q->inStack->cnt == 0 && q->outStack->cnt == 0) printf("empty queue\n");
	else {
		if (q->outStack->cnt == 0) {
			while (q->inStack->cnt != 0) {
				transfer(q);
			}
		}
		printf("%c", *(q->outStack->top));
		pop(q->outStack); //����
	}
}
void front(Queue *q) {
	if (q->inStack->cnt == 0 && q->outStack->cnt == 0) printf("empty queue\n");
	else {
		if (q->outStack->cnt == 0) {
			while (q->inStack->cnt != 0) {
				transfer(q);
			}
		}
		printf("%c\n", *(q->outStack->top));//���
	}
}
void print(Queue *q) {
	char *p;
	if (q->inStack->cnt == 0 && q->outStack->cnt == 0) printf("empty queue\n");

	p = q->outStack->arr;
	for (int i = 0; i < q->outStack->cnt - 1; i++) {
		p++;
	}
	for (int i = 0; i < q->outStack->cnt; i++) {
		printf("%c", *p);
		p--;
	}
	p = q->inStack->top; // ��instack->arr ���� �ȵɱ�
	for (int i = 0; i < q->inStack->cnt - 1; i++) {
		p--;
	}
	for (int i = 0; i < q->inStack->cnt; i++) {
		printf("%c", *p);
		p++;
	}
	printf("\n");
}
void dequeueAll(Queue *q) {
	if (q->inStack->cnt == 0 && q->outStack->cnt == 0) printf("empty queue\n");
	else {
		while (q->inStack->cnt != 0 || q->outStack->cnt != 0) {
			dequeue(q);
		}
		printf("\n");
	}
}
int main() {
	int n, i;
	char command, ch;
	Queue *queue;
	queue = initQueue();

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &command);
		if (command == 'E') { //enqueue
			getchar();
			scanf("%c", &ch);
			enqueue(queue, ch);
		}
		else if (command == 'D') { //dequeue
			dequeue(queue);
			printf("\n");
		}
		else if (command == 'F') { //front
			front(queue);
		}
		else if (command == 'P') {
			print(queue);
		}
		else if (command == 'A') {
			dequeueAll(queue);
		}
	}
	free(queue);
	return 0;
}