import serial
import time

porta = "COM5"
velocidade = 9600
conexao = serial.Serial(porta, velocidade)


time.sleep(2)

opcao = 0 

while opcao != "2":
    opcao = input("Digite 1 para ligar\nDigite 2 para sair\n")
    if opcao != "2":
        conexao.write(opcao.encode())  

conexao.close() 
