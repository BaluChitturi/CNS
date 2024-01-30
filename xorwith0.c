#include <stdio.h>
#include <string.h>

void binaryValue(int n) {
    int b[8],x[8];
    int j,k,l;
    // Convert to binary
    for ( j = 7; j >= 0; j--) {
        b[j] = n % 2;
        n = n / 2;
    }

    // Print binary representation
  /* for (int i = 0; i < 8; i++) {
        printf("%d\t", b[i]);
    }*/
   // printf("\n");
    for( k=0;k<8;k++)
    {
        if(b[k]==0)
        {
            x[k]=0;
        }
        else{
            x[k]=1;
        }
    }

    int decimal = 0;
    for ( l = 0; l < 8; l++) {
        decimal = decimal * 2 + x[l];
    }
  
    printf("%c", (char)decimal);
}

int main() {
    char str[100];
    int i;
    printf("Enter a String for Xor operation\n");
    scanf("%s", str);
      printf("After xor operation\n");
    for ( i = 0; i < strlen(str); i++) {
        binaryValue((int)str[i]);
    }

    return 0;
}
