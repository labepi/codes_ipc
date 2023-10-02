from xmlrpc.server import SimpleXMLRPCServer


# funcao somar
def somar(x, y):
    return x + y


# funcao subtrair
def subtrair(x, y):
    return x - y


IP = "localhost"
PORTA = 8000

# criando o servidor RPC
server = SimpleXMLRPCServer(("", PORTA))

# registrando as funcoes que serao ofertadas
server.register_function(somar, 'somar')
server.register_function(subtrair, 'subtrair')

# rodando o main loop do servidor
server.serve_forever()
