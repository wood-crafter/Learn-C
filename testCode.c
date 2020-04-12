#include<stdio.h>
#include<stdlib.h>

int main(){
	char* string;
	char c = '0';
	int i = 0;
	string = (char*) malloc(sizeof(char));
	enterString(string, i);
	printf("%s", string);
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

