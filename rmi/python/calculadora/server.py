import Pyro5.api


# definindo a classe com os objetos remotos via decorators
@Pyro5.api.expose
class Calculadora(object):

    def add(self, a, b):
        return a+b

    def sub(self, a, b):
        return a-b


# utilizar este campo quando rodar na nuvem
# IPNUVEM = "a.b.c.d"
PORTA = 8080
PORTA_NS = 8888

# criando um serviço Pyro
#daemon = Pyro5.server.Daemon()
daemon = Pyro5.server.Daemon(host="0.0.0.0", port=PORTA)
#daemon = Pyro5.server.Daemon(host="0.0.0.0", port=8080, nathost=IPNUVEM)

# NOTE: precisa executar o name server em alguma porta,
# antes de executar o servidor:
# pyro5-ns -n 0.0.0.0 -p 8888

# encontrando um name server
ns = Pyro5.api.locate_ns(port=PORTA_NS)

# registrando a classe como um objeto Pyro
uri = daemon.register(Calculadora)

print(uri)

# registrando o objeto com um nome no name server
ns.register("calculadora", uri)

print("Pronto.")

# iniciando o loop do servidor para aguradar chamadas
daemon.requestLoop()
