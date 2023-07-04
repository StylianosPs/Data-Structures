CC=gcc
CFLAGS=-Wall

main: main.o Session.o 
	$(CC) $(CFLAGS) -o main main.o Session.o 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

Session.o: Session.c
	$(CC) $(CFLAGS) -c Session.c 


.PHONY: clean

clean:
	rm -f main main.o
	rm -f Session.o
	
	
	

