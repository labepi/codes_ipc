import sys
import Pyro5.api

if len(sys.argv) != 2:
    print("Erro: informe um número")
    exit(1)

x = int(sys.argv[1])

# buscando a URI do objeto remoto no name server
s = Pyro5.api.Proxy("PYRONAME:prevnext@localhost:8888")

print("Prev:", s.prev(x))
print("Next:", s.next(x))
