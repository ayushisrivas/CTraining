#include <stdio.h>
int main() {
	float temperature;
	printf("***Temperature Advice***\n");
	printf("Enter the temperature in Celsius: ");
	scanf("%f", &temperature);
 
  	if (temperature > 30) {
		printf("It's hot outside, stay hydrated!\n");
 	} 
	else if (temperature >= 20) {
		printf("The weather is nice and warm.\n");
  	} 
	else if (temperature >= 10) {
		printf("It's a bit chilly, wear a jacket.\n");
  	} 
	else {
		printf("It's cold outside, stay warm!\n");
  	}	
 	return 0;
}
