#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],str1[20];
	printf("Enter string one: \n");
	fgets(str,20,stdin);
	printf("Enter string two: \n");
	fgets(str1,20,stdin);
	if(strcmp(str,str1)==0)
	{
		printf("Anagram!\n");
	}
	else
	{
		printf("Not an anagram!\n");
	}

	return 0;
}
