/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int a,b,c,res;
    printf("***CALCULATOR***\n");
    printf("-MENU\n 1. Add\n 2. Subtract\n 3. Multiply\n 4. Divide\n 5. Remainder\n 6. Bitwise And \n 7. Bitwise Or\n 8. Bitwise Not\n 9. Exit\n");
    printf("Enter your choice :");
    scanf(" %d",&c);
    while (c!=9){
        printf("Enter 2 integers: ");
        scanf(" %d%d", &a,&b);
        switch(c){
            case 1:
                res =a+b;
                break;
            case 2:
                res = a-b;
                break;
            case 3:
                res=a*b;
                break;
            case 4:
                if(b>0)
                res=a/b;
                else
                res=0;
                break;
            case 5:
                res=a%b;
                break;
            case 6:
                res=a&b;
                break;
            case 7:
                res=a|b;
                break;
            case 8:
                res=~b;
                break;
        }
        
        printf("The output is : %d",res);
        printf("\n-MENU\n 1. Add\n 2. Subtract\n 3. Multiply\n 4. Divide\n 5. Remainder\n 6. Bitwise And \n 7. Bitwise Or\n 8. Bitwise Not\n 9. Exit\n");
        printf("Enter your choice :");
        scanf(" %d",&c);
        
    }
    return 0;
}


