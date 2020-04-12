#include <stdio.h>

int main() {
	int i = 0;
	
	
	char* userArray;
    int arraySize = 0;
    printf("Enter string: ");
    userArray = (char*) malloc(sizeof(char));
	enterString(userArray, arraySize);
	arraySize = strlen(userArray) - 1;
	
	
	char uniqueArray[arraySize];
	printf("The original array: \n");
	i = 0;
	int uniqueCount = 1;
	uniqueArray[0] = userArray[0];
	
	for(; i < arraySize; i++){
		int j = 0;
		printf("%c ", userArray[i]);
		
		for(; j < uniqueCount ; j++){
			if(uniqueArray[j] == userArray[i]){
				break;
			} else if(j == uniqueCount - 1){
				uniqueArray[uniqueCount] = userArray[i];
				uniqueCount += 1;
			}
		}
	}
	
	
	    
	i = 0;
	printf("\nThe array after removing duplicate elements: \n");
	for(; i < uniqueCount ; i++){
		printf("%c ", uniqueArray[i]);
	}
	
	
}


int checkInputInt(char* msg, int MIN, int MAX) {
    int num, check;
    char ch;

    while (1) {
        printf("%s", msg);

        check = scanf("%d%c", &num, &ch);
        
        if (check != 2 || ch != '\n') {
            printf("Invalid input, please enter integer only\n");

            // Clear the buffer
            // while ((getchar()) != '\n'); 
            fflush(stdin);
            continue;
        }

        if (num < MIN || MAX < num) {
            printf("Out of range, please enter integer between %d and %d\n", MIN, MAX);
            continue;
        }

        return num;
    }
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

