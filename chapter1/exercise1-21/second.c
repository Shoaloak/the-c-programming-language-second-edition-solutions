#include <stdio.h>
#define TABSTOP 8
#define TRUE    1
#define FALSE   0

/* replace strings of blanks by the minimum number of tabs */
int main()
{
    int i, c;
    int iw;     /* inside whitespace */
    int cc;     /* character counter */
    int ci;     /* character index */
    int bc;     /* blank counter */

    iw = FALSE;
    cc = 0;
    while ((c = getchar()) != EOF) {
        /* new character, increase counter */
        cc += 1;

        /* newline, reset */
        if (c == '\n') {
            putchar('\n');
            cc = 0;
            iw = FALSE;
        }

        /* blank, set/increase whitespace and counter */
        if (c == ' ') {
            if (iw)
                bc += 1;
            else {
                iw = TRUE;
                bc = 0;
            }
        }

        /* reset and print blanks if nonblank whilst inside whitespace */
        if (c != ' ' && iw) {
            for (i = 0; i <= bc; ++i)
                putchar(' ');

            iw = FALSE;
        }

        /* tab, reset */
        if (c == '\t') {
            cc = 0;
            iw = FALSE;
        }

        if (cc == TABSTOP) {
            if (iw) {
                putchar('\\');
                putchar('t');
            }
            else if (!(c == '\n'))
                putchar(c);

            /* reset */
            cc = 0;
            iw = FALSE;
        }
        else
            if (!iw && !(c == '\n'))
                putchar(c);
    }

    return 0;
}
