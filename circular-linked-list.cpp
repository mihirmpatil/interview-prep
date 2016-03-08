string Check(LinkedListNode* L) {
	LinkedListNode *f,*s;
	f = s = L;

	while(s!=NULL && f!=NULL && f->next!=NULL){
		s = s->next;
		f = f->next->next;
		if(s==f)
			return "YES";
	}
	return "NO";

}
