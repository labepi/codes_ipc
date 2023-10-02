#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define ARQUIVO_FIFO "MEUFIFO"

int main()
{
    FILE *fp;
    char readbuf[80];

    // criando o arquivo FIFO
    umask(0);
    mknod(ARQUIVO_FIFO, S_IFIFO|0666, 0);

    while(1)
    {
        // abrindo o FIFO para leitura
        fp = fopen(ARQUIVO_FIFO, "r");
        fgets(readbuf, 80, fp);
        printf("Conteudo do FIFO: %s\n", readbuf);
        fclose(fp);
    }
    
    return 0;
}
