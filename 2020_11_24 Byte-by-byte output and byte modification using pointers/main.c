#include <stdio.h>


void byteOutOfNum(int num){
    unsigned char *pointer = (unsigned char *)&num; 
    for (char i = 0 ; i < 4 ; i++){
        printf("%d byte of the number: %02X\n", i + 1, *pointer);
        pointer++;
    }
}

int changeByteInNum(int num, unsigned char byte, unsigned char value){
    unsigned char *pointer = (unsigned char *)&num; 
    pointer += byte - 1;
    *pointer = value;
    return num;
}

int main(){
    int num = 0x0F1E2D3C;
    printf("Task1:\n");
    printf("number = %08X\n", num);
    byteOutOfNum(num);

    printf("\nTask2:\n");
    printf("number = %08X\n", num);
    int newNum = changeByteInNum(num, 2, 0xAA);

    printf("new number after replacing 2 byte with 0xAA = %08X\n", newNum);
}