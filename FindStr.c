#include<stdio.h>
#include<string.h>
int main()
{
	char str[100], substr[20],c;
	int ind_S=-1,ind_C=-1;
	printf("Enter the string: ");
	fgets(str,100,stdin);
	str[strcspn(str,"\n")]='\0';
	printf("Enter the substring: ");
	fgets(substr,20,stdin);
	substr[strcspn(substr,"\n")]='\0';
	printf("Enter the character: ");
	scanf(" %c",&c);
	int n=strlen(str);
	for(int i=0;i<n-strlen(substr);i++)
	{
		int j=0,flag=0;;
		if(str[i]==substr[j])
		{
			for(int j=0;j<strlen(substr);j++)
			{
				if(str[i+j]!=substr[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				ind_S=i+1;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(str[i]==c)
		{
			ind_C=i+1;
			break;
		}
	}

	printf("Substr found at index %d\n", ind_S);
	printf("Character found at index %d\n", ind_C);
	return 0;
}
