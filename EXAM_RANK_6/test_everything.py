import subprocess
import socket
import time
import os

ADDRESS = '127.0.0.1'

def test_wrong_number_of_arguments():
    os.system("pkill mini_serv")

    result = subprocess.run(['./mini_serv'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    assert result.returncode == 1
    assert result.stderr.decode() == 'Wrong number of arguments\n'


def test_client_message_relay():
    os.system("pkill mini_serv")

    PORT = 8080
    server = subprocess.Popen(['./mini_serv', str(PORT)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    time.sleep(0.1)

    c1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c1.connect((ADDRESS, PORT))
    c2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c2.connect((ADDRESS, PORT))

    assert c1.recv(1024).decode() == 'server: client 1 just arrived\n'

    c1.close()

    assert c2.recv(1024).decode() == 'server: client 0 just left\n'

    server.kill()

def test_messages():
    os.system("pkill mini_serv")

    PORT = 8081
    server = subprocess.Popen(['./mini_serv', str(PORT)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    time.sleep(0.1)

    
    c1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c1.connect((ADDRESS, PORT))
    c2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c2.connect((ADDRESS, PORT))
    c3 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c3.connect((ADDRESS, PORT))

    N = 1000
    for _ in range(N):
        c1.sendall(b"yo\nyo\n")
    time.sleep(0.3)
    assert c2.recv(30000).decode().count("yo\n") == N * 2
    assert c3.recv(30000).decode().count("yo\n") == N * 2
    
    server.kill()

def test_large():
    os.system("pkill mini_serv")

    PORT = 8082
    server = subprocess.Popen(['./mini_serv', str(PORT)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    time.sleep(0.1)

    c1 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c1.connect((ADDRESS, PORT))
    c2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c2.connect((ADDRESS, PORT))
    c3 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    c3.connect((ADDRESS, PORT))

    N = 30000
    msg = "x" * N + "\n"
    c1.sendall(msg.encode())
    c1.sendall(msg.encode())
    c1.sendall(msg.encode())

    time.sleep(0.1)

    assert c2.recv(N*4).decode().count("x") == N*3
    assert c3.recv(N*4).decode().count("x") == N*3

    server.kill()