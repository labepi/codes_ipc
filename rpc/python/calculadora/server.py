from xmlrpc.server import SimpleXMLRPCServer


# funcao somar
def somar(x, y):
    return x + y


# funcao subtrair
def subtrair(x, y):
    return x - y


# dados da conexao com o servidor
IP = ""
PORTA = 8000

# criando o servidor RPC
server = SimpleXMLRPCServer((IP, PORTA))

# registrando as funcoes que serao ofertadas
server.register_function(somar, 'somar')
server.register_function(subtrair, 'subtrair')

# rodando o main loop do servidor
server.serve_forever()
