#include <stdio.h>

int	ft_calculator(int number1, int number2)
{
	int	result;

	result = 0;
	if (number1 != '\0' || number2 != '\0')
	{
		result = (number1 + number2);
	}
	return (result);
}

int main(void)
{
	int	number1 = 10;
	int	number2 = 50;

	printf ("Girilen iki sayının toplamı: %d", ft_calculator(number1, number2));
	printf ("\n");
	return (0);
}