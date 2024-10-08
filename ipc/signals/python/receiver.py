import signal
import os
import time


def quit_handle(signum, frame):
    signame = signal.Signals(signum).name
    print('Finalizando...')
    exit(1)


def local_message(signum, frame):
    signame = signal.Signals(signum).name
    print(f'Recebendo sinal local {signame} [({signum}]')


def remote_message(signum, frame):
    signame = signal.Signals(signum).name
    print(f'Recebendo sinal remoto {signame} [{signum}]')


# registrando os tratadores dos sinais
signal.signal(signal.SIGINT, quit_handle)
signal.signal(signal.SIGALRM, local_message)
signal.signal(signal.SIGUSR1, remote_message)


print(f'Meu PID: {os.getpid()}')


while 1:
    signal.alarm(5)
    time.sleep(5)

