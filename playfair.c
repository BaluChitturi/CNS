#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define size 5
void splitStringIntoPairs(char input[], char pairs[][2]) {
    int len = strlen(input);
    int pairIndex = 0;
    int i;

    for ( i = 0; i < len; i += 2) {
        pairs[pairIndex][0] = input[i];

        if (i + 1 < len) {
            pairs[pairIndex][1] = input[i + 1];
        } else {
            pairs[pairIndex][1] = 'X'; 
        }

        pairIndex++;
    }
}

int main() {
    char plaintext[100];
    char pairs[50][2];
    int i;
    char key[size*size];
    char keySquare[size][size];
    
    printf("Enter the plaintext (all uppercase): ");
    scanf("%s", plaintext);

    splitStringIntoPairs(plaintext, pairs);
    int n=strlen(plaintext);
    printf("Pairs: ");
    for ( i = 0; i < n / 2 + n % 2; i++) {
    	if(pairs[i][0]==pairs[i][1])
    	{
    		n=n+1;
    		char temp=pairs[i][1];
    		pairs[i][1]='X';
    		pairs[i+1][0]=temp;
    		
		}
        printf("%c%c ", pairs[i][0], pairs[i][1]);
    }
    fillKeySquare(key,keySquare);
    ptint(keySquare);
}
void fillKeySquare(char key[],char keySquare[size][size]) {
    int k = 0;
    int used[26] = {0};
    char ch;
    int i,j;
    for ( i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            while (used[key[k] - 'A']) {
                k++;
            }
            keySquare[i][j] = toupper(key[k]);
            used[key[k] - 'A'] = 1;
            k++;
        }
    }

    for ( ch = 'A'; ch <= 'Z'; ch++) {
        if (ch != 'J' && !used[ch - 'A']) {
            for ( i = 0; i < 5; i++) {
                for ( j = 0; j < size; j++) {
                    if (keySquare[i][j] == '\0') {
                        keySquare[i][j] = ch;
                        used[ch - 'A'] = 1;
                        break;
                    }
                }
                if (used[ch - 'A']) {
                    break;
                }
            }
        }
    }
}
void print(char keySquare[size][size]) {
	int i,j;
    printf("Key Square:\n");
    for (i = 0; i < size; i++) {
        for ( j = 0; j < size; j++) {
            printf("%c ", keySquare[i][j]);
        }
        printf("\n");
    }
}
