#include <stdio.h>

int getuser_mainMenu_choice()
{
    int ChoiceValue =0, AnyScanCheck = 0;
    printf("\n\nPlease enter your choice : ");
    for(;;)
    {
        fflush(stdin);
        AnyScanCheck = scanf("%d", &ChoiceValue);

        if(AnyScanCheck == 1)
        {
            if(ChoiceValue>=1 && ChoiceValue <=7)
            {
                break;
            }
            else
            {
                printf("Please enter choice between 0 to 10  : ");
            }
        }
        else
        {
            printf("Please enter valid choice : ");
        }
    }
    return ChoiceValue;
}
void printf_options()
{
    printf("******************** Options ********************\n");
    printf("1. Add two numbers\n");
    printf("2. Sub two numbers\n");
    printf("3. Multi two numbers\n");
    printf("4. Division two numbers\n");
    printf("5. Shift left number\n");
    printf("6. Shift right number\n");
    printf("7. Get bit in number\n");
    printf("8. Set bit in number\n");
    printf("9. Clear bit in number\n");
    printf("10. Toggle bit in number\n");
    printf("0. Exit\n");
}
