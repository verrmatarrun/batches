#include<stdio.h>
#include<stdlib.h>
struct text
{	char string[100];
	char piglatin[200];
	int words;
};

void readText(struct text *t)
{
	char temp;	
	int i,j=0;
	printf("\nEnter the string : ");
	gets(t->string);	
	/*Iterate over the string*/
	t->words=0;
	for(i=0;t->string[i]!='\0';i++)
	{	if(t->string[i]==' ')
			t->words++;
		if(i==0||t->string[i-1]==' ')
		{
			temp=t->string[i];	
			if(t->string[i+1]==' ')
			{	t->piglatin[j]=t->string[i];
				j++;
				t->piglatin[j]='a';
				j++;
			}
		}
		else
		{	t->piglatin[j]=t->string[i];
			j++;
			if(t->string[i+1]==' '||t->string[i+1]=='\0')
			{	t->piglatin[j]=temp;
				j++;
				t->piglatin[j]='a';
				j++;
			}			
		}
	}
	t->piglatin[j]='\0';		
}
void writeText(struct text *t)
{
	printf("\nString is : %s\nPiglatin is : %s",t->string,t->piglatin);
	printf("\nString have %d words",t->words+1);
}

int main()
{	
	int size,i;
	struct text *t;
	printf("How many string you want to input : ");
	scanf("%d",&size);
	fflush(stdin);
	t=(struct text *)malloc(sizeof(struct text)*size);
	
	printf("\nEnter %d string",size);
	for(i=0;i<size;i++)
		readText(&t[i]);
	
	for(i=0;i<size;i++)
	writeText(&t[i]);
	return 0;	
}
