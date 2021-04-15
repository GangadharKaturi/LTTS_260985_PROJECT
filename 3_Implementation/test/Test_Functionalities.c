#include "unity.h"

/* Modify these two lines according to the project */
#include "Functionalities.h"
#define PROJECT_NAME    "Medical Store Management System "


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 

  //=========FOR CUSTOMER DISPLAY LIST ==========
void cust_list()
{
 char ch;
 system("cls");
	   ptr1=fopen("customer.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   box();
	   //textcolor(GREEN+BLINK);
	   gotoxy(8,48);
	   printf("Press Anykey to go to CUSTOMER MENU!!!");
	   //textcolor(GREEN);
	   lbox();
	   gotoxy(30,8);
	   printf(" CUSTOMER LIST ");
	   //textcolor(WHITE);
	   i=14;
	   gotoxy(5,10);
	   printf(" ID. CUSTOMER NAME.    CITY.     MOBILE.NO.      EMAIL");
	   gotoxy(4,12);
	   printf("==============================================================");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		gotoxy(4,i);
		printf(" %d",temp_c.cust_id);
		gotoxy(11,i);
		printf(" %s",temp_c.cust_name);
		gotoxy(28,i);
		printf(" %s",temp_c.city);
		gotoxy(40,i);
		printf(" %s",temp_c.mob_no);
		gotoxy(53,i);
		printf(" %s",temp_c.email);
		i=i+2;
	   }
	   getche();
}
//======================search CUSTOMER==================
void cust_search()
{
  int ch;

	do
	 {
	   system("cls");
	   //textcolor(WHITE);
	   gotoxy(17,10);
	   printf(" Two options Available for searching ");
	   gotoxy(15,15);
	   printf("Search by");
	   gotoxy(25,15);
	   //textcolor(RED+BLINK);
	   printf("I");
	   //textcolor(WHITE);
	   gotoxy(26,15);
	   printf("D number");

	   gotoxy(15,18);
	   printf("Search by");
	   gotoxy(25,18);
	   //textcolor(RED+BLINK);
	   printf("N");
	   //textcolor(WHITE);
	   gotoxy(26,18);
	   printf("ame");

	   gotoxy(15,21);
	   //textcolor(RED+BLINK);
	   printf("R");
	   //textcolor(WHITE);
	   gotoxy(16,21);
	   printf("eturn");
	   main_box();
	   gotoxy(17,24);
	   printf("Press First charecter for the operation : ");
	   ch=toupper(getche());
	   switch(ch)
	   {
		case 'I':
			animation();
			search_cid();

			break;
		case 'N':
			animation();
			search_cname();
			break;
		case 'R':
			animation();
			customer();
			break;
		default:
			gotoxy(22,18);
			printf("You entered wrong choice!!!!!");
			getch();
	   }
	   }while(ch!='R');
       getche();
}
//===========================Search by CustomerId=========================
void search_cid()
{
  int id;
  system("cls");
  box();
	   ptr1=fopen("customer.dat","rb");
	   gotoxy(13,8);
	   printf("\xDB\xDB\xB2  Enter id to be searched:");
	   scanf("%d",&id);
	   //textcolor(GREEN);
	   //textcolor(WHITE);
	   i=18;
	   gotoxy(9,15);
	   printf(" ID. CUSTOMER NAME.    CITY.     MOBILE.NO.      EMAIL");
	   gotoxy(8,16);
	   printf("==============================================================");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		if(temp_c.cust_id==id)
		{
			gotoxy(8,i);
			printf(" %d",temp_c.cust_id);
			gotoxy(15,i);
			printf(" %s",temp_c.cust_name);
			gotoxy(28,i);
			printf(" %s",temp_c.city);
			gotoxy(40,i);
			printf(" %s",temp_c.mob_no);
			gotoxy(54,i);
			printf(" %s",temp_c.email);
			gotoxy(20,35);
			//textcolor(YELLOW);
			printf("Press Any key to go to CUSTOMER MENU ...........");
			break;
		}
	   }
	   if(temp_c.cust_id!=id)
	   {
		gotoxy(20,30);
		printf("Record not found!");
	   }
	   fclose(ptr1);
       getche();
}
/*****************************search by CUSTOMERname******************************/
void search_cname()
{
  char name[20];
  system("cls");
  box();
	   ptr1=fopen("customer.dat","rb");
	   gotoxy(12,8);
	   printf("\xDB\xDB\xB2  Enter Customer Name to be searched:");
	   scanf("%s",&name);
	   //textcolor(GREEN);
	   //textcolor(WHITE);
	   i=18;
	   gotoxy(9,15);
	   printf(" ID. CUSTOMER NAME.    CITY.     MOBILE.NO.      EMAIL");
	   gotoxy(8,16);
	   printf("==============================================================");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		if(strcmp(temp_c.cust_name,name)==0)
		{
			gotoxy(8,i);
			printf(" %d",temp_c.cust_id);
			gotoxy(15,i);
			printf(" %s",temp_c.cust_name);
			gotoxy(28,i);
			printf(" %s",temp_c.city);
			gotoxy(40,i);
			printf(" %s",temp_c.mob_no);
			gotoxy(54,i);
			printf(" %s",temp_c.email);
			gotoxy(20,35);
			//textcolor(YELLOW);
			printf("Press Any key to go to CUSTOMER MENU ...........");
			break;
		}
	   }
	   if(strcmp(temp_c.cust_name,name)!=0)
	   {
		gotoxy(5,10);
		//textcolor(YELLOW);
		printf("Record not found!");
	   }
	   fclose(ptr1);
	getche();
}
//============CUSTOMER update=================
void cust_update()
{
  int i;
  char ch;
  int cid;
  FILE *ft;
  system("cls");
  box();
	   ptr1=fopen("customer.dat","rb+");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open file!! ");
		exit(0);
	   }
	   lbox();
	   gotoxy(30,8);
	   printf(" Modifying customer ");
	   gotoxy(12,13);
	   printf("Enter the CUSTOMER ID : ");
	   scanf("%d",&cid);
	   gotoxy(12,15);

		ft=fopen("temp.txt","w");
		if(ft==NULL)
		{
			printf("\n Can not open file");
			exit(0);
		}
		else
		{

			while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
			{
				if(temp_c.cust_id==cid)
				{
					gotoxy(25,17);
					printf("*** Existing Record ***");
					gotoxy(10,19);
					printf("%d\t %s \t%s \t%s \t%s",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
					gotoxy(12,22);
					printf("Enter New Name         : ");
					//flushall();
					ventry(temp_c.cust_name,0);
					gotoxy(12,24);
					printf("Enter New mobile no    : ");
					//flushall();
					ventry(temp_c.mob_no,1);
					gotoxy(12,26);
					printf("Enter New City         : ");
					//flushall();
					ventry(temp_c.city,0);
					gotoxy(12,28);
					printf("Enter New email        : ");
					//flushall();
					scanf("%s",temp_c.email);
					gotoxy(20,32);
					//textcolor(RED+BLINK);
					printf("U");
					gotoxy(21,32);
					//textcolor(WHITE);
					printf("pdate");
					gotoxy(30,32);
					//textcolor(RED+BLINK);
					printf("C");
					gotoxy(31,32);
					//textcolor(WHITE);
					printf("ancel");
					gotoxy(18,35);
					printf("Press First charecter for the operation : ");
					ch=getche();
					if(ch=='u' || ch=='U')
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
				       //	fprintf(ft,"\n");
					fflush(stdin);
					gotoxy(20,36);
					printf("Customer updated successfully...");
					remove("customer.dat");
					rename("temp.txt","customer.dat");
					}					}
					else
					{
					fprintf(ft,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
					fflush(stdin);
					}
				  }


	   fclose(ft);
	   fclose(ptr1);
      }

}
