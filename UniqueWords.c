#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],words[100][100];
	printf("Enter the string: ");
	fgets(str,100,stdin);


	char *token;
	int n=0,count=0;
	token=strtok(str," ");
	while(token)
	{
		strcpy(words[n],token);
		token=strtok(NULL," ");
		n++;
	}
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
		for(int j=0;j<n;j++)
		{
			if(!strcmp(words[i],words[j]))
				count++;
		}
		arr[i]=count;
		count =0;
	}
	printf("The unique words are:\n");
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
			printf("\t%s",words[i]);
	}
	return 0;
}
