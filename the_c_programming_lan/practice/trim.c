#include <stdio.h>

int main(){
  char s[] ="hi now test one!";
  int i = 0;
  
  while(s[i] != '\0'){
    if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'){
      s[i] = s[i + 1];
    }
    if(s[i] == '\0'){
      s[i] = '\0';
    }
    i++;
  }
  printf("%s", s);
  return 0;
}
