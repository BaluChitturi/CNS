#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
void sha1(uint8_t *message, size_t len, uint32_t hash[5]) 
{
    uint32_t h0, h1, h2, h3, h4;
    uint32_t a, b, c, d, e;
    uint32_t *w;
    size_t padded_len, i, j;
    padded_len = len + 9;
    padded_len += (512 - (padded_len % 512)) % 512;
    padded_len /= 8;
    w = (uint32_t *)malloc(padded_len);
    memset(w, 0, padded_len);
    memcpy(w, message, len);
    w[len/4] |= 0x80 << (24 - (8 * (len % 4)));
    w[padded_len - 1] = len * 8;
    h0 = 0x67452301;
    h1 = 0xEFCDAB89;
    h2 = 0x98BADCFE;
    h3 = 0x10325476;
    h4 = 0xC3D2E1F0;
    for (i = 0; i < padded_len; i += 16) 
    {
        uint32_t temp;
        uint32_t *chunk = w + i;
        uint32_t *words = (uint32_t *)malloc(80 * sizeof(uint32_t));
        memcpy(words, chunk, 16 * sizeof(uint32_t));
        for (j = 16; j < 80; j++)
            words[j] = LEFTROTATE(words[j - 3] ^ words[j - 8] ^ words[j - 14] ^ words[j - 16], 1);
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        for (j = 0; j < 80; j++) 
        {
            if (j < 20)
                temp = (b & c) | ((~b) & d);
            else if (j < 40)
                temp = b ^ c ^ d;
            else if (j < 60)
                temp = (b & c) | (b & d) | (c & d);
            else
                temp = b ^ c ^ d;
            temp += LEFTROTATE(a, 5) + e + words[j];
            e = d;
            d = c;
            c = LEFTROTATE(b, 30);
            b = a;
            a = temp;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        free(words);
    }
    hash[0] = h0;
    hash[1] = h1;
    hash[2] = h2;
    hash[3] = h3;
    hash[4] = h4;
    free(w);
}
int main() 
{
    char message[100];
    printf("Enter a Message for the SHA1:Encryption\n");
    scanf("%s",message);
    size_t len = strlen(message);
    uint32_t hash[5];
    sha1((uint8_t *)message, len, hash);
    printf("SHA-1 digest of \"%s\" is: %08x%08x%08x%08x%08x\n", message, hash[0], hash[1], hash[2], hash[3], hash[4]);
    return 0;
}
