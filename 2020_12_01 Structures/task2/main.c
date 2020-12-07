#include <stdio.h>
#include <string.h>

#define NAME_SIZE 15
#define SURNAME_SIZE 25
#define PHONE_SIZE 20

struct contact{
    char name[NAME_SIZE];
    char surname[SURNAME_SIZE];
    char phoneNumber[PHONE_SIZE];
};


void phoneBookInit(struct contact phoneBook[], int size);
void phoneBookPrint(struct contact phoneBook[], int size);
void phoneBookAdd(struct contact phoneBook[], int size);
void phoneBookDel(struct contact phoneBook[], int size);
void phoneBookSearch(struct contact phoneBook[], int size);


int main(){
    const int sizePhoneBook = 10;
    struct contact phoneBook[sizePhoneBook];
    
    phoneBookInit(phoneBook, sizePhoneBook);

    int choice = 0;
    do
    {
        printf("1.  Display the phone book\n");
        printf("2.  Add a contact to phone book\n");
        printf("3.  Delete a contact from the phone book\n");
        printf("4.  Search for a contact in the phone book\n");
        printf("5.  Exit the program\n");

        do
            scanf("%d", &choice);
        while (choice < 1 || choice > 5);
        getchar();

        printf("\n");

        switch (choice) {
        case 1:
            phoneBookPrint(phoneBook, sizePhoneBook);
            break;
        case 2:
            phoneBookAdd(phoneBook, sizePhoneBook);
            break;
        case 3:
            phoneBookDel(phoneBook, sizePhoneBook);
            break;
        case 4:
            phoneBookSearch(phoneBook, sizePhoneBook);
            break;
        default:
            break;
        }

        printf("\n\n\n\n\n");
    } while (choice != 5);
    
    return 0;
}


void phoneBookInit(struct contact phoneBook[], int size){
    for (int i = 0 ; i < size ; ++i){
        phoneBook[i].name[0] = '\0';
        phoneBook[i].surname[0] = '\0';
        phoneBook[i].phoneNumber[0] = '\0';
    }
    /*
    strcpy(phoneBook[0].name, "Ivan");
    strcpy(phoneBook[0].surname, "Ivanov");
    strcpy(phoneBook[0].phoneNumber, "8-800-555-35-35");

    strcpy(phoneBook[1].name, "Taxi");
    strcpy(phoneBook[1].surname, "  ");
    strcpy(phoneBook[1].phoneNumber, "+7(383)312-10-00");

    strcpy(phoneBook[2].name, "Petr");
    strcpy(phoneBook[2].surname, "Petrov");
    strcpy(phoneBook[2].phoneNumber, "8-999-456-78-90");

    strcpy(phoneBook[3].name, "Petr");
    strcpy(phoneBook[3].surname, "Ivanov");
    strcpy(phoneBook[3].phoneNumber, "8-800-555-53-53");
    */
}


void phoneBookPrint(struct contact phoneBook[], int size){
    int num = 0;
    for (int i = 0 ; i < size ; ++i)
        if (phoneBook[i].name[0] != '\0' || phoneBook[i].surname[0] != '\0')
            printf("%4d. %s %s\t%s\n", ++num, phoneBook[i].name, phoneBook[i].surname, phoneBook[i].phoneNumber);
    if (!num)
        printf("The database is empty\n");
}


void phoneBookAdd(struct contact phoneBook[], int size){
    for (int i = 0 ; i < size ; ++i)
        if (phoneBook[i].name[0] == '\0' && phoneBook[i].surname[0] == '\0'){
            printf("Enter name: ");
            fgets(phoneBook[i].name, NAME_SIZE, stdin);
            *index(phoneBook[i].name, '\n') = '\0';
                
            printf("Enter surname: ");
            fgets(phoneBook[i].surname, SURNAME_SIZE, stdin);
            *index(phoneBook[i].surname, '\n') = '\0';

            printf("Enter phone: ");
            fgets(phoneBook[i].phoneNumber, PHONE_SIZE, stdin); 
            *index(phoneBook[i].phoneNumber, '\n') = '\0';
            
            printf("\nAdding successfully\n");

            return; 
        }
    printf("The database is full\n");
}


void phoneBookDel(struct contact phoneBook[], int size){
    int num = 0;
    for (int i = 0 ; i < size ; ++i)
        if (phoneBook[i].name[0] != '\0' || phoneBook[i].surname[0] != '\0')
            printf("%4d. %s %s\t%s\n", ++num, phoneBook[i].name, phoneBook[i].surname, phoneBook[i].phoneNumber);
    if (!num){
        printf("The database is empty\n");
        return;
    }

    printf("\nEnter the index of the record to delete: ");
    int choice;
    do
        scanf("%d", &choice);
    while (choice < 1 || choice > num);
    getchar();

    num = 0;
    for (int i = 0 ; i < size ; ++i){
        if (phoneBook[i].name[0] != '\0' || phoneBook[i].surname[0] != '\0')
            num++;
        if ((num) == choice){
            phoneBook[i].name[0] = '\0';
            phoneBook[i].surname[0] = '\0';
            phoneBook[i].phoneNumber[0] = '\0';

            printf("\nDelete successfully\n");

            return;
        }
    }
}


void phoneBookSearch(struct contact phoneBook[], int size){
    printf("Enter surname for searching: ");
    char surname[SURNAME_SIZE];
    fgets(surname, SURNAME_SIZE, stdin);
    *index(surname, '\n') = '\0';
    printf("\n");

    for (int i = 0; i < size; i++) {
        int num = 0;
        if (strcmp(phoneBook[i].surname, surname) == 0)
            printf("%4d. %s %s\t%s\n", ++num, phoneBook[i].name, phoneBook[i].surname, phoneBook[i].phoneNumber);
    }
}