#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> hotels; // Pair of {number of free rooms, hotel index}
    for (int i = 0; i < n; ++i) {
        int rooms;
        cin >> rooms;
        hotels.push_back(make_pair(rooms, i + 1));
    }

    // Sort hotels manually based on the number of free rooms
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (hotels[j].first > hotels[j + 1].first) {
                swap(hotels[j].first, hotels[j + 1].first);
                swap(hotels[j].second, hotels[j + 1].second);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int requiredRooms;
        cin >> requiredRooms;

        int hotelIndex = 0;
        // Find the first hotel with enough free rooms
        for (int j = 0; j < n; ++j) {
            if (hotels[j].first >= requiredRooms) {
                hotelIndex = hotels[j].second;
                hotels[j].first -= requiredRooms;
                break;
            }
        }

        if (hotelIndex != 0) {
            // Assign the group to the hotel
            cout << hotelIndex << " ";
        } else {
            // No hotel has enough free rooms
            cout << "0 ";
        }
    }

    return 0;
}


