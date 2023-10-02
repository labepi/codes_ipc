#include "calculadora.h"

int main (int argc, char *argv[])
{
	char *host;

	CLIENT *clnt;
	int *result;
	operando ops;
	
	if (argc < 4) {
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit (1);
	}
					
	// ip
	host = argv[1];
	
	// x e y
	ops.x = atoi(argv[2]);
	ops.y = atoi(argv[3]);
	
	// conectando
	clnt = clnt_create (host, 
	       			CALCULADORA, 
				CALCULADORA_VERSAO, 
				"tcp");
	   
	// chamada remota pra soma
    	result = somar_1(&ops, clnt);
	printf("A SOMA: %d\n", *result);

	// chamada remota pra subtracao
	result = subtrair_1(&ops, clnt);
	printf("A SUBTRACAO: %d\n", *result);
	    
	exit (0);
}
