#include<stdio.h>
#include<string.h>
int main(){
	char str[100][32];
	int n;
	printf("enter the number of time comparisons: ");
       	fgets(str[0], sizeof(str[0]), stdin);
    	sscanf(str[0], "%d", &n);
	while(getchar()!='\n');

	int h1,m1,s1,h2,m2,s2,flag=-1;

	printf("enter the strings: \n");
	for(int i=0;i<n;i++)
	{
		fgets(str[i], sizeof(str[i]), stdin);
        	str[i][strcspn(str[i], "\n")] = '\0';
   
	}
	for(int i=0;i<n;i++)
	{
		flag=0;
		sscanf(str[i], "%d|%d|%d %d|%d|%d", &h1, &m1, &s1, &h2, &m2, &s2);

		if(h1>h2||(h1==h2 && (m1>m2 || ( m1==m2 && (s1>s2)))))
		{
			flag=1;
		}
			
		if(h1<h2||(h1==h2 && (m1<m2 || ( m1==m2 && (s1<s2)))))
		{
			flag=2;
		}

		switch(flag)
		{
			case 1:
				printf("Late\n");
				break;
			case 2:
				printf("Early\n");
				break;
			default:
				printf("Equal\n");
		}
	}
	return 0;
}
