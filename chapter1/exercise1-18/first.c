#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int mygetline(char line[], int maxline);
int removewhitespace(char line[], int length);

/* remove trailing blanks and tabs from input and delete blank lines entirely */
int main()
{
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0)
        if (removewhitespace(line, len) > 0)
            printf("%s\n", line);

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

/* removewhitespace: cut off trailing whitespace with NULL, return new length */
int removewhitespace(char s[], int len)
{
    int i;

    for (i = len-1; i > 0; --i)
        if (s[i] != ' ' && s[i] != '\t')
            break;

    s[i+1] = '\0';

    return i;
}
