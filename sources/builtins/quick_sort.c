
#include "minishell.h"

/* static unsigned int	partition(char **array, unsigned int left, unsigned int right)
{
	unsigned int	i;
	unsigned int	j;
	char	*tmp;
	char	*pivot;

	pivot = array[right];
	i = left - 1;
	j = left;
	while (j <= right -1)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = pivot;
	array[right] = array[i];
	array[i] = tmp;
	return(i);
} */

static int	partition(char **array, int left, int right)
{
	int		i;
	int		j;
	char	*pivot;
	char	*temp;

	pivot = array[left];
	i = left;
	j = left + 1;
	while (j <= right)
	{
		if (ft_strcmp(pivot, array[j]) > 0)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = pivot;
	array[left] = array[i];
	array[i] = temp;
	return (i);
}

void	quick_sort(char **array, unsigned int left, unsigned int right)
{
	unsigned int	pivot_i;

	if (left < right)
	{
		pivot_i = partition(array, left, right);
		quick_sort(array, left, pivot_i - 1);
		quick_sort(array, pivot_i + 1, right);
	}
}
