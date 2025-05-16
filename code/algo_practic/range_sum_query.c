#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long	arr[100000];
long long	sum_tmp[100000];

int	main(void)
{
	long long	i;

	int n, q, l, r;
	scanf("%d %d", &n, &q);
	i = 0;
	while (i < n)
	{
		scanf("%lld", &arr[i]);
		// 		printf("%lld", arr[i]);
		i++;
	}
	i = 1;
	while (i <= n)
	{
		sum_tmp[i] += arr[i - 1];
		printf("\n%lld\n", sum_tmp[i]);
		i++;
	}
	while (q)
	{
		scanf("%d %d", &l, &r);
		printf("%lld\n", (sum_tmp[r]));
		q--;
	}
	return (0);
}
