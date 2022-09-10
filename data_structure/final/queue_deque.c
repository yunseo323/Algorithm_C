#include <stdio.h>
#include <string.h>

typedef struct node {
	struct node *prev;
	struct node *next;
	int data;
}Node;
typedef struct deque {
	int cnt; //queue size
	Node *front;
	Node *rear;
}Deque;
Node *createNode() {
	Node *new = (Node *)malloc(sizeof(Node));
	return new;
}
Deque *initDeque() {
	Deque *new = (Deque *)malloc(sizeof(Deque));
	Node *node = createNode();
	node->next = NULL;
	node->prev = NULL;
	node->data = NULL;

	new->front = node;
	new->rear = node;
	new->cnt = 0;
	return new;
}
Deque *add_front(Deque *d, int X) {
	Node *p = createNode();

	if (d->cnt > 0) {
		p->next = d->front;
		d->front->prev = p;
		d->front = p;
	}
	d->cnt++;
	d->front->data = X;
}
Deque *add_rear(Deque *d, int X) {
	Node *p = createNode();

	if (d->cnt > 0) {
		p->prev = d->rear;
		d->rear->next = p;

		d->rear = p;
	}
	d->cnt++;
	d->rear->data = X;
}
Deque *delete_front(Deque *d) {
	d->cnt--;
	if (d->cnt == 0) {
		d->front->data = NULL;
	}
	else {
		d->front = d->front->next;
		d->front->prev = NULL;
	}
}
Deque *delete_rear(Deque *d) {
	d->cnt--;
	if (d->cnt == 0) {
		d->rear->data = NULL;
	}
	else {
		d->rear = d->rear->prev;
		d->rear->next = NULL;
	}
}
void print(Deque *d) {
	Node *p = d->front;
	for (int i = 0; i < d->cnt; i++) {
		printf(" %d", p->data);
		p = p->next;
	}
}

int main() {
	int n, i, num;
	char command[3] = { NULL };
	Deque *deque = initDeque();

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%s", command);
		if (strcmp(command, "AF") == 0) {
			scanf("%d", &num);
			add_front(deque, num);
		}
		else if (strcmp(command, "AR") == 0) {
			scanf("%d", &num);
			add_rear(deque, num);
		}
		else if (strcmp(command, "DF") == 0) {
			if (deque->cnt == 0) {
				printf("underflow");
				break;
			}
			delete_front(deque);
		}
		else if (strcmp(command, "DR") == 0) {
			if (deque->cnt == 0) {
				printf("underflow");
				break;
			}
			delete_rear(deque);
		}
		else if (strcmp(command, "P") == 0) {
			print(deque);
			printf("\n");
		}
	}

	return 0;
}