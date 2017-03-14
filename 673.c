#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

typedef struct tElemento {
  char simbolo;
  struct tElemento *anterior;
} tElemento;

typedef struct tPilha {
  int qnt;
  tElemento *topo;
} tPilha;

void iniciaPilha(tPilha *pilha){
  pilha->qnt = 0;
  pilha->topo = NULL;
}

void push(tPilha *pilha, char c){
  pilha->qnt++;
  tElemento *novo;
  novo = (tElemento*) malloc(sizeof(tElemento));
  novo->simbolo = c;
  if(pilha->topo == NULL){
    pilha->topo = novo;
    novo->anterior = NULL;
  } else {
    tElemento *temp;
    temp = pilha->topo;
    pilha->topo = novo;
    novo->anterior = temp;
  }
}

char pop(tPilha *pilha){
  char r;
  tElemento * removido;
  if(pilha->qnt == 0){
    return 'c';
  } else {
    pilha->qnt--;
    r = pilha->topo->simbolo;
    removido = pilha->topo;
    if(!pilha->qnt){
      pilha->topo = NULL;
    } else {
      pilha->topo = pilha->topo->anterior;
    }
    free(removido);
    return r;
  }
}

int comparaChars(char pop, char fecha){
  int flag = 0;
  switch(pop){
    case '(':
      if(fecha == ')') flag = 1;
      break;
    case '[':
      if(fecha == ']') flag = 1;
  }
  return flag;
}

int main(void){
  int i, j, t;
  char a[SIZE];
  char num[SIZE];
  tPilha minhaPilha;
  fgets(num, SIZE, stdin);
  t = atoi(num);
  for(j = 0; j < t; j++){
    iniciaPilha(&minhaPilha);
    fgets(a, SIZE, stdin);
    a[SIZE] = '\0';
    for(i = 0; i < SIZE; i++){
      if(a[i] == ' '){
        continue;
      }
      if((a[i] == '\0') || (a[i] == '\n') || (i == SIZE -1)){
        if(minhaPilha.qnt == 0){
          printf("Yes\n");
        } else {
          printf("No\n");
        }
        break;
      }
      switch(a[i]){
        case '(':
        case '[':
          push(&minhaPilha, a[i]);
          break;
        case ')':
        case ']':
          if(!comparaChars(pop(&minhaPilha), a[i])){
            i = SIZE;
            printf("No\n");
          }
      }
    }
  }
  return 0;
}