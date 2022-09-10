# 큐 ADT

- 삽입과 삭제는 **선입선출**
- 삽입은 큐의 뒤, 삭제는 큐의 앞

# 큐 메소드

- enqueue(e) 큐의 뒤에 원소를 삽입
- element dequeue() 큐의 앞에서 원소를 삭제하여 반환
- element front() 큐의 앞에 있는 원소를 (삭제하지 않고) 반환
- integer size() 큐에 저장된 원소의 수를 반환
- boolean inEmpty() 큐가 비어 있는지 여부를 반환
- iterator elements() 큐 원소 전체를 반환
- emptyQueueException() 비어 있는 큐에 대해 삭제 또는 front를 수행 시도할 경우 발령
- fulllQueueException() 만원 큐에 대해 삽입을 수행 시도할 경우 발령
