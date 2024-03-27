#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int maxSize;
    int top;

public:
    Stack(int size) {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    void push(int x) {
        if (top < maxSize - 1) {
            arr[++top] = x;
            cout << "Pushed " << x <<endl;
        } else {
            cout << "Overflow" <<endl;
        }
    }

    void pop() {
        if (top >= 0) {
            cout << "Popped " << arr[top--] <<endl;
        } else {
            cout << "Underflow" << endl;
        }
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == maxSize - 1;
    }

    int size() const {
        return top + 1;
    }

    int getTop() const {
        if (top >= 0) {
            return arr[top];
        } else {
            return -1;
        }
    }
};

int main() {
    int N;
    cin >> N;

    Stack stack(N);

    int ID;
    while (true) {
        cin >> ID;

        if (ID == -1) {
            break;
        }

        switch (ID) {
            case 1: {
                int x;
                cin >> x;
                stack.push(x);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                cout << (stack.isEmpty() ? "True" : "False") <<endl;
                break;
            case 4:
                cout << (stack.isFull() ? "True" : "False") <<endl;
                break;
            case 5:
                cout << stack.size() << endl;
                break;
            case 6:
                cout << stack.getTop() <<endl;
                break;
            default:
                cout << "Invalid ID" <<endl;
        }
    }

    return 0;
}
