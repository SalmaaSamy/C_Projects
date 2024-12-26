#include <stdio.h>
#include <windows.h>

void printf_options();
int getuser_mainMenu_choice();
void add();
void subtract();
void multiply();

int main(void)
{
    system("cls");
    for(;;)
    {
        printf_options();

        switch(getuser_mainMenu_choice())
        {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }

        system("cls");
    }

    return 200;
}


