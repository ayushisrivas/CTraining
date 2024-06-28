//Input a word, delete adjacent duplicate characters.
#include<stdio.h>
#include<string.h>
int removchar(char a[],int k)
{
	for(int i=k;i<strlen(a);i++)
	{
		a[i]=a[i+1];
	}


}


int main()
{
	char str[50];
	printf("Enter a string : ");
	fgets(str,50,stdin);

	int n=strlen(str);
	for(int i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
		{
			int f= removchar(str,i);
			n--;
			i--;
		}
	}
	printf("The updated string is: %s\n", str);
	return 0;
}
				


