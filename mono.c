#include <stdio.h>
#include <string.h>

int main() {
    char alpha[26], key[10], final[26] = {'\0'}, plain[100], matched[100] = {'\0'};
    printf("Enter a string:\n");
    scanf("%s", plain);
    printf("Enter a Key string:\n");
    scanf("%s", key);

    int j = 65;
    for (int i = 0; i < 26; i++) {
        alpha[i] = (char)j++;
    }
    printf("Alphabets:%s\n", alpha);

    strcpy(final, key);
    int k = strlen(key);

    for (int i = 0; i < strlen(alpha); i++) {
        int isMatch = 0;
        for (int j = 0; j < strlen(key); j++) {
            if (alpha[i] == key[j]) {
                isMatch = 1;
                break;
            }
        }
        if (!isMatch) {
            final[k] = alpha[i];
            k++;
        }
    }

    printf("Cipher String:%s\n", final);

    int m = 0;
    for (int i = 0; i < strlen(plain); i++) {
        for (int j = 0; j < strlen(alpha); j++) {
            if (plain[i] == alpha[j] && final[j] != '\0') {
                matched[m] = final[j];
                final[j] = '\0'; 
                m++;
                break;
            }
        }
    }

    printf("Encrypted string: %s\n", matched);

    return 0;
}
