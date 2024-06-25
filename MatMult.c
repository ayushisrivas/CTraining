#include<stdio.h>
int main(){
	int m,n,o,p,i,j;
	printf("Enter the dimension of first 2D matrix: ");
	scanf("%d%d", &m,&n);
	printf("Enter the dimension of second 2D matrix: ");
	scanf(" %d%d", &o,&p);
	int arr1[m][n], arr2[o][p], arr3[m][p];
	printf("\nEnter the first matrix: \n");
	for(int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("\nEnter the second matrix: \n");
	for(i=0;i<o;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d",&arr2[i][j]);
		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<p;j++)
		{
			arr3[i][j]=0;
			for(int k=0;k<o;k++)
			{
				arr3[i][j]+=arr1[i][k]*arr2[k][j];
			}
		}
	}

	printf("The multiplied matrix is: \n");

	for(int i=0;i<m;i++)
	{
		for ( int j=0;j<p;j++)
		{
			printf("%d\t", arr3[i][j]);
		}
		printf("\n");
	}
	return 0;	

}
