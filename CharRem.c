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
		char a;
		printf("Enter the character: ");
		scanf(" %c",&a);
		for(int i=n-1;i>=0;i--)
		{
//			printf("%c%c%d\n",str[i],a,i);
			if(str[i]==a)
			{
				printf("%d\n",i);
				index=i;
				break;
			}
		}
//		printf("\nIndex:%d\n",index);
		if(index!=-1)
		{
			printf("\nThe updated string is: ");
			for(int i=0;i<n;i++)
			{
				if(i!=index)
				printf("%c",str[i]);
			
			}
			printf("\n");
		}
		else
		{
			printf("Character not found!\n");
		}
		return 0;
	}
