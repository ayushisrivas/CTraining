#include<stdio.h>
#include<string.h>
int main()
{
	char str[]={"abbbfdgslajff"};
	int arr[20]={0};
	int n=strlen(str);
	char str2[]={""};
	for(int i=0;i<n;i++)
	{
		int count=0;
		for (int j=0;j<i;j++)
		{
			if(str[i]==str[j] && i!=j)
			{
				count++;
			}
		}
		arr[i]=count;

	}
	for(int i=0;i<n;i++)
	{
		if (arr[i]==0)
			strncat(str2,&str[i],1);
	}
	printf("%s\n",str2);

	return 0;
}	
