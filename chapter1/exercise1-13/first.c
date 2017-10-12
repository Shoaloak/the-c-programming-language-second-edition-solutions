#include <stdio.h>

#define MAXWORD     32
#define HISTSIZE    48
#define IN          1
#define OUT         0

/* print histogram of the lengths of words */
main()
{
    int c, i, j;
    int status, cc, biggest, histlen;
    int nword[MAXWORD]; 

    for (i = 0; i < MAXWORD; ++i)
        nword[i] = 0;

    cc = 0;         /* character counter */
    status = OUT;   /* status in/outside word */
    biggest = 0;    /* largest word length seen */

    while ((c = getchar()) != EOF) {
        if (status == IN && (c == ' ' || c == '\t' || c == '\n')) {
            status = OUT;
            nword[cc] += 1;
            cc = 0;
        }
        else if (status == OUT)
            status = IN;
        else
            ++cc;
    }

    for (i = 0; i < MAXWORD; ++i)
        if (nword[i] > biggest)
            biggest = nword[i];

    /* print horizontal histogram */
/*
    for (i = 0; i < MAXWORD; ++i) {
        histlen = (nword[i] * HISTSIZE) / biggest;
        printf("wordsize:%2d, occurrences:%2d - [", i, nword[i]);
        for (j = 0; j < histlen; ++j)
            putchar('*');
        printf("]\n");
    }
*/

    /* print vertical histogram */
    for (i = HISTSIZE; i > 0; --i) {
        printf("        ");
        for (j = 0; j < MAXWORD; ++j) {
            histlen = (nword[j] * HISTSIZE) / biggest;

            if ((i - histlen) <= 0)
                printf(" # ");
            else
                printf("   ");
        }
        putchar('\n');
    }
    printf("length: ");
    for (i = 0; i < MAXWORD; ++i)
        printf("%2d ", i+1);
    putchar('\n');
    printf("#     : ");
    for (i = 0; i < MAXWORD; ++i)
        printf("%2d ", nword[i]);
    putchar('\n');
}
