#include<stdio.h>
#include<math.h>
int main(){
	int num, nearest_root;
	float squareroot;

	printf("Enter the number: ");
	scanf("%d", &num);

	squareroot =sqrt((float)num);	

	nearest_root =round(squareroot);

	printf("The answer is: %d\n", nearest_root);
	return 0;
}

