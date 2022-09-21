#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>



/*******************************************
Make a personal diary that allows you to
1.Login User
2. Add record
3. Edit record
4. Delete record
5. password function (to be upgraded later)
6. edit password (future)

REMAINDER: TO WRITE A MORE COMPLEX AND
SECURED PASSWORD PROTECTION
*******************************************/

int password(); //manages password protection task
void editPassword();
void addRecord();
void viewRecord();
void editRecord();
void delRecord();
void login()
{
    char user[10] = "User";
    char pass[10] = "Pass";


        printf("\n ENTER YOUR LOGIN DETAILS\n \n");
        printf(" USERNAME: ");
        gets(user);
        printf("\n PASSWORD: ");
        gets(pass);
        if(strcmp(user, "user")==0 && strcmp(pass, "pass")==0)
        {
            printf("\n Login Successful");
            printf("\n\n\t\tPress any key to continue...");
            getch();
        }

        else
        {
            printf("\n***||USER NOT IDENTIFIED||***\n");
            getch();
            system("cls");
            main();

        }
}

struct record
{
    char time[12];
    char name[30];
    char place[30];
    char note[1000];
};

int main()
{
    printf("\n\n	**********   Welcome To The Personal Diary   **********\n\n");
	printf("\t\t\t        _ _\n");
	printf("\t\t\t   .-. | | |\n");
	printf("\t\t\t   |M|_|A|N\n");
	printf("\t\t\t   |A|a|.|.|<\\\n");
	printf("\t\t\t   |T|r| | | \\\\\n");
	printf("\t\t\t   |H|t|M|Z|  \\\\\n");
	printf("\t\t\t   | |!| | |   \\>\n");
	printf("\t\t\t  \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n\n");
	printf("	              Lets Verify Your Identity		     \n\n\n");
    login();
    fflush(stdin);
    system("cls");
    int choice;
    printf("\n\t-----------------------");
    printf("\n\t: PERSONAL DIARY MENU :");
    printf("\n\t-----------------------\n\n");

printf("\t       _______        \n");
printf("\t      /Once  /,    \n");
printf("\t     /Upon A//     \n");
printf("\t    /Time  //      \n");
printf("\t   /______//      \n");
printf("\t  (______(/      \n\n");

    while(1)
    {
        printf("\n\t:MAIN MENU:");
        printf("\n\t[1]. ADD RECORD");
        printf("\n\t[2]. VIEW RECORD");
        printf("\n\t[3]. EDIT RECORD");
        printf("\n\t[4]. DELETE RECORD");
        printf("\n\t[5]. EDIT PASSWORD");
        printf("\n\t[6]. EXIT");


        printf("\n\n\n\t\tENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            viewRecord();
            break;
        case 3:
            editRecord();
            break;
        case 4:
            delRecord();
            break;
        case 5:
     //       editPassword();
            break;
        case 6:
            system("cls");
            fflush(stdin);
            printf("\n\n  **********   Goodbye To The Personal Diary   **********\n\n");
            printf("              ________\n");
            printf("             / ______ \\\n");
            printf("             || _  _ ||\n");
            printf("             ||| || |||\n");
            printf("             |||_||_|||\n");
            printf("             || _  _o||\n");
            printf("             ||| || |||\n");
            printf("             |||_||_|||      ^~^  ,\n");
            printf("             ||______||     \('Y') )\n");
            printf("            /__________\\    /   \\/\n");
            printf("    ________|__________|__ \(\\|||/) _________\n");
            printf("           /____________\\\n");
            printf("           |____________|\n\n");
            printf("The System Will Be Closing Now\n");
            printf("\n\t\t***||+ Closing diary +||***.....");
            getch();
            exit(0);
        default:
            printf("YOU ENTERED WRONG CHOICE...");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            break;
        }
        system("cls");
    }
    return 0;
}

