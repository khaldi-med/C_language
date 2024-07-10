#include <stdio.h>

void sameChar(char s[], int c){
	int i, j;

	i = 0;
	j = 0;
	while(s[i] != '\0'){
		if(s[i] != c){
			s[j++] = s[i];
		}
		i++;

	}
	s[j] = '\0';
}
int main(){
	char s[] = "hellooo";
	char c = 'o';
	sameChar(s, c);
	printf("%s", s);
	return 0;
}
        
