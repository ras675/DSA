#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1;  // For enqueue operation
    stack<int> stack2;  // For dequeue operation

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    void dequeue() {
        if (stack2.empty()) {
            // Transfer elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (!stack2.empty()) {
            stack2.pop();
        } else {
            cout << "Underflow!" << endl;
        }
    }

    void printQueue() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Size:0 Elements: Null" << endl;
            return;
        }

        int size = stack1.size() + stack2.size();
        cout << "Size:" << size << " Elements:";

        // Print elements in the order of dequeue operation
        stack<int> tempStack = stack2;
        while (!tempStack.empty()) {
            cout << " " << tempStack.top();
            tempStack.pop();
        }

        // Print elements in the order of enqueue operation
        while (!stack1.empty()) {
            cout << " " << stack1.top();
            stack1.pop();
        }

        cout << endl;
    }
};

int main() {
    QueueUsingTwoStacks queue;
    int N, q, query, x;

    cin >> N >> q;

    for (int i = 0; i < q; ++i) {
        cin >> query;

        if (query == 1) {
            cin >> x;
            queue.enqueue(x);
        } else if (query == 2) {
            queue.dequeue();
        }

        queue.printQueue();
    }

    return 0;
}
