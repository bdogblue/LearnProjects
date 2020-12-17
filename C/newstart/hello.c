#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    printf("----------------\n");

    int c = (getchar() != EOF);
    printf("%d\n", c);

    printf("%d\n", EOF);

    printf("-----------------\n");

    int b, nl, tb, bl;

    nl = tb = bl = 0;
    b = getchar();
    while (b != EOF) {
        if (b == '\n')
            ++nl;
        if (b == '\v')
            ++tb;
        if (b == ' ')
            ++bl;
        if (b == EOF)
            break;
    }
    printf("NewLines = %d\n", nl);
    printf("Tabs = %d\n", tb);
    printf("Blanks = %d\n", bl);
}
