# DataStructure_C

## 연결리스트
<주요 Method>
- 초기화 
- 추가: 끝/처음/n번째
- 삭제: 끝/처음/n번째
- 데이터 탐색
- 출력

<구조>
- 배열을 이용한 리스트 
- 단일 연결리스트 
노드 안 : 원소, 다음 노드를 가리키는 next 링크
- 이중 연결리스트
노드 안 : 원소, 이전 노드를 가리키는 next 링크, 다음 노드를 가리키는 next 링크
리스트의 처음을 알려주는 **header**과 끝을 알려주는 **trailer** 존재
- 원형 연결리스트

+)리스트들을 묶어주는 구조체 List가 있으면 좋음 (header 주소, size 등등)

## 집합 ADT
<주요 Method>
- union: 합집합
- intersect: 교집합
- subtract: 차집합
- emptySetException: 비어 있는 집합에 대해 삭제 혹은 첫 원소를 접근 시도할 경우 경고

## 스택 ADT
<**후입선출**> 삽입과 삭제는 스택의 top 위치에서 수행
- 배열 이용
- 단일 연결리스트를 사용해 스택 구현
: 삽입과 삭제가 특정위치에서만 수행되어, header은 불필요하다.
  top 원소를 연결리스트의 첫 노드에 저장하고 t로 가리키게 한다.
<주요 Method>
- push
- pop
## 큐 ADT
<**선입선출**>

## 트리 ADT

