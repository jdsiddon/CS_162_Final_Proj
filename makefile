PROGS := game

all: $(PROGS)

game: game.o Player.o Item.o Room.o BarCar.o Queue.o
	g++ -g game.o Player.o Item.o Room.o BarCar.o Queue.o -o game

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Room.o: Room.cpp Room.hpp
	g++ -c Room.cpp

BarCar.o: BarCar.cpp BarCar.hpp
	g++ -c BarCar.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

clean:
	rm -f ${PROGS} *.o *~
