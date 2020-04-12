#include <stdio.h>


int main(){
	int userNum;
	char userChoice;
	int toContinue = 1;
	int i = 1;
	int boolean = 1;
	
	while(1){
		toContinue = 1;
		i = 1;
		userNum = checkInputInt("Enter a number (1-9):  ", 1, 9);
	    printf("Multiplication table for %d number:\n", userNum);
	
	    for(; i < 11; i++){
		    printf("%d * %d = %d\n", userNum, i, userNum * i);
	    }
	char c;
	
	    while(toContinue){
	    	printf("Press 'Y' to continue, 'N' to exit: ");
	    	scanf("%c%c", &userChoice, &c);
	    	userChoice = toupper(userChoice);
	    	if((userChoice == 'Y' || userChoice == 'N') && c == 13){
	    		break;
			}
		}
if(userChoice == 'N'){
	break;
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

