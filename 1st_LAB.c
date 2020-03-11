#include <stdio.h>
#include<Windows.h>


int main(){
	int arraySize;
	char userChoice = 13;
	
	while(userChoice == 13){
		
	    arraySize = checkInputInt("Enter number of elements in array: ", 1, 2147483647);
	
    	char userString[arraySize];
	    char reservedString[arraySize];
	    printf("Enter your string: ");
	    scanf("%s", userString);
	
	    int i = 0;
	    for(; i < arraySize; i++){
		    reservedString[i] = userString[arraySize - i - 1];
	    }
	
	    printf("The old string: %s\n", userString);
	    printf("The reserved string: %s\n", reservedString);	
	    
	    int toContinue = 1;
	    while(toContinue){
	    	printf("Press Enter to continue reserved, press ESC to exit...\n");
		    userChoice = getch();
		    if(userChoice == 13) toContinue = 0;
		    if(userChoice == 27) break;
	    }
	}
	
	return 0;
	
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
