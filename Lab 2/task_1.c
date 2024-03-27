#include <stdio.h>

#define MAX_N 100000
#define MAX_R 100000

int soldiers[MAX_N];
int powers[MAX_R];
int points[MAX_R];

void countAndPrint(int n, int r) {
    int maxPower = 0;
    for (int i = 0; i < n; i++) {
        if (soldiers[i] > maxPower) {
            maxPower = soldiers[i];
        }
    }

    for (int i = 0; i < r; i++) {
        int power = powers[i];
        int killed = 0;
        int totalPoints = 0;

        if (power >= maxPower) {
            killed = n;
            for (int j = 0; j < n; j++) {
                totalPoints += soldiers[j];
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (soldiers[j] <= power) {
                    killed++;
                    totalPoints += soldiers[j];
                }
            }
        }

        points[i] = totalPoints;
        printf("%d %d\n", killed, totalPoints);
    }
}

int main() {
    int n, r;
    while (1) {
        scanf("%d %d", &n, &r);
        if (n == 0 && r == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &soldiers[i]);
        }

        for (int i = 0; i < r; i++) {
            scanf("%d", &powers[i]);
        }

        countAndPrint(n, r);
    }

    return 0;
}



