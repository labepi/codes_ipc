#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 100

int main()
{
    int msqid;
    char *caminho = "/etc/passwd";
    int tamanhomensagem;

    struct meu_msgbuf
    {
        long mtype;
        long cliente_id;
        char cliente_nome[80];
        char cliente_telefone[15];
        char cliente_endereco[180];
        char cliente_cidade[30];
        char cliente_estado[2];
    } mensagem;

    if ((msqid = msgget(ftok(caminho, (key_t)KEY), IPC_CREAT|0666)) == -1)
    {
        printf("Erro ao criar a fila de mensagem\n");
        exit(1);
    }

    printf("A chave %#x foi usada para criar o identificador da fila\n",ftok(caminho, (key_t)KEY));

    printf("Esta fila existe com o identificador numero: %d\n",msqid);

    printf("Uma mensagem do tipo 1 sera lida\n");

    tamanhomensagem = 328;

    // primeira mensagem que o mtype for igual
    int msgtyp = 1;

    if (msgrcv(msqid, &mensagem, tamanhomensagem, msgtyp, IPC_NOWAIT) == -1)
    {
        printf("Nao foi possivel ler a mensagem\n");
        exit(-1);
    }
    else
    {
        printf("A mesagem foi lida com sucesso\n");

        printf("Cliente Type: %ld\n", mensagem.mtype);
        printf("Cliente ID: %ld\n", mensagem.cliente_id);
        printf("Cliente Nome: %s\n",mensagem.cliente_nome);
        printf("Cliente Tel: %s\n",mensagem.cliente_telefone);
        printf("Cliente End: %s\n",mensagem.cliente_endereco);
        printf("Cliente Cid: %s\n",mensagem.cliente_cidade);
        printf("Cliente UF: %s\n",mensagem.cliente_estado);
    }

    return 0;
}
