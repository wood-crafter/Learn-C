#include <stdio.h>

int main() {
	int arraySize;
	int oddSum = 0;
	int evenSum = 0;
	int i = 0;
	
	printf("Sum Even Odd program\n");
	arraySize = checkInputInt("Enter number of elements:  ", 1, 1000);
	int userArray[arraySize];
	
	for(; i < arraySize; i++){
	    printf("Enter element #%d: ", i);
	    userArray[i] = checkInputInt(" ", 1, 1000);
	    fflush(stdin);
	}
	
	i = 0;
	for(; i < arraySize; i++){
		if(userArray[i] % 2 == 0){
			evenSum = evenSum + userArray[i];
		} else{
			oddSum = oddSum + userArray[i];
		}
	}
	
	printf("\nSum of even number: %d", evenSum);
	printf("\nSum of odd number: %d", oddSum);
	
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
