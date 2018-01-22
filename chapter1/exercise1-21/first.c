#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */
#define TABSTOPS 8

int mygetline(char line[], int maxline);
void entab(char to[], char from[], int tabstop);


/* entab:   a program that replaces tabs with proper amount of blanks */
int main()
{
    int len;
    char line[MAXLINE];
    char entabbed_line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0)
    {
        entab(entabbed_line, line, TABSTOPS);
        printf("%s", entabbed_line);
    }
    
    return 0;
}

/* mygetline:   read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;
    c = '\0';

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* entab: looks for space to substitute with tab */
void entab(char to[], char from[], int n)
{
    int oldloc, newloc, offset;

    for (newloc = oldloc = 0; from[oldloc] != '\0'; ++oldloc)
    {
        /* end of chunk AND tab possible */
        if ((oldloc+1) % n == 0 && from[oldloc] == ' ')
        {
            /* discover tab placing offset */
            for (offset = oldloc; from[offset] == ' '; --offset);

            /* newloc hasn't been incremented yet, hence the +1 */
            newloc = (newloc+1) - (oldloc-offset);

            to[newloc] = '\t';
            ++newloc;

        }
        /* not end of chunk */
        else
        {
            to[newloc] = from[oldloc];
            ++newloc;
        }
    }

    to[newloc] = '\0';
}
