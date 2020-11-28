#include <stdio.h>


void byteOutOfNum(int num){
    for (char i = 0 ; i < 4 ; i++, num  = num >> 8)
        printf("%d byte of the number: %02X\n", i + 1, num & 0xFF);
}

int changeByteInNum(int num, unsigned char byte, unsigned char value){
    return (num & ~(0xFF << 8 * (byte - 1))) | (value << 8 * (byte - 1));
}

int main(){
    int num = 0x0A1B2C3D;
    printf("Task1:\n");
    printf("number = %08X\n", num);
    byteOutOfNum(num);

    printf("\nTask2:\n");
    printf("number = %08X\n", num);
    int newNum = changeByteInNum(num, 3, 0xDD);

    printf("new number after replacing 3 byte with 0xDD = %08X\n", newNum);
}