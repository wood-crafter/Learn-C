#include <stdio.h>
#include <string.h>
int main(){
	char* string;
	int i = 0;
	string = (char*) malloc(sizeof(char));
	enterString(string, i);
	int g = strlen(string) / 2 - 3;
	int j = 0;
	for(; j < 5; j++){
		printf("%c", string[g]);
		g += 1;
	}
}
void enterString(char* string, int i){
	i += 1;
    char c;
    scanf("%c", &c);
    string[i - 1] = c;
    string = (char*) realloc(string,(i + 1) * sizeof(char*));
    
    if(c != '\n'){
        enterString(string, i);
    } else{
    	string[i] = NULL;
	}
}
