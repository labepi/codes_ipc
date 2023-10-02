#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// #include <sys/types.h>

#define KEY 100

int main()
{
    int msqid;
    char *caminho = "/etc/passwd";

    // criando uma nova fila de mensagens
    if ((msqid = msgget(ftok(caminho, (key_t)KEY), IPC_CREAT|IPC_EXCL|0666)) == -1)
    {
        printf("Erro ao criar a fila de mensagem\n");
        exit(1);
    }

    printf("Esta nova fila tem o identificador numero: %d\n",msqid);

    return 0;
}
