all:
	gcc -o main.o main.c
	./main.o
clear:
	rm main.o