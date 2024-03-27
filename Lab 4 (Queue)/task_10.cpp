#include <iostream>

using namespace std;

class Deque {
private:
    int *arr;
    int front, rear, s;

public:
    Deque(int size) {
        s = size;
        arr = new int[s];
        front = rear = -1;
    }

    void push_front(int key) {
        if (isFull()) {
            cout << "Error: Deque is full!" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + s) % s;
        }

        arr[front] = key;
        printDeque();
    }

    void push_back(int key) {
        if (isFull()) {
            cout << "Error: Deque is full!" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % s;
        }

        arr[rear] = key;
        printDeque();
    }

    int pop_front() {
        if (isEmpty()) {
            cout << "Error: Deque is empty!" << endl;
            return -1;
        }

        int popped = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % s;
        }

        printDeque();
        return popped;
    }

    int pop_back() {
        if (isEmpty()) {
            cout << "Error: Deque is empty!" << endl;
            return -1;
        }

        int popped = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + s) % s;
        }

        printDeque();
        return popped;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }

        if (front <= rear) {
            return rear - front + 1;
        } else {
            return s - front + rear + 1;
        }
    }

    bool isFull() {
        return (front == 0 && rear == s - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void printDeque() {
        if (isEmpty()) {
            cout << "Empty" << endl;
            return;
        }

        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % s;
        } while (i != (rear + 1) % s);
        cout << endl;
    }
};

int main() {
    int choice, key;
    Deque deque(5);

    do {
        cout << "Press 1 to push_front\nPress 2 to push_back\nPress 3 to pop_front\nPress 4 to pop_back\nPress 5 for size\nPress 6 to exit." << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push_front: ";
                cin >> key;
                deque.push_front(key);
                break;
            case 2:
                cout << "Enter value to push_back: ";
                cin >> key;
                deque.push_back(key);
                break;
            case 3:
                cout << "Popped from front: " << deque.pop_front() << endl;
                break;
            case 4:
                cout << "Popped from back: " << deque.pop_back() << endl;
                break;
            case 5:
                cout << "Size: " << deque.size() << endl;
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
