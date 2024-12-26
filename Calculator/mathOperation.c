#include <stdio.h>
#include <windows.h>
void add()
{
    int FirstNumber =0,SecondNumber =0;
    int checkFirstNumber =0, checkSecondNumber =0;
    system("cls");
    char message = 0;
    for(;;)
    {
        system("cls");
        printf("**** Application [SUM] ****\n\n");
        printf("Enter First Number : ");
        fflush(stdin);
        checkFirstNumber= scanf("%d", &FirstNumber);
        if (checkFirstNumber !=1 )
        {
            add();
            break;
        }
        else
        {
            printf("Enter Second Number : ");
            checkSecondNumber= scanf("%d", &SecondNumber);
            if ( checkSecondNumber !=1 )
            {
                add();
                break;
            }
            else
            {
                printf("Result = %d", FirstNumber+SecondNumber);
                printf("\n\nEnter any letter to continue : ");
                printf("\n\nEnter B to back : ");
                fflush(stdin);
                scanf("%c", &message);
                if(message == 'B' || message == 'b')
                {
                    break;
                }
                else
                {
                    system("cls");
                }
            }
        }
    }
}
void subtract()
{

    int FirstNumber =0,SecondNumber =0;
    int checkFirstNumber =0, checkSecondNumber =0;
    system("cls");
    char message = 0;
    for(;;)
    {
        system("cls");
        printf("**** Application [SUB] ****\n\n");
        printf("Enter First Number : ");
        fflush(stdin);
        checkFirstNumber= scanf("%d", &FirstNumber);
        if (checkFirstNumber !=1 )
        {
            subtract();
            break;
        }
        else
        {
            printf("Enter Second Number : ");
            checkSecondNumber= scanf("%d", &SecondNumber);
            if ( checkSecondNumber !=1 )
            {
                subtract();
                break;
            }
            else
            {
                printf("Result = %d", FirstNumber - SecondNumber);
                printf("\n\nEnter any letter to continue : ");
                printf("\n\nEnter B to back : ");
                fflush(stdin);
                scanf("%c", &message);
                if(message == 'B' || message == 'b')
                {
                    break;
                }
                else
                {
                    system("cls");
                }
            }
        }
    }
}

void multiply()
{

    int FirstNumber =0,SecondNumber =0;
    int checkFirstNumber =0, checkSecondNumber =0;
    system("cls");
    char message = 0;
    for(;;)
    {
        system("cls");
        printf("**** Application [MUL] ****\n\n");
        printf("Enter First Number : ");
        fflush(stdin);
        checkFirstNumber= scanf("%d", &FirstNumber);
        if (checkFirstNumber !=1 )
        {
             multiply();
            break;
        }
        else
        {
            printf("Enter Second Number : ");
            checkSecondNumber= scanf("%d", &SecondNumber);
            if ( checkSecondNumber !=1 )
            {
                multiply();
                break;
            }
            else
            {
                printf("Result = %d", FirstNumber * SecondNumber);
                printf("\n\nEnter any letter to continue : ");
                printf("\n\nEnter B to back : ");
                fflush(stdin);
                scanf("%c", &message);
                if(message == 'B' || message == 'b')
                {
                    break;
                }
                else
                {
                    system("cls");
                }
            }
        }
    }
}
