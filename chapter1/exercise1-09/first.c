#include <stdio.h>

#define IN  1
#define OUT 0

/* no else or && || ... introduced */
main()
{
    int c, blank;

    blank = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            if (blank == OUT) {
                blank = IN;
                putchar(c);
            }

        if (c != ' ') {
            blank = OUT;
            putchar(c);
        }
    }
}
