#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intToBinary(int num)
{
	int maxBits = sizeof(num) * 4;
	char *binary = (char *)malloc(maxBits + 1); /* Extra space for null. */

	if (binary == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < maxBits; i++)
	{
		binary[maxBits - 1 - i] = (num & (1 << i)) ? '1' : '0';
	}

	binary[maxBits] = '\0';

	return (binary);
}



int main(void)
{
	int a = 420;
	int b = 333;
	char space[] = "          ";
	char *bitA = intToBinary(a);
	char *bitB = intToBinary(b);

	printf("%sBitwise Operation\n", space);
	printf("%sa = %d in binary: %s\n", space, a, bitA);
	printf("%sb = %d in binary: %s\n", space, b, bitB);

	printf("%sa | b = \n%s%s\n%s%s\n%s----------------\n%s%s =%d\n\n", space, space, bitA, space, bitB, space, space, intToBinary(a | b), a | b);

	printf("%sa & b = \n%s%s\n%s%s\n%s----------------\n%s%s =%d\n\n", space, space, bitA, space, bitB, space, space, intToBinary(a & b), a & b);

	printf("%sa >> 2 = \n%s%s\n%s----------------\n%s%s =%d\n\n", space, space, bitA, space, space, intToBinary(a >> 2), a >> 2);

	printf("%sa << 2 = \n%s%s\n%s----------------\n%s%s =%d\n\n", space, space, bitA, space, space, intToBinary(a << 2), a << 2);

	free(bitA);
	free(bitB);


}
