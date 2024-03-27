#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void extractOriginalLyrics(char *dubstepLyrics) {
    int len = strlen(dubstepLyrics);
    char originalLyrics[MAX_LEN];
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (i < len - 2 && strncmp(&dubstepLyrics[i], "dub", 3) == 0) {
            i += 2;
            if (index > 0 && originalLyrics[index - 1] != ' ') {
                originalLyrics[index++] = ' ';
            }
        } else {
            originalLyrics[index++] = dubstepLyrics[i];
        }
    }
    originalLyrics[index] = '\0';

    printf("%s\n", originalLyrics);
}

int main() {
    int length;
    char dubstepLyrics[MAX_LEN];

    scanf("%d\n", &length);
    fgets(dubstepLyrics, MAX_LEN, stdin);
    dubstepLyrics[strlen(dubstepLyrics) - 1] = '\0';

    extractOriginalLyrics(dubstepLyrics);

    return 0;
}


