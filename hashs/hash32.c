#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
// http://ctips.pbworks.com/w/page/7277591/FNV%20Hash
#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U
uint32_t FNV32(const char *s)
{
    uint32_t hash = FNV_OFFSET_32, i;
    for(i = 0; i < strlen(s); i++)
    {
        hash = hash ^ (s[i]); // xor next byte into the bottom of the hash
        hash = hash * FNV_PRIME_32; // Multiply by prime number found to work well
    }
    return hash;
}

void main() {
char *teststring = "This is a test";
uint32_t hash_of_string = FNV32(teststring);

printf("%d\n", hash_of_string);
}

