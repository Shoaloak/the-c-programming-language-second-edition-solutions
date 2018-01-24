#include <stdio.h>
#define LIMIT   1000
#define TRUE    1
#define FALSE   0

int removecomment();

/* a program to remove comments from a C program, no nesting */
int main() {
    if (removecomment() != 0)
        printf("\n/*ERROR*/, nested comment!\n");

    return 0;
}

/* removecomment:   removes comments from input C code, returns !0 if nested comment */
int removecomment() {
    int c; 

    int instr;  /* inside string */
    int incons; /* inside character constant */
    int incom;  /* inside comment */
    int encom;  /* entry comment */
    int excom;  /* exit comment */
    int nested; /* nested comment */

    instr   = FALSE;
    incons  = FALSE;
    incom   = FALSE;
    encom   = FALSE;
    excom   = FALSE;
    nested  = FALSE;

    /* TODO: remove continue, make giant if else chain */
    while ((c = getchar()) != EOF) {
        /* inside string? */
        if (instr) {
            putchar(c);
            if (c == '"')
                instr = FALSE;
            continue;
        }

        /* inside character constant? */
        if (incons) {
            putchar(c);
            if (c == '\'')
                incons = FALSE;
            continue;
        }

        /* inside comment? */
        if (incom) {
            if (!excom && c == '*')
                excom = TRUE;
            else if (excom && c == '/') {
                incom = FALSE;
                excom = FALSE;
            }
            /* check nested */
            if (!nested && c == '/')
                nested = TRUE;
            else if (nested && c != '*')
                nested = FALSE;
            else if  (nested && c == '*')
                return 1;

            continue;
        }

        /* potential entry comment */
        if (!encom && c == '/' && !instr && !incons) {
            encom = TRUE;
            continue;
        }
        else if (encom && c != '*') {
            encom = FALSE;
            putchar('/');
            putchar(c);
            continue;
        }
        else if (encom && c == '*') {
            incom = TRUE;
            encom = FALSE;
            continue;
        }

        /* entry string */
        if (!incom && c == '"') {
            putchar(c);
            instr = TRUE;
            continue;
        }

        /* entry character constant */
        if (!incom && c == '\'') {
            putchar(c);
            incons = TRUE;
            continue;
        }

        putchar(c);
    }

    return 0;
}
