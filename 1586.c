#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OXI 16.000
#define CARB 12.010
#define HID 1.000
#define NIT 14.010

int main(void){
  int t;
  int qnt;
  char palavra[SIZE];
  float mol;
  int i,j;

  scanf("%d", &t);
  for(i = 0; i < t; i++){
    scanf("%s", palavra);
    for(j = 0; j < strlen(palavra); j++){
      if (palavra[j] >= 48 && palavra[j] <= 57){
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
//Git:
//git add .
//git commit -m ""
//git push origin master