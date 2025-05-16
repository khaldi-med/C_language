#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long	arr[100000];
int	main(void)
{
	long long	i;
	long long	sum;

	int n, q, l, r;
	scanf("%d", "%d", &n, &q);
	i = 0;
	while (++i <= n)
	{
		scanf("%lld", &arr[i]);
	}
	i = 0;
	sum = 0;
	scanf("%d", "%d", &l, &r);
	while (l <= r)
	{
		sum += arr[i];
		i++;
		l++;
	}
	printf("%lld\n", sum);
	return (0);
}
