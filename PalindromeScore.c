#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("Enter the string: \n");
	fgets(str,100,stdin);
	int n=strlen(str);
	int sc_4=0,sc_5=0;
	if(n>=5)
	for(int i=0;i<=n-4;i++)
	{
		if(str[i]==str[i+3] && str[i+1]==str[i+2])
		{
			sc_4++;
		}
		if(str[i]==str[i+4] && str[i+1]==str[i+3])
		{
			sc_5++;
		}
	}
	int res = (sc_4 *5) + (sc_5*10);
	printf("The result is: %d\n",res);
	return 0;
}
