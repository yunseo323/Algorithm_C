#include <stdio.h>

typedef struct cirqueue_ {
	int capacity; //queue size
	int *front;
	int *rear;
	int *arr;
}CirQueue;

int isEmpty(CirQueue *queue);
int isFull(CirQueue *queue);
void printOverflow();
void printUnderflow();
CirQueue *insertQueue(CirQueue *q, int num);
CirQueue *deleteQueue(CirQueue *q);
void printQueue(CirQueue *q);

int isEmpty(CirQueue *queue) {
	if (queue->front == queue->rear) return 1; //공백이면 1 반환
	else return 0;
}
int isFull(CirQueue *queue) {
	int indexRear, indexFront;
	int *p;
	indexFront = queue->front - queue->arr;
	p = queue->rear;
	indexRear = p - queue->arr;

	if ((indexRear + 1) % (queue->capacity) == indexFront) return 1; //가득 찼다면 1 반환
	else return 0;
}
void printOverflow() {
	printf("overflow");
}

void printUnderflow() {
	printf("underflow");
}

CirQueue *insertQueue(CirQueue *q, int num) {
	int index;

	q->rear++;
	index = q->rear - q->arr;
	index %= q->capacity;
	q->arr[index] = num;

	return q;
}
CirQueue *deleteQueue(CirQueue *q) {
	int index;
	q->front++;
	index = q->front - q->arr;
	index %= q->capacity;
	q->arr[index] = 0;
	return q;
}
void printQueue(CirQueue *q) {
	int *p = q->arr;
	for (int i = 0; i < q->capacity; i++) {
		printf(" %d", *p);
		p++;
	}
}
int main() {
	int q, n, i, num;
	char command;
	CirQueue *cirqueue;
	cirqueue = (CirQueue *)malloc(sizeof(CirQueue));
	scanf("%d", &q);//원형 큐의 크기
	//init
	cirqueue->arr = (int *)malloc(sizeof(int) * (q + 1));
	for (i = 0; i < q; i++) {
		cirqueue->arr[i] = 0; //0으로 초기화
	}
	cirqueue->front = cirqueue->arr;
	cirqueue->rear = cirqueue->arr;
	cirqueue->capacity = q;


	scanf("%d", &n);//연산 개수

	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &command);
		if (command == 'I') {
			if (isFull(cirqueue) == 1) {
				printOverflow();
				printQueue(cirqueue);
				break;
			}
			getchar();
			scanf("%d", &num);
			insertQueue(cirqueue, num);
		}
		else if (command == 'D') {
			if (isEmpty(cirqueue) == 1) {
				printUnderflow();
				break;
			}
			deleteQueue(cirqueue);
		}
		else if (command == 'P') {
			printQueue(cirqueue);
			printf("\n");
		}
	}
	return 0;
}