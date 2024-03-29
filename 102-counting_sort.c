#include "sort.h"

/**
 * get_max - Get maximum value in array of integers
 * @array: array of integers.
 * @size: size t he array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max = 0;
	size_t k;

	if (array == NULL || size == 0)
		return max;

	for (k = 0; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}

	return (max);
}

/**
 * counting_sort - Sort array of integers in ascending order
 *                 using the counting sort algo.
 * @array: array of integers.
 * @size: The size of array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted;
	int max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);

}

/**
 * John Mbithi Mutave and Victor Mburu
 * jellyjones-pixel
*/
