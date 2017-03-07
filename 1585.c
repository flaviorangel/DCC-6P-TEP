#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80

int main(void){
  int numTests;
  char palavra[SIZE];
  int score;
  int acc;
  int i,j;

  scanf("%d", &numTests);
  for(i = 0; i < numTests; i++){
    score = 0;
    acc = 0;
    scanf("%s", palavra);
    for(j = 0; j < strlen(palavra); j++){
      if (palavra[j] == 'O'){
        score = score + 1 + acc;
        acc = acc + 1;
      } else {
        acc = 0;
      }
    }
    printf("%d\n", score);
  }
  return 0;
}

//gcc file.c -o test -lm
// ./test