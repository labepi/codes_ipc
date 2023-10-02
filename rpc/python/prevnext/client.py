import xmlrpc.client
import sys

if len(sys.argv) != 2:
    print("Erro: informe um número")
    exit(1)

x = int(sys.argv[1])

s = xmlrpc.client.ServerProxy('http://localhost:8000')

# realizando as chamadas remotas
x_prev = s.prev(x)
x_next = s.next(x)

print("Num: %d, prev: %d, next: %d" % (x, x_prev, x_next))
