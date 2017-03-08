#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OXI 16.000
#define CARB 12.010
#define HID 1.008
#define NIT 14.010
#define SIZE 80

int main(void){
  int t;
  int qnt;
  float peso = 0;
  char palavra[SIZE];
  float mol = 0;
  int i,j;
  char numero[3];

  scanf("%d", &t);
  for(i = 0; i < t; i++){
    mol = 0;
    scanf("%s", palavra);
    for(j = 0; j < strlen(palavra); j++){
      qnt = 1;
      switch(palavra[j]){
        case 'O':
          peso = OXI;
          break;
        case 'C':
          peso = CARB;
          break;
        case 'H':
          peso = HID;
          break;
        case 'N':
          peso = NIT;
          break;
      }
      if((j + 1 < strlen(palavra)) && (palavra[j + 1] >= 48) && (palavra[j + 1] <= 57)){
        j++;
        if((j + 1 < strlen(palavra)) && (palavra[j + 1] >= 48) && (palavra[j + 1] <= 57)){
          numero[0] = palavra[j];
          numero[1] = palavra[j + 1];
          numero[2] = '\0';
          qnt = atoi(numero);
          j++;
        } else {
          numero[0] = palavra[j];
          numero[1] = '\0';
          qnt = atoi(numero);
        }
        mol = mol + peso*qnt;
      } else {
        mol = mol + peso;
      }
    }
    printf("%.3f\n", mol); 
  }
  return 0;
}

//gcc file.c -o test -lm
// ./test
//Git:
//git add .
//git commit -m ""
//git push origin master