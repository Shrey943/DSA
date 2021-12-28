// date : 23-07-2021
// project name : rock paper and scissors game
// author : Priyanshi Agrawal
// co-author : Atharv Vani
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char name[20];        //global var for name
int sp1 = 0, sp2 = 0; // global score var

void displayTurn(int turn) //print name of active player
{
    if (turn == 1)
    {
        printf("%s'S TURN :\n", name); // user turn
    }
    else if (turn == 2)
    {
        printf("COMPUTER'S TURN :\n"); //computer turn
    }
}

int randomNumber() // creating random numbers [0/1/2]
{
    srand(time(NULL));
    return rand() % 2;
}

void checkCondition(char p1, char p2) //cheking conditions of game
{
    if ((p1 == 'r' && p2 == 'r') || (p1 == 'p' && p2 == 'p') || (p1 == 's' && p2 == 's')) //condition for TIE
    {
        printf("RESULT : tie\n");
    }

    else if ((p1 == 'r' && p2 == 's') || (p1 == 'p' && p2 == 'r') || (p1 == 's' && p2 == 'p')) //condition for PLAYER1  to win
    {
        printf("%s got this one\n", name);
        sp1++;
    }

    else //PLAYER2 wins
    {
        printf("COMPUTER got this one\n");
        sp2++;
    }
}
void displayFinalResult() //print winner of game
{
    if (sp1 > sp2) // user is winner
        printf("\n%s is WINNER %c...\n", name, 1);

    else if (sp2 > sp1) // computer is winner
    {
        printf("\nCOMPUTER is WINNER %c...\n", 1);
        printf("%s better luck next time %c...\n", name, 3);
    }

    else // tie match
        printf("\nIt was a TIE match %c...", 1);
}

void main()
{
    // adding general information
    printf("\n*****************ROCK.PAPER.SCISSORS.****************\n");
    printf("Game Rules : \n");
    printf("You have to select following code :\n0 for Rock\n1 for Paper\n2 for Scissors\n");

    // taking player name input
    printf("Please enter PLAYER1 Name : ");
    gets(name);
    strupr(name); // converting name into uppercase

    // game starts
    int p1, p2, i = 0;
    char code[3] ={'r','p','s'};
    while (i < 3)
    {
        printf("\n");
        displayTurn(1); //displaying name for turn of player1 (user)
    up:
        printf("Enter code [0-rock/1-paper/2-scissors] : ");
        scanf("%d", &p1);
        printf("you selected : %c\n",code[p1]);
        if (p1 > 2 || p1 < 0)
        {
            printf("invalid code selection ...\n");
            goto up;
        }

        displayTurn(2); //displaying name for turn of player2 (computer)
        p2 = randomNumber();
        printf("%d\n", p2);     //print computer's selected code
        printf("computer selected: %c\n",code[p2]);
        checkCondition(code[p1], code[p2]); //checking conditions
        printf("-------------------------------------------------------------\n");
        i++;
    }
    printf("\n***************************SCORE*******************************\n");
    printf("%s : %d\n", name, sp1);
    printf("COMPUTER : %d\n", sp2);
    displayFinalResult();
    printf("\n**************************THANK YOU*****************************\n");
}