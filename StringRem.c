#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	char words[100][100];
	printf("Enter the string: ");
	fgets(str, 100, stdin);

	char str2[10];
	printf("Enter the word to replace last occurrence of:");
	fgets(str2,10,stdin);

	char *token;
	char delimiter[]=" ";
	int i=0, c=0;
	str2[strcspn(str2, "\n")] = '\0';
	str[strcspn(str, "\n")] = '\0';
	token=strtok(str,delimiter);
	int flag=-1;
	while(token)
	{
		strcpy(words[i],token);
		token=strtok(NULL,delimiter);
		i++;
	}

	for(int j=0;j<i;j++)
	{
		if(strcmp(str2,words[j])==0)
		{
			flag=j;
		}
	}
	if(flag!=-1)
	{	
		for (int j=0;j<i;j++)
		{
			if(j!=flag)
			printf("%s ",words[j]);
		}
	}
	else
	{
		printf("there are no instances of the word!\n");
	}



	return 0;
}
