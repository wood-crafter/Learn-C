#include <stdio.h>

int main(){
	int userNum;
	int userChoice = 13;
	int toContinue = 1;
	int i = 1;
	
	while(userChoice == 13){
		toContinue = 1;
		i = 1;
		userNum = checkInputInt("Enter a number (1-9):  ", 1, 1000);
	    printf("Multiplication table for %d number:\n", userNum);
	
	    for(; i < 11; i++){
		    printf("%d * %d = %d\n", userNum, i, userNum * i);
	    }
	    
	    while(toContinue){
	    	printf("Press'Enter' to continue, 'ESC' to exit...\n");
            userChoice = getch();
            if(userChoice == 13){
            	toContinue = 0;
			}
			if(userChoice == 27){
				break;
			}
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
