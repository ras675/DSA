#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class UnethicalQueue {
private:
    unordered_map<int, int> friendCircle;  // Map to store the friend circle of each person
    queue<int> unethicalQueue;  // Queue to simulate the unethical queue

public:
    void enterQueue(int person) {
        unethicalQueue.push(person);
    }

    void processQueue() {
        while (!unethicalQueue.empty()) {
            int frontPerson = unethicalQueue.front();
            unethicalQueue.pop();

            cout << frontPerson << endl;
        }
    }

    void addToFriendCircle(int circleSize, const vector<int>& circleMembers) {
        for (int person : circleMembers) {
            friendCircle[person] = circleSize;
        }
    }

    void simulateUnethicalQueue() {
        string command;
        while (true) {
            cin >> command;

            if (command == "ENQUEUE") {
                int person;
                cin >> person;

                enterQueue(person);
            } else if (command == "DEQUEUE") {
                if (!unethicalQueue.empty()) {
                    int frontPerson = unethicalQueue.front();
                    unethicalQueue.pop();

                    cout << frontPerson << endl;
                }
            } else if (command == "STOP") {
                break;
            }
        }
    }
};

int main() {
    int t = 1;  // Initialize the test case number

    while (true) {
        int numCircles;
        cin >> numCircles;

        if (numCircles == 0) {
            break;  // End of input
        }

        UnethicalQueue unethicalQueueObj;

        for (int i = 1; i <= numCircles; ++i) {
            int circleSize;
            cin >> circleSize;

            vector<int> circleMembers(circleSize);
            for (int j = 0; j < circleSize; ++j) {
                cin >> circleMembers[j];
            }

            unethicalQueueObj.addToFriendCircle(circleSize, circleMembers);
        }

        cout << "Scenario #" << t++ << endl;
        unethicalQueueObj.simulateUnethicalQueue();
        cout << endl;
    }

    return 0;
}
