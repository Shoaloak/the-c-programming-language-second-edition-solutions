/* removed stdio.h inclusion */
/* does still compile and run, gives warning and note however */

/* warning: incompatible implicit declaration of built-in function ‘printf’ */
/* printf("hello, world\n"); */
/* ^ */
/* note: include ‘<stdio.h>’ or provide a declaration of ‘printf’ */

#include <stdio.h>

/* removed main braces {} */
/* main() */
/*     printf("hello, world\n"); */

/* error: expected declaration specifiers before ‘printf’ */
/* error: expected ‘{’ at end of input */

/* removed parentheses main */
/* error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘{’ token */

/* removed main function with compound statement (or block) completely */
/* Scrt1.o: In function `_start': */
/* (.text+0x20): undefined reference to `main' */
/* collect2: error: ld returned 1 exit status */

main()
{
    /* removed printf arguments */
    /* printf(); */
    /* error: too few arguments to function ‘printf’ */

    /* removed semicolon (;) */
    /* printf("hello, world\n") */
    /* error: expected ‘;’ before ‘}’ token */

    /* original */
    printf("hello, world\n");
}
