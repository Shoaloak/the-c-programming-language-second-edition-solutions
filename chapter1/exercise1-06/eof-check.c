#include <stdio.h>

main()
{
    printf("getchar = a; (getchar() != EOF) == %i\n", 'a' != EOF);
    printf("getchar = EOF; (getchar() != EOF) == %i\n", EOF != EOF);
}
