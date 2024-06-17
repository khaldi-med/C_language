#include <stdio.h>

int main(void){
    int i, sum;

    sum = 0;
    for(i = 0; i <=1000; ++i){
	sum += i;
    }
    printf("The sum is: %d\n", sum);
    return 0;
}
