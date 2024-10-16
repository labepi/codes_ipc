import sys
import Pyro5.api

# recebendo os valores 'a' e 'b'
if len(sys.argv) != 3:
    print("Erro: informe dois números x e y")
    exit(1)

x = int(sys.argv[1])
y = int(sys.argv[2])

# utilizar este campo quando rodar na nuvem
# IPNUVEM = "a.b.c.d"
# PORTA_NS = 8888

# buscando a URI do objeto remoto no name server
calc = Pyro5.api.Proxy("PYRONAME:calculadora@localhost:8888")
# calc = Pyro5.api.Proxy("PYRONAME:calculadora@{}:{}".format(IPNUVEM, PORTA_NS))

# Exemplo: conectando diretamente ao objeto remoto (caso conheça seu URI)
# calc = Pyro5.api.Proxy("PYRO:obj_e17ddd5a1d3945b3a56a24394e8742f2@{}:8080".format(IPNUVEM))

print("Som: {}", calc.add(x, y))
print("Sub: {}", calc.sub(x, y))
