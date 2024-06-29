#include <stdio.h>
#include <string.h>

int atoi(char s[]){
  int i, n;

  i = 0;
  n = 0;
  while(s[i] >= '0' && s[i] <= '9'){
  n = 10 * n + (s[i] - '0');
  ++i;
  }
  return n;
  }

/**
 int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
*/

int main(){
	char s[] = "hello";
	int result = atoi(s);

	printf("the number is : %d\n %d\n",atoi(s), result);
	return 0;
}