void addRecord()
{
    system("cls");
 //   system("color 7d");  will Play with terminal color design when I am less lazy, or not
    fflush(stdin);
	printf("\n\n\t--------------\n");
    printf("\t: ADD RECORD :");
    printf("\n\t--------------\n\n") ;
	printf("\t\(\\\n");
	printf("\t\\'\\\n");
	printf("\t \\'\\     __________ \n");
	printf("\t / '|   \()_________)\n");
	printf("\t \\ '/    \\ ~~~~~~~~ \\\n");
	printf("\t   \\       \\ ~~~~~~   \\\n");
	printf("\t   ==).      \\__________\\\n");
	printf("\t \(__)       \()__________)\n\n\n");
	fflush(stdin);
    FILE *fp;
    char opt = 'Y'; //Yes or no option if you want to add another record
    char time[10];
    struct record aR;
    char FileName[15];
    int ch;
    printf("\n\tENTER DATE OF YOUR RECORD[dd-mm-yyyy] : ");
    fflush(stdin);
    gets(FileName);
    fp = fopen(FileName, "ab+");
    if (fp == NULL)
    {
        fp = fopen(FileName, "wb+");
        if (fp == NULL)
        {
            printf("\n!!!SYSTEM ERROR!!!");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return;
        }
    }
    //Function to select option to add another record and also check if the record exists

    while(opt == 'Y' || opt == 'y')
    {
        ch = 0;
        fflush(stdin);
        printf("\n ENTER TIME[hh:mm]:");
        scanf("%s", time);
        rewind(fp);
        while(fgets(&aR,sizeof(aR),fp)!=NULL)
        {
            if(strcmp(aR.time,time) == 0)
            {
                printf("\n\tTHE RECORD ALREADY EXISTS. \n");
              ch = 1;
            }
        }
       if (ch == 0)
        {
            strcpy(aR.time, time);
            printf("\nENTER YOUR NAME:");
            scanf("%s", aR.name);
            fflush(stdin);
            printf("\nENTER NAME OF PLACE: ");
            scanf("%s",aR.place);
            fflush(stdin);
            printf("\n\tNOTE: ");
            scanf("%s", aR.note);
            fflush(stdin);
            fwrite(&aR,sizeof(aR), 1, fp);
            printf("\n\t YOUR RECORD HAS BEEN ADDED SUCCESFULLY. \n");
        }
        printf("\n\t\tDo you want to add another record?(Y/N) ");
        system("cls");
        fflush(stdin);
        opt = getchar();
    }
    fclose(fp);
    printf("\n\t\tPRESS ANY KEY TO EXIT....");
    getch;
}

void viewRecord()
{
    system("cls");
    fflush(stdin);
    printf("\n\t\t\t_________________\n");
    printf("\t\t\t:  VIEWING MENU :");
    printf("\n\t\t\t_________________\n\n");

	printf("                 .--.   _\n");
	printf("             .---|__| .\(\(\\-.\n");
	printf("          .--|===|--|/    , \\\n");
	printf("          |  |===|  |\\      y\n");
	printf("          |  |   |  | `.__,'\n");
	printf("          |  |   |  | /  \\\\\\\n");
	printf("          |  |   |  |/|  | \\`----.\n");
	printf("          |  |   |  ||\\  \\  |___.'_\n");
	printf("         _|  |   |__||,\\  \\-+-._.' )_\n");
	printf("        / |  |===|--|\\  \\  \\      /  \\\n");
	printf("       /  `--^---'--' `--`-'---^-'    \\\n");
	printf("      '================================`\n\n");


    FILE *fview;
    char FileName[14];
    char time[10];
    char choice;
    struct record vR;

//   choice=password();

    if (choice != 0)
    {
        return ;
    }

    do
    {
        printf("ENTER DATE OF RECORD TO BE VIEWED:[dd-mm-yyyy]: ");
        fflush(stdin);
        gets(FileName);
        fview = fopen(FileName, "r");
        if (fview == NULL)
        {
            puts("\nTHE RECORD DOES NOT EXIST");
            printf("\nPRESS ANY KEY TO EXIT...");
            getch();
            return;
        }
        system("cls");
        printf("\n\tHERE IS YOUR RECORD:\n");
        printf("\nTHE RECORD OF %s is: \n", FileName);
        while(fgets(&vR, sizeof(vR), fview) !=NULL)
        {
            printf("\nTIME\t\t: %s", vR.time);
            printf("\nNAME\t\t: %s", vR.name);
            printf("\nPLACE\t\t: %s", vR.place);
            printf("\nNOTE\t\t: %s", vR.note);
            break;
        }
        fflush(stdin);
        printf("\n\nWOULD YOU LIKE TO VIEW MORE RECORDS?...(Y/N): ");
        scanf("%c", &choice);
    }
    while (choice == 'Y' || choice == 'y');
        fclose(fview);
        return;
}

void editRecord()
{
    system("cls");
    FILE *fEdit;
    struct record eR;
    char time[6];
    char FileName[15];
    char choice;
    int num= 0;
    int count = 0;
    printf("\n\n\t\t:::::::::::::::::::::::::::::::\n");
    printf("\t\t\t: EDIT RECORD :");
    printf("\n\t\t:::::::::::::::::::::::::::::::\n\n");
printf("         __                                             \n");
printf("        (`/\\                                        \n");
printf("        `=\\/\\ ___...--~~~~~-._    _.-~~~~~--...__      \n");
printf("         `=\\/\\                \\ /               \\\\     \n");
printf("          `=\\/      EDIT       V    RECORDS      \\\\    \n");
printf("           //_\\___--~~~~~~-._  |  _.-~~~~~~--...__\\\\     \n");
printf("          //  ) (..----~~~~._\\ | /_.~~~~----.....__\\\\     \n");
printf("         ===( INK )==========\\\\|//====================     \n");
printf("       __ejm\___/________dwb`---`__________________________  \n\n\n");
   // choice = password();
   if (choice != 0)
   {
       return ;
   }
   do
   {
       printf("\n\tENTER DATE OF RECORD TO BE EDITED:[dd-mm-yyyy]: ");
       fflush(stdin);
       gets(FileName);
       printf("\nENTER THE TIME[hh:mm]: ");
       fflush(stdin);
       gets(time);
       fEdit = fopen(FileName, "r++");
       if(fEdit == NULL)
       {
           printf("THE RECORD DOES NOT EXIST");
           printf("\nPRESS ANY KEY TO GO BACK");
           getch();
           return ;
       }
       while(fgets(&eR,sizeof(eR), fEdit) == 1)
       {
           if(strcmp(eR.time,time)==0)
           {
                printf("\nYOUR OLD RECORD WAS:");
                printf("\nTIME: %s",eR.time);
                printf("\nNAME: %s",eR.name);
                printf("\nPLACE: %s",eR.place);
                printf("\nNOTE: %s",eR.note);
                printf("\n1.EDIT THE RECORD: ");
                printf("\n2.GO BACK TO MAIN MENU.");
                do
                {
                    printf("\n\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d", &num);
                    fflush(stdin);
                    printf("\nENTER THE NEW DATA:");
                    switch(num)
                    {
                    case 1:
                        printf("\nNEW TIME[hh:mm]: ");
                        gets(eR.time);
                        printf("\nNEW NAME:");
                        gets(eR.name);
                        printf("\nNEW PLACE:");
                        gets(eR.place);
                        printf("\nNEW NOTE:");
                        gets(eR.note);
                        printf("THE RECORD IS EDITED");
                        break;
                    case 2:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        getch();
                        return ;
                        break;
                    default:
                        printf("\nWRONG INPUT....TRY AGAIN\n");
                        break;
                    }
                }
                while(num<1||num>8);
                fseek(fEdit,sizeof(eR),SEEK_CUR);
                fwrite(&eR,sizeof(eR),1,fEdit);
                fseek(fEdit,sizeof(eR),SEEK_CUR);
                fgets(&eR,sizeof(eR), fEdit);
                choice=5;
                break;
           }
       }
       if (choice == 1)
       {
           system("cls");
           printf("\n\nEDITING COMPLETED...\n");
           printf("---------------------------\n");
           printf("THE NEW RECORD IS : \n");
           printf("---------------------------\n");
           printf("\nTIME: %s", eR.time);
           printf("\nNAME: %s", eR.name);
           printf("\nPLACE: %s", eR.place);
           printf("\n\tNOTE: %s", eR.note);
           fclose(fEdit);
           if(count == 1)
           {
               printf("\n %d FILE IS EDITED...\n", count);
           }
           else if(count > 1)
           {
               printf("\n %d FILES ARE EDITED..\n", count);
           }
               else
                printf("\n NO FILES EDITED");
                printf("\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD?(Y/N)");
               scanf("%eR", &choice);
               count++;
        }
        else
        {
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            scanf("%c",&choice);
        }
    }
    while(choice == 'Y'|| choice =='y');
    fclose(fEdit);
      if(count==1)
        printf("\n%d FILE IS EDITED...\n",count);
    else if(count>1)
        printf("\n%d FILE ARE EDITED..\n",count);
    else
        printf("\nNO FILES EDITED...\n");
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();
   }

void delRecord ()
{
       system("cls");
       FILE *fDel, *fp;
       struct record dR;
       char FileName[15];
       char opt = 'Y';
       char time[12];
       int choice, check;

       printf("\n\n\t        -----------------\n");
       printf("  \t\t: DELETE RECORD :");
       printf("\n\t        -----------------\n\n");

printf("         __...--~~~~~-._   _.-~~~~~--...__   \n");
printf("       //   DELETE      `V'               \\ \n");
printf("      //                 |    RECORDS      \\ \n");
printf("     //__...--~~~~~~-._  |  _.-~~~~~~--...__\\ \n");
printf("    //__.....----~~~~._\ | /_.~~~~----.....__\\ \n");
printf("   ====================\\|//==================== \n");
printf("                   dwb `---`                      \n");
//       check=password();
       if (check == 1)
       {
           return;
       }
       while (opt == 'Y' || opt == 'y')
       {
           printf("\n\n\tWHAT WOULD YOU LIKE TO DO?");
           printf("\n\n\t[1]. DELETE WHOLE RECORD");
           printf("\n\n\t[2]. DELETE A PARTICULAR RECORD");

           do
           {
               printf("\n\n\tENTER YOU CHOICE: ");
               scanf("%d", &choice);
               switch(choice)
               {
               case 1:
                printf("\n\tENTER THE DATE OF THE RECORD TO BE DELETED[dd-mm-yyyy]:");
                fflush(stdin);
                gets(FileName);

                fDel= fopen(FileName, "w++");
                if (fDel == NULL)
                {
                    printf("\nTHE RECORD DOES NOT EXIST");
                    printf("\n\tPRESS ANY KEY TO EXIT...");
                    getch();
                    return;
                }
                fclose(fDel);
                remove(FileName);
                printf("\nRECORD DELETED SUCCESFULLY!");
                break;

               case 2:
                printf("\n\tENTER THE DATE OF THE RECORD TO BE DELETED[dd-mm-yyyy]:");
                fflush(stdin);
                gets(FileName);
                fDel = fopen(FileName, "r");
                if (fDel==NULL)
                {
                    printf("\nTHE RECORD DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK...");
                    getch();
                    return;
                }
                fp=fopen("temp", "w");
                if(fp==NULL)
                {
                    printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK...");
                    getch();
                    return;
                }
                printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");
                fflush(stdin);
                gets(time);
                while(fgets(&dR, sizeof(dR), fDel) != NULL)
                {
                    if (strcmp(dR.time,time)!= 0)
                        fwrite(&dR,sizeof(dR),1,fp);
                }
                fclose(fDel);
                fclose(fp);
                remove(FileName);
                remove("temp");
                printf("\nRECORD DELETED SUCCESFULLY!");
                break;
               default:
                printf("\nWRONG INPUT");
                break;
               }
           }
           while(choice<1||choice>2);
           printf("\n\tWOULD YOU LIKE TO DELETE ANOTHER RECORD. (Y/N):");
           fflush(stdin);
           scanf("%c",&opt);
       }
       printf("\n\n\tPRESS ANY KEY TO EXIT...");
       getch();
   }



