#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"data.h"
#include"search.h"

void add_contact();
void delete_contact();
void edit_contact();
void search_contact();
void list_contact();
void change_pass();

void main()
{
	FILE *ptr;
	char ch, original[30], pass[30], choice;
	int i = 0;

	window(1,1,80,25);
	textbackground(YELLOW);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	clrscr();

	gotoxy(4,3);
	textcolor(RED+BLINK);
	cprintf("Enter the passward : ");

	while(1)
	{
		ch = getch();

		if(ch == 13)
		{
			pass[i] = '\0'	;
			break;
		}
		pass[i++] = ch;

		printf("*");
	}


	ptr = fopen("passward.dat","r");

	fgets(original,30,ptr);

	fclose(ptr);

	if(!strcmp(original,pass) == 0)
	{
		gotoxy(4,4);
		textcolor(WHITE+BLINK);
		cprintf("\nIncorrect passward, Press any key...");
		getch();
		exit(0);
	}
	else{
		window(1,1,80,25);
		textbackground(11);
		clrscr();
		gotoxy(32,3);
		textcolor(RED);
		cprintf("CONTACT MANAGER");
		gotoxy(33,5);
		textcolor(BLUE);
		cprintf("Version : 1.00");
		gotoxy(29,8);
		textcolor(YELLOW);
		cprintf("Developed by : Dishant");
		gotoxy(5,15);
		textcolor(RED);
		cprintf("Please wait ");
		for(i=0;i<50;i++)
		{
			cprintf("%c",254);
			delay(100);
		}

		while(1)
		{
			textbackground(YELLOW);
			clrscr();

			window(18,5,60,22);
			textbackground(BLACK);
			clrscr();

			textcolor(GREEN);
			gotoxy(18,2);
			cprintf("MAIN MENU");

			gotoxy(16,3);
			cprintf("-------------");

			gotoxy(13,5);
			textcolor(WHITE);
			cprintf("1  Add new contact");

			gotoxy(13,6);
			cprintf("2  Delete contact");

			gotoxy(13,7);
			cprintf("3  Edit contact");

			gotoxy(13,8);
			cprintf("4  Search contact");

			gotoxy(13,9);
			cprintf("5  List of contacts");

			gotoxy(13,10);
			cprintf("6  Change passward");

			gotoxy(13,11);
			cprintf("7  Exit");

			gotoxy(5,12);
			cprintf("-----------------------------------");

			gotoxy(13,14);
			textcolor(YELLOW);
			cprintf("Enter your choice(1-7) ?");

			choice = getche();

			switch(choice)
			{
				case '1':
					add_contact();
					break;

				case '2':
					delete_contact();
					break;

				case '3':
					edit_contact();
					break;

				case '4':
					search_contact();
					break;

				case '5':
					list_contact();
					break;

				case '6':
					change_pass();
					break;

				case '7':
					exit(0);

			}

		}
	}

	getch();

}

int getsno()
{
	FILE *ptr;
	int n,size;

	ptr = fopen("info.dat","rb");

	size = sizeof(cont);

	fseek(ptr,-size,SEEK_END);

	fread(&cont,sizeof(cont),1,ptr);

	n = cont.sno;
	n++;

	return(n);
}

void add_contact()
{
	FILE *ptr;

	window(1,1,80,25);
	textbackground(YELLOW);
	textcolor(11);
	clrscr();

	printf("Add new contatct\n");
	printf("-----------------------------------\n");

	fflush(stdin);

	cont.sno = getsno();
	printf("\nSerial no. : %d",cont.sno);

	printf("\nEnter category(frd/family/college/office/hospital) : ");
	gets(cont.category);
	fflush(stdin);

	printf("\nEnter name : ");
	gets(cont.name);
	fflush(stdin);

	printf("\nEnter gender(m/f) : ");
	scanf("%c",&cont.gender);
	fflush(stdin);

	printf("\nEnter age : ");
	scanf("%d", &cont.age);
	fflush(stdin);

	printf("\nEnter address : ");
	gets(cont.address);
	fflush(stdin);

	printf("\nEnter Mobile no. : ");
	gets(cont.mob);
	fflush(stdin);

	ptr = fopen("info.dat","ab");
	fwrite(&cont,sizeof(cont),1,ptr);
	fclose(ptr);

	textcolor(WHITE+BLINK);
	cprintf("\nSucessfully saved! Press any key...");

}

void delete_contact()
{
	FILE *ptr1, *ptr2;
	char choice;
	int n,found;

	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(YELLOW);
	clrscr();

	printf("Delete Contact");
	printf("\n-------------------------------------------------");
	printf("\nEnter serial no to be deleted : ");
	scanf("%d",&n);

	ptr1 = fopen("info.dat","rb");
	found = 0;

	while(fread(&cont,sizeof(cont),1,ptr1) != NULL)
	{
		if(cont.sno == n)
		{
			printf("\nCategory   : %s",cont.category);
			printf("\nName       : %s",cont.name);
			printf("\nGender     : %c",&cont.gender);
			printf("\nAge        : %d",cont.age);
			printf("\nAddress    : %s",cont.address);
			printf("\nMobile No. : %s",cont.mob);
			printf("\n---------------------------------------------");
			found = 1;
			break;
		}

	}

	if(found == 0)
	{
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("Not found !!! Press any key...");
		getch();

		fclose(ptr1);
		return;
	}

	printf("\nDelete it (y/n)? : ");
	choice = getche();

	if(choice == 'y' || choice == 'Y')
	{
		rewind(ptr1);
		ptr2 = fopen("temp.dat","wb");

		while(fread(&cont,sizeof(cont),1,ptr1) != NULL)
		{
			if(cont.sno != n)
			{
				fwrite(&cont,sizeof(cont),1,ptr2);
			}
		}

		fclose(ptr1);
		fclose(ptr2);

		remove("info.dat");

		rename("temp.dat","info.dat");

		textcolor(GREEN+BLINK);
		printf("\n");
		cprintf("Successfully Deleted !, press any key...");
		getch();
	}

}

void edit_contact()
{
	FILE *ptr;
	int n,found,pos;

	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(YELLOW);
	clrscr();

	printf("EDIT CONTACT\n");
	printf("---------------------------------------------------\n");

	printf("Enter the serial no. to be edited : \n");
	scanf("%d",&n);

	ptr = fopen("info.dat","r+b");

	found = 0;

	while(fread(&cont,sizeof(cont),1,ptr) != NULL)
	{
		if(cont.sno == n)
		{
			found = 1;

			printf("\nCategory   : %s",cont.category);
			printf("\nName       : %s",cont.name);
			printf("\nGender     : %c",&cont.gender);
			printf("\nAge        : %d",cont.age);
			printf("\nAddress    : %s",cont.address);
			printf("\nMobile No. : %s",cont.mob);

			break;

		}
	}

	if(found == 0)
	{
		printf("\n");

		textcolor(RED+BLINK);
		cprintf("Contatct not exist device !\npress any key...");

		getch();

		fclose(ptr);

		return;
	}

	printf("\n\nENTER NEW DATA\n");

	pos = ftell(ptr);

	fseek(ptr,pos-sizeof(cont),SEEK_SET);
	fflush(stdin);

	printf("\nEnter category(frd/family/college/office/hospital) : ");
	gets(cont.category);
	fflush(stdin);

	printf("\nEnter name : ");
	gets(cont.name);
	fflush(stdin);

	printf("\nEnter gender(m/f) : ");
	scanf("%c", &cont.gender);
	fflush(stdin);

	printf("\nEnter age : ");
	scanf("%d", &cont.age);
	fflush(stdin);

	printf("\nEnter address : ");
	gets(cont.address);
	fflush(stdin);

	printf("\nEnter Mobile no. : ");
	gets(cont.mob);
	fflush(stdin);

	fwrite(&cont,sizeof(cont),1,ptr);
	fclose(ptr);

	printf("\n");

	textcolor(RED+BLINK);
	cprintf("Successfully updated, Press any key...");

	getch();


}

void search_contact()
{
	char ch;

	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(11);
	clrscr();

	textcolor(WHITE);
	cprintf("SEARCH OPTIONS");
	printf("\n");
	printf("--------------------------------------------");

	printf("\n1  Search by serial no ");
	printf("\n2  Search by category ");
	printf("\n3  Search by name ");
	printf("\n4  Search by mobile no. ");
	printf("\n5  Back to main menu ");

	textcolor(YELLOW+BLINK);
	printf("\n");
	cprintf("Enter your choice ?");

	ch = getche();

	switch(ch)
	{
	 case '1':
		search_sno();
		break;

	 case '2':
		search_category();
		break;

	 case '3':
		search_name();
		break;

	 case '4':
		search_mob();
		break;

	 case '5':
		return;
	}
}

void list_contact()
{
	int i=0;
	FILE *ptr;

	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();

	gotoxy(33,1);
	printf("LIST OF CONTACTS");

	printf("\n");
	for(i=0;i<80;i++)
	{
		printf("-");
	}

	gotoxy(1,3);
	printf("SNO");

	gotoxy(8,3);
	printf("CATEGORY");

	gotoxy(20,3);
	printf("NAME");

	gotoxy(36,3);
	printf("GENDER");

	gotoxy(46,3);
	printf("AGE");

	gotoxy(55,3);
	printf("ADDRESS");

	gotoxy(70,3);
	printf("MOBILE NO.");

	printf("\n");
	for(i=0;i<80;i++)
	{
		printf("-");
	}

	ptr = fopen("info.dat","rb");
	i = 5;

	while(fread(&cont,sizeof(cont),1,ptr) != NULL)
	{
		gotoxy(1,i);
		printf("%d",cont.sno);

		gotoxy(8,i);
		printf("%s",cont.category);

		gotoxy(20,i);
		printf("%s",cont.name);

		gotoxy(36,i);
		printf("%c",cont.gender);

		gotoxy(46,i);
		printf("%d",cont.age);

		gotoxy(55,i);
		printf("%s",cont.address);

		gotoxy(70,i);
		printf("%s",cont.mob);

		i++;

	}
	fclose(ptr);

	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Press any Key...");

	getch();
}

void change_pass()
{
	char current[15],original[15],newpass[15],confirm[15];
	FILE *ptr;

	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();

	printf("Change Passward");
	printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

	printf("Enter the current passward : ");
	gets(current);

	ptr = fopen("passward.dat","r");
	fgets(original,30,ptr);
	fclose(ptr);

	if(strcmp(original,current) != 0)
	{
		printf("\nIncorrect passward !\nPress any key...");
		getch();
		return;
	}

	printf("\nEnter new passward : ");
	gets(newpass);

	printf("\nRe-enter passward : ");
	gets(confirm);

	if(strcmp(confirm,newpass) != 0)
	{
		printf("\nNot matched,press any key...");
		getch();
		return;
	}

	ptr = fopen("passward.dat","w");

	fprintf(ptr,"%s",newpass);
	fclose(ptr);

	printf("\nSuccessfully updated passward....\nPress any key...");

	getch();

}