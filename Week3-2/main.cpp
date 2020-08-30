#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int shop, hour, min, charge=0;
	printf("Enter your shopping cost: ");
	scanf("%d", &shop);
	printf("Enter your parking time in hour and minute: ");
	scanf("%d %d", &hour, &min);
	if (shop >= 0 && hour >= 0 && min >= 0 && min <= 60) {
		if (shop >= 1000) {// 3 hours free parking 
			if (min > 0) { hour++; }
			if (hour <= 3) {
				printf("Free parking charge!\n");
				return 0;
			}
			else if (hour > 3) charge = 40 * (hour - 3);
		}
		else {//<1000 --> 1 hour free parking 
			if (min > 0) { hour++; }
			if (hour <= 1) {
				printf("Free parking charge!\n");
				return 0;
			}
			else if (hour > 1) charge = 40 * (hour - 1);
		}
		if (charge >= 160) printf("Your total parking charge is %d Baht\nBut you can take a flat price and pay only 150 Baht\n", charge);
		else if (charge < 160) printf("Your total parking charge is %d Baht\n", charge);
	}
	else if (min > 60) printf("Please enter the minute less than 60\n");
	else printf("Please enter the number in positive integer\n");
	return 0;
}