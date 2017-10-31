#include <stdio.h>
#define TABSTOP 8

/* replace tabs in input with proper number of blanks */
int main()
{
    int c, i;
    int cc;

    cc = TABSTOP; /* character counter */

    while ((c = getchar()) != EOF) {
        if (cc < TABSTOP)
            ++cc;
        else
            cc = 1;

        if (c == '\t') {
            for (i = 0; i <= TABSTOP-cc; ++i)
                putchar(' ');
            cc = TABSTOP;
        }
        else {
            if (c == '\n')
                cc = TABSTOP;
            putchar(c);
        }
    }



    return 0;
}
