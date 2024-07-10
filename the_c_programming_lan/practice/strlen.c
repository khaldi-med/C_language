#include <stdio.h>

int strLength(char s[]){
	int i;

	i = 0;
	while(s[i] != '\0')
		++i;
	return i;
}

int main(){
	int i =	strLength("hello world");
	printf("The length is: %d\n", i);
	return 0;
}


