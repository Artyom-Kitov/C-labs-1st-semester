#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

char int_to_char(int n)
{
	if (n >= 10 && n <= 16) return n - 10 + 'A';
	return n + '0';
}

int char_to_int(char c)
{
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return c - '0';
}

int strchar(char *s, char c)
{
	int index;
	for (index = 0; index < strlen(s); index++)
		if (s[index] == c) return index;

	return index;
}

void to_beginning(char *s, char c)
{
	for (int i = strlen(s); i > 0; i--)
	{
		s[i] = s[i - 1];
	}
	s[0] = c;
}

void to_end(char *s, char c)
{
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

int main()
{
	int b1 = 0, b2 = 0;
	scanf("%d%d", &b1, &b2);

	if (b1 < 2 || b1 > 16 || b2 < 2 || b2 > 16)
	{
		printf("bad input\n");
		return EXIT_FAILURE;
	}

	char number[14];
	scanf("%s", number);

    // checking input
	for (int i = 0; i < strlen(number); i++)
	{
		if (number[i] == '.') continue;

		int digit = char_to_int(number[i]);

		if (digit >= b1)
		{
			printf("bad input\n");
			return EXIT_FAILURE;
		}		
	}

	// to decimal
	int point = strchar(number, '.');

	double decimal = 0;
	double power = 1;

	// before point
	for (int i = point - 1; i >= 0; i--)
	{
		decimal += char_to_int(number[i]) * power;
		power *= b1;
	}

	// after point
	power = pow(b1, -1);
	for (int i = point + 1; i < strlen(number); i++)
	{
		decimal += char_to_int(number[i]) * power;
		power /= b1;
	}

	int first = (int)decimal;
	double second = decimal - first;

	char s_first[100], s_second[100];
	s_first[0] = '\0'; s_second[0] = '\0';

	// before point
	while (first > 0)
	{
		to_beginning(s_first, int_to_char(first % b2));
		first /= b2;
	}
	
	// after point
	for (int i = 0; i < 12 && second > 0; i++)
	{
		second *= b2;
		to_end(s_second, int_to_char((int)second));
		second -= (int)second;
	}

	printf("%s.", s_first);
	printf("%s\n", s_second);

	return EXIT_SUCCESS;
}