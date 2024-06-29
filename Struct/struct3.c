
#include<stdio.h>
#include<string.h>

typedef struct products
{
	char PID[10];
	int flag;
	int quantity;
} PROD;

	
int main()
{
	char str[50], *token;
	int n,i=0,j=0,k=0,count;
	printf("Enter the number of instanes: ");
	scanf("%d",&n);
	getchar();
	PROD products[n],res[n];


	//taking inputs and splitting the string into PID-quantity format
	printf("Enter the %d string in PID-quantity format:\n",n);
	for(int i=0;i<n;i++)
	{
		fgets(str,50,stdin);
		str[strcspn(str,"\n")]='\0';
		sscanf(str, "%[^-]-%d", products[i].PID,&products[i].quantity);
		products[i].flag=0;
	}



	//code logic to calcualte the total quantity for each product
	res[0]=products[0];
	for(i=1;i<n;i++)
	{
		int f=-1;
		for(j=0;j<=k;j++)
		{
		//if id found, adding the value. if id not found, f will return -1 else f will give the last index of res where score was updated.
			if(!strcmp(products[i].PID,res[j].PID))
			{
				f=j;
				if(products[i].flag==0)
				{
					res[j].quantity+=products[i].quantity;
					products[i].flag=1;
				}
			}
		}

		if(f==-1)
		{
			k++;
			res[k]=products[i];
		}
	
	}

	//sort in descending order
	for( i=0;i<=k;i++)
	{
		PROD temp;
		for( j=0;j<=k;j++)
		{
			if(res[i].quantity>res[j].quantity)
			{
				temp=res[i];
				res[i]=res[j];
				res[j]=temp;
			}
		}
	}



	//printing the output
				
	printf("The output is:\n");
	for(i=0;i<=k;i++)
	{
		printf("\n%s : %d", res[i].PID,res[i].quantity);
	}


	return 0;
}
