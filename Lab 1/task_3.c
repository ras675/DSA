#include <stdio.h>


int iterative_binary_search(int x, int array[], int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == x) {
            return mid;
        } else if (array[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


int recursive_binary_search(int x, int array[], int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == x) {
            return mid;
        } else if (array[mid] < x) {
            return recursive_binary_search(x, array, mid + 1, right);
        } else {
            return recursive_binary_search(x, array, left, mid - 1);
        }
    }

    return -1;
}

int main() {
    int array[100];
    int size = 0;

    printf("Enter sorted array elements (enter a negative number to stop):\n");
    while (1) {
        int num;
        scanf("%d", &num);

        if (num < 0) {
            break;
        }

        array[size] = num;
        size++;
    }

    int target;
    printf("Enter target value to search: ");
    scanf("%d", &target);

    int iteration_result = iterative_binary_search(target, array, size);
    printf("%d (using iteration)\n", iteration_result);

    int recursion_result = recursive_binary_search(target, array, 0, size - 1);
    printf("%d (using recursion)\n", recursion_result);

    return 0;
}