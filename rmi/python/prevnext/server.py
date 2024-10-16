import Pyro5.api


# definindo a classe com os objetos remotos via decorators
@Pyro5.api.expose
class PrevNext(object):

    def prev(self, x):
        return x-1

    def next(self, x):
        return x+1


PORTA = 8080
PORTA_NS = 8888

# criando um serviço Pyro
daemon = Pyro5.server.Daemon(host="0.0.0.0", port=PORTA)

# NOTE: precisa executar o name server em alguma porta,
# antes de executar o servidor:
# pyro5-ns -n "0.0.0.0" -p 8888

# encontrando um name server
ns = Pyro5.api.locate_ns(port=PORTA_NS)

# registrando a classe como um objeto Pyro
uri = daemon.register(PrevNext)

print(uri)

# registrando o objeto com um nome no name server
ns.register("prevnext", uri)

print("Pronto.")

# iniciando o loop do servidor para aguradar chamadas
daemon.requestLoop()
