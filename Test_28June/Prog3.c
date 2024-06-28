
//Delete adjacent consecutive characters.
#include<stdio.h>
#include<string.h>
int removchar(char a[],int k)
{
	for(int i=k;i<strlen(a);i++)
	{
		a[i]=a[i+2];

	}
}


int main()
{
	char str[50];
	printf("Enter a string : ");
	fgets(str,50,stdin);

	int n=strlen(str);
	for(int i=0;i<=n-1;i++)
	{
		if(strlen(str)<3)
			break;
		if((str[i]+1)==str[i+1])
		{
			int f= removchar(str,i);
			n-=2;
			i=-1;
	//		printf("\n%s, %c, %c\n",str,str[i],str[i+1]);
		}
	}
	printf("The updated string is: ");
	if(strlen(str)>1)
		printf("%s\n",str);
	else
		printf("NULL\n");

	return 0;
}
				


