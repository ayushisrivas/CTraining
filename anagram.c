#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],str1[20];
	printf("Enter string one: ");
	fgets(str,20,stdin);
	printf("Enter string two: ");
	fgets(str1,20,stdin);
	int flag=0;
	if(strlen(str1)!=strlen(str))
	{
		printf("It is not an anagram.\n");
	}
	else
	{
		for(int i=0;i<strlen(str);i++)
		{
			flag=0;
			for(int j=0;j<strlen(str);j++)
			{	flag=0;
				if(str[i]==str1[j])
				{
					flag=1;
					break;
				}
			}
			if (flag==0)
			{
				printf("it is not an anagram.\n");
				break;
			}
		}
	}
	if(flag==1)
		printf("It is an anagram!\n");

	return 0;
}
