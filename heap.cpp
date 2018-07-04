#include <iostream>

using namespace std;

class MinHeap {
public:
    MinHeap(int capacity)
    : capacity(capacity)
    {
        size = 0;
        items = new int[capacity];
    }

    ~MinHeap() {
        delete[] items;
    }

    int peek();
    int removeMin();
    void add(int item);
    void print();
private:

    int leftChildIndex(int i) {
        int r = 2*i + 1;
        if (r > size)
            return -1;
        return r;
    }

    int rightChildIndex(int i) {
        int r = 2*i + 2;
        if (r > size)
            return -1;
        return r;
    }

    int parentIndex(int i) {
        int r = (i - 1)/2;
        if (r > size)
            return -1;
        return r;
    }

    void extendCapacity();
    void heapifyUp();
    void heapifyDown();

    int size;
    int capacity;
    int *items;
};

void MinHeap::extendCapacity() {
    int *newItems = new int[capacity*2];
    capacity *= 2;
    int *temp = items;
    for (int i = 0; i < size; i++)
        newItems[i] = items[i];
    items = newItems;
    delete[] temp;
}

int MinHeap::peek() {
    if (size > 0)
        return items[0];
    else
        return -1;
}

void MinHeap::add(int item) {
    if (size == capacity)
        extendCapacity();
    items[size] = item;
    size++;
    heapifyUp();
}

int MinHeap::removeMin() {
    if (size == 0)
        return -1;
    int item = items[0];
    items[0] = items[size - 1];
    size--;
    heapifyDown();
    return item;
}

void MinHeap::heapifyUp() {
    int curr = size - 1;
    while(parentIndex(curr) >= 0 && items[curr] < items[parentIndex(curr)]) {
        swap(items[curr], items[parentIndex(curr)]);
        curr = parentIndex(curr);
    }
}

void MinHeap::heapifyDown() {
    int curr = 0;

    while (leftChildIndex(curr) < size) {
        int smallerChildIndex = leftChildIndex(curr);
        if (smallerChildIndex == -1)
            return;
        int rightIndex = rightChildIndex(curr);
        if (rightIndex != -1 && items[rightIndex] < items[smallerChildIndex])
            smallerChildIndex = rightIndex;
        if (items[curr] > items[smallerChildIndex]) {
            swap(items[curr], items[smallerChildIndex]);
        }
        else {
            break;
        }
        curr = smallerChildIndex;
    }
}

void MinHeap::print() {
    cout << "Size: " << size << ", Capacity: " << capacity << endl;
    for (int i = 0; i < size; i++)
        cout << items[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    MinHeap m(10);
    m.add(9);
    m.add(5);
    m.add(7);
    m.add(3);
    m.add(37);
    m.add(17);
    m.add(2);
    m.add(13);
    m.print();
    cout << "Peeking: " << m.peek() << endl;
    cout << "Peeking: " << m.peek() << endl;
    cout << "Removing: " << m.removeMin() << endl;
    cout << "Peeking: " << m.peek() << endl;
    cout << "Removing: " << m.removeMin() << endl;
    cout << "Peeking: " << m.peek() << endl;
    m.print();
    m.add(14);
    m.add(43);
    m.add(6);
    m.add(8);
    m.add(11);
    m.add(1);
    m.print();
    return 0;
}