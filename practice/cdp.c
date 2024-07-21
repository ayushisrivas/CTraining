#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <pthread.h>
 
#define MAX_BUFF 1024

#define PORT_NO 65534

#define MAX_LINE_LEN 1024
 
struct user

{

    char msisdn[20];

    char op_brand_name[64];

    char op_mmc[20];

    char call_type[10];

    char duration[10];

    char download[10];

    char upload[10];

    char third_party_msisdn[10];

    char third_party_mmc[10];

};
 
typedef struct interop

{

    char op_mmc[20];

    char op_name[20];

    long int incoming_call;

    long int outgoing_call;

    long int incoming_sms;

    long int outgoing_sms;

    long int downloaded;

    long int uploaded;

} IP;
 
 
//Process the data of CDR file for Customer billing.
void *customerDataProcess(void *cargs)
{
	long int n=0;	
	struct User *CS=(struct User*)cargs;
	FILE *p_fp;
	p_fp=fopen("cdrdata.txt","r");
	if(p_fp == NULL)
	{
		return NULL;
	}
	else
	{	
			
		char line[MAX_LINE_LENGTH]={0,};
		int i=0,j=0,token_count = 0;
		char tokens[9][MAX_LINE_LENGTH]={0,};
		
   	 	while (fgets(line,MAX_LINE_LENGTH,p_fp) != NULL) 
		{	
			for(i=0;line[i]!='\0';i++)
			{
				if(line[i]=='|')
				{
					tokens[token_count][j]='\0';
					token_count++;
					j=0;
					continue;
				}
				tokens[token_count][j]=line[i];
				j++;
			}

			n++;		
        	strcpy(CS[n-1].msisdn, tokens[0]);
      	    strcpy(CS[n-1].op_brand_name, tokens[1]);
        	strcpy(CS[n-1].op_mmc, tokens[2]);
        	strcpy(CS[n-1].call_type, tokens[3]);
        	strcpy(CS[n-1].duration, tokens[4]);
        	strcpy(CS[n-1].download, tokens[5]);
        	strcpy(CS[n-1].upload, tokens[6]);
        	strcpy(CS[n-1].third_party_msisdn, tokens[7]);
        	strcpy(CS[n-1].third_party_mmc, tokens[8]);
			token_count=0;
			j=0;
    	}
    fclose(p_fp);
   }
   return NULL;
}

//Process the data of CDR file for Ineter operator billing.
void *cdr_operator_data_rocess(void *oargs)
{
	IP *op=(IP*)oargs;
	FILE *p_fp;
	p_fp=fopen("cdrdata.txt","r");
	if(p_fp == NULL)
	{
		printf("\nfile error\n");
		return NULL;
	}
	else
	{

		char line[MAX_LINE_LENGTH]={0,};
		int i=0,j=0,token_count = 0;
		long int in=0;
		char tokens[9][MAX_LINE_LENGTH]={0,};
		struct User *us=(struct User *)malloc(1*(sizeof(struct User)));
		while (fgets(line,MAX_LINE_LENGTH,p_fp) != NULL)
		{

			us=(struct User *)realloc(us,(in+1)*sizeof(struct User));
			for(i=0;line[i]!='\0';i++)
			{
				if(line[i]=='|')
				{
					tokens[token_count][j]='\0';
					token_count++;
					j=0;
					continue;
				}
				tokens[token_count][j]=line[i];
				j++;
			}

			in++;
			strcpy(us[in-1].msisdn, tokens[0]);
      	   	strcpy(us[in-1].op_brand_name, tokens[1]);
        	strcpy(us[IN-1].op_mmc, tokens[2]);
        	strcpy(us[IN-1].call_type, tokens[3]);
        	strcpy(us[IN-1].duration, tokens[4]);
        	strcpy(us[IN-1].download, tokens[5]);
        	strcpy(us[IN-1].upload, tokens[6]);
        	strcpy(us[IN-1].third_party_msisdn, tokens[7]);
        	strcpy(us[IN-1].third_party_mmc, tokens[8]);

			token_count=0;
			j=0;
    	}

		strcpy(op[0].op_mmc,"42500");
		strcpy(op[1].op_mmc,"42501");
		strcpy(op[2].op_mmc,"42502");
		strcpy(op[3].op_mmc,"42503");
		strcpy(op[4].op_mmc,"42504");
		int k=0;
		while(k<5)
		{
			bzero(op[k].op_name,20);
			op[k].incoming_call=0;
			op[k].outgoing_call=0;
			op[k].incoming_sms=0;
			op[k].outgoing_sms=0;
			op[k].downloaded=0;
			op[k].uploaded=0;
			k++;
		}
	    char *mtc="MTC", *moc="MOC", *smsin="SMS-MT", *smsout="SMS-MO", *gprs="GPRS";
		k=0;
		while(k<IN)
		{
			if(atol(us[k].op_mmc)==atol(op[0].op_mmc))
			{
				if(strcmp(us[k].call_type,mtc)==0)
				{
					op[0].incoming_call=op[0].incoming_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,moc)==0)
				{
					op[0].outgoing_call=op[0].outgoing_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,smsin)==0)
				{
					op[0].incoming_sms=op[0].incoming_sms+1;
				}
				else if(strcmp(us[k].call_type,smsout)==0)
				{
					op[0].outgoing_sms=op[0].outgoing_sms+1;
				}
				else if(strcmp(us[k].call_type,gprs)==0)
				{
					op[0].downloaded=op[0].downloaded+atol(us[k].download);
					op[0].uploaded=op[0].uploaded+atol(us[k].upload);
				}
				
				strcpy(op[0].op_name,us[k].op_brand_name);
				k++;
			}
		
		
		
		
		

			else if(atol(us[k].op_mmc)==atol(op[1].op_mmc))
			{
				if(strcmp(us[k].call_type,mtc)==1)
				{
					op[1].incoming_call=op[1].incoming_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,moc)==0)
				{
					op[1].outgoing_call=op[1].outgoing_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,smsin)==0)
				{
					op[1].incoming_sms=op[1].incoming_sms+1;
				}
				else if(strcmp(us[k].call_type,smsout)==0)
				{
					op[1].outgoing_sms=op[1].outgoing_sms+1;
				}
				else if(strcmp(us[k].call_type,gprs)==0)
				{
					op[1].downloaded=op[1].downloaded+atol(us[k].download);
					op[1].uploaded=op[1].uploaded+atol(us[k].upload);
				}
			
				strcpy(op[1].op_name,us[k].op_brand_name);
				k++;
			}
			else if(atol(us[k].op_mmc)==atol(op[2].op_mmc))
			{
				if(strcmp(us[k].call_type,mtc)==0)
				{
					op[2].incoming_call=op[2].incoming_call+atol(us[k].dur);
				}
				else if(strcmp(us[k].call_type,moc)==0)
				{
					op[2].outgoing_call=op[2].outgoing_call+atol(us[k].dur);
				}
				else if(strcmp(us[k].call_type,smsin)==0)
				{
					op[2].incoming_sms=op[2].incoming_sms+1;
				}
				else if(strcmp(us[k].call_type,smsout)==0)
				{
					op[2].outgoing_sms=op[2].outgoing_sms+1;
				}
				else if(strcmp(us[k].call_type,gprs)==0)
				{
					op[2].downloaded=op[2].downloaded+atol(us[k].download);
					op[2].uploaded=op[2].uploaded+atol(us[k].upload);
				}
				strcpy(op[2].op_name,us[k].op_brand_name);
				k++;
			}
			else if(atol(us[k].op_mmc)==atol(op[3].op_mmc))
			{
				if(strcmp(us[k].call_type,mtc)==0)
				{
					op[3].incoming_call=op[3].incoming_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,moc)==0)
				{
					op[3].outgoing_call=op[3].outgoing_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,smsin)==0)
				{
					op[3].incoming_sms=op[3].incoming_sms+1;
				}
				else if(strcmp(us[k].call_type,smsout)==0)
				{
					op[3].outgoing_sms=op[3].outgoing_sms+1;
				}
				else if(strcmp(us[k].call_type,gprs)==0)
				{
					op[3].downloaded=op[3].downloaded+atol(us[k].download);
					op[3].uploaded=op[3].uploaded+atol(us[k].upload);
				}
				strcpy(op[3].op_name,us[k].op_brand_name);
				k++;
			}
			else if(atol(us[k].op_mmc)==atol(op[4].op_mmc))
			{
				if(strcmp(us[k].call_type,mtc)==0)
				{
					op[4].incoming_call=op[4].incoming_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,moc)==0)
				{
					op[4].outgoing_call=op[4].outgoing_call+atol(us[k].duration);
				}
				else if(strcmp(us[k].call_type,smsin)==0)
				{
					op[4].incoming_sms=op[4].incoming_sms+1;
				}
				else if(strcmp(us[k].call_type,smsout)==0)
				{
					op[4].outgoing_sms=op[4].outgoing_sms+1;
				}
				else if(strcmp(us[k].call_type,gprs)==0)
				{
					op[4].downloaded=op[4].downloaded+atol(us[k].download);
					op[4].uploaded=op[4].uploaded+atol(us[k].upload);
				}
				strcpy(op[4].op_name,us[k].op_brand_name);
				k++;
			}
				
		}
		free(us);
	}
    fclose(p_fp);
	return NULL;

}

