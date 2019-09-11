from socket import *
severPort = 12000
severSocket = socket(AF_INET,SOCK_DGRAM)
severSocket.bind(('',severPort))
print("The sever is ready to receive")
while True:
  message ,clientAddress = severSocket.recvfrom(2048)
  modifiedMessage = message.decode().upper()
  severSocket.sendto(modifiedMessage.encode(),clientAddress)