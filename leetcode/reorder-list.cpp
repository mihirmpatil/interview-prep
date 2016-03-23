class Solution {
	public:
		void reorderList(ListNode* head) {
			ListNode *slow, *fast, *temp, *head2;
			slow = head;
			fast = head;
			if(head==NULL || head->next==NULL)
				return;
			while (fast->next!=NULL && fast->next->next!=NULL) {
				slow = slow->next;
				fast = fast->next->next;
			}
			head2 = slow->next;
			slow->next = NULL;
			ListNode *prev = NULL;
			ListNode *cur = head2;
			while (cur!=NULL) {
				temp = cur->next;
				cur->next = prev;
				prev = cur;
				cur = temp;
			}
			head2 = prev;
			cur = head;
			ListNode *cur2 = head2;
			ListNode *temp2;
			while (cur2!=NULL) {
				temp = cur->next;
				temp2 = cur2->next;
				cur->next = cur2;
				cur2->next = temp;
				cur2 = temp2;
				cur = temp;
			}
		}
};
