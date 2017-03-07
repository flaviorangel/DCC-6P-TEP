#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define GRAV 9810

void posicao(float l, float d, float h, float v){
  float t, r;
  float d1 = d - 500;
  float d2 = d + 500;
  float d3 = d + l - 500;
  float d4 = d + l + 500;
  t = sqrt(h*2/GRAV);
  r = v*t;
  if(r < d1 || r > d4){
    printf("FLOOR\n");
  } else if(r > d2 && r < d3){
    printf("POOL\n");
  } else {
    printf("EDGE\n");
  }
}

int main(void){
  int numSamples;
  float l, d, h, v;
  int i;

  scanf("%d", &numSamples);
  for(i = 0; i < numSamples; i++){
    scanf("%f", &l);
    scanf("%f", &d);
    scanf("%f", &h);
    scanf("%f", &v);
    posicao(l, d, h, v);
  }
  return 0;
}

//gcc file.c -o test -lm
// ./test
//Git:
//git add .
//git commit -m ""
//git push origin master