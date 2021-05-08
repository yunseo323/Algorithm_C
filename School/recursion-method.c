int oneToNum(int N) {
	if (N == 1) return 1;
	else {
		return N + oneToNum(N - 1);
	}
}


void printNum(int N) {
	if (N / 10 == 0) {
		printf("%d\n", N % 10);
	}
	else {
		printNum(N / 10);
		printf("%d\n", N % 10);
	}
}

int findMax(int arr[], int index, int N, int max) {
	if (index == N) {
		return max > arr[index] ? max : arr[index];
	}
	else {
		return max > arr[index] ? findMax(arr, index + 1, N, max) : findMax(arr, index + 1, N, arr[index]);
	}
}

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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int check_char(char *arr, char ch, char *pt, int cnt) {
	if (*(pt + 1) == NULL) {
		if (*pt == ch) {
			cnt++;
			//printf("%d final\n",cnt);
		}
		return cnt;
	}
	else {
		if (*pt == ch) {
			cnt++;
			//printf("%d level\n",cnt);
		}
		pt++;

		check_char(arr, ch, pt, cnt);
	}
}


int main() {
	char arr[100] = { ' ' };
	int n;

	gets(arr);
	n = strlen(arr);
	printf("%d", rlsPalindrome(arr, 0, n - 1));

	return 0;
}
int rlsPalindrome(char arr[], int i, int j) {
	//printf("i:%d j:%d\n", i, j);
	if (i >= j) {
		return 1; //회문임
	}
	else {
		if (arr[i] != arr[j]) return 0;
	}

	rlsPalindrome(arr, i + 1, j - 1);

}


void divide(int a, int b, int cnt) {
	if (a < 0) {
		a += b;
		cnt--;
		printf("%d %d", cnt, a);
	}
	else {
		a -= b;
		cnt++;
		divide(a, b, cnt);
	}
}