#include <stdio.h>

main()
{
    /* compiler will give warning, but compile and y will be printed. */
    /* warning: unknown escape sequence: '\y' */
    printf("\y");
}
