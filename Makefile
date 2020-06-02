example: example.c
	gcc -o example example.c -lpthread
example.o: example.c
	gcc -c example.c
clean:
	rm *.o example
