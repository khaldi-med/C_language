#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	search(int *nums, int numsSize, int target)
{
	int	max;
	int	min;
	int	mid;

	max = numsSize;
	min = 0;
	while (min <= max)
	{
		mid = max - min / 2;
		if (nums[mid] == target)
			return (mid);
		else if (nums[mid] < target)
			min = mid + 1;
		else
			max = mid - 1;
	}
	return (0);
}

int	main(void)
{
	int	tar;
	int	arr[6];
	int	r;

	arr[6] = {-1, 0, 3, 5, 9, 12};
	tar = 12;
	r = search(arr, 5, tar);
	printf("%d\n", r);
	return (0);
}
