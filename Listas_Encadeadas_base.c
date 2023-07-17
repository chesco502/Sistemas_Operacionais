#include <stdio.h>
typedef struct reg {
   int         conteudo;
   struct reg *prox;
} celula;

main(){
  celula a;
  printf("%li",sizeof(a));
}
