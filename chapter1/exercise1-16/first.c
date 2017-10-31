#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int mygetline(char line[], int maxline);    /* using my since getline is in stdio.h */
void copy(char to[], char from[]);

/* print (as much as possible from) longest input line and its length */
main()
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0 && max >= MAXLINE) {    /* there was a too big line */
        printf("String exceeded limit, printing only %d chars.\n", MAXLINE);
        printf("length line: %d.\n%s\n", max, longest);
    } else if (max > 0)    /* there was a line */
        printf("length line: %d.\n%s\n", max, longest);

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

/* copy:    copy 'from' into 'to';assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
