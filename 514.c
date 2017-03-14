#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tElemento {
  char chave;
  struct tElemento* anterior;
} tElemento;

typedef struct tPilha {
  int qnt;
  tElemento* topo;
} tPilha;

void iniciaPilha(tPilha* pilha){
  pilha->qnt = 0;
  pilha->topo = NULL;
}

void push(tPilha* pilha, int c){
  pilha->qnt++;
  tElemento* novo;
  novo = (tElemento*) malloc(sizeof(tElemento));
  novo->chave = c;
  if(pilha->topo == NULL){
    pilha->topo = novo;
    novo->anterior = NULL;
  } else {
    tElemento* temp;
    temp = pilha->topo;
    pilha->topo = novo;
    novo->anterior = temp;
  }
}

void pop(tPilha* pilha){
  tElemento* removido;
  if(pilha->qnt == 0){
    return;
  } else {
    pilha->qnt--;
    removido = pilha->topo;
    if(!pilha->qnt){
      pilha->topo = NULL;
    } else {
      pilha->topo = pilha->topo->anterior;
    }
    free(removido);
    return;
  }
}

void esvaziaPilha(tPilha* pilha){
  while(pilha->qnt != 0) pop(pilha);
}

int main(void){
  int i, j, valor;
  int n;
  int falha = 0;
  tPilha minhaPilha;
  while(1){
    scanf("%d", &n);
    if(!n) break;
    while(1){
      scanf("%d", &valor);
      if(!valor) break;
      iniciaPilha(&minhaPilha);
      falha = 0;
      i = 1;
      while(i != valor){
        printf("push %d\n", i);
        push(&minhaPilha, i);
        i++;
      }
      i++;
      for(j = 1; j < n; j++){
        scanf("%d", &valor);
        if((minhaPilha.qnt > 0) && (valor == minhaPilha.topo->chave)){
          printf("pop %d\n", valor);
          pop(&minhaPilha);
        } else {
          while((i < n) && (i != valor)){
            push(&minhaPilha, i);
            i++;
          }
          if(i != valor){
            falha = 1;
          }
        }
      }
      if(falha){
        printf("No\n");
      } else {
        printf("Yes\n");
      }
      esvaziaPilha(&minhaPilha);
    }
    printf("\n");
  }
  return 0;
}