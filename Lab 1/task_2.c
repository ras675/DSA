#include <stdio.h>

 factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

 factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_recursive(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Factorial using iteration: %d\n", factorial_iterative(num));
    printf("Factorial using recursion: %d\n", factorial_recursive(num));

    return 0;
}