
#include<stdio.h>
#include<string.h>

int lexic(char a[],char b[])
{
	int i;
	for(int i=0;a[i]!='\0' || b[i]!='\0';i++)
	{
		if(a[i]>b[i])
			return 1;
		else if(b[i]>a[i])
			return 2;
	}
	if (a[i]!='\0')
		return 1;
	else if (b[i]!='\0')
		return 2;
	else
		return 0;
}

int main(){
	char str[100];
	char *token;
	char delimeter[]="|";
	char words[100][100];
	int i=0,j=0;
	printf("Enter the string: ");
	fgets(str,100,stdin);
	token = strtok(str,delimeter);
	while(token)
	{
		token[strcspn(token, "\n")] = '\0';
		strcpy(words[i], token);
		token=strtok(NULL,delimeter);
		i++;
	}
	for(j=0;j<i;j++)
	{
		for(int k=j+1;k<i;k++)
		{
			if(lexic(words[j],words[k])==1)
			{
				strcpy(str,words[j]);
				strcpy(words[j],words[k]);
				strcpy(words[k],str);
			}
		}
	}
	printf("\nThe lexicographical order is: \n");

	for(int j=0;j<i;j++)
	{
		if(words[j][0]!='\0')
		{
			printf("%s",words[j]);
			if(j!=i-1)
				printf("|");
		}
	}
	
       return 0;
}       
	

