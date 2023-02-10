/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Abraham Lopez
 */
#include <stdio.h>
#define MONTHS 12
const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void salesreport(float sales[], char *months[]) {
	printf("\nMonthly sales report for 2022\n");
	printf("\nMonth    \t Sales\n");
	for (int i = 0; i < MONTHS; i++) {
		printf("%-7s \t $%.2f\n", months[i], sales[i]);
	}
}

void salessummary(float sales[], char *months[]) {
	int min = 0;
	int max = 0;
	float startingpoint = sales[0];
	float totalavg = 0;
	printf("\nSales Summary:\n");
	//minimum
	for (int i = 0; i < MONTHS; i++) {
		if (startingpoint > sales[i]) {
			startingpoint = sales[i];
			min = i;
		}
	}
	printf("Minimum Sales: \t $%.2f \t (%s)\n", sales[min], months[min]);

	//maximum
	startingpoint = 0;
	for (int i = 0; i < MONTHS; i++) {
		if (startingpoint < sales[i]) {
			startingpoint = sales[i];
			max = i;
		}
	}
	printf("Maximum Sales: \t $%.2f \t (%s)\n", sales[max], months[max]);

	//average
	for (int i = 0; i < MONTHS; i++) {
		totalavg = sales[i] + totalavg;
	}
	printf("Average sales: \t $%.2f\n", totalavg/MONTHS);
}

void sixmonthavg(float sales[MONTHS], char *months[]) {
	printf("\nSix-Month Moving Average Report\n");
	for (int i = 0; i <= (MONTHS/2); i++) {
		float starting = 0;
		for (int j = i; j <= i + 5; j++) {
			starting = sales[j] + starting;
		}
		printf("%-8s - %-10s $%.2f\n",months[i], months[i + 5], starting/6);
	}
}

void montlysaleshightolow(float tempfloat[], char *months[]) {
	char *tempchar[12];
	float tempval = 0;
	char *tmonth[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char *tempmonth;
	printf("\nSales Report (Highest to Lowest):\n");
	for (int i = 0; i < MONTHS; i++) {
		for (int j = 0; j < MONTHS - i - 1; j++) {
			if (tempfloat[j] > tempfloat[j + 1]) {
				tempval = tempfloat[j+1];
				tempmonth = tmonth[j+1];
				tempfloat[j+1] = tempfloat[j];
				tmonth[j+1] = tmonth[j];
				tempfloat[j] = tempval;
				tmonth[j] = tempmonth;
			}
		}
	}
	printf("Month     \t Sales\n");
	for (int i = MONTHS - 1; i >= 0; i--) {
		printf("%-10s \t $%.2f\n", tmonth[i], tempfloat[(i)]);
	}
}

int main() {
	float sales[MONTHS];
	FILE *fileptr;
	fileptr = fopen("inputs.txt", "r");
	if (fileptr == NULL) {
		printf("Error opening file\n");
		return 1;
	}
	for (int i = 0; i < MONTHS; i++) {
		fscanf(fileptr, "%f", &sales[i]);
	}
	salesreport( sales, months);
	salessummary(sales, months);
	sixmonthavg(sales, months);
	montlysaleshightolow(sales, months);
	fclose(fileptr);
	return 0;
}

