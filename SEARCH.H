void search_sno()
{
	FILE *ptr;
	int n,found;

	textcolor(YELLOW);
	clrscr();

	printf("Enter the serial no. : ");
	scanf("%d", &n);

	ptr = fopen("info.dat","r");

	found = 0;

	while(fread(&cont,sizeof(cont),1,ptr) != NULL)
	{
		if(cont.sno == n)
		{
			printf("\nCategory  : %s",cont.category);
			printf("\nName  :  %s",cont.name);
			printf("\nGender  : %c",cont.gender);
			printf("\nAge  : %d",cont.age);
			printf("\nAddress  : %s",cont.address);
			printf("\nMobile no.  :  %s",cont.mob);

			found = 1;

			getch();

			break;
		}
	 }

	 if(found == 0)
	 {
		printf("\nNot found, Press any key...");

		fclose(ptr);

		getch();

		return;
	 }
	 fclose(ptr);

}

void search_category()
{
	int i=0;
	char cat[20];
	FILE *ptr;

	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();

	printf("Enter category(frd/family/college/office/hospital) : ");
	gets(cat);

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
		if(strcmpi(cat,cont.category) == 0)
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

	}
	fclose(ptr);

	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Press any Key...");

	getch();
}

void search_name()
{
	int i=0;
	char name[20];
	FILE *ptr;

	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();

	printf("Enter name : ");
	gets(name);

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
		if(strcmpi(name,cont.name) == 0)
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

	}
	fclose(ptr);

	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Press any Key...");

	getch();
}

void search_mob()
{
	FILE *ptr;
	int found;
	char mno[10];

	textcolor(YELLOW);
	clrscr();

	printf("Enter mobile no. : ");
	gets(mno);

	ptr = fopen("info.dat","r");

	found = 0;

	while(fread(&cont,sizeof(cont),1,ptr) != NULL)
	{
		if(strcmpi(mno,cont.mob) == 0)
		{
			printf("\nCategory  : %s",cont.category);
			printf("\nName  :  %s",cont.name);
			printf("\nGender  : %c",cont.gender);
			printf("\nAge  : %d",cont.age);
			printf("\nAddress  : %s",cont.address);
			printf("\nMobile no.  :  %s",cont.mob);

			found = 1;

			getch();

			break;
		}
	 }

	 if(found == 0)
	 {
		printf("\nNot found, Press any key...");

		fclose(ptr);

		getch();

		return;
	 }

	 fclose(ptr);

	 getch();

}