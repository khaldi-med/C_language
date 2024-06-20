#include <stdio.h>
#include <stdlib.h>

int sumRange(int start, int end){
    int i;
    int sum;

    sum = 0;
    i = start;
    while(i < end){
	sum = sum + i;
	i++;
    }
    return sum;
}

int main(int argc, char **argv){
    int start;
    int end;
    if(argc != 3) {
	fprintf(stderr, "Usage: %s\n start end", argv[0]);
	return 1;
    };
    start = atoi(argv[1]);
    end = atoi(argv[2]);

    printf("sumRange(%d, %d) = %d\n", start, end, sumRange(start, end));

    return 0;
}

