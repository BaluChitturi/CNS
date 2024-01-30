#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void encryptMonoalphabetic(char plaintext[], char key[]) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            int index = tolower(plaintext[i]) - 'a';
            if (isupper(plaintext[i])) {
                plaintext[i] = toupper(key[index]);
            } else {
                plaintext[i] = tolower(key[index]);
            }
        }
    }
}

int main() {
    char plaintext[1000];
    char key[ALPHABET_SIZE] = "QWERTYUIOPASDFGHJKLZXCVBNM";  

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    encryptMonoalphabetic(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
