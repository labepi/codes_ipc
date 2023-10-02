#include "calculadora.h"

int *somar_1_svc(operando *argp, struct svc_req *rqstp)
{
	    static int result;
	        result = argp->x + argp->y;
		    return &result;
}

int *subtrair_1_svc(operando *argp, struct svc_req *rqstp)
{
	    static int result;
	        result = argp->x - argp->y;
		    return &result;
}
