#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
// old code  [old array]
//                       {--  ,--  ,R M1,R M2, N1 , OP , N2 ,VApp,VApp}
static unsigned int oldcode[10]= {0x50,0x60,0xFF,0xFF,0x04,0x01,0x05,0xA5,0XA5};

// new code  [new array]
static unsigned int newcode[10]= {0x50,0x60,0xFF,0xFF,0x04,0x02,0x05,0xFF,0XFF};
/*  carrying the return of BL_main  */
int App_Main(void)
{
    int x,result,i,spaces,j;
    printf("Application is started.\n");
    printf("==============================\n");
    printf("Welcome to Application\n");
    printf("1- Start normal app.\n");
    printf("2- Flash new software.\n");
    printf("3- Exit.\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:

        if(oldcode[5]==1)
        {
            result=oldcode[4]+oldcode[6];
            printf("%d + %d =%d",oldcode[4],oldcode[6],result);
        }
        else if(oldcode[5]==2)
        {
            result=oldcode[4]*oldcode[6];
            printf("%d * %d =%d",oldcode[4],oldcode[6],result);
        }
        break;
    case 2:
        printf("\033[2J\033[1;1H");
        printf("There is a reprogramming request.\n");
        printf("%sStart Flashing...%s\n",YELLOW,RESET);
        printf("Erasing Memory\n");
        int downloadProgress = 0;
        int totalProgress = 100;


        for (downloadProgress = 1; downloadProgress <= totalProgress; downloadProgress++)
        {
            // Calculate the number of equal signs based on the progress
            int numEquals = (int)((double)downloadProgress / totalProgress * 50);

            // Display the progress bar
            printf("\r[");
            for (int i = 0; i < numEquals; i++)
            {
                printf("=");
            }
            printf(">");
            for(j=50-numEquals; j>0; j--)
            {
                printf(" ");
            }
            printf("]%d%%", downloadProgress);
            fflush(stdout); // Flush the output buffer
            // Simulate some delay to mimic a real download process
            Sleep(50); // Adjust the delay as needed
        }

        printf("\n%sErase Memory : Positive Response%s\n",GREEN,RESET);

        // erasing the old code to copy the new one
        for(i=0; i<10; i++)
        {
            oldcode[i]=0;
        }
        printf("Downloading Data...\n");
        downloadProgress = 0;
        totalProgress = 100;


        for (downloadProgress = 1; downloadProgress <= totalProgress; downloadProgress++)
        {
            // Calculate the number of equal signs based on the progress
            int numEquals = (int)((double)downloadProgress / totalProgress * 50);

            // Display the progress bar
            printf("\r[");
            for (int i = 0; i < numEquals; i++)
            {
                printf("=");
            }
            printf(">");
            for(j=50-numEquals; j>0; j--)
            {
                printf(" ");
            }
            printf("]%d%%", downloadProgress);
            fflush(stdout); // Flush the output buffer
            // Simulate some delay to mimic a real download process
            Sleep(50); // Adjust the delay as needed
        }
        printf("\n%sTransferring Data : Positive Response\n",GREEN);
        printf("Check Sum : Positive Response\n");
        printf("Flashing Succeeded..%s\n",RESET);
        // download new code
        for(i=0; i<10; i++)
        {
            oldcode[i]=newcode[i];
        }
        oldcode[7]=0xA5;
        oldcode[8]=0xA5;
        // Pause to see the output
        //system("pause");
        // press any key to continue...
        _getch();
        // delete the cmd screen
        system("cls");
    // stat flashing

    case 3:
        return 0;

    }
}
// bootloader Functions //
int Bl_Main(void)
{
    int flagReProg=0,flagVapp=0,flagStartFalshing=0;
    /*  chech if there is reprogramming request  */
    flagReProg = checkReProgReq();
    if(1==flagReProg)
    {
        /* there is reprogramming request, then start falshing */
        flagStartFalshing=1;
    }
    else
    {
        /* there is not reprogramming request, then check validity of app */
        flagVapp = checkValidApp();
        if(1==flagVapp)
        {
            /*  start the main app  */
            return 1;
        }
        else
        {
            /* the main app is no valid , then start flashing  */
            flagStartFalshing=1;
        }
    }
}
int checkReProgReq(void)
{
    if(oldcode[2]==0XFF&&oldcode[3]==0XFF)
    {
        printf("There is no reprogramming request.\n");
        return 0;
    }
    else if(newcode[2]==0XA5&&newcode[3]==0XA5)
    {
        /*  then start falshing  */
        return 1;
    }
}
int checkValidApp(void)
{
    if(oldcode[7]==0XA5&&oldcode[8]==0XA5)
    {
        printf("%sThe application is vaild%s\n",GREEN,RESET);

        return 1;
    }
    else if(oldcode[2]==0XA5&&oldcode[3]==0XA5)
    {
        /*  then start falshing  */
        return 1;
    }
}

int main()
{
    int runAppFlag=0;
    while(1)
    {
        /* calling BL main function */
        runAppFlag = Bl_Main();
        /*  check the carry of Bl_main to run app or not */
        if(runAppFlag==1)
        {
            /*   reset the falg   */
            runAppFlag=0;
            /*  calling main function  */
            App_Main();
        }
    }

    return 0;
}
