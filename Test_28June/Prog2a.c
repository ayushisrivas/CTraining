

//Delete adjacent consecutive characters.
#include<stdio.h>
#include<string.h>
int removchar(char a[],int k)
{
	char s=a[k];
	int count=0;
	for(int i=k+1;i<strlen(a);i++)
	{
		if(a[i]==s)
			count++;
		else 
			break;

	}
	for(int i=k;i<strlen(a);i++)
	{
		printf("\n%c",a[i]);
		a[i]=a[i+count+1];
		printf("\n%c",a[i]);

	}
	return count;

}


int main()
{
	char str[50];
	printf("Enter a string : ");
	fgets(str,50,stdin);

	int n=strlen(str);
	for(int i=0;i<=n-1;i++)
	{
		if((str[i])==str[i+1])
		{
			int f= removchar(str,i);
			n-=f;
			printf("\n%s, %c, %c\n",str,str[i],str[i+1]);
			i=-1;
		}
	}
	printf("The updated string is: ");
	if(strlen(str)>1)
		printf("%s\n",str);
	else
		printf("NULL\n");

	return 0;
}
				


