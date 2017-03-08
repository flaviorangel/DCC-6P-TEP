#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int i, t, a, b, c, d;
  int teste = 0x8000;
  char x[32];
  char y[32];

  scanf("%d", &t);
  for(i = 0; i < t; i++){
    scanf("%s", x);
    scanf("%s", y);
    printf("x = %s\n", x);
    printf("y = %s\n", y);
  }
  return 0;
}

//gcc file.c -o test -lm
// ./test
//Git:
//git add .
//git commit -m ""
//git push origin master