#include <stdio.h>
#include <string.h>

void binaryValue(int n) {
    int b[8],x[8];

    // Convert to binary
    for (int i = 7; i >= 0; i--) {
        b[i] = n % 2;
        n = n / 2;
    }

    // Print binary representation
    for (int i = 0; i < 8; i++) {
        printf("%d\t", b[i]);
    }
    printf("\n");
    for(int i=0;i<8;i++)
    {
        if(b[i]==0)
        {
            x[i]=0;
        }
        else{
            x[i]=1;
        }
    }

    int decimal = 0;
    for (int i = 0; i < 8; i++) {
        decimal = decimal * 2 + x[i];
    }

    printf("ASCII: %c\n", (char)decimal);
}

int main() {
    char str[100];
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        binaryValue((int)str[i]);
    }

    return 0;
}
