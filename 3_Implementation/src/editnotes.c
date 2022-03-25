#include "notestaker.h"
void editnotes()

{

    system("cls");

    FILE *fpte ;

    struct notes customer ;

    char time[6],choice,filename[14];

    int num,count=0;

    printf("\n\n\t\t*******************************\n");

    printf("\t\t* WELCOME TO THE EDITING MENU *");

    printf("\n\t\t*******************************\n\n");

    choice=password();

    if(choice!=0)

    {

        return ;

    }

    do

    {

        printf("\n\tENTER THE DATE OF NOTES TO BE EDITED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);

        printf("\n\tENTER TIME:[hh:mm]:");

        gets(time);

        fpte = fopen ( filename, "rb+" ) ;

        if ( fpte == NULL )

        {

            printf( "\nNOTE DOES NOT EXISTS:" ) ;

            printf("\nPRESS ANY KEY TO GO BACK");

            getch();

            return;

        }

        while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

        {

            if(strcmp(customer.time,time)==0)

            {

                printf("\nYOUR OLD NOTE WAS AS:");

                printf("\nTIME: %s",customer.time);

                printf("\nYOUR NAME: %s",customer.name);

                printf("\nPLACE OF THE EVENT: %s",customer.place);

                printf("\nTIME DURATION: %s",customer.duration);

                printf("\nNOTE: %s",customer.note);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n1.TIME.");

                printf("\n2.YOUR NAME.");

                printf("\n3.PLACE OF THE EVENT.");

                printf("\n4.TIME DURATION.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE RECORD.");

                printf("\n7.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\tENTER YOUR CHOICE:");

                    fflush(stdin);

                    scanf("%d",&num);

                    fflush(stdin);

                    switch(num)

                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(customer.time);

                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW NAME:");

                        gets(customer.name);

                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW PLACE OF EVENT:");

                        gets(customer.place);

                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nTIME DURATION:");

                        gets(customer.duration);

                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nNOTE:");

                        gets(customer.note);

                        break;

                    case 6:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(customer.time);

                        printf("\nNEW NAME:");

                        gets(customer.name);

                        printf("\nNEW PLACE OF THE EVENT:");

                        gets(customer.place);

                        printf("\nTIME DURATION:");

                        gets(customer.duration);

                        printf("\nNOTE:");

                        gets(customer.note);

                        break;

                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");

                        getch();

                        return ;

                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                        break;

                    }

                }
                while(num<1||num>8);

                fseek(fpte,-sizeof(customer),SEEK_CUR);

                fwrite(&customer,sizeof(customer),1,fpte);

                fseek(fpte,-sizeof(customer),SEEK_CUR);

                fread(&customer,sizeof(customer),1,fpte);

                choice=5;

                break;

            }

        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW RECORD IS:\n");

            printf("--------------------\n");

            printf("\nTIME: %s",customer.time);

            printf("\nYOUR NAME: %s",customer.name);

            printf("\nPLACE OF THE EVENT: %s",customer.place);

            printf("\nTIME DURATION: %s",customer.duration);

            printf("\nNOTE: %s",customer.note);

            fclose(fpte);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER NOTE(Y/N)");

            scanf("%c",&choice);

            count++;

        }

        else

        {

            printf("\nTHE NOTE DOES NOT EXIST::\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

            scanf("%c",&choice);

        }

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    if(count==1)

        printf("\n%d FILE IS EDITED...\n",count);

    else if(count>1)

        printf("\n%d FILES ARE EDITED..\n",count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");

    getch();

}
