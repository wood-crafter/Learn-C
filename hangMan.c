#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int checkLetter(char userGuess, char* wordToGuess, char* guessedLetter, int numOfLetter);
void showPuzzle(char userGuess, char* puzzle, char* wordToGuess);
int randWordIndex(int* blackList, int wordCount, int playTimes);

int main(){
	int WORD_SIZE = 10 * sizeof(char);
    int userChoice = 13;
    int toContinue = 1;
    char userGuess;
    char guessedLetter[26];
    char fileName[21];
    int incorrectNum = 0;
    int numOfLetter = 0;
    char puzzle[20];
    int wordCount = 0;
    int wordListSize = 1;
    char **wordList;
    
    wordList = (char**) malloc(wordListSize * WORD_SIZE);
    
    printf("What file stores the puzzle words?\n");
    scanf("%20[^\n]", fileName);
    FILE *file;
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Sorry, we couldn't find your stored file!");
        return 0;
	}

//TODO: read wordList from file
while(1){
    	wordList[wordCount] = malloc(WORD_SIZE);
    	if (fscanf(file, "%s", wordList[wordCount]) == EOF) {
    		break;
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
  	
  	while(userChoice == 13){
  		toContinue = 1;
  		while(toContinue){
  			printf("Press Enter to play, press ESC to exit\n");
  			userChoice = getch();
  			if (userChoice == 13)
                toContinue = 0;
            if (userChoice == 27)
                break;
        }
        int indexWord = randWordIndex(blackList, wordCount, playTimes);
        playTimes += 1;
        int boolen = 1;
        int k = 0;
        for(; k < strlen(wordList[indexWord]); k++){
        	puzzle[k] = '-';
		}
        
        //TOFIX: HAVE TO GUESS 2 times for 1 same latter
        while(boolen){
        	printf("Enter your guess: ");
            userGuess = getch();
            printf("%c\n", userGuess);
            int check = checkLetter(userGuess, wordList[indexWord], guessedLetter, numOfLetter) == 2;
            if(check == 0){
        	    incorrectNum += 1;
        	    numOfLetter += 1;
        	    guessedLetter[numOfLetter - 1] = userGuess;
        	
        	    printf("\nSorry, the letter is NOT in the puzzle\n");
        	    printf("You currently have %d incorrect guesses!\n", incorrectNum);
        	    printf("Here is your puzzle:\n");
        	    printf("%s\n", puzzle);
		    }
		
		    if(check == 1){
                numOfLetter += 1;
            	guessedLetter[numOfLetter - 1] = userGuess;
            
                showPuzzle(userGuess, puzzle, wordList[indexWord]);
	    	}
		
		    if(check == 2){
		    	incorrectNum += 1;
            	printf("Sorry, you have guessed that letter already\n");
            	printf("Now it count a miss!");
            	printf("You currently have %d incorrect guesses!\n", incorrectNum);
            	printf("Here is your puzzle:\n");
            	printf("%s", puzzle);
        	
	    	}
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
	int i = 0;
	
	for(; i < numOfLetter ; i++){
		if(userGuess == guessedLetter[i]){
			return 2;
		}
	}
	
	i = 0;
	for(; i < 11; i++){
		if(userGuess == wordToGuess[i]){
			return 1;
		}
	}
	
	return 0;
}

//TOFIX: inform
void showPuzzle(char userGuess, char* puzzle, char* wordToGuess){
	int i = 0;
	
	for(; i < 11; i++){
		if(userGuess == wordToGuess[i]){
			puzzle[i] = wordToGuess[i];
		}
	}
    printf("\nHere is your puzzle:\n");
    printf("%s\n", puzzle);
}

