# include <stdio.h>
# include <stdlib.h>

void transverse(int* ptr, int n);

int main()
{
    int* ptr  =  calloc(5,sizeof(int));

    if (ptr == NULL) {
        printf("ptr null");
    }
    transverse(ptr,5);

    int a,b,c,d ;

    printf("\n ADDRESS OF ABCD  : ");
    printf("\n%u",&a);
    printf("\n%u",&b);
    printf("\n%u",&c);
    printf("\n%u",&d);

    ptr = realloc(ptr,sizeof(int)*7);
    if (ptr == NULL) {
        printf("ptr null");
    }
    transverse(ptr,7);
    
    return 0;
}

void transverse(int* ptr,int n){
    printf("\n");
    for (int i = 0; i <n; i++){
        printf("%u",&ptr[i]);
        printf("\n");
    }
}