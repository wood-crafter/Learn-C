#include <stdio.h>
#include<Windows.h>
#include<string.h>


int main(){
	char userChoice = 13;
	
	while(userChoice == 13){
	
    	char* userString;
    	int StringSize = 0;
    	printf("Enter string: ");
    	userString = (char*) malloc(sizeof(char));
	    enterString(userString, StringSize);
	    StringSize = strlen(userString) - 1;
	    
	    char reservedString[StringSize];
	
	    int i = 0;
	    for(; i < StringSize 	; i++){
	    	if(userString[StringSize - i - 1] > 64 && userString[StringSize - i - 1] < 91){
	    		reservedString[i] = userString[StringSize - i - 1] + 32;
			} 
			else if(userString[StringSize - i - 1] > 96 && userString[StringSize - i - 1] < 123){
				reservedString[i] = userString[StringSize - i - 1] - 32;
			} else{
				reservedString[i] = userString[StringSize - i - 1];
			}
	    }
	    reservedString[StringSize] = NULL;
	    
	    printf("The old string: %s\n", userString);
	    printf("The reserved string: %s", reservedString);	
	    
	    int toContinue = 1;
	    while(toContinue){
	    	printf("\nPress Enter to continue reserved, press ESC to exit...\n");
		    userChoice = getch();
		    if(userChoice == 13) toContinue = 0;
		    if(userChoice == 27) break;
	    }
	}
	
	return 0;
	
}



void enterString(char* string, int StringSize){
	StringSize += 1;
    char c;
    scanf("%c", &c);
    string[StringSize - 1] = c;
    string = (char*) realloc(string,(StringSize + 1) * sizeof(char));
    
    if(c != '\n'){
        enterString(string, StringSize);
    } else{
    	string[StringSize] = NULL;
	}
	
}

