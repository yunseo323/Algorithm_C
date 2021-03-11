Node *Union(List *listA, List *listB) { //합집합
	int minnum, i;
	Node *pA, *pB, *pC;
	List *create;
	List *empty; //공집합
	Init(create);
	Init(empty);

	pA = listA->header;
	pB = listB->header;
	pC = create->header;

	minnum = listA->cnt >= listB->cnt ? listB->cnt : listA->cnt;
	if (minnum == listA->cnt) { //B를 기준으로 A원소 끼우기

		//create 리스트에 B옮겨닮기
		for (i = 0; i < listB->cnt; i++) {
			pB = pB->next;
			InsertNode(create, pB->data);
		}

		for (i = 0; i < minnum; i++) {
			pA = pA->next;
			if (SearchData(pA->data, listB == 0)) { //없으면 끼우기
				PushUpperNode(listB, pA->data);
			}
		}

		//반환
		if (listB->cnt == 0) {
			return empty->header;
		}
		else
			return pC;
	}
	else { //A를 기준으로 B원소 끼우기

		//create 리스트에 A옮겨닮기
		for (i = 0; i < listA->cnt; i++) {
			pA = pA->next;
			InsertNode(create, pA->data);
		}
		for (i = 0; i < minnum; i++) {
			pB = pB->next;
			if (SearchData(pB->data, listA == 0)) { //없으면 끼우기
				PushUpperNode(listA, pB->data);
			}
		}

		//반환
		if (listA->cnt == 0) {
			return empty->header;
		}
		else
			return pC;
	}



}
Node *Intersect(List *listA, List *listB) { //교집합
	int minnum, i;
	Node *pA, *pB, *pN;
	List *new;
	List *empty; //공집합
	Init(new);
	Init(empty);

	pA = listA->header;
	pB = listB->header;
	pN = new->header;

	minnum = listA->cnt >= listB->cnt ? listB->cnt : listA->cnt;

	if (minnum == listA->cnt) { //B를 기준으로 A원소 찾기
		for (i = 0; i < listA->cnt; i++) {
			pA = pA->next;
			if (SearchData(pA->data, listB) == 1) {//같으면
				InsertNode(new, pA->data);
			}
		}
	}
	else {
		for (i = 0; i < listB->cnt; i++) {
			pB = pB->next;
			if (SearchData(pB->data, listA) == 1) {//같으면
				InsertNode(new, pB->data);
			}
		}
	}

	//반환
	if (new->cnt == 0) {
		return empty->header;
	}
	else return pN;
}
