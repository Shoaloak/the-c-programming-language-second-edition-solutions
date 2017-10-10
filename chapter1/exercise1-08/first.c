#include <stdio.h>

/* count blanks, tabs and newlines in input */
main()
{
    int c, nb, nt, nl;

    nb = nt = nl = 0;
    /* would use switch, but not introduced yet. */
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("%d blanks, %d tabs and %d newlines\n", nb, nt, nl);
}
