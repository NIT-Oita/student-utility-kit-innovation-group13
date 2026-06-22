CC = gcc

all: quiz

quiz: main.o ui.o storage.o logic.o
	$(CC) -o quiz main.o ui.o storage.o logic.o

main.o: main.c
	$(CC) -c main.c

ui.o: ui.c
	$(CC) -c ui.c

storage.o: storage.c
	$(CC) -c storage.c

logic.o: logic.c
	$(CC) -c logic.c

clean:
	del *.o quiz.exe