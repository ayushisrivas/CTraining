#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int count_l=0;
	printf("Enter the string: ");
	fgets(str,100,stdin);
	int count=0;
	char match[]="aeiouAEIOU";
	for(int i=0; i<strlen(str);i++)
	{
		int flag=0;
		for(int j=0;j<strlen(match);j++)
		{
			if(str[i]==match[j])
				flag=1;
		}
		if(!flag)
			count++;
	}
	int total=0;
	for(int i=0;i<strlen(str);i++)
	{
		int flag=0;
		for(int j=0;j<strlen(match);j++)
		{
			if(str[i]==match[j])
				flag=1;
		}
		if(!flag)
			count_l++;
		if(count_l>count-count_l)
			total++;
	}
	printf("It can be partitioned in %d ways.",total);
	return 0;
}

			
		
	
