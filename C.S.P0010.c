#include <stdio.h>

int main() {
	int arraySize;
	int numOfDuplicate = 0;
	int i = 0;
	
	arraySize = checkInputInt("Enter number of elements:  ", 1, 1000);
	char userArray[arraySize];
	
	for(; i < arraySize; i++){
		printf("Enter element #%d: ", i);
		scanf("%c", &userArray[i]);
		fflush(stdin);
	}
	
	i = 0;
//	for(; i < arraySize; i++) {
//		int j = 0;
//		for(; j < arraySize ; j++) {
//			if(j != i && userArray[i] == userArray[j]){
//				numOfDuplicate = numOfDuplicate + 1;
//			}
//		}
//	}
//	numOfDuplicate = numOfDuplicate / 2;
	
	printf("The original array: \n");
	i = 0;
	for(; i < arraySize; i++){
		printf("%c  ", userArray[i]);
	}
	
	char newArray[arraySize - numOfDuplicate];
	i = 1;
	newArray[0] = userArray[0];
	for(; i < arraySize; i++) {
		int j = 0;
		
		for(; j < arraySize - numOfDuplicate; j++){
		    if(userArray[i] == newArray[j]){
		    	break;
			} else if(j == arraySize - numOfDuplicate - 1){
				newArray[j] = userArray[i];
			}
    	    
		}
	}
	    
	i = 0;
	printf("\nThe array after removing duplicate elements: \n");
	for(; i < arraySize - numOfDuplicate; i++){
		printf("%c  ", newArray[i]);
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
