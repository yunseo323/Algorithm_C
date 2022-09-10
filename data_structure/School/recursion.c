/*�ϳ��� ž*/
#include <stdio.h>

void move(int N, char a, char b); //���� ����, ���� ����, ���� ����
void hanoi(int N, char a, char b, char c); //���� ����, ���� ����,��������, ��������

int main() {
	int n; //���� ����
	scanf("%d", &n);
	hanoi(n, 'A', 'C', 'B');
	return 0;
}

void move(int N, char a, char b) { //������ ������ ������
	printf("%c %c\n", a, b);
}
void hanoi(int N, char a, char b, char c) { //����, ����, ����
	if (N == 1) {
		move(1, a, b);
	}
	else {
		hanoi(N - 1, a, c, b);
		move(N, a, b);
		hanoi(N - 1, c, b, a);
	}
}

/*������ Ǯ��*/
/*������ ����*/