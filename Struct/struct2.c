#include<stdio.h>
#include<string.h>

typedef struct students
{
	char SID[10];
	int flag;
	float score;
} STUDENT;

	
int main()
{
	char str[50], *token;
	int n,i=0,j=0,k=0,count;
	printf("Enter the number of instanes: ");
	scanf("%d",&n);
	getchar();
	STUDENT student[n],res[n];


	//taking inputs and splitting the string into id-score format
	printf("Enter the strings in SID-score format:\n");
	for(int i=0;i<n;i++)
	{
		fgets(str,50,stdin);
		str[strcspn(str,"\n")]='\0';
		sscanf(str, "%[^-]-%f", &student[i].SID,&student[i].score);
		student[i].flag=0;
	//	printf("%s,%d\n",student[i].SID,student[i].score);
	}



	//code logic to calcualte the average and find the unique students
	res[0]=student[0];
	for(i=1;i<n;i++)
	{
		int f=-1;
		count=1;
		for(j=0;j<=k;j++)
		{
	
			if(!strcmp(student[i].SID,res[j].SID))
			{
				f=j;
				if(student[i].flag==0)
				{
					res[j].score+=student[i].score;
					student[i].flag=1;
					count++;
				}
			}
		}

		if(f!=-1)
		{
			res[f].score/=count;
		}
		else
		{
			k++;
			res[k]=student[i];
		}
	
	}

	printf("The output is:\n");
	for(i=0;i<=k;i++)
	{
		printf("\n%s : %.2f", res[i].SID,res[i].score);
	}


	return 0;
}
