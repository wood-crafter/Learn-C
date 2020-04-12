#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int checkLetter(char userGuess, char* wordToGuess, char* guessedLetter, int numOfLetter);
void showPuzzle(char userGuess, char* puzzle, char* wordToGuess);
int randWordIndex(int* blackList, int wordCount, int playTimes);
int checkInputInt(char* msg, int MIN, int MAX);
int isBadWord(char* word);
void appendFile(char* fileName, char* content) {
    FILE *file;
    file = fopen(fileName, "a");
    fprintf(file, "%s\n", content);
	fclose(file);
}

int main() {
	int WORD_SIZE = 15 * sizeof(char);
    int userChoice = 13;
    int toContinue = 1;
    char userGuess;
    char fileName[21];
    int incorrectNum = 0;
    int numOfLetter = 0;
    char puzzle[20];
    int wordCount = 0;
    int wordListSize = 1;
    char **wordList;
    char method;
    
    while(1){
    	printf("Press '0' to add word to file, '1' to play hangman: \n");
        method = getch();
        fflush(stdin);
        if(method == '0' || method == '1'){
        	break;
		}
	}
    
    switch(method){
    	
    	//Add word to File
    	case '0': {
    	    char fileName[21];
    	    printf("Enter your file name: \n");
    	    scanf("%20[^\n]", fileName);
    	    fflush(stdin);
    	
    	    while(userChoice == 13){
    		    toContinue = 1;
    		    char newWord[15];
    		    printf("Enter a word: ");
    		    scanf("%20[^\n]", newWord);
    		    fflush(stdin);

    		    if (isBadWord(newWord)) {
    		    	printf("%s is not a valid word, please try again\n", newWord);
    		    	continue;
				}

				appendFile(fileName, newWord);

            	while(toContinue) {
  					printf("\nPress 'Enter' to add more word, 'ESC' to exit: \n");
  					userChoice = getch();
  	    			if (userChoice == 13)
                		toContinue = 0;
            		if (userChoice == 27)
                		break;
            	}
			}
			break;
		}
		
		//Play hangman
		case '1': {
			
			wordList = (char**) malloc(wordListSize * WORD_SIZE);
    
    		printf("What file stores the puzzle words?\n");
    		scanf("%20[^\n]", fileName);
    		fflush(stdin);
    		FILE *file;
    		file = fopen(fileName, "r");
    		if (file == NULL) {
        		printf("Sorry, we couldn't find your stored file!");
        		return 0;
			}
    

// read wordList from file
			while(1){
    			wordList[wordCount] = malloc(WORD_SIZE);
    			if (fscanf(file, "%[^\n]\n", wordList[wordCount]) == EOF) {
    				fflush(stdin);
    				break;
				}
                
                if (isBadWord(wordList[wordCount])) {
                	printf("The file contains bad format word at line %d", wordCount + 1);
                	return -1;
				}

    			wordCount += 1;

    			if(wordCount == wordListSize){
    				wordListSize *= 2;
    				wordList = (char**) realloc(wordList, wordListSize * sizeof(char*));
				}
			}

    		int blackList[wordCount];
    		int playTimes;
    		srand(time(0));

            //rand a new word
  			while(userChoice == 13){
  				toContinue = 1;
        		int indexWord = randWordIndex(blackList, wordCount, playTimes);
        		playTimes += 1;
        		int boolen = 1;
        		int k = 0;
        		char* guessedLetter = calloc(26, sizeof(char));
        		for(; k < strlen(wordList[indexWord]); k++){
        			puzzle[k] = '-';
				}
				puzzle[k] = '\n';
				k = 0;
				printf("Here is your puzzle:\n");
        	    printf("%s\n", puzzle);
        
                //Play
        		while(boolen){
        			printf("Enter your guess: ");
            		userGuess = getch();
            		printf("%c\n", userGuess);
            		int check = checkLetter(userGuess, wordList[indexWord], guessedLetter, numOfLetter);
            		if(check == 0){
        	    		incorrectNum += 1;
        	    		numOfLetter += 1;
        	    		guessedLetter[numOfLetter - 1] = userGuess;
        	
        	    		printf("\nSorry, the letter is NOT in the puzzle\n");
        	    		printf("You currently have %d incorrect guesses!\n", incorrectNum);
        	    		if(incorrectNum == 5){
            				printf("The puzzle was %s\n", wordList[indexWord]);
            				printf("Game over!");
            				return 0;
						}
        	    		printf("Here is your puzzle:\n");
        	    		printf("%s\n", puzzle);
		    		}
		
		    		if(check == 1){
		    			int length = strlen(puzzle);
                		numOfLetter += 1;
            			guessedLetter[numOfLetter - 1] = userGuess;
            			printf("Congratulation, you have guessed the right letter in puzzle!\n");
            			printf("You currently have %d incorrect guesses!\n", incorrectNum);
            
                		showPuzzle(userGuess, puzzle, wordList[indexWord]);
                		for(; k < length; k++){
                			if(puzzle[k] == '-'){
                			k = length - 1;
                			continue;
						}
						if(k == length - 1){
							printf("Congratulation, you got the correct word %s\n\n\n", wordList[indexWord]);
							boolen = 0;
						}
						}
						k = 0;
	    			}
		
		    		if(check == 2){
		    			incorrectNum += 1;
            			printf("Sorry, you have guessed that letter already\n");
            			printf("Now it count a miss!\n");
            			printf("You currently have %d incorrect guesses!\n", incorrectNum);
            			if(incorrectNum == 5){
            				printf("The puzzle was %s\n", wordList[indexWord]);
            				printf("Game over!");
            				return 0;
						}
            			printf("Here is your puzzle:\n");
            			printf("%s", puzzle);
        	
	    			}
				}
		
		        //Enter to play
				while(toContinue){
  					printf("Press Enter to play, press ESC to exit\n");
  					userChoice = getch();
  	    			if (userChoice == 13)
            		    toContinue = 0;
          		  if (userChoice == 27)
             		   break;
       		 	}
			}
        	break;
        }
    }
			
}

int randWordIndex(int* blackList, int wordCount, int playTimes){
	int random;
	int i;
	int boolen = 1;
	
	while(boolen){
		boolen = 0;
		i = 0;
		random = rand() % wordCount + 0;
		for(; i < playTimes + 1; i++){
			if(random == blackList[i]){
				boolen = 1;
			}
		}	
	}
	blackList[playTimes] = random;
	return random;
}

int checkLetter(char userGuess, char* wordToGuess, char* guessedLetter, int numOfLetter) {
	int length = strlen(wordToGuess);
	int i = 0;
	
	for(; i < numOfLetter ; i++){
		if(userGuess == guessedLetter[i]){
			return 2;
		}
	}
	
	i = 0;
	for(; i < length; i++){
		if(userGuess == wordToGuess[i]){
			return 1;
		}
	}
	
	return 0;
}

int isBadWord(char* word) {
	int i = 0;

    for(i; i < strlen(word); i++){
    	char c = word[i];
    	int isUpperChar = 65 <= c && c <= 90;
    	int isLowerChar = 97 <= c && c <= 122;
    	
    	if (!isUpperChar && !isLowerChar) {
    		return -1;
		}
	}

	return 0;
}

void showPuzzle(char userGuess, char* puzzle, char* wordToGuess){
	int length = strlen(wordToGuess);
	int i = 0;
	
	for(; i < length; i++){
		if(userGuess == wordToGuess[i]){
			puzzle[i] = wordToGuess[i];
		}
	}
    printf("\nHere is your puzzle:\n");
    printf("%s\n", puzzle);
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

