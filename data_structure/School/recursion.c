/*하노이 탑*/
#include <stdio.h>

void move(int N, char a, char b); //원반 개수, 시작 말뚝, 도착 말뚝
void hanoi(int N, char a, char b, char c); //원반 개수, 시작 말뚝,도착말뚝, 경유말뚝

int main() {
	int n; //원반 개수
	scanf("%d", &n);
	hanoi(n, 'A', 'C', 'B');
	return 0;
}

void move(int N, char a, char b) { //실제로 원반을 움직임
	printf("%c %c\n", a, b);
}
void hanoi(int N, char a, char b, char c) { //시작, 도착, 경유
	if (N == 1) {
		move(1, a, b);
	}
	else {
		hanoi(N - 1, a, c, b);
		move(N, a, b);
		hanoi(N - 1, c, b, a);
	}
}

/*스도쿠 풀이*/
/*스도쿠 생성*/