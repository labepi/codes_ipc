#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // armazena os descritores do pipe
    int desc[2];
    // criando o pipe
    pipe(desc);
    printf("Um tubo foi criado!\n");

    // processo filho
    if (fork() == 0)
    {
        char mensagem[] = "Olá mundo!";

        printf("\tO processo filho vai escrever dados no tubo\n");

        close(desc[0]); // tubo fechado para leitura

        if (write(desc[1], mensagem, sizeof(mensagem)) < 0)
        {
            printf("Erro ao gravar no tubo\n");
        }
        
        close(desc[1]); // tubo fechado para escrita
        
        printf("\tO processo filho finalizando...\n");
        sleep(1);
        
        exit(0);
    }
    // processo pai
    else
    {
        // aguardando o filho terminar de escrever
        wait(0);

        char leitura[11];
        
        printf("O processo pai vai ler os dados no tubo\n");

        close(desc[1]); // tubo fechado para escrita
        
        if (read(desc[0], leitura, 11) == 0)
        {
            printf("Tubo vazio\n");
        }
        else
        {
            printf("O valor lido foi: %s.\n",leitura);
        }

        close(desc[0]); // tubo fechado para leitura
        
        exit(0);
    }

    return 0;
}
