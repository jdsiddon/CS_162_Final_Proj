PROGS := game

all: $(PROGS)

game: game.o Player.o Item.o Room.o
	g++ -g game.o Player.o Item.o Room.o -o game.o

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Room.o: Room.cpp Room.hpp
	g++ -c Room.cpp

clean:
	rm -f ${PROGS} *.o *~
