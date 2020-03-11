#include<stdio.h>

int main() {
	int array_Size;
	int new_Value;

	array_Size = checkInputInt("Enter number of elements:  ", 1, 1000);
	int user_Array[array_Size];
	int newArray[array_Size + 1];
	int element;
	
	int i = 0;
	for(; i < array_Size; i++){
		
		printf("Enter element #%d: ", i);
		scanf("%d", &element);
		user_Array[i] = element;
	}
	
	int j = 0;
	for(; j < array_Size; j++){
		int k = 0;
	    for (; k < array_Size - 1; k++){

	    	if(user_Array[k] > user_Array[k + 1]){
	    		int compare = user_Array[k];
	    		user_Array[k] = user_Array[k + 1];
	    		user_Array[k + 1] = compare;
			}
		}
	}
	
	printf("The array after sorting:\n");
	int count = 0;
	for(; count < array_Size; count++)
    {
        printf(" %d ", user_Array[count]);
    }
    count = 0;
    
	new_Value = checkInputInt("\nPlease enter the new value: ", 0, 99999);
	printf("New array: \n");
	
	int g = 0;
	for(;count < array_Size + 1;count++){
		
		if(new_Value > user_Array[g]){
			newArray[count] = user_Array[g];
			g = g + 1;
			
		} else {
			newArray[count] = new_Value;
			new_Value = user_Array[array_Size - 1] + 1;
		}
	}
	g = 0;
	for(;g < array_Size + 1;g++){
		printf("  %d  ", newArray[g]);
	}
	return 0;
}

#include <stdio.h>

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
