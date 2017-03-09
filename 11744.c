#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 31

int main(void){
  int t, i, j;
  char a[100];
  char b[100];
  char c[100];
  char d[100];
  int jzero = 0;
  int pararWhile = 0;

  scanf("%d", &t);
  for(i = 0; i < t; i++){
    scanf("%s", a);
    scanf("%s", b);
    strcpy(d, b);
    do{
      strcpy(b, d);
      printf("%s %s\n", a, b);
      for(j = 30; j <= 0; j--){
        puts("entrou no for");
        if(j == 0){
          jzero = 1;
        }
        if(a[j] == b[j]){
          a[j] = '0';
          if(a[j] == '1'){
            if(jzero){
              jzero = 0;
              pararWhile = 1;
              printf("%s overflow\n", a);
              continue;
            }
            d[j - 1] = '1';
          } else {
            if(jzero){
              jzero = 0;
              continue;
            }
            d[j - 1] = '0';
          }
        } else {
          a[j] = '1';
          if(jzero){
            jzero = 0;
            continue;
          }
          d[j - 1] = '0';
        }
        //printf("a[%d] = %c AND b[%d] = %c\nc[%d] = %d AND d[%d] = %d\n", j, a[j], j, b[j], j, c[j], j, d[j]);
      }
      //getchar(); //para fazer uma etapa por vez
    } while(continuar);
  }
  return 0;
}

//gcc file.c -o test -lm
// ./test
//Git:
//git add .
//git commit -m ""
//git push origin master