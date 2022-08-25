
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t	random_number()
{
	size_t					random;
	unsigned int			random_ret;
	char					*rdm;

	random_ret = 0; 
	random = (size_t)&rdm;
	if (this_enemy->random)
		random =+ (this_enemy->random + this_enemy->x_pos + this_enemy->y_pos);
	else
		random =+ (this_enemy->x_pos + this_enemy->y_pos);
	rdm = malloc(1);
	if (random < 0)
		random *= -1;
	printf("adresse %ld\n", random);
	if (!rdm)
		return (-1);
	while (random > 9)
	{
		random_ret = random_ret + (random % 10);
		//random_ret = (random_ret % 10) + random_ret;
		random = random / 10;
	}
	while (random_ret > 9)
	{
		random_ret = (random_ret / 10) + (random_ret % 10);
	}
	printf("this enemy->random = %d\n", random_ret);
	free(rdm);
	return (random_ret);
}

int main()
{
	int i = 0;
	size_t result;
	while (i < 100)
	{
	result = random_number();
	printf("%ld", result);
	}
	return (0);
}
