#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>

using namespace std;

void remove_dups(vector<int>& v) {
	map<int,int> m;
	vector<int>::iterator it = v.begin();
	for(;it!=v.end();++it) {
		if (m.count(*it) == 0)
			m.insert(make_pair(*it, 1));
		else {
			++m[*it];
		}
	}

	map<int,int>::iterator it2 = m.begin();
	for(;it2!=m.end();++it2)
		cout << it2->first << " " << it2->second << endl;

	int x;
	for(it=v.begin();it!=v.end();) {
		x = *it;
		cout << "Value of " << x << ":" << m[x] << endl; 
		if (m[x] > 1) {
		//if (m.count(*it)) {
			it = v.erase(it);
			m[x]--;
			cout << "Erasing " << x << " new value " << m[x] << endl;
		}
		else
			++it;
	}
	
		
	for(it2=m.begin();it2!=m.end();++it2)
		cout << it2->first << " " << it2->second << endl;
	for(it=v.begin();it!=v.end();++it)
		cout << "Vector: " << *it << endl;
}

struct _node {
	int val;
	struct _node *next;
};

typedef struct _node node;

node* append(node *head, int v) {
	node *temp = head;
	node *n = (node*)malloc(sizeof(node));
	n->val = v;
	n->next = NULL;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = n;
	return head;
}

void printList(node *head) {
	node *temp = head;
	while (temp!=NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

node* reverseIterative(node *head) {
	node *prev = NULL; 
	node *curr = head;
	node *temp;
	while (curr!=NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

int main() {
	/*vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(13);
	v.push_back(145);
	v.push_back(145);
	v.push_back(145);
	v.push_back(157);
	v.push_back(156);
	v.push_back(11);
	v.push_back(12);
	v.push_back(12);
	v.push_back(14);
	v.push_back(12);
	v.push_back(10);
	remove_dups(v);
*/
	
	node *head = (node*)malloc(sizeof(node));
	head->val = 1;
	head->next = NULL;
	int i;
	for (i=0;i<=10;i++)
		head = append(head, rand()%1000);
	printList(head);
	head = reverseIterative(head);
	printList(head);

	return 0;
}
