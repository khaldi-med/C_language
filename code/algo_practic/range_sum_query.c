#include <stdio.h>
#include <unistd.h>



int	main(void)
{
	long long	arr[100000];
	long long	sum_tmp[100000] = {0};
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
	sum_tmp[0] = arr[0];
	while (i <= n)
	{
		sum_tmp[i] = sum_tmp[i - 1] + arr[i];
		printf("%lld\n", sum_tmp[i]);
		i++;
	}
	write(1, "\n", 1);
	while (q)
	{
		scanf("%d %d", &l, &r);
		printf("%lld\n", (sum_tmp[r] - sum_tmp[l - 1]));
		q--;
	}
	return (0);
}
