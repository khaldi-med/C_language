#include <stdio.h>
#include <string.h>

void reverse(char s[]){
    int i, j, temp;

    i = 0;
    j = strlen(s) -1;
    temp = 0;

    while( i < j){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main(){
    char s[] = "hello";
    reverse(s);
    printf("%s", s);
    return 0;

}
