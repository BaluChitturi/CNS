#include <stdio.h>
#include <string.h>

int a = 0;
void printState(int state, char c) {
    printf("|q%d|-----%c----->", state, c);
}

void start(char c) {
    if (c == 'a') {
        a = 2;
        printState(a - 1, c);
    } else {
        a = -1;
    }
}

void state1(char c) {
    if (c == 'b') {
        a = 3;
        printState(a - 1, c);
    } else {
        a = -1;
    }
}

void state3(char c) {
    if (c == 'a' || c == 'b') {
        a = 3;
        printState(a, c);
    } else {
        a = -1;
    }
}

int main(void) {
    char str[100];
    int i;
    printf("NFA for Regular Expression of-->ab(a|b)*\n");
    printf("Enter a String without spaces\n");
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++) {
        if (a == 0) {
            start(str[i]);
        } else if (a == 2) {
            state1(str[i]);
        } else if (a == 3) {
            state3(str[i]);
        } else {
            break;
        }
    }
    printf("||q%d||\n",a);
    if (a == -1) {
        printf("String is not accepted\n");
    } else {
        printf("String is accepted\n");
    }

    return 0;
}
