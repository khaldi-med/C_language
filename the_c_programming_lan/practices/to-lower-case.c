#include <stdio.h>

int main(void){
    char a[] = "HELLO";
    int i;
    for(i = 0; a[i] != '\0'; i++)
        printf("%c", a[i] < 'a' ? a[i] + 32 : a[i]);
    return 0;
}
