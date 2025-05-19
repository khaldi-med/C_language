---
title: Untitled doc (3)
---
<SwmSnippet path="/code/algo_practic/range_sum_query.c" line="1">

---

&nbsp;

```c
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
	while (i <= n)
	{
		sum_tmp[i] = sum_tmp[i] + arr[i - 1];
		printf("%lld\n", sum_tmp[i]);
		i++;
	}
	write(1, "\n", 1);
	while (q)
	{
		scanf("%d %d", &l, &r);
		printf("%lld\n", (sum_tmp[r]) - sum_tmp[l - 1]);
		q--;
	}
	return (0);
}
```

---

</SwmSnippet>

<SwmMeta version="3.0.0" repo-id="Z2l0aHViJTNBJTNBQ19sYW5ndWFnZSUzQSUzQWtoYWxkaS1tZWQ=" repo-name="C_language"><sup>Powered by [Swimm](https://app.swimm.io/)</sup></SwmMeta>
