import xmlrpc.client
import sys

if len(sys.argv) != 3:
    print("Erro: informe dois números x e y")
    exit(1)

x = int(sys.argv[1])
y = int(sys.argv[2])

s = xmlrpc.client.ServerProxy('http://localhost:8000')

print("%d + %d = %d" % (x, y, s.somar(x, y)))
print("%d - %d = %d" % (x, y, s.subtrair(x, y)))

