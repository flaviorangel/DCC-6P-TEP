#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 31

int main(void){
  int primeiraVez;
  int t, i, j;
  char a[100];
  char b[100];
  char c[100];
  char d[100];
  int sinal, cont;

  scanf("%d", &t);
  for(i = 0; i < t; i++){
    cont = 0;
    primeiraVez = 1;
    scanf("%s", a);
    scanf("%s", b);
    do{
      if(!primeiraVez){
        strcpy(a, c);
        strcpy(b, d);
        b[SIZE + cont] = '0';
        b[SIZE + cont + 1] = '\0';
        cont++;
        printf("%s %.31s\n", a, b + cont);
      }
      sinal = 1;
      for(j = 31; j >= 0; j--){
        if(a[j] == b[j + cont]){
          c[j] = '0';
          if(a[j] == '1'){
            d[j] = '1';
            sinal = 0;
          } else {
            d[j] = '0';
          }
        } else {
          c[j] = '1';
          d[j] = '0';
        }
      }
      if(primeiraVez){
        primeiraVez = 0;
      }
    } while((d[0] != '1') || (sinal));
  }
  return 0;
}

//gcc file.c -o test -lm
// ./test
//Git:
//git add .
//git commit -m ""
//git push origin master