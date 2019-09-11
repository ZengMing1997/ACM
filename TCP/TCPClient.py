# This Python file uses the following encoding: utf-8
from socket import *
serverName = '127.0.0.1' 
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM) 
clientSocket.connect((serverName,serverPort)) 
sentence = raw_input('Input lowercase sentence:')
clientSocket.send(sentence)
modifiedSentence = clientSocket.recvfrom(1024) 
print(modifiedSentence[0].decode()) 
clientSocket.close()