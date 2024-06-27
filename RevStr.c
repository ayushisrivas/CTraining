

#include<stdio.h>
#include<string.h>
int main(){
	char str[]= "This is the string that is inputted";
	char *token;
	char delimeter[]=" ";
	char words[100][100];
	int i=0;
	char temp[100];
	token = strtok(str,delimeter);
	while(token)
	{
		strcpy(words[i], token);
		token=strtok(NULL,delimeter);
		i++;
	}
	for(int j=0;j<i/2;j++)
	{
		strcpy(temp, words[j]);
		strcpy(words[j],words[i-j-1]);
		strcpy(words[i-j-1],temp);
	}
	for (int i=0;i<strlen(str);i++)
	{
		printf(" %s\n", words[i]);
	}
       return 0;
}       
	

