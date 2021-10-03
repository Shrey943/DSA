#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1;

    for (int i = 0; i <= 5; i++)
    {
        x = x++ + ++x;
        if (x > 100)
        {
            break;
        }
    }
    printf("%d\n", x);

    return 0;
}