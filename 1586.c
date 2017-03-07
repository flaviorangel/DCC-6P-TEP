#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OXI 16.000
#define CARB 12.010
#define HID 1.000
#define NIT 14.010

int main(void){
  int t;
  int qnt = 1;
  float peso = 0;
  char palavra[SIZE];
  float mol = 0;
  int i,j;
  char numero[2];
  int sinal = 0;
  int proximaNum = 0;

  scanf("%d", &t);
  for(i = 0; i < t; i++){
    scanf("%s", palavra);
    for(j = 0; j < strlen(palavra); j++){
      proximaNum = 0;
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
        proximaNum = 1;
      }
      if(!proximaNum){
        mol = mol + peso;
      } else {
        j++;
        if((j + 1 < strlen(palavra)) && (palavra[j + 1] >= 48) && (palavra[j + 1] <= 57)){
          proximaNum = 1;
          numero[0] = palavra[j];
          numero[1] = palavra[j + 1];
          qnt = atoi(numero);
          j++;
        }
      }
      }













      proximaNum = 0;
      if(palavra[j + 1] >= 48 && palavra[j + 1] <= 57){
        proximaNum = 1;
      }
      if(palavra[j] >= 48 && palavra[j] <= 57){
        if((j + 1 < strlen(palavra)) && (proximaNum)){
          
          j = j + 1;
          sinal = 1;
        } else {
          qnt = atoi(palavra[j]);
          sinal = 1
        }
      } else {
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
        if(proximaNum){

        }
      }
      if(sinal){
        mol = mol + qnt*peso;
        sinal = 0;
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