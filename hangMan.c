#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkLetter(char userGuess, char* wordToGuess, char* guessedLetter, int numOfLetter);
void showPuzzle(char userGuess, char* puzzle, char* wordToGuess);

int main(){
	int WORD_SIZE = 10 * sizeof(char);
    int userChoice = 13;
    int toContinue = 1;
    char userGuess;
    char guessedLetter[26];
    char fileName[21];
    int numOfLetter = 0;
    int incorrectNum = 0;
    char wordToGuess[20];
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

	int j = 0;
	for(;j < wordCount;j++){
		printf("%s", wordList[j]);
	}
	return 0;
//TODO: rand index from wordList
//TODO: Add this index to blackList

//Read again
//if(fscanf(file, "%s", c) == EOF){
//	printf("End of file");
//}
//  	fscanf(file, "%s", wordList);

// TODO: Read the File - Get word
  	
  	while(userChoice == 13){
  		toContinue = 1;
  		while(toContinue){
  			printf("Press Enter to play, press ESC to exit");
  			userChoice = getch();
  			if (userChoice == 13)
                toContinue = 0;
            if (userChoice == 27)
                break;
        }
        
        //TODO: Let user play
        printf("Enter your guess: ");
        userGuess = getch();
        if(checkLetter(userGuess, wordToGuess, guessedLetter, numOfLetter) == 0){
        	incorrectNum += 1;
        	numOfLetter += 1;
        	guessedLetter[numOfLetter - 1] = userGuess;
        	
        	printf("Sorry, the letter is NOT in the puzzle\n\n");
        	printf("You currently have %d incorrect guesses!\n", incorrectNum);
        	printf("Here is your puzzle:\n");
        	printf("%s", puzzle);
		}
		
		if(checkLetter(userGuess, wordToGuess, guessedLetter, numOfLetter) == 1){
            numOfLetter += 1;
        	guessedLetter[numOfLetter - 1] = userGuess;
            
            showPuzzle(userGuess, puzzle, wordToGuess);
		}
		
		if(checkLetter(userGuess, wordToGuess, guessedLetter, numOfLetter) == 2){
			incorrectNum += 1;
        	printf("Sorry, you have guessed that letter already\n");
        	printf("Now it count a miss!");
        	printf("You currently have %d incorrect guesses!\n", incorrectNum);
        	printf("Here is your puzzle:\n");
        	printf("%s", puzzle);
        	
		}
		
	}
    
    

}

int checkLetter(char userGuess, char* wordToGuess, char* guessedLetter, int numOfLetter) {
	int wordLength = strlen(wordToGuess);
	int i = 0;
	
	for(; i < numOfLetter; i++){
		if(userGuess == guessedLetter[i]){
			return 2;
		}
	}
	
	for(; i < wordLength; i++){
		if(userGuess == wordToGuess[i]){
			return 1;
		}
	}
	
	return 0;
}

//TOFIX: inform
void showPuzzle(char userGuess, char* puzzle, char* wordToGuess){
	int wordLength = strlen(wordToGuess);
	int i = 0;
	
	for(; i < wordLength; i++){
		if(userGuess = wordToGuess[i]){
			puzzle[i] = wordToGuess[i];
		}
	}
    printf("Here is your puzzle:\n");
    printf("%s", puzzle);
}

