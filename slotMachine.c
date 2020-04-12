#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int delay();
float checkNumber(number);

int main()
{
	
  char userName[21];
  float userMoney;
  float fee = 0.25;
  int randomNumber;
  char userChoice = 13;
  int toContinue = 1;
  FILE *file;

  srand(time(0));

  while(userChoice == 13){
  	toContinue = 1;
  	  printf("Enter your name: ");
  	  fflush(stdin);
      scanf("%20[^\n]", userName);

      file = fopen(userName, "r");
      if (file != NULL) {
  	    if(fscanf(file, "%s %f", userName, &userMoney) == 2){
  		    printf("You have %f$", userMoney);
  		    userChoice = 1;
	      }

//FIXED: File not follow format
		  else{
	      	
	  	    printf("Invalid file format!\n");
	  	    
	  	    while(toContinue){
	  	    	printf("Press 'Enter' to re-enter name, press 'ESC' to exit:\n");
	  	        userChoice = getch();
	  	    
                if (userChoice == 13){
                	toContinue = 0;
				}
        
                if (userChoice == 27)
                    return 0;
			}
        }
	    }
	    
//New player
	  else {
  	      userMoney = 10.0;
          printf("We will offer you %f$ at the beginning!", userMoney);
          userChoice = 1;
      }
  }
  
  rand() % 100 + 1;
  delay(500);
  system("cls");
  printf("Welcome %s!", userName);
  delay(700);
  system("cls");
  printf("This is Slot Machine...!");
  delay(700);
  system("cls");

  delay(700);
  system("cls");
  printf("Good luck...!");
  delay(700);
  system("cls");
  userChoice = 13;
  while (userMoney > 0){
  	
    while (userChoice == 13){
    	
    	toContinue = 1;

        while (toContinue){
        	
        printf("You have %f$\n", userMoney);
        printf("Press'Enter' to play, 'ESC' to exit...\n");
        userChoice = getch();
        if (userChoice == 13)
          toContinue = 0;
        if (userChoice == 27)
          break;
        }

// -> rand a number
        if(userChoice == 13){
        	randomNumber = rand() % 1000 + 1;
            userMoney += checkNumber(randomNumber);
//FIXED: Save right after here
        file = fopen(userName, "w+");
        fprintf(file, "%s %f\n", userName, userMoney);
        fclose(file);
		}

        printf("The number is %d\n", randomNumber);

        if (userMoney <= 0){
        	
        printf("Sorry, you have not enough money to play!");
        userChoice = 0;
        delay(500);
        }
    }

//cash out
    printf("\n\nYou have %f", userMoney);
    printf("\nThank you for play slot machine!");
    


    break;
  }
  
  return 0;
  
}

int delay(time){
	
  int c, d;
  for (c = 1; c <= 50 * time; c++){
  	for (d = 1; d <= 50 * time; d++){
	  }
  }
    
    

  return 0;
}

float checkNumber(number){
	
  int a;
  int b;
  int c;

  a = number / 100;
  b = (number - 100 * a) / 10;
  c = (number - 100 * a - 10 * b);

  if (a == b && a == c){
  	
    printf("\nCongratulation! you won...\n");
    return 9.75;
  }
  
  else if (a == b || a == c || b == c){
  	
    printf("\nCongratulation! you won...\n");
    return 0.25;
  }

  printf("\nSorry, you have not won!\n");
  return -0.25;
}
