/*연결리스트*/
typedef struct CircularQueueNodeType
{
	char data;
} CircularQueueNode;

typedef struct _cirqueue {
	CircularQueueNode *pData; //큐배열
	int front, rear;
	int currentCount;
	int maxCount;
}CirQueue;

void createCircularQueue(CirQueue *arr, int N) { //큐 초기화
	CircularQueue *new = NULL;
	new = (CirQueue *)malloc(sizeof(CirQueue));

	new->maxCount = size;
	new->front = -1;
	new->rear = -1;

	new->pData = (CirQueue *)malloc(sizeof(CirQueue));
	return new;
}

int isEmpty(CirQueue *Queue) {
	int re = 0;

	if (Queue != NULL)
	{
		if (Queue->currentCount == 0)
		{
			re = 1;
		}
	}

	return re;
}

int isFull(CirQueue *Queue) {
	int re = 0;
	if (Queue != NULL)
	{
		if (Queue->currentCount == Queue->maxCount)
		{
			re = 1;
		}
	}

	return re;
}

void enqueue(CirQueue *Queue, char data) {
	if (Queue != NULL) {
		if (isFull(Queue) == 0) {
			pQueue->rear = (pQueue->rear + 1) % pQueue->maxCount;
			pQueue->pData[pQueue->rear].data = data;
			pQueue->currentCount++;
		}
		else {
			printf("ERROR:enqueue");
		}
	}
	
}

CircularQueueNode dequeue(CirQueue *Queue) {
	CircularQueueNode *re = NULL;
	if (Queue != NULL) {
		if (isEmpty(Queue)) {
			pQueue->front = (pQueue->front + 1) % pQueue->maxCount;
			pReturn->data = pQueue->pData[pQueue->front].data;
			pQueue->currentCount--;
		}
		else {
			printf("ERROR:dequeue");
		}
	}

	
}
