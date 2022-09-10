/*
1¹ø
DFGGG
ABDFGP
*/
#include<stdio.h>
#include<string.h>

int subset(int A[], int B[]) {
	int i, Anum = 0, Bnum = 0, flag = 0;
	for (i = 0; i < 26; i++) {
		if (A[i] == 1) Anum++;
		if (B[i] == 1) Bnum++;
	}
	if (Anum > Bnum)return 0;
	for (i = 0; i < 26; i++) {
		if (A[i] == 1 && B[i] == 1) {
			flag++;
		}
		else continue;
	}
	if (flag == Anum) return 1;
	else return 0;
}
void Union(int A[], int B[]) {
	int re[26] = { 0 };
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (A[i] == 1 || B[i] == 1) {
			re[i] = 1;
			flag++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (re[i] == 1)printf("%c", 'A' + i);
	}
	if (flag == 0)printf("0");
}
void Intersect(int A[], int B[]) {
	int re[26] = { 0 };
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (A[i] == 1 && B[i] == 1) {
			re[i] = 1;
			flag++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (re[i] == 1)printf("%c", 'A' + i);
	}
	if (flag == 0)printf("0");
}
int main() {
	char tmp[1000] = { NULL }, *A, *B;
	int iA[26] = { 0 }, iB[26] = { 0 };
	int i;
	char ch;
	//ÀÔ·Â
	scanf("%s", tmp);
	A = (char *)malloc((strlen(tmp) + 1) * sizeof(char));
	strcpy(A, tmp);
	getchar();
	tmp[0] = "\0";
	scanf("%s", tmp);
	B = (char *)malloc((strlen(tmp) + 1) * sizeof(char));
	strcpy(B, tmp);
	//printf("%s\n", A);
	//printf("%s\n", B);
	for (i = 0; i < strlen(A); i++) {
		if (A[i] != '0') iA[A[i] - 'A'] = 1;
	}
	for (i = 0; i < strlen(B); i++) {
		if (B[i] != '0') iB[B[i] - 'A'] = 1;
	}
	printf("%d", subset(iA, iB));
	return 0;
}
