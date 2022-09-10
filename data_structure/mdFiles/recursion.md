## 재귀
같은 형태의 보다 작은 입력을 가진 자신을 사용하여 정의된 알고리즘

## 재귀 기본 규칙
1. base case : 항상 가져야 하는 것으로, 재귀 없이 해결될 수 있어야 함
2. recursion : **재귀 호출은 베이스 케이스를 향하는 방향으로 진행되어야 함**

저장/복구 때문에 성능이 저하되기에 적절한 사용이 필요함!
```
#include <stdio.h>
int sum(int n);

int main() {
  int N;
  scanf("%d,&N);
  printf("%d", sum(N));
  return 0;
}

int sum(int n) { //재귀함수
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

