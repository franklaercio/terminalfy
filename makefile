song.o: song.cpp song.h
	g++ song.cpp -c

songlist.o: songlist.cpp songlist.h
	g++ songlist.cpp -c

terminalfy: main.cpp song.o songlist.o
	g++ main.cpp song.o songlist.o -o terminalfy

all: terminalfy
