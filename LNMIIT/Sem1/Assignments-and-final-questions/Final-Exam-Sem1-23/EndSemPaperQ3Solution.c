#include<stdio.h>
#include<stdlib.h>
struct Stud_Rec
{
	int roll_no;
	char name[100]	;
	int marks;
};

void Read_Rec(struct Stud_Rec t[])
{
	int i;
	printf("Enter details of 5 students\n");
	for(i=0;i<5;i++)
	{
		printf("Name : ");				gets(t[i].name);
		printf("Roll Number : ");		scanf("%d",&t[i].roll_no);
		printf("Marks : ");				scanf("%d",&t[i].marks);
		fflush(stdin);
	}
}

void Write_Rec(struct Stud_Rec t[])
{
	int i;
	printf("\nDetails of 5 students\n");
	for(i=0;i<5;i++)
	{
		printf("Name : %s\n",t[i].name);
		printf("Roll Number : %d\n",t[i].roll_no);
		printf("Marks : %d\n",t[i].marks);
	}
}
int Stud_Count(struct Stud_Rec t[],int th)
{
	int c=0,i;
	for(i=0;i<5;i++)
	{
		if(t[i].marks>th)
		{		//you can also print details
				c++;
		}
	}
	return c;
}
int main()
{
	int th,count;
	struct Stud_Rec s[5];
	//call the function Read_Rec() and pass s
	Read_Rec(s);
	system("cls");//instead of clrscr()
	//call the function Write_Rec() and pass s
	Write_Rec(s);
	printf("\nEnter the threshold marks : ");
	scanf("%d",&th);
	//call the Stud_Count() and pass s , and th
	count=Stud_Count(s,th);	
	printf("\nTotal %d students scored marks >= %d",count,th);	
	return 0;
}
