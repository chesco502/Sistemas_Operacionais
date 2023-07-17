#include <stdio.h>
typedef struct reg {
   int         conteudo;
   struct reg *prox;
} celula;

main(){
  celula a;
  printf("%li",sizeof(a));
}
//de acordo com o programa, uma struct da 12 bits!
//meu computador tem 8 gigas de memoria ram entao 666.666.666 nós !!
