#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void quit_handle(int s)
{
    printf("Finalizando...\n");
    exit(0);
}

void local_message(int s) 
{
     printf("Imprimindo mensagem local...\n" );
}

void remote_message(int s) 
{
     printf("Imprimindo mensagem remota...\n", s);
}

int main(void) {
    
    // registrando um tratador para o sinal
    signal(SIGINT, quit_handle);

    // registrando um tratador para o sinal
    signal(SIGALRM, local_message);

    // registrando um tratador para o sinal
    signal(SIGUSR1, remote_message);

    printf("Processo Receiver tem PID: %d\n",getpid());

    // faz um loop para manter o main ativo
    while (1)
    {
        // envia o SIGALRM a cada 5 segundos
        alarm(5);
        sleep(5);
    }

    return 0;
}
