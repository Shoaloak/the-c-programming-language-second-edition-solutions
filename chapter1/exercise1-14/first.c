#include <stdio.h>

#define MAXCHAR     127 /*ASCII charset */
#define HISTSIZE    48

/* print histogram of the lengths of words */
main()
{
    int c, i, j;
    int grocc, histlen;
    int nchar[MAXCHAR]; 

    for (i = 0; i < MAXCHAR; ++i)
        nchar[i] = 0;

    while ((c = getchar()) != EOF)
        nchar[c] += 1;

    grocc = 0;  /* greatest occurrence */
    for (i = 0; i < MAXCHAR; ++i)
        if (nchar[i] > grocc)
            grocc = nchar[i];

    /* print horizontal histogram since 127 doesn't fit vertically */
    for (i = 0; i < MAXCHAR; ++i) {
        histlen = (nchar[i] * HISTSIZE) / grocc;
        /* can be improved using isprint from ctype.h */
        /* e.g. if (isprint(c)) printf(...); else printf("ascii:%d"); */
        printf("char:%2c, occurrences:%2d - [", i, nchar[i]);
        for (j = 0; j < histlen; ++j)
            putchar('*');
        printf("]\n");
    }
}
