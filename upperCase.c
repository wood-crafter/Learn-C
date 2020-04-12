#include<stdio.h>
#include<string.h>

char* upperCase();
int main(){
	char* string[3];
//	scanf("%4[^\n]", string);
	gets(string);
//	printf("%s", string);
	printf("%s", upperCase(string));
}

char* upperCase(char* string){
	int i = 0;
	for(; i < strlen(string); i++){
		if(string[i] > 96 && string[i] < 123){
			string[i] =  string[i] - 32;
		}
	}
	return string;
}
