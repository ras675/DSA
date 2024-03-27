#include <stdio.h>

int main() {
    int size = 100;
    int arr[size];
    int count = 0;

    printf("Enter positive integers :\n");

    while (count < size) {
        int num;
        scanf("%d", &num);

        if (num <= 0) {
            break;
        }

        arr[count] = num;
        count++;
    }


    int occurrences[100] = {0};
    for (int i = 0; i < count; i++) {
        occurrences[arr[i]]++;
    }

    printf("Entered positive integers and their occurrences:\n");
    for (int i = 0; i < count; i++) {
        if (occurrences[arr[i]] > 0) {
            printf("%d: %d times\n", arr[i], occurrences[arr[i]]);
            occurrences[arr[i]] = 0;
        }
    }

    return 0;
}