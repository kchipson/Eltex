#include <stdio.h>
#include <stdlib.h>
#include "libmyCalc/myCalc.h"


int main(){

    int choice = 0;
    float op1, op2;
    do
    {
        printf("1.  Addition\n");
        printf("2.  Subtraction\n");
        printf("3.  Multiplication\n");
        printf("4.  Division\n");
        printf("5.  Exit the program\n");
        do
            scanf("%d", &choice);
        while (choice < 1 || choice > 5);
        
        if (choice == 5)
            continue;
        printf("\nEnter the first operand of the operation:  ");
        scanf("%f", &op1);
        printf("Enter the second operand of the operation: ");
        scanf("%f", &op2);

        switch (choice) {
        case 1:
            printf("Result of the addition operation %f and %f: %f\n", op1, op2, myCalc_add(op1, op2));
            break;
        case 2:
            printf("The result of the operation of subtracting %f from %f: %f\n", op1, op2, myCalc_sub(op1, op2));
            break;
        case 3:
            printf("The result of the operation of multiplying %f by %f: %f\n", op1, op2, myCalc_mul(op1, op2));
            break;
        case 4:
            printf("The result of the operation of dividing  %f by %f: %f\n", op1, op2, myCalc_div(op1, op2));
            break;
        default:
            break;
        }

        printf("\n\n\n\n\n");
    } while (choice != 5);
    
    return 0;
}

