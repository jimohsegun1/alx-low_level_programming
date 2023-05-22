#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - prints the last digit of n and prints out whether it is
 * greater than 5, 0, or less than 6
 * Return: 0
 */
int main(void)
{
	int n;
	int m;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("Last digit of %d is ", n);

	m = n % 10;
	printf("%d and is ", m);

	if (m == 0)
		printf("0\n");
	else if (m < 6)
		printf("less than 6 and not 0\n");
	else
		printf("greater than 5\n");

	return (0);
}
