
from socket import *
import selectors

sel = selectors.DefaultSelector()
socket1 = socket(AF_INET, SOCK_STREAM)
socket1.connect(("newton.computing.clemson.edu", 3604))
events1 = selectors.EVENT_READ | selectors.EVENT_WRITE
data1 = 1
socket1.setblocking(False)
sel.register(socket1, events1, data1)

socket2 = socket(AF_INET, SOCK_STREAM)
socket2.connect(("newton.computing.clemson.edu", 3604))
events2 = selectors.EVENT_READ | selectors.EVENT_WRITE
data2 = 2
socket2.setblocking(False)
sel.register(socket2, events2, data2)

socket3 = socket(AF_INET, SOCK_STREAM)
socket3.connect(("newton.computing.clemson.edu", 3604))
events3 = selectors.EVENT_READ | selectors.EVENT_WRITE
data3 = 3
socket3.setblocking(False)
sel.register(socket3, events3, data3)

while True:
    #user input
    message = input()
    events = sel.select(timeout = 10)
    for key, mask in events:
        socket = key.fileobj
        data = key.data

        if mask & selectors.EVENT_READ:
            rdata = socket.recv(2048)
            messages = rdata.split("\r\n")
            for i in messages:
                print(data, ': ', i)
        if mask & selectors.EVENT_WRITE:
            socket.send(message.encode())
        pass
    pass
