/*�迭(ũ�� N�� �迭�� �������� ���)*/

typedef struct _cirqueue {
	int *arr; //ť�迭
	int front, rear;
	int size;
}CirQueue;

void initQueue(CirQueue *arr, int N) { //ť �ʱ�ȭ
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
/*���Ḯ��Ʈ*/