/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bankmanagementsystem.c
 * Author: Sagar
 *
 * Created on May 24, 2018, 9:11 PM
 *
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "windows.h"

typedef struct bank
{      
       long int accno;
       char name[50];
       char addr[100];
       long int bal;
 };

 struct bank b[100] ;   // Global Variable
 int total = 0 ;        //Global Variable
 int color;             //Global Variable

void TitleScreen()
  {
  system("cls");

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  color = 7;
  SetConsoleTextAttribute(hConsole, color);

  printf("\n\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
  printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
  printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
  printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
  printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");

   color = 9;
   SetConsoleTextAttribute(hConsole, color);
   printf("\n\n\n \t\t\t    %s","STATE BANK OF INDIA");

   color = 15;
   SetConsoleTextAttribute(hConsole, color);
   printf("\n\n\n\n\n\t\t\t        \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
   printf("\n \t\t\t        \xba WELCOME \xba");
   printf("\n \t\t\t        \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

   color = 15;
   SetConsoleTextAttribute(hConsole, color);
   printf("\n\n\n\n\n\n\n \tPROGRAMMED BY:");
   color = 7;
   SetConsoleTextAttribute(hConsole, color); 
   printf("   Sagar");
   color = 15;
   SetConsoleTextAttribute(hConsole, color);
   printf("\n\n \tCOPYRIGHTS   :");
   color = 7;
   SetConsoleTextAttribute(hConsole, color);
   printf("   CCL (Central Coalfields Limited) , Ranchi");

   printf("\n\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
   printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
   printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
   printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
   printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");

   color = 15;
   SetConsoleTextAttribute(hConsole, color);
   getchar();

}

void creatacc()
{
     char accno[] = {"This is the account no\02628031"};
     char accbal[] = {"This is the account balance\031"};
     system("cls");
     FILE *op;
     op=fopen("database","wb+");
     
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     color = 9;
     SetConsoleTextAttribute(hConsole, color);

     printf("\n\n\n\n\t   ---------------|| CREATING NEW ACCOUNT  ||---------------");

     color = 15;
     SetConsoleTextAttribute(hConsole, color);

     printf("\n\n\n\t Enter your details");
     printf("\n\n\n\t Account no:  ");

     color = 7;
     SetConsoleTextAttribute(hConsole, color);

     fgets(accno , 31 , stdin);
     b[total].accno = atol(&accno);  

     color = 15;
     SetConsoleTextAttribute(hConsole, color);

     printf("\n\n\t Name:  ");

     color = 7;
     SetConsoleTextAttribute(hConsole, color);
     fgets(b[total].name , 50 , stdin);
     color = 15;
     SetConsoleTextAttribute(hConsole, color);
     printf("\n\n\t Address:  ");

     color = 7;
     SetConsoleTextAttribute(hConsole, color);
     fgets(b[total].addr , 100 , stdin );
     color = 15;
     SetConsoleTextAttribute(hConsole, color);
     printf("\n\n\t Balance:  ");
     color = 7;
     SetConsoleTextAttribute(hConsole, color);
     fgets(accbal , 31 , stdin);  
     b[total].bal = atol(&accbal);

     total++;
     fwrite(&b,sizeof(struct bank),1,op);
	
     system("cls");
	
     color = 9;
     SetConsoleTextAttribute(hConsole, color);

     printf("\n\n\n\n\t   ---------------|| CREATING NEW ACCOUNT  ||---------------");
	
     color = 287;
     SetConsoleTextAttribute(hConsole, color);
     printf("\n\n\n\n\n\t\t\t       Account Created");
	
     color = 15;
     SetConsoleTextAttribute(hConsole, color);
	
     fclose(op);
     getchar();
     }

void deleteacc()
     {
     char accno[] = {"This is the account no to delete34"};        
	 int acc,i,flag=0;
	 system("cls");
         FILE *ip;
         ip=fopen("database","rb");
	 printf("\n\n");
	
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     
     color = 9;
     SetConsoleTextAttribute(hConsole, color);
	
	 printf("\n\n\t    ---------------|| CLOSING AN ACCOUNT ||---------------");
	
     color = 15;
     SetConsoleTextAttribute(hConsole, color);
	 printf("\n\n\n\t Enter the account no.:  ");
	 color = 7;
     SetConsoleTextAttribute(hConsole, color);
     fgets( accno , 34 , stdin);
     acc = atol(&accno);

     fread(&b,sizeof(struct bank),total,ip);
     for(i=0;i<total;i++)
	 {
	     if(b[i].accno==acc)
	     {
		   flag=1;
		   break;
	     }
	 }
	 if (flag==1)
	 {
             FILE *op;
             op=fopen("database","wb");
            for(; i<=total; i++)
	    {
	      b[i].accno=b[i+1].accno;
	      b[i].bal=b[i+1].bal;
	      strcpy(b[i].name,b[i+1].name);
	      strcpy(b[i].addr,b[i+1].addr);
	    }
	  total--;
	
	  color = 287;
      SetConsoleTextAttribute(hConsole, color);
	  printf("\n\n\n\t\t\t Account CLOSED");
          fwrite(&b,sizeof(struct bank),total,op);
          fclose(op);
          getchar();
     }
      else
      {
      color = 287;
      SetConsoleTextAttribute(hConsole, color);
	  printf("\n\n\n\t Account Not Found, Please Verify Account Number And Try Again");
          getchar();
      }
	  color = 15;
      SetConsoleTextAttribute(hConsole, color);
      fclose(ip);
    }

void viewacc()
     {
     char accno[] = {"This is the account no to View32"};
     int acc,i,flag=0;
     system("cls");
     FILE *ip;
     ip=fopen("database","rb");
     printf("\n\n");

     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     color = 9;
     SetConsoleTextAttribute(hConsole, color);

     printf("\n\n\t    ---------------|| Account information ||---------------");

     color = 15;
     SetConsoleTextAttribute(hConsole, color);
     printf("\n\n\n\t Enter the account no.:  ");

     color = 7;
     SetConsoleTextAttribute(hConsole, color);

     fgets( accno , 32 , stdin); 
     acc = atol(&accno);

     color = 15;
     SetConsoleTextAttribute(hConsole, color);
     fread(&b,sizeof(struct bank),total,ip);
     for(i=0; i<total; i++)
      {
		if(b[i].accno==acc )
		{
		     flag=1;
		     break;
		}
	    }
	    if(flag==1)
	    {
	    printf("\n\n\n\t   Account no : ");
	    color = 7;
        SetConsoleTextAttribute(hConsole, color);
        printf("%ld", b[i].accno);
        color = 15;
        SetConsoleTextAttribute(hConsole, color);
	    printf("\n\n\n\t   Name       : ");
	    color = 7;
        SetConsoleTextAttribute(hConsole, color);
	    printf("%s", b[i].name);
	    color = 15;
        SetConsoleTextAttribute(hConsole, color);
	    printf("\n\n\t   Address    : ");
	    color = 7;
        SetConsoleTextAttribute(hConsole, color);
        printf("%s", b[i].addr);
        color = 15;
        SetConsoleTextAttribute(hConsole, color);
	    printf("\n\n\t   Balance    : ");
	    color = 7;
        SetConsoleTextAttribute(hConsole, color);
	    printf("%ld",b[i].bal);  
            getchar();
        }
        else
            {
            color = 287;
            SetConsoleTextAttribute(hConsole, color);
            printf("\n\n\n\t Account Not Found, Please Verify Account Number And Try Again");
            color = 15;
            SetConsoleTextAttribute(hConsole, color);
            getchar();
            }
     fclose(ip);
    }


void withdraw()
   {
     char accno[] = {"This is the account no to withdraw36"};
     char amtwd[] = {"Amount to be Withdrawn is dis much36"};
     long int acc,amt;
     int i,flag=0;
     system("cls");
     FILE *ip;
     ip=fopen("database","rb");
     printf("\n\n");

     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

     color = 9;
     SetConsoleTextAttribute(hConsole, color);

     printf("\n\n\t   ---------------|| WITHDRAW MONEY ||---------------" );

     color = 15;
     SetConsoleTextAttribute(hConsole, color);
     printf("\n\n\n\t Enter the Account No : ");
     color = 7;
     SetConsoleTextAttribute(hConsole, color);
     fgets( accno , 36 , stdin);
     acc = atol(&accno);
     fread(&b,sizeof(struct bank),total,ip);
     for(i=0; i<total; i++)
     {
       if(b[i].accno==acc )
       {
	    flag= 1;
	    break ;
	    }
     }
   if(flag==1)
   {
    color = 15;
    SetConsoleTextAttribute(hConsole, color);
    printf("\n\n\t Enter the Amount of Money to Withdraw : ");
    color = 7;
    SetConsoleTextAttribute(hConsole, color);
    fgets( amtwd , 36 , stdin);
    amt = atol(&amtwd);
	
	 if(amt>b[i].bal)
	 {
      color = 287;
      SetConsoleTextAttribute(hConsole, color);
      printf("\n\n\t\t Not Enough Money");
      color = 15;
      SetConsoleTextAttribute(hConsole, color);
      getchar();
      }
      else
          {
             FILE *op;
             op=fopen("database","wb");
	      b[i].bal-=amt;
	      system("cls");
	
	      color = 9;
          SetConsoleTextAttribute(hConsole, color);
	      printf("\n\n\n\n\t   ---------------|| WITHDRAW MONEY ||---------------" );
	      color = 287;
          SetConsoleTextAttribute(hConsole, color);
	      printf("\n\n\n\n\n\t\t Withdraw Successful , Balance Updated");
	      color = 15;
          SetConsoleTextAttribute(hConsole, color);

	    printf("\n\n\n\t\t  Available Balance    : ");
	    color = 7;
        SetConsoleTextAttribute(hConsole, color);
	    printf("%ld",b[i].bal);
            fwrite(&b,sizeof(struct bank),total,op);
            fclose(op);
            getchar();
	      }
      }
	 else
	      {
           color = 287;
           SetConsoleTextAttribute(hConsole, color);
           printf("\n\n\n\t Account Not Found, Please Verify Account Number And Try Again");
           color = 15;
           SetConsoleTextAttribute(hConsole, color);
           getchar();
                              }
     fclose(ip);
  }
	
	
void deposit()
	 {
      char accno[] = {"This is the account no to deposit35"};
      char amtdp[] = {"Amount to be deposit is this much35"};
      long int acc,amt;
      int i, flag=0;
      system("cls");
      FILE *ip;
      ip=fopen("database","rb");
	
       HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

       color = 9;
       SetConsoleTextAttribute(hConsole, color);

	   printf("\n\n\n\n\t       ---------------|| DEPOSIT MONEY ||---------------");
	
       color = 15;
       SetConsoleTextAttribute(hConsole, color);
       printf("\n\n\n\t Enter the Account No : ");
	
       color = 7;
       SetConsoleTextAttribute(hConsole, color);
       fgets( accno , 35 , stdin);
       acc = atol(&accno);
	
       color = 15;
       SetConsoleTextAttribute(hConsole, color);
       fread(&b,sizeof(b),1,ip);
       for(i=0; i<total; i++)
       {
	    if (b[i].accno==acc)
	       {
		   flag=1;
		   break;
		   }
      }
	  if(flag==1)
	  {
              FILE *op;
              op=fopen("database","wb");
	  printf("\n\n\t Enter the Amount of Money to Deposit : ");
      color = 7;
      SetConsoleTextAttribute(hConsole, color);

      fgets( amtdp , 35 , stdin);
	  amt = atol(&amtdp);
	  b[i].bal+=amt;

           system("cls");
           color = 9;
           SetConsoleTextAttribute(hConsole, color);
	       printf("\n\n\n\n\t       ---------------|| DEPOSIT MONEY ||---------------" );
	       color = 287;
           SetConsoleTextAttribute(hConsole, color);
	       printf("\n\n\n\n\n\t\t Cash Deposit Successful , Balance Updated");
	       color = 15;
           SetConsoleTextAttribute(hConsole, color);

      printf("\n\n\n\t\t  Available Balance    : ");
      color = 7;
      SetConsoleTextAttribute(hConsole, color);
      printf("%ld",b[i].bal);
      fwrite(&b,sizeof(struct bank),total,op);
      fclose(op);
      getchar();
    }
    else
        {
         color = 287;
         SetConsoleTextAttribute(hConsole, color);
         printf("\n\n\n\t Account Not Found, Please Verify Account Number And Try Again");
         color = 15;
         SetConsoleTextAttribute(hConsole, color);
         getchar();
      }
       fclose(ip);
 }


void logout()
     {    
      char input[] = {"This is the input for exiting the program43"};
      int tester1,tester2;

      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      color = 287;
      SetConsoleTextAttribute(hConsole, color);

      printf("\n\n\t Logging Out\n");
		
      color = 15;
      SetConsoleTextAttribute(hConsole, color);
      printf("\n\t Confirm , Yes or Press Any Key to Continue : ");

      color = 7;
      SetConsoleTextAttribute(hConsole, color);

      fgets( input , 43 , stdin);
      tester1 = strncmp(input,"y",1);
      tester2 = strncmp(input,"Y",1);

      if(tester1==0||tester2==0) 
       {
        exit(0);
        }               
     }


void MainMenu()
	{
	    char ch;
	    int *ch1;
	    int val;
	    system("cls");
           HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

           color = 9;
           SetConsoleTextAttribute(hConsole, color);

	       printf("\n\n\t     ----------------------|| M E N U ||----------------------");
           color = 15;
           SetConsoleTextAttribute(hConsole, color);

	     printf("\n\n\n\t1> Open NEW Account\n\n\t");
	     printf("2> Close Existing Account\n\n\t");
	     printf("3> View Account Information\n\n\t");
	     printf("4> Withdraw Money\n\n\t");
	     printf("5> Deposit Money\n\n\t");
	     printf("6> Log Out \n\n\t");
	     printf("Enter Your Choice :  ");
	
	     color = 7;
         SetConsoleTextAttribute(hConsole, color);
	
	     fgets(&ch , 50 , stdin);
	     ch1 = (int*)malloc(sizeof(ch));
	     val = atoi(&ch);
	     ch1 = &val;
	
	     switch(*ch1)
	     {
                   case 1:
                        creatacc();
                        MainMenu();
                        break;
                   case 2:
                        deleteacc();
                        MainMenu();
                        break;
                   case 3:
                        viewacc();
                        MainMenu();
                        break;
                   case 4:
                        withdraw();
                        MainMenu();
                        break;
                   case 5:
                        deposit();
                        MainMenu();
                        break;
                   case 6:
                        logout();
                        MainMenu();
                        break;
                   default:
                       {    color = 287;
                            SetConsoleTextAttribute(hConsole, color);
                            printf("\n\n\t Enter A Valid Choice\n");
                            color = 7;
                            SetConsoleTextAttribute(hConsole, color);
                            getchar();
                            MainMenu();
                        break;
                       }                        
	  }
   }



int main()
   {
       int i,j,k;
       system("cls");

       TitleScreen();
       for(i=0; i<50; i++)
       {
         b[i].accno=0;
	     b[i].bal=0;
	     b[50+i].accno=0;
	     b[50+i].bal=0;
	
        for(j=0; j<50 ; j++)
         {
          b[i].name[j] ='\0';
          b[50+i].name[j] ='\0';

            for(k=0; k<100 ; k++)
            {
	          b[i].addr[k] ='\0';
	          b[50+i].addr[k] ='\0';
            }
          }
        }
     total=0;
     MainMenu();

 return 0;
 }


