#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:


  char arr[5][10000];
  scanf("%s", &arr[0]);
  fflush(stdin);
  scanf("%s", &arr[1]);
  fflush(stdin);
  scanf("%s", &arr[2]);
  fflush(stdin);
  scanf("%s", &arr[3]);
  fflush(stdin);
  scanf("%s", &arr[4]);
  fflush(stdin);
  int i = 0;;
for(; i < 5;i++){
	int j;
	for(;j < 5; j++){
		if(arr[j][0] > arr[j + 1][0]){
			char arr1[10000] = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = arr1;
		}
	}
}

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:


printf("%s ", arr[0]);
printf("%s ", arr[1]);
printf("%s ", arr[2]);
printf("%s ", arr[3]);
printf("%s ", arr[4]);



  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
