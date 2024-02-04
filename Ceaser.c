// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    // Write C code here
    char text[100];
    char f_text[100],s_text[100];
    printf("Enter a String\n");
    scanf("%s",text);
    for(int i=0;i<strlen(text);i++)
    {
        if(isupper(text[i]))
        {
        f_text[i] =(char)((text[i]+3-65)%26+65);
        }
        else{
        f_text[i] =(char)((text[i]+3-97)%26+97);
        }
    }
    printf("%s",f_text);
    printf("\nDecryption of text:\n");
    for(int i=0;i<strlen(f_text);i++)
    {
        if(isupper(f_text[i]))
        {
            s_text[i]=(char)((f_text[i]-3-65)%26+65);
        }
        else{
            s_text[i]=(char)((f_text[i]-3-97)%26+97);
        }
    }
    printf("%s",s_text);

    return 0;
}
