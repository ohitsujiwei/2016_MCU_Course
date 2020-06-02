thread: thread.c
	gcc -o thread thread.c -lpthread
thread.o: thread.c
	gcc -c thread.c
clean:
	rm *.o thread
