#include <stdio.h>

#define MAXWORD 500
#define IN      1
#define OUT     0

main()
{
    int c, i, state, counter, longest;
    int nword[MAXWORD];

    for (i = 0; i < MAXWORD; ++i)
        nword[i] = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            nword[counter] += 1;
        }
        else if (state == OUT) {
            state = IN;
        }

    }

    /* print histogram */
}
