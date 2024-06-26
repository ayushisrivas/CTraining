#include<stdio.h>
#include<string.h>
int main()
	{
		char str[50];
		printf("Enter the string: ");
		fgets(str,50,stdin);
		str[strcspn(str,"\n")]='\0';
		int index,n;
		n=strlen(str);
		char a,b;
		printf("Enter the character: ");
		scanf(" %c",&a);
		printf("Enter the character to be placed instead: ");
		scanf(" %c",&b);
		for(int i=n-1;i>=0;i--)
		{
//			printf("%c%c%d\n",str[i],a,i);
			if(str[i]==a)
			{
				str[i]=b;
				break;
			}
		}
//		printf("\nIndex:%d\n",index);
		printf("\nThe updated string is: %s\n",str);	
		return 0;
	}
