from xmlrpc.server import SimpleXMLRPCServer


def prev(x):
    return x - 1


def next(x):
    return x + 1


IP = "localhost"
PORTA = 8000

# criando o servidor RPC
server = SimpleXMLRPCServer(("", PORTA))

# registrando as funcoes que serao ofertadas
server.register_function(prev, 'prev')
server.register_function(next, 'next')

# rodando o main loop do servidor
server.serve_forever()
