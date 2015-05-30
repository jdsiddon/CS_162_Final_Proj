PROGS := game

all: $(PROGS)

game: game.o Player.o Item.o
	g++ -g game.o Player.o Item.o -o game.o

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

clean:
	rm -f ${PROGS} *.o *~
