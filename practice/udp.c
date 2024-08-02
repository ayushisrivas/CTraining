#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_USERS 11

struct User {
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

void *customerDataProcess(void *cargs) {
    struct User *users = (struct User *)cargs;
    FILE *fp = fopen("cdrdata.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    int n = 0;

    while (fgets(line, sizeof(line), fp) != NULL && n < MAX_USERS) {
        line[strcspn(line, "\n")] = '\0';  // Remove newline character if present

        char tokens[9][MAX_LINE_LENGTH] = {0};
        int token_count = 0;
        int j = 0;

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '|') {
                tokens[token_count][j] = '\0';
                token_count++;
                j = 0;
                continue;
            }
            tokens[token_count][j] = line[i];
            j++;
        }

        strcpy(users[n].msisdn, tokens[0]);
        strcpy(users[n].op_brand_name, tokens[1]);
        strcpy(users[n].op_mmc, tokens[2]);
        strcpy(users[n].call_type, tokens[3]);
        strcpy(users[n].duration, tokens[4]);
        strcpy(users[n].download, tokens[5]);
        strcpy(users[n].upload, tokens[6]);
        strcpy(users[n].third_party_msisdn, tokens[7]);
        strcpy(users[n].third_party_mmc, tokens[8]);

        n++;
    }

    fclose(fp);
    return NULL;
}

int main() {
    struct User *users = (struct User *)malloc(MAX_USERS * sizeof(struct User));
    
    if (users == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    customerDataProcess((void *)users);

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

    free(users);

    return 0;
}

