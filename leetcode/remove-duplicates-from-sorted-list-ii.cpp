class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			ListNode *p,*c,*n,*tmp;
			p = head;
			c = head;
			if (head==NULL)
				return head;
			int flag = 0;
			while (c!=NULL) {
				n = c->next;
				if (n!=NULL && c->val == n->val) {
					while (n!=NULL && c->val == n->val) {
						n=n->next;
					}
					if (c!=head) {
						p->next = n;
						c=n;
					}
					else {
						head=n;
						p=head;
						c=head;
					}
				}
				else {
					p=c;
					c=c->next;
				}
			}
			return head;
		}
};
