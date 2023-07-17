#include <stdio.h>
#include <stdlib.h>
typedef struct reg
{
  int conteudo;
  struct reg *prox;
} celula;
typedef struct reg celula;
void
print (struct reg *ponteiro)
{
 
  while (ponteiro != NULL)
    {
      printf ("%i\n", ponteiro->conteudo);
      ponteiro = ponteiro->prox;

    }
}

void remover(struct reg **head_ref, int N) {
    
    struct reg *current = *head_ref, *prev = NULL;
   
    
    if (current != NULL && current->conteudo == N) {
        *head_ref = current->prox; 
        
        free(current); 
        return;
    }

    
    while (current != NULL && current->conteudo != N) {
        prev = current;
        current = current->prox;
    }

    
    prev->prox = current->prox;
    free(current); 
}


int
main ()
{
  celula *cabeca;
  celula a;
  a.conteudo = 1;
  cabeca = & a;
  celula b;
  b.conteudo = 2;
  a.prox = &b;
  celula c;
  c.conteudo = 3;
  b.prox = &c;
  
  print (cabeca);
  
  
  remover(&cabeca,2);
  
  print (cabeca);
  
  
  
  
  return 0;
}
