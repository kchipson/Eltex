#include <stdio.h>

struct unpacked{
    char a;
    int b;
};

struct packed{
    char a;
    int b;
}__attribute__((packed));

int main(){
    char test[10] = {'A', 0, 0, 0, 0, 'B', 0, 0, 0, 0};

    struct unpacked *unpackedPtr = (struct unpacked *) test;
    struct packed *packedPtr = (struct packed *) test;

    printf("Unpacked structure:\n");
    printf("  sizeOf: %d\n", sizeof(struct unpacked));
    printf("  1: a = \"%c\"  b = \"%d\"\n", unpackedPtr->a, unpackedPtr->b);
    unpackedPtr++;
    printf("  2: a = \"%c\"  b = \"%d\"\n", unpackedPtr->a, unpackedPtr->b);

    printf("\nPacked structure:\n");
    printf("  sizeOf: %d\n", sizeof(struct packed));
    printf("  1: a = \"%c\"  b = \"%d\"\n", packedPtr->a, packedPtr->b);
    packedPtr++;
    printf("  2: a = \"%c\"  b = \"%d\"\n", packedPtr->a, packedPtr->b);

    return 0;
}