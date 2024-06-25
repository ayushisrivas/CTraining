
#include<stdio.h>
#include<string.h>
int main(){
	char str[]= {"This|is|the|string|that|is|inputted"};
	char *token;
	char delimeter[]="|";
	char words[100][100];
	int i=0,count=0;
	token = strtok(str,delimeter);
	while(token)
	{
		strcpy(words[i], token);
		token=strtok(NULL,delimeter);
		i++;
	}


	int arr[i];
	for(int j=0;j<i;j++)
	{
		for(int k=0;k<i;k++)
		{
			if(strcmp(words[j],words[k])==0)
			{
				count++;
			}
		}
		arr[j]=count;
		count=0;
	}
	for(int j=0;j<i;j++)
	{
		printf(" %s occurs %d times. \n", words[j],arr[j]);
	}
       return 0;
}       
	

