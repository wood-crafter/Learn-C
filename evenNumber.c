#include <stdio.h>

int main(){
	int arraySize;
	
	arraySize = checkInputInt("Enter size of an array:  ", 1, 1000);
	int userArray[arraySize];
	
	int i = 0;
	printf("\nEnter element:\n");
	for(; i < arraySize; i++){
		userArray[i] = checkInputInt("\n ", 1, 1000);
	}
	
	int max = userArray[0];
	i = 1;
	for(; i < arraySize; i++){
		if(userArray[i] > max){
			max = userArray[i];
		}
	}
	printf("Array maximium value: %d\n", max);
	
	printf("Array even value: \n");
	i = 0;
	for(; i < arraySize; i++){
		if(userArray[i] % 2 == 0){
			printf("%d  ", userArray[i]);
		}
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
