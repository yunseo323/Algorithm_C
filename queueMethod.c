/*배열(크기 N의 배열을 원형으로 사용)*/

typedef struct _cirqueue {
	int *arr; //큐배열
	int front, rear;
	int size;
}CirQueue;

void initQueue(CirQueue *arr, int N) { //큐 초기화
	arr->size = N;
	arr->front = 0;
	arr->rear = arr->size - 1;
}

int isEmpty(CirQueue *arr) {

}

int isFull(CirQueue *arr) {

}

void enqueue(CirQueue *arr, int elem) {
	if (isFull(arr)) {

	}
}

int dequeue(CirQueue *arr) {
	if (isEmpty(arr)) {

	}
}
/*연결리스트*/