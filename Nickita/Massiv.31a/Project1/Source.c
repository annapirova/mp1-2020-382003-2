#include <stdio.h>
#include <stdlib.h>

int count(int n, int nums[n]) 
{
	int lot = 0, sum = 0, average;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
	}
	average = sum / n;

	for (int j = 0; j < n; j++) {
		if (nums[j] > average) {
			lot += 1;
		}
	}

	return lot;
}

int main(void) {
	int n = 15;
	int nums[n];
	for (int i = 0; i < n; i++) {
		nums[i] = rand() % 1000000;
	}
	printf("Количество работников с зарплатой выше среднего: %d", count(n, nums));

	return 0;
}