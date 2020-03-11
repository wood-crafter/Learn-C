#include <stdio.h>

int main() {
	int arraySize;
	int i = 0;
	
	arraySize = checkInputInt("Enter number of elements:  ", 1, 1000);
	char userArray[arraySize];
	char uniqueArray[arraySize];
	
	for(; i < arraySize; i++){
		printf("Enter element #%d: ", i);
		scanf("%c", &userArray[i]);
		fflush(stdin);
	}
	
	printf("The original array: \n");
	i = 0;
	int uniqueCount = 0;
	for(; i < arraySize; i++){
		printf("%c  ", userArray[i]);
		if(myIndexOf(uniqueArray, uniqueCount, userArray[i]) == -1){
			uniqueArray[uniqueCount] = userArray[i];
			uniqueCount++;
		}
	}
	
	
	    
	i = 0;
	printf("\nThe array after removing duplicate elements: \n");
	for(; i < uniqueCount ; i++){
		printf("%c  ", uniqueArray[i]);
	}
	
	
}

int myIndexOf(char* arr, int size, char value){
	int i = 0;
	for(; i < size; i++){
		if(value == arr[i]){
			return i;
		}
	}
	return -1;
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
