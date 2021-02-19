song.o: song.cpp song.h
	g++ song.cpp -c

songlist.o: songlist.cpp songlist.h
	g++ songlist.cpp -c

playlist.o: playlist.cpp playlist.h
	g++ playlist.cpp -c

terminalfy: main.cpp song.o songlist.o playlist.o
	g++ main.cpp song.o songlist.o playlist.o -o terminalfy

all: terminalfy
