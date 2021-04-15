#include "Functionalities.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//======================= VIEW PURCHASE REPORT ===========================
void pur_rpt()
{
  char ch;
  int j;
  system("cls");
  t();
  box();
	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   gotoxy(20,50);
	   printf("Press Enter to go to REPORT MENU ...........");
	   lbox();
	   //textcolor(GREEN);
	   gotoxy(30,8);
	   printf("Purchase Report");
	   //textcolor(WHITE);
	   gotoxy(7,10);
	   printf("ID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
	   gotoxy(7,12);
	   printf("===================================================================");
	   j=14;
	   while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {
		gotoxy(6,j);
		printf("%s",p_r.medi_id);
		gotoxy(11,j);
		printf("%s",p_r.medir_name);
		gotoxy(28,j);
		printf("%s",p_r.supp_name);
		gotoxy(44,j);
		printf("%d",p_r.qty);
		gotoxy(50,j);
		printf("%.2f",p_r.rate);
		gotoxy(57,j);
		printf("%.2f",p_r.total);
		gotoxy(65,j);
		printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
		j+=2;
	   }
	   getche();
}
//========================= report of profit ===========================
void profit_rpt()
{
  char ch;
  int j;
  system("cls");
  t();
  box();
	   ptrpr_r=fopen("profitRpt.dat","r");
	   if(ptrpr_r==NULL)
	   {
		printf("\n\t Can not open File! ");
	       //	exit(0);
	   }
	   gotoxy(20,50);
	   printf("Press Enter to go to REPORT MENU ...........");
	   lbox();
	   //textcolor(GREEN);
	   gotoxy(30,8);
	   printf("Profit Report");
	   //textcolor(WHITE);
	   gotoxy(7,10);
	   printf("ID. Medicine Name.   Date        Qty.  Unit Price  Sale Price. Profit. ");
	   gotoxy(7,12);
	   printf("===================================================================");
	   j=14;
	   while(fscanf(ptrpr_r,"%s %s %d %d %d %d %f %f %f \n",pr_r.medi_id,pr_r.medir_name,&pr_r.sDay,&pr_r.sMonth,&pr_r.sYear,&pr_r.qty,&pr_r.unit,&pr_r.rate,&pr_r.profit)!=EOF)
	   {
		gotoxy(6,j);

		printf("%s",pr_r.medi_id);
		gotoxy(11,j);
		printf("%s",pr_r.medir_name);
		gotoxy(28,j);
		printf("%d-%d-%d",pr_r.sDay,pr_r.sMonth,pr_r.sYear);
		gotoxy(40,j);
		printf("%d",pr_r.qty);
		gotoxy(48,j);
		printf("%.2f",pr_r.unit);
		gotoxy(60,j);
		printf("%.2f",pr_r.rate);
		gotoxy(70,j);
		printf("%.2f",pr_r.profit);
		gotoxy(10,j);
		printf("%c",124);
		j+=2;

	   }
	   getche();
}

void sale_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;
  system("cls");
	   ptrs_r=fopen("saleRpt.dat","r");
	   if(ptrs_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   gotoxy(15,10);
	   printf("Enter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");
	   gotoxy(20,50);
	   printf("Press any key to go to REPORT MENU ...........");
	   box();
	   lbox();
	   //textcolor(GREEN);
	   gotoxy(30,8);
	   ////textcolor(GREEN+BLINK);
	   printf("Sales Report");
	   //textcolor(WHITE);
	   gotoxy(7,10);
	   printf("ID. Medicine Name.  Customer Name.   Qty.  Rate.  Total.   Date");
	   gotoxy(7,12);
	   printf("===================================================================");
	   j=14;
	   while(fscanf(ptrs_r,"%s %s %s %d %f %f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,&s_r.qty,&s_r.rate,&s_r.total,&s_r.sDay,&s_r.sMonth,&s_r.sYear)!=EOF)
	   {
		if(d==s_r.sDay &&m== s_r.sMonth && y==s_r.sYear)
		{
		gotoxy(6,j);
		printf("%s",s_r.medi_id);
		gotoxy(11,j);
		printf("%s",s_r.medir_name);
		gotoxy(28,j);
		printf("%s",s_r.cust_name);
		gotoxy(44,j);
		printf("%d",s_r.qty);
		gotoxy(50,j);
		printf("%.2f",s_r.rate);
		gotoxy(57,j);
		printf("%.2f",s_r.total);
		gotoxy(65,j);
		printf("%d-%d-%d",s_r.sDay,s_r.sMonth,s_r.sYear);
		j=j+2;
		total=total+s_r.total;
		}
	   }
	   gotoxy(7,42);
	   printf("-------------------------------------------------------------------");
	   gotoxy(45,43);
	   printf("Total:        %.2f",total);
	   getche();
}
void pur_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;

	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   gotoxy(15,10);
	   printf("Enter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("cls");
	   gotoxy(20,50);
	   printf("Press Enter to go to REPORT MENU ...........");
	   t();
	   box();
	   lbox();
	   //textcolor(GREEN);
	   gotoxy(30,8);
	   printf("Purchase Report");
	   //textcolor(WHITE);
	   gotoxy(7,10);
	   printf("ID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
	   gotoxy(7,12);
	   printf("===================================================================");
	   j=14;
	   while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {
		if(d==p_r.sDay &&m== p_r.sMonth && y==p_r.sYear)
		{
		gotoxy(6,j);
		printf("%s",p_r.medi_id);
		gotoxy(11,j);
		printf("%s",p_r.medir_name);
		gotoxy(28,j);
		printf("%s",p_r.supp_name);
		gotoxy(44,j);
		printf("%d",p_r.qty);
		gotoxy(50,j);
		printf("%.2f",p_r.rate);
		gotoxy(57,j);
		printf("%.2f",p_r.total);
		gotoxy(65,j);
		printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
		j+=2;
		total=total+p_r.total;
		}
	   }
	   gotoxy(7,42);
	   printf("-------------------------------------------------------------------");
	   gotoxy(45,43);
	   printf("Total:        %.2f",total);
	   getche();
}

  
  void AElevatorUp(int a)
    {
     printf("\nThe lift is on it's way up...");

        for (int i=Alift;i<=a;i++)
        {
        	Alift=i;
		            printf("%d->",Alift);

		        }

        printf("\nThe lift has arrived");
    }

   void AElevatorDown(int a)
    {
        printf("\nThe lift is on it's way down...");
        for (int i=Alift;i>=a;i--)
        {
        	Alift=i;

        printf("%d->",Alift);
    }

        printf("\nThe lift has arrived");
    }
void BElevatorUp(int a)
    {
     printf("\nThe lift is on it's way up...");

        for (int i=Blift;i<=a;i++)
        {
        	Blift=i;
		            printf("%d->",Blift);

		        }

        printf("\nThe lift has arrived");
    }
     void BElevatorDown(int a)
    {
        printf("\nThe lift is on it's way down...");
        for (int i=Blift;i>=a;i--)
        {
        	Blift=i;

        printf("%d->",Blift);
    }

        printf("\nThe lift has arrived");
    }
  

    int main()
    {
    	int ch;
       while(1)
       { 
      printf("----------------------------------------------------------------------------\n");
      printf("\t\t\tLIFT MANAGEMENT SYSTEM\n");
      printf("\nENTER YOUR CHOICE\n 1.want to use the lifts\n 2.Check the status of the lifts\n 3.Report the lifts\n 4.exit the program\n");
      printf("-----------------------------------------------------------------------------\n");  
        scanf("%d",&ch);
     switch(ch)
    {
       case 1:
	 
         printf("\nWhich floor are you at now (0-10) where 0 = basement: ");
        scanf("%d",&person);

     if(check_lift()==1){
        if(Alift== person)
        {
            printf("\nEnter into the elevator");
      }

        else if(Alift> person)
        {
            AElevatorDown(person);
             printf("\nEnter into the elevator");
       
        }

        else if(Alift< person)
        {
            AElevatorUp(person);
             printf("\nEnter into the elevator");
       
        }

        printf("\nTo which floor would you want to go (0-10) where 0 = basement");
        scanf("%d",&choice1);
        if(Alift==choice1){
        	printf("Already you are in floor %d",choice1);
		}
        

       else if(Alift> choice1)
        {
            AElevatorDown(choice1);
            printf("\nyou reached to the floor %d",Alift);
        }

        else if(Alift< choice1)
        {
            AElevatorUp(choice1);
             printf("\nyou reached to the floor %d",Alift);

        }
}
else if(check_lift()==2)
{
        if(Blift== person)
        {
            printf("\nEnter into the elevator");
      }

        else if(Blift> person)
        {
            BElevatorDown(person);
             printf("\nEnter into the elevator");
       
        }

        else if(Blift< person)
        {
            BElevatorUp(person);
             printf("\nEnter into the elevator");
       
        }

        printf("\nTo which floor would you want to go (0-10) where 0 = basement");
        scanf("%d",&choice1);
         if(Blift==choice1){
        	printf("Already you are in floor %d\n",choice1);
		}

        if(Blift> choice1)
        {
            BElevatorDown(choice1);
            printf("\nyou reached to the floor %d\n",Blift);
        }

        else if(Blift< choice1)
        {
            BElevatorUp(choice1);
             printf("\nyou reached to the floor %d\n",Blift);

        }
        }  
          break;
      case 2:
            status_of_lifts();
           break;
     case 3:
         report();
         printf("Thanks for your Reporting we will work over it\n");
       break;
     case 4:
         exit(0);
      break;
          default:
          	printf("Enter valid input\n");
          	break;
      
 }
}
    
        getch();
        return 0;


    }

    

