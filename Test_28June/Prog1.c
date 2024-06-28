//input a sentence and capitalie first letter of each word.
#include<stdio.h>
#include<string.h>
int main()
{
	char str[50],str1[50];
	char words[10][20];
	char *token;


	printf("Enter the string: ");
	fgets(str,50,stdin);
	str[strcspn(str,"\n")]='\0';

	for(int i=0;i<strlen(str);i++)
	{
		if(i==0 || (i>0 && str[i-1]==' '))
		{
		str[i]-=32;
		}
	}
	printf("The capitalized sentence is: \n");
	printf("%s\n",str);
	return 0;
}
		
