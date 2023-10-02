#define VERSAO 1
struct operando {
    int x;
    int y;
};

program CALCULADORA {
    version CALCULADORA_VERSAO {
        int SOMAR(operando) = 1;
        int SUBTRAIR(operando) = 2;
    } = VERSAO;
} = 300000001;
