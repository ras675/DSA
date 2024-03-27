#include <iostream>

using namespace std;

int largestRectangleArea(int heights[], int n) {
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];
        for (int j = i; j < n; j++) {
            minHeight = min(minHeight, heights[j]);
            int width = j - i + 1;
            int area = minHeight * width;
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int main() {
    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        int heights[n];
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        int result = largestRectangleArea(heights, n);
        cout << result << endl;
    }

    return 0;
}
