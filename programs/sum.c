#include <stdio.h>
#include <stdlib.h>

int sumRange(int start, int end){
    int i;
    int sum;

    sum = 0;
    while(i < end){
	sum += 1;
	++i;
    }
    return sum;
}

int main(int argc, char **argv){
  int start
int end
    if(argc != 3){
	puts("The argements is not enogh try agin with 3 argements.");
    }
    start = atoi(argv[0]);
    end = atoi(argv[1]);
    pritnf("SumRange(%d, %d) = %d\n", start, end, sumRange(start, end));
    return 0;
}

