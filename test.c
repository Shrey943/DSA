# include <stdio.h>
# include <stdlib.h>

int main()
{
    int *element1, *element2, *element3, *element4, *element5;

    element1 = (int *)malloc(sizeof(int));
    element2 = (int *)malloc(sizeof(int));
    element3 = (int *)malloc(sizeof(int));
    element4 = (int *)malloc(sizeof(int));
    element5 = (int *)malloc(sizeof(int));

    printf("%d\n", sizeof(int));

    printf("Address1: %d\n", element1);
    printf("Address2: %d\n", element2);
    printf("Address3: %d\n", element3);
    printf("Address4: %d\n", element4);
    printf("Address5: %d\n", element5);

    return 0;
}