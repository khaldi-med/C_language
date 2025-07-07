#include <stdio.h>

// #include <stdlib.h>
// #include <string.h>

int	search(int *nums, int numsSize, int target)
{
	int	max;
	int	min;
	int	mid;

	max = numsSize;
	min = 0;
	while (min <= max)
	{
		mid = min + (max - min) / 2;
		if (nums[mid] == target)
			return (mid);
		if (nums[mid] < target)
			min = mid + 1;
		else
			max = mid - 1;
	}
	return (-1);
}

int	main(void)
{
	int	tar;
	int	r;
	int	arr[6];

	arr = {-1, 0, 3, 5, 9, 12};
	tar = 9;
	r = search(arr, 6, tar);
	printf("%d\n", r);
	return (0);
}
