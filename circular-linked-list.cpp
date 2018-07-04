#include <iostream>
#include "node.h"

using namespace std;

class CircularLinkedList {
public:
    CircularLinkedList()
    : head(NULL)
    , tail(NULL)
    , len(0)
    {}

    int length() {
        return len;
    };
    bool empty() {
        bool ret;
        (len == 0) ? ret = true : ret = false;
        return ret;
    };
    void insert(int v);
    void remove(int v);
    bool exists(int v);
    LinkedListNode* find(int v);
    void print();

private:
    LinkedListNode* head;
    LinkedListNode* tail;
    int len;
};

void CircularLinkedList::print() {
    LinkedListNode* temp = head;
    while (temp != tail) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val;
    cout << endl;
}

// insert at head
void CircularLinkedList::insert(int v) {
    LinkedListNode* n = new LinkedListNode(v);
    if (empty()) {
        tail = n;
    }
    else {
        n->next = head;
    }
    head = n;
    tail->next = head;
    len++;
}

bool CircularLinkedList::exists(int v) {
    LinkedListNode* temp = head;
    while (temp != tail) {
        if (temp->val == v)
            return true;
        temp = temp->next;
    }
    return false;
}

LinkedListNode* CircularLinkedList::find(int v) {
    LinkedListNode* temp = head;
    while (temp != tail) {
        if (temp->val == v)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void CircularLinkedList::remove(int v) {
    LinkedListNode *n, *prev = head;
    if (head->val == v) {
        n = head;
        head = head->next;
        tail ->next = head;
    }
    while (prev!= tail) {
        if (prev->next->val == v) {
            n = prev->next;
            if (n == tail)
                tail = prev;
            prev->next = n->next;
        }
        prev = prev->next;
    }
    len--;
    delete n;
}

int main(int argc, char const *argv[])
{
    CircularLinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.print();
    ll.remove(3);
    ll.print();
    ll.remove(1);
    ll.print();
    ll.remove(5);
    ll.print();	
    return 0;
}


/*
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
*/