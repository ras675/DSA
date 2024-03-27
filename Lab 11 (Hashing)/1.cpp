#include <iostream>
#include <vector>

using namespace std;

int linearProbing(int key, int i, int n) {
    return (key + i) % n;
}

int quadraticProbing(int key, int i, int n) {
    return (key + i * i) % n;
}

int doubleHashing(int key, int i, int n) {
    int secondHash = 7;
    return (key + i * secondHash) %n;
}

int insert(int choice, int n, vector<int>& hashTable, int key, int& filledSlots) {
    int i = 0;
    while (i < n) {
        int index;
        if (choice == 1) {
            index = linearProbing(key, i, n);
        } else if (choice == 2) {
            index = quadraticProbing(key, i, n);
        } else if (choice == 3) {
            index = doubleHashing(key, i, n);
        }

        if (hashTable[index] == -1) {
            hashTable[index] = key;
            filledSlots++;
            return index;
        } else {
            i++;
        }
    }
    return -1;
}

int main() {
    int choice,n,q;
    cin>>choice>>n>>q;

    vector<int> hashTable(n, -1);
    int filledSlots = 0;

    for (int i = 0; i < q; i++) {
        int key;
        cin >> key;

        int attempts = 0;
        while (attempts < 6) {
            int result = insert(choice, n, hashTable, key, filledSlots);
            if (result != -1) {
                double loadFactor = static_cast<double>(filledSlots) / n;
                cout << "Inserted : Index " << result << " (L.F = " << loadFactor << ")" << endl;
                break;
            } else {
                cout << "Input Abandoned" << endl;
                break;
            }
        }
    }

    return 0;
}