//Perform the data processing for both customer and inter operator using multi threading.
void dataProcess(struct User *CS,IP *IOS)
{

	pthread_t CDthread,IDthread;
	pthread_create(&CDthread,NULL,cdr_customer_data_process,(void *)CS);
	pthread_join(CDthread,NULL);
	pthread_cancel(CDthread);
	pthread_create(&IDthread,NULL,cdr_operator_data_process,(void *)IOS);
	pthread_join(IDthread,NULL);
	pthread_cancel(IDthread);

}



int main() {
    struct User *users = (struct User *)malloc(MAX_USERS * sizeof(struct User));
    IP *interoperators = (IP *)malloc(5 * sizeof(IP));  // Assuming 5 interoperators based on your code

    if (users == NULL || interoperators == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize the structures or arrays as needed before calling dataProcess

    // Call the data processing function
    dataProcess(users, interoperators);

    // Print the results for users
    printf("User data:\n");
    for (int i = 0; i < MAX_USERS; ++i) {
        if (users[i].msisdn[0] == '\0')  // Assume empty msisdn indicates end of data
            break;
        printf("User %d:\n", i+1);
        printf("MSISDN: %s\n", users[i].msisdn);
        printf("Operator Brand Name: %s\n", users[i].op_brand_name);
        printf("Operator MMC: %s\n", users[i].op_mmc);
        printf("Call Type: %s\n", users[i].call_type);
        printf("Duration: %s\n", users[i].duration);
        printf("Download: %s\n", users[i].download);
        printf("Upload: %s\n", users[i].upload);
        printf("Third Party MSISDN: %s\n", users[i].third_party_msisdn);
        printf("Third Party MMC: %s\n", users[i].third_party_mmc);
        printf("\n");
    }

    // Print the results for interoperators
    printf("Interoperator data:\n");
    for (int i = 0; i < 5; ++i) {
        printf("Interoperator %d:\n", i+1);
        printf("Operator MMC: %s\n", interoperators[i].op_mmc);
        printf("Operator Name: %s\n", interoperators[i].op_name);
        printf("Incoming Call: %ld\n", interoperators[i].incoming_call);
        printf("Outgoing Call: %ld\n", interoperators[i].outgoing_call);
        printf("Incoming SMS: %ld\n", interoperators[i].incoming_sms);
        printf("Outgoing SMS: %ld\n", interoperators[i].outgoing_sms);
        printf("Downloaded: %ld\n", interoperators[i].downloaded);
        printf("Uploaded: %ld\n", interoperators[i].uploaded);
        printf("\n");
    }

    // Free allocated memory
    free(users);
    free(interoperators);

    return 0;
}
