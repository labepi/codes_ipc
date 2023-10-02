#include <stdio.h>
#include <stdlib.h>

#define ARQUIVO_FIFO "MEUFIFO"

int main(int argc, char** argv)
{
    FILE *fp;

    if (argc != 2)
    {
        printf("Uso: ./escritor \"frase\"\n");
        exit(1);
    }

    if ((fp = fopen(ARQUIVO_FIFO, "w")) == NULL)
    {
        perror("fopen");
        exit(1);
    }

    fputs(argv[1], fp);
    fclose(fp);

    return 0;
}
