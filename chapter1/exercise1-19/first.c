#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int mygetline(char line[], int maxline);
void reverse(char line[], int length);

/* reverse input line by line */
int main()
{
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s\n", line);
    }

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

/* reverse:     reverse line s*/
void reverse(char s[], int len)
{
    int tmp;
    int i = 0;
    int j = len-1;

    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        ++i;
        --j;
    }
}
