#include <stdio.h>

#define MAXLINE                 1000
#define FOLDLENGTH              80
#define WHITESPACESEARCHLIMIT   20
#define TRUE                    1

int mygetline(char string[], int limit);
void fold(char string[], int length, int limit, int whitespacesearchlimit);
int findwhite(char string[], int start, int whitespacesearchlimit);

/* a program that "folds" long input lines into multiple shorter lines */
int main() {
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len < FOLDLENGTH)
            printf("%s", line);
        else
            fold(line, len, FOLDLENGTH, WHITESPACESEARCHLIMIT);
    }

    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';

    return i;
}

/* fold:    break long input lines based on limit */
void fold(char s[], int len, int lim, int wsl) {
    int i;
    int wl;     /* whitespace location for fold */
    int ss;     /* searchstart, starting point for findwhite */
    int cl;     /* sentence location (printed thus far) */

    wl = 0;
    ss = lim;
    cl = 0;

    /* search whitespace near lim, print until said place, increase, repeat */
    while (TRUE) {
        wl = findwhite(s, ss, wsl);

        /* print until whitespace fold location */
        for (i = cl; i < wl; ++i)
            putchar(s[i]);
        if (s[i] != '\n')
            putchar('\n');
        cl = i+1;       /* set sentence start +1 to skip the whitespace char */

        ss = cl + lim;  /* next start will be $wsl chars ahead */

        /* end sentence, print remaining chars and break */
        if (ss > len) { 
            ss = len;
            for (i = cl; i < len; ++i)
                putchar(s[i]);
            break;
        }
    }
}

/* findwhite:   find whitespace location, if not found within $wsl chars, return start */
int findwhite(char s[], int start, int wsl) {
    int i, j;

    for (i = start, j = 0; i > 0; --i, ++j) {
        if (s[i] == ' ' || s[i] == '\t')
            break;
        if (j == wsl) {
            i = start;
            break;
        }
    }

    return i;
}
