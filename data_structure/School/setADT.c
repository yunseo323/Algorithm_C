Node *Union(List *listA, List *listB) { //������
	int minnum, i;
	Node *pA, *pB, *pC;
	List *create;
	List *empty; //������
	Init(create);
	Init(empty);

	pA = listA->header;
	pB = listB->header;
	pC = create->header;

	minnum = listA->cnt >= listB->cnt ? listB->cnt : listA->cnt;
	if (minnum == listA->cnt) { //B�� �������� A���� �����

		//create ����Ʈ�� B�Űܴ��
		for (i = 0; i < listB->cnt; i++) {
			pB = pB->next;
			InsertNode(create, pB->data);
		}

		for (i = 0; i < minnum; i++) {
			pA = pA->next;
			if (SearchData(pA->data, listB == 0)) { //������ �����
				PushUpperNode(listB, pA->data);
			}
		}

		//��ȯ
		if (listB->cnt == 0) {
			return empty->header;
		}
		else
			return pC;
	}
	else { //A�� �������� B���� �����

		//create ����Ʈ�� A�Űܴ��
		for (i = 0; i < listA->cnt; i++) {
			pA = pA->next;
			InsertNode(create, pA->data);
		}
		for (i = 0; i < minnum; i++) {
			pB = pB->next;
			if (SearchData(pB->data, listA == 0)) { //������ �����
				PushUpperNode(listA, pB->data);
			}
		}

		//��ȯ
		if (listA->cnt == 0) {
			return empty->header;
		}
		else
			return pC;
	}



}
Node *Intersect(List *listA, List *listB) { //������
	int minnum, i;
	Node *pA, *pB, *pN;
	List *new;
	List *empty; //������
	Init(new);
	Init(empty);

	pA = listA->header;
	pB = listB->header;
	pN = new->header;

	minnum = listA->cnt >= listB->cnt ? listB->cnt : listA->cnt;

	if (minnum == listA->cnt) { //B�� �������� A���� ã��
		for (i = 0; i < listA->cnt; i++) {
			pA = pA->next;
			if (SearchData(pA->data, listB) == 1) {//������
				InsertNode(new, pA->data);
			}
		}
	}
	else {
		for (i = 0; i < listB->cnt; i++) {
			pB = pB->next;
			if (SearchData(pB->data, listA) == 1) {//������
				InsertNode(new, pB->data);
			}
		}
	}

	//��ȯ
	if (new->cnt == 0) {
		return empty->header;
	}
	else return pN;
}
