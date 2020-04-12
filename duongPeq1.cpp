#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:

  

   char* userString;
    	int StringSize = 0;
    	printf("Enter string: ");
    	userString = (char*) malloc(sizeof(char));
	    enterString(userString, StringSize);
	    StringSize = strlen(userString) - 1;
	    
	    char reservedString[StringSize];
	
	    int i = 0;
	    for(; i < StringSize 	; i++){
		    reservedString[i] = userString[StringSize - i - 1];
	    }
	    reservedString[StringSize] = NULL;

  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
printf("%s", reservedString);






  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
