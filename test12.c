#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void Bin_to_Dec() // Converted return from int to void
{
    int i, number, ans = 0, base = 1, rem;

    printf("\nEnter the number in binary to convert it into decimal form: ");
    scanf("%d", &number); // Removed \n

    while (number > 0)
    {
        rem = number % 10;
        ans = ans + rem * base;
        number = number / 10;
        base = base * 2;
    }
    printf("\nDecimal form is: %d\n", ans);
    // return 0;                                                                 // No need to return if already printing.
}

void Dec_to_Bin()
{
    int number, i, reverse;
    int ar;

    printf("\nEnter the number in Decimal form to convert it into Binary form: ");
    scanf("%d", &number);

    for (i = 1; number > 0; i++)
    {
        ar = number % 2;
        number = number / 2;
        reverse = (reverse * 10) + (ar % 10);
        printf("%d", ar);
    }
    // return 0;
}

void Dec_to_Oct()
{
    int number, i, reverse;
    int ar;

    printf("\nEnter the number in Decimal form to convert it into Octal form: ");
    scanf("%d", &number);

    for (i = 1; number > 0; i++)
    {
        ar = number % 8;
        number = number / 8;
        reverse = (reverse * 10) + (ar % 10);
        printf("%d\n", ar);
    }
    // return 0;
}

void Oct_to_Dec()
{
    int i, number, ans = 0, base = 1, rem;

    printf("\nEnter the number in Octal form to convert it into decimal form: ");
    scanf("%d", &number);

    while (number > 0)
    {
        rem = number % 10;
        ans = ans + rem * base;
        number = number / 10;
        base = base * 8;
    }
    printf("\nDecimal form is: %d\n", ans);
    // return 0;
}

void Dec_to_Hex()
{
    int number, i, reverse, ar;
    char hex[50]; // Needed char array

    printf("\nEnter the element in decimal form to convert it into hexadecimal form: ");
    scanf("%d", &number);

    for (i = 0; number > 0; i++) // Array start's from zero
    {
        ar = number % 16;
        hex[i] = ar;

        if (ar < 10)
        {
            hex[i] = ar + 48; // Storing in ASCII code
        }
        else
        {
            hex[i] = ar + 55;
        }
        number = number / 16;
    }

    printf("\nHexadecimal number is : ");

    // Now i is equal to length of array and we need to print array in reverse hence, reverse loop is used

    for (int j = i - 1; j >= 0; j--) //  j ko length -1 ke equal kia aur decrease krte jayenge har baar, i-- se, jb tk zero na ho jaye
                                     //  also, zero index bhi print krna h isiliye j >= 0  kia
    {
        printf("%c", hex[j]);
    }

    // return 0;
}

int Hex_to_Dec()
{

    int i, number, ans = 0, base = 1, rem, len;
    char hex[20], ch;

    printf("\nEnter length of hexadecimal: ");
    scanf("%d", &len);

    printf("\nEnter Hexadecimal number: ");
    i = 0;
    while (i < len)
    {
        scanf(" %c", &ch);
        hex[i] = ch;
        printf("\nChar is: %c", ch);
        i++;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        int val = hex[i];
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            ans += (val - 48) * base;

            // incrementing base by power
            base = base * 16;
        }

        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            ans += (val - 55) * base;

            // incrementing base by power
            base = base * 16;
        }
    }
    printf("\nDecimal of this is: %d\n", ans);
    // while (number > 0)
    // {
    //     rem = number % 10;
    //     ans = ans + rem * base;
    //     number = number / 10;
    //     base = base * 16;
    // }
    // printf("\n Decimal form is: %d\n", ans);
    // return 0;
}

int main()
{
    int ch;
    do
    {
        printf("\n\n**** CONVERSION SYSTEM ****\n");
        printf("Enter 1 to convert Binary to Decimal Form.\n"); // Always try to put \n on end of line
        printf("Enter 2 to convert Decimal to Binary Form.\n");
        printf("Enter 3 to convert Decimal to Octal Form.\n");
        printf("Enter 4 to convert Octal to Decimal Form.\n");
        printf("Enter 5 to convert Decimal to Hexadecimal Form.\n");
        printf("Enter 6 to convert Hexadecimal to Decimal Form.\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Bin_to_Dec();
            break;
        case 2:
            Dec_to_Bin();
            break;
        case 3:
            Dec_to_Oct();
            break;
        case 4:
            Oct_to_Dec();
            break;
        case 5:
            Dec_to_Hex();
            break;
        case 6:
            Hex_to_Dec();
            break;
        default:
            printf("WRONG CHOICE!!!!!");
            break;
        }
    } while (1);
    getch();
}