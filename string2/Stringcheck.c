#include<stdio.h>
#include<string.h>

void strsort(char str[])
{
	int n=strlen(str),i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(str[i]<str[j])
			{
				char a=str[i];
				str[i]=str[j];
				str[j]=a;
			}
		}
	}
}
int main()
{
	char str[3][100];
	printf("Enter the three strings:\n");
	for(int i=0;i<3;i++)
	{
		printf("%d :\t",i+1);
		fgets(str[i],100,stdin);
		str[i][strcspn(str[i],"\n")]='\0';
		//strsort(str[i]);
	}
	strcat(str[0],str[1]);
	strsort(str[0]);
	strsort(str[2]);
	if(!strcmp(str[0],str[2]))
	{
		printf("\nValid! String c can form strings a and b.\n:");
	}
	else
	{
		printf("\nInvalid, string c can not form strings a and b.\n");
	}
	//printf("string 1: %s\nstring3: %s\n", str[0],str[2]);
	return 0;
}

