#include<stdio.h>
#include<string.h>
 
int check(char t1[20], char t2[20])
{
 
        char s1[20];
        strcpy(s1,t1);
 
        char s2[30];
        strcpy(s2,t2);
        int f=0;
        if(strlen(s1)!=strlen(s2))
                return 1;
 
        for(int i=0;i< strlen(s1); i++)
        {
        f=0;
                for(int j=0;j<strlen(s2); j++)
                {
                        if(s1[i]==s2[j])
                                {f=1;
                //                      printf("\n s1[i]=%c,  s2[j]=%c", s1[i], s2[j]);
                                                        s1[i]='1';
                                        s2[j]='1';
                                break;}
                }
                if(f==0)
                        return 1;
        }
return 0;
}
 
 
int main()
{
        char str[50], res[50][20];
        printf("Enter string :");
        fgets(str,50,stdin);
        str[strcspn(str,"\n")]='\0';
        char *token, deli[]="|";
	token= strtok(str, deli);      
        char s[30][20];
        int n=0;
        while(token)
        {
                strcpy(s[n],token);
                printf(" %s \n", s[n]);
                n++;
                token=strtok(NULL, deli);
        }
        int k=0;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                    if(i!=j&&check(s[i],s[j])==0)
                    {
 
                //         printf("\n %s,  another- %s", s[i], s[j]);
                           strcpy(res[k++],s[i]);
                           strcpy(res[k++],s[j]);
                           strcpy(s[i],"\0");
                         //  strcpy(s[j],"\0");
                    }
                }
        }
 
 
        printf("\n Duplicate words are:-  \n");
        if(k==0)
                printf("\nNo duplicate element present");
        for(int i=0;i<k;i+=2)
        {
                printf("\t %s,   %s\n", res[i],res[i+1]);
        }
 
return 0;
}

