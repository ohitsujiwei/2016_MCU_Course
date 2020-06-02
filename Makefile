Lab03: Lab03.c
	gcc -o Lab03 Lab03.c
Lab03.o: Lab03.c
	gcc -c Lab03.c
clean:
	rm *.o Lab03
