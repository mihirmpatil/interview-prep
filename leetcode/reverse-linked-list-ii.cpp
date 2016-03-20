class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode *prev, *cur, *tmp, *nxt;
			ListNode *m_left=head, *n_node, *m_node;
			int idx=1;
			cur=head;
			prev=NULL;
			if (m==n)
				return head;
			while (cur!=NULL) {
				if (idx==m-1)
					m_left = cur;
				while (idx>=m && idx<=n) {
					if (idx==m)
						m_node = cur;
					if (cur) nxt = cur->next;
					cur->next = prev;
					prev = cur;
					cur = nxt;
					idx++;
				}
				if (idx==n+1) {
					n_node = prev;
					m_left->next = n_node;
					m_node->next = cur;
				}
				prev = cur;
				if (cur) cur = cur->next;
				idx++;
			}
			if (m==1)
				head = n_node;
			return head;
		}
};
