#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Informe o PID do processo Receiver\n");
        exit(1);
    }

    // obtendo o PID para mandar o sinal
    int PID = atoi(argv[1]);

    // envia o SIGUSR1 a cada 5 segundos
    kill(PID, SIGUSR1);

    return 0;
}
