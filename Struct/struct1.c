/*Question 1:
Define a structure to hold the product sales information, structure will contain the product_ID and total_sales_amount. Write a program that accepts multiple product records (product_ID and total_sales_amount) and prints them in decreasing order of total_sales_amount. In case there are multiple records pertaining to the same product_id, the program should choose a single record containing the highest total_sales_amount.
The program should be capable of accepting a multi-line input. 
Each subsequent line of input will contain a Product record, that is, a product_ID and total_sales_amount(separated by a hyphen). The output should consist of the combination of product_ID and corresponding total_sales_amount in decreasing order of score.
 
Sample Input:
 
P1001-200
P1002-150
P1003-300
P1001-100
P1002-200
P1003-50
P1001-50
P1002-250
 
Sample Output:
 
P1003-300
P1002-250
P1001-200*/



#include<stdio.h>
#include<string.h>

typedef struct Sales {
	char PID[6];
	int amt;
} SALES;
int main()
{
	int n,i;
	printf("Enter the number of instances: ");
	scanf("%d",&n);
	SALES sale[n];
	char str[50];
	getchar();
	printf("Enter the string in PID-Amount format: \n");
	for(int i=0;i<n;i++)
	{
		fgets(str,15,stdin);
		//printf("\n%s\n",str);
		str[strcspn(str,"\n")]='\0';
		sscanf(str,"%10[^-]-%d",sale[i].PID,&sale[i].amt);
		//printf("The Pid is: %s and the amount is: %d",sale[i].PID,sale[i].amt);
	}
	SALES res[n];
	i=0;
	strcpy(res[0].PID,sale[0].PID);
	res[0].amt=sale[0].amt;
	int k=0;
	//printf("this \n %s:%d\n",res[0].PID,res[0].amt);
	for(int i=1;i<n;i++)
	{
		int j;
		for(j=0;j<=k;j++)
		{
			if(!strcmp(res[j].PID,sale[i].PID))
			{	
				if(res[j].amt<sale[i].amt)
				{
					res[j].amt=sale[i].amt;
				}
				break;
			}	
		}
		if(j==k+1)
		{
			res[k+1]=sale[i];
			k++;
		}

	}
	/*int arr[k];
	printf("\nk=%d",k);
	for(int i=0;i<=k;i++)
	{
		for(int i=0;i<=k;i++)
			printf("outer%s:%d\n",res[i].PID,res[i].amt);
	}*/
	SALES temp;
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(res[j].amt>res[i].amt)
			{
				temp=res[i];
				res[i]=res[j];
				res[j]=temp;
			}
		}
	}
	printf("The sorted products and their amounts are:");
	for(int i=k;i>=0;i--)
	{
		printf("\n%s : %d",res[i].PID,res[i].amt);
	}
	return 0;
}





