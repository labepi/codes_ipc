#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define CHAVE 123

int main()
{
    int shmid;
    int tamanho = 1024;
    char *memoria;
    char *caminho = "/etc/passwd";

    if ((shmid = shmget(ftok(caminho, (key_t)CHAVE), tamanho,
                    IPC_CREAT|SHM_R|SHM_W)) == -1)
    {
        printf("Erro ao criar segmento.\n");
        exit(1);
    }
        
    printf("O segmento identificado por %d esta sendo usado para ler e gravar dados\n",shmid);
    
    memoria = shmat(shmid,0,0);

    printf("Um segmento de memoria foi endereçado e apontado para variavel string 'memoria'\n");

    // processo filho
    if (fork() == 0)
    {
        printf("Processo filho PID %d foi criado\n",getpid());
        strcpy(memoria,"Livro de SD");
        printf("Uma string foi gravada no segmento\n");
        shmdt(memoria);
        sleep(2);
    }
    // processo pai
    else
    {
        wait(0);
        printf("A seguinte frase foi lida no segmento: %s\n",memoria);
        shmdt(memoria);
        exit(0);
    }
}
