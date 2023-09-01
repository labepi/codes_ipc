#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define CHAVE 123

int main()
{
    int shmid;
    int tamanho = 1024;
    char *caminho = "/etc/passwd";

    if ((shmid = shmget(ftok(caminho, (key_t)CHAVE), tamanho,
                    IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1)
    {
        printf("O segmento de memoria ja existe.\n");
        exit(1);
    }
    else
    {
        printf("Foi criado um segmento de memoria com o id num: %d\n",shmid);
        exit(0);
    }
}
