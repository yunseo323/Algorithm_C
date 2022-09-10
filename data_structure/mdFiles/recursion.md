## ���
���� ������ ���� ���� �Է��� ���� �ڽ��� ����Ͽ� ���ǵ� �˰���

## ��� �⺻ ��Ģ
1. base case : �׻� ������ �ϴ� ������, ��� ���� �ذ�� �� �־�� ��
2. recursion : **��� ȣ���� ���̽� ���̽��� ���ϴ� �������� ����Ǿ�� ��**

����/���� ������ ������ ���ϵǱ⿡ ������ ����� �ʿ���!
```
#include <stdio.h>
int sum(int n);

int main() {
  int N;
  scanf("%d,&N);
  printf("%d", sum(N));
  return 0;
}

int sum(int n) { //����Լ�
	if (n == 1) return 1; // base case
	else return n + sum(n - 1); //recursion
}

/*
(1~3)
sum(3)
sum(2)
sum(1) -> return 1
2+sum(1)->2 + return 1
3+sum(2)->3+ return 2+1
*/
```

