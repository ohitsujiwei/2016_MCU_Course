socket: socket.c
	gcc -o socket socket.c
socket.o: socket.c
	gcc -c socket.c
clean:
	rm *.o socket
