import os
import signal
import sys

if (len(sys.argv) != 2):
    print("Informe o PID do processo Receiver!")
    exit(1)


pid = int(sys.argv[1])


# Enviando o sinal para o processo 
os.kill(pid, signal.SIGUSR1)

