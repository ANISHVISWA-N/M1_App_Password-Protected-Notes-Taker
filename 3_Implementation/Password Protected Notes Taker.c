#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include "notestaker.h"

#include "addnotes.c"

#include "editnotes.c"

#include "viewnotes.c"

#include "deletenotes.c"

int password();

void addnotes();

void viewnotes();

void editnotes();

void editnotes();

void deletenotes();
int main()

{

    int ch;

    printf("\n\n\t***********************************\n");

    printf("\t*PASSWORD PROTECTED NOTES*\n");

    printf("\t***********************************");

    while(1)

    {

        printf("\n\n\t\tMAIN MENU:");

        printf("\n\n\tADD NOTES\t[1]");

        printf("\n\tVIEW NOTES\t[2]");

        printf("\n\tEDIT NOTES\t[3]");

        printf("\n\tDELETE NOTES\t[4]");

        printf("\n\tEDIT PASSWORD\t[5]");

        printf("\n\tEXIT\t\t[6]");

        printf("\n\n\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:

            addnotes();

            break;

        case 2:

            viewnotes();

            break;

        case 3:

            editnotes();

            break;

        case 4:

            deletenotes();

            break;

        case 5:

            editpassword();

            break;

        case 6:

            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");
            printf("\n\n\t\tHAVE A NICE DAY");

            getch();

            exit(0);

        default:

            printf("\nYOU ENTERED WRONG CHOICE..");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            getch();

            break;

        }

        system("cls");

    }

    return 0;

}
int password()

{

    char pass[15]= {0},check[15]= {0},ch;

    FILE *fpp;

    int i=0,j;

    printf("::FOR SECURITY PURPOSE::");

    printf("::ONLY THREE TRIALS ARE ALLOWED::");

    for(j=0; j<3; j++)

    {

        i=0;

        printf("\n\n\tENTER THE PASSWORD:");

        pass[0]=getch();

        while(pass[i]!='\r')

        {

            if(pass[i]=='\b')

            {

                i--;

                printf("\b");

                printf(" ");

                printf("\b");

                pass[i]=getch();

            }

            else

            {

                printf("*");

                i++;

                pass[i]=getch();

            }

        }

        pass[i]='\0';

        fpp=fopen("SE","r");

        if (fpp==NULL)

        {

            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");

            getch();

            return 1;

        }

        else

            i=0;

        while(1)

        {

            ch=fgetc(fpp);

            if(ch==EOF)

            {

                check[i]='\0';

                break;

            }

            check[i]=ch-5;

            i++;

        }

        if(strcmp(pass,check)==0)

        {

            printf("\n\n\tACCESS GRANTED...\n");

            return 0;

        }

        else

        {

            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");

        }

    }

    printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");

    getch();

    return 1;

}

void editpassword()

{

    system("cls");

    printf("\n");

    char pass[15]= {0},confirm[15]= {0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("SE","rb");

    if(fp==NULL)

    {

        fp=fopen("SE","wb");

        if(fp==NULL)

        {

            printf("SYSTEM ERROR...");

            getch();

            return ;

        }

        fclose(fp);

        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");

        getch();

    }

    fclose(fp);

    check=password();

    if(check==1)

    {

        return ;

    }

    do

    {

        if(check==0)

        {

            i=0;

            choice=0;

            printf("\n\n\tENTER THE NEW PASSWORD:");

            fflush(stdin);

            pass[0]=getch();

            while(pass[i]!='\r')

            {

                if(pass[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    pass[i]=getch();

                }

                else

                {

                    printf("*");

                    i++;

                    pass[i]=getch();

                }

            }

            pass[i]='\0';

            i=0;

            printf("\n\tCONFIRM PASSWORD:");

            confirm[0]=getch();

            while(confirm[i]!='\r')

            {

                if(confirm[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    confirm[i]=getch();

                }

                else

                {

                    printf("*");

                    i++;

                    confirm[i]=getch();

                }

            }

            confirm[i]='\0';

            if(strcmp(pass,confirm)==0)

            {

                fp=fopen("SE","wb");

                if(fp==NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");

                    getch();

                    return ;

                }

                i=0;

                while(pass[i]!='\0')

                {

                    ch=pass[i];

                    putc(ch+5,fp);

                    i++;

                }

                putc(EOF,fp);

                fclose(fp);

            }

            else

            {

                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");

                choice=1;

            }

        }

    }
    while(choice==1);

    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");

    getch();

}
