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

    printf("Esta nova fila foi criada com o identificador numero: %d\n",msqid);
    
    printf("Uma mensagem será enviada para a fila\n");

    mensagem.mtype = 1;
    mensagem.cliente_id = 1234;
    sprintf(mensagem.cliente_nome,"Joao");
    sprintf(mensagem.cliente_telefone,"555");
    sprintf(mensagem.cliente_endereco,"Rua Tal");
    sprintf(mensagem.cliente_cidade,"Caico");
    sprintf(mensagem.cliente_estado,"RN");

    tamanhomensagem = sizeof(mensagem);
    printf("O tamanho da mensagem é %d bytes\n\n",tamanhomensagem);

    // enviando uma mensagem para a fila
    if (msgsnd(msqid,&mensagem,tamanhomensagem,IPC_NOWAIT) == -1)
    {
        printf("Nao foi possivel enviar a mensagem\n");
        exit(-1);
    }
    else
    {
        printf("A mesagem foi enviada com sucesso\n");
    }

    return 0;
}
