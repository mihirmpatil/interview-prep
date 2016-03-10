LinkedListNode* MergeInBetween(LinkedListNode* L1, LinkedListNode* L2, int A, int B) {
	LinkedListNode *a,*b,*tmp;
	int count = 1;
	a = L1;
	b = L1;



	while(count<A-1){
		a = a->next;
		b = b->next;
		count++;
	}
	while(count <= B){
		b = b->next;
		count++;
	}
	if(a==L1 && b==NULL)
		return L2;

	a->next = L2;
	tmp = L2;
	while(tmp->next!=NULL)
		tmp = tmp->next;

	tmp->next = b;
	return L1;


}
