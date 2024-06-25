#include<stdio.h>
int main(){
	int m,n,o,p,i,j;
	printf("Enter the dimension of first 2D matrix: ");
	scanf("%d%d", &m,&n);
	int arr1[m][n], arr2[n][m];
	printf("\nEnter the first matrix: \n");
	for(int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			scanf("%d",&arr1[i][j]);
		
		}
		printf("\n");

	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			arr2[i][j]=arr1[j][i];
		}
	}
	printf("The transposed matrix is: \n");

	for(int i=0;i<n;i++)
	{
		for ( int j=0;j<m;j++)
		{
			printf("%d\t", arr2[i][j]);
		}
		printf("\n");
	}
	return 0;	

}
