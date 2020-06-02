QQ: QQ.c
	gcc -o QQ QQ.c
QQ.o: QQ.c
	gcc -c QQ.c
clean:
	rm *.o QQ
