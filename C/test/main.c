#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This file is for me to test my code and learn c*/


int main() {


    printf("%d\n", EOF);

    printf("Hello world!\n");

    char name[100];

    char *description;

    strcpy(name, "Bob Newhart");

    printf("Name = %s\n", name);

    int counter;
    for (counter = 0; counter < 10; counter++)
        printf("---");
    printf("---\n");

    int myNumber = 32;

    int *addr = &myNumber;

    printf("myNumber = %d\n", myNumber);

    printf("The Address of myNumber is %x\n", addr);

    printf("----------------------------\n");

    union greatnums {

        int i;

        float j;

    };

    union greatnums first_number;

    first_number.i = 87;
    first_number.j = 4.9;

    printf("i = %d\n", first_number.i);
    printf("j = %f\n", first_number.j);

    int *numaddri = &first_number.i;
    int *numaddrj = &first_number.j;

    printf("The address of i is %x\n", numaddri);
    printf("The address of j is %x\n", numaddrj);

    printf("--------------------------------\n");

    struct newpoint {

        int x, z;

    } first_npoint, second_npoint;

    return 0;
}
