#include <stdio.h>

void    ft_swap(int *a, int *b){
    
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 5;
    int b = 63;
    printf("after => a is: %d b is: %d\n", a, b);
    ft_swap(&a, &b);    
    printf("befor => a is: %d b is: %d\n", a, b);
    return 0;
}
