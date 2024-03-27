#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n) {
        size=10001;
        front = rear = -1;
        arr = new int[size];
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    int getSize() {
        if (isEmpty()) return 0;
        return (rear - front + size) % size + 1;
    }

    void enQueue(int value) {
        if (isFull()) {
            cout << "EnQueue: Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "DeQueue: Underflow" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Front: Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    
};

int main() {
    int n;
    cin >> n;
    CircularQueue cq(n);

    int functionID, p;
    while (cin >> functionID && functionID != -1) {
        switch (functionID) {
            case 1:
                cin >> p;
                cq.enQueue(p);
                break;
            case 2:
                cq.deQueue();
                break;
            case 3:
                cout << "isEmpty: " << (cq.isEmpty() ? "True" : "False") << endl;
                break;
            case 4:
                cout << "isFull: " << (cq.isFull() ? "True" : "False") << endl;
                break;
            case 5:
                cout << "Size: " << cq.getSize() << endl;
                break;
            case 6:
                cout << "Front: " << cq.getFront() << endl;
                break;
        }
    }

    return 0;
}

