

#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
// 64kB stack
#define FIBER_STACK 1024*64
#define thread 100


#include <string.h>
///////////////////
pthread_t filosofo[thread];	// threads para cada filC3sofo
sem_t garfo;			// semC!foros para cada garfo
sem_t mutex;
///////////////////
struct c
{
  int saldo;
};
typedef struct c conta;
conta *from, *to, B, A;
int valor;

// The child thread will execute this function
void *
transferencia (void *arg)
{
  int i = *(int *) arg;
  while (1)
    {





      sem_wait (&mutex);
      sem_wait (&garfo);
      if (from->saldo == 0)
	{
	  sem_post (&garfo);
	  sem_post (&mutex);
	  //printf ("finalizando thread :%i\n", i);
	  pthread_exit (NULL);
	}
      if (rand () % 4 < 2)
	{

	  from = &A;
	  to = &B;

	}
      else
	{
	  from = &B;
	  to = &A;
	}

    

  if (from->saldo < valor)
    {
      valor = from->saldo;
    }

  from->saldo -= valor;
  to->saldo += valor;



  printf ("TransferC*ncia concluC-da com sucesso!\n");
  printf ("Saldo de c1: %d\n", A.saldo);
  printf ("Saldo de c2: %d\n", B.saldo);
  printf ("hello da thread :%i\n", i);
  sem_post (&garfo);
  sem_post (&mutex);




}}




int
main ()
{
  void *stack;
  pid_t pid;
  int i;
  int resp;
  char r;

  printf ("a");
  stack = malloc (FIBER_STACK);

  A.saldo = 100;
  B.saldo = 100;
   from = &A;
	  to = &B;

  
  valor = from->saldo / 100;

  int id[thread];
  sem_init (&mutex, 0, 1);	// inicializa semC!foro mutex
  sem_init (&garfo, 0, 1);	// inicializa semC!foro de cada garfo

  for (i = 0; i < thread; i++)
    {
      id[i] = i;
      pthread_create (&filosofo[i], NULL, transferencia, (void *) &id[i]);
    }
  for (i = 0; i < thread; i++)
    {

      pthread_join (filosofo[i], NULL);	// aguarda tC)rmino das threads
    }

  printf ("valor na conta A: %d\n valor na conta B: %d\n", A.saldo, B.saldo);

  free (stack);
  //printf ("TransferC*ncias concluC-das e memC3ria liberada.\n");

  return 0;
}
