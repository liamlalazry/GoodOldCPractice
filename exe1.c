#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>   // for printf, scanf
#include <stdlib.h>  // for malloc, free, exit
#include <string.h>  // for strcpy, strlen, etc.
#include <stddef.h> // for offsetof
#include <stdint.h>
unsigned mask = 0b0101;
int example(){
    // Declare variables
    int number = 0;
    char name[50];
    int x;
    // Print to console
    printf("Enter your name: ");
    x = scanf("%49s", name);  // limit input to avoid buffer overflow
    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input!\n");
        return 1; // exit with error
    }
    // Process data
    printf("Hello, %s!\n", name);
    printf("Your number doubled is %d.\n", number * 2);
    // Return success
    return 0;

}
int exe1a(){
    struct Person {
        char name[50];//50 bytes    
        int age;//4 bytes
        float height;//4 bytes
        double weight;//8 bytes
        short number_of_friends;//2 bytes
    };
    struct BetterPerson {
        int Bage;//4 bytes
        float Bheight;//4 bytes 
        double Bweight;//8 bytes
        short Bnumber_of_friends;//2 bytes
        char Bname[50];//50 bytes
    };
    printf("sizeof Person struct is = %zu\n", sizeof(struct Person));
    printf("Offset of name: %zu\n", offsetof(struct Person, name));
    printf("Offset of age: %zu\n", offsetof(struct Person, age));
    printf("Offset of height: %zu\n", offsetof(struct Person, height)); 
    printf("Offset of weight: %zu\n", offsetof(struct Person, weight));
    printf("Offset of number_of_friends: %zu\n", offsetof(struct Person, number_of_friends));
    printf("---------------------------------------------------------------------------------\n");
    printf("sizeof Person struct is = %zu\n", sizeof(struct BetterPerson));
    printf("Offset of name: %zu\n", offsetof(struct BetterPerson, Bname));
    printf("Offset of age: %zu\n", offsetof(struct BetterPerson, Bage));
    printf("Offset of height: %zu\n", offsetof(struct BetterPerson, Bheight));
    printf("Offset of weight: %zu\n", offsetof(struct BetterPerson, Bweight));
    printf("Offset of number_of_friends: %zu\n", offsetof(struct BetterPerson, Bnumber_of_friends));
}
int exe1b(){
    union Uni {
        uint32_t u32;
        uint8_t b[4];
    };
    union Uni c;
    c.u32 = 0x11223344;
    printf("u32 = 0x%08X\n", c.u32);
    printf("b[0] = 0x%08X\n", c.b[0]);
    printf("b[1] = 0x%08X\n", c.b[1]);
    printf("b[2] = 0x%08X\n", c.b[2]);
    printf("b[3] = 0x%08X\n", c.b[3]);
    //big endian!
}
int exe1c(){
    
    enum Checker {
        READ = 1,//0001
        WRITE =2,//0010
        EXEC =4//0100
    };
    if (mask & READ)
    {
      printf("Read is up! 0001 \n");
    }
    if (mask & WRITE)
    {
        printf("Write is up ! 0010");

    }
    if (mask & EXEC) {
        printf("EXEC is up ! 0100");
    }
};
int main(void) {

    return 0;
    
}
