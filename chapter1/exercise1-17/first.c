#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define MINLINE 80      /* minimum required for output */

int mygetline(char line[], int maxline);    /* using my since getline is in stdio.h */

/* print input lines bigger than 80 chars */
main()
{
    int len;            /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > MINLINE)
            printf("%s", line);

    return 0;
}

/* mygetline:   read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for (i=0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim) {
            s[i] = c;
            ++j;
        }
    s[j] = '\0';
    return i;
}
