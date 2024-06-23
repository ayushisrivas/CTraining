#include <stdio.h>
int main() {
	float weight, height, bmi;
 	printf("***BMI Calculator***\n");
	printf("Enter your weight in kg: ");
	scanf("%f", &weight);
 
	printf("Enter your height in meters: ");
	scanf("%f", &height);
 
	bmi = weight / (height * height);
 	printf("Your BMI is: %.2f\n", bmi);
 
  	if (bmi < 18.5) {
		printf("Classification: Underweight\n");
  	} 
	else if (bmi >= 18.5 && bmi <= 24.9) {
		printf("Classification: Normal weight\n");
  	} 
	else if (bmi >= 25 && bmi <= 29.9) {
		printf("Classification: Overweight\n");
  	} 
	else {
		printf("Classification: Obesity\n");
  	}
	return 0;
}
