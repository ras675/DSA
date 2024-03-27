#include <stdio.h>
#include <string.h>

void hint(const char *secret, const char *guess) {
    int bulls = 0;
    int cows = 0;
    int secretCount[10] = {0};
    int guessCount[10] = {0};

    for (int i = 0; secret[i] != '\0'; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secretCount[secret[i] - '0']++;
            guessCount[guess[i] - '0']++;
        }
    }


    for (int i = 0; i < 10; i++) {
        cows += (secretCount[i] < guessCount[i]) ? secretCount[i] : guessCount[i];
    }

    printf("%dB%dC\n", bulls, cows);
}

int main() {
    char secret[1001];
    char guess[1001];

    scanf("%s", secret);
    scanf("%s", guess);

    hint(secret, guess);

    return 0;
}