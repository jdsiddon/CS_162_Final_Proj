PROGS := game

all: $(PROGS)

game: game.o Player.o Item.o Room.o Train.o Car.o Dice.o BarCar.o PassengerCar.o BaggageCar.o
	g++ -g game.o Player.o Item.o Room.o Train.o Car.o Dice.o BarCar.o PassengerCar.o BaggageCar.o -o game

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Item.o: Item.cpp Item.hpp
	g++ -c Item.cpp

Room.o: Room.cpp Room.hpp
	g++ -c Room.cpp

Train.o: Train.cpp Train.hpp
	g++ -c Train.cpp

Car.o: Car.cpp Car.hpp
	g++ -c Car.cpp

Dice.o: Dice.cpp Dice.hpp
	g++ -c Dice.cpp

BarCar.o: BarCar.cpp BarCar.hpp
	g++ -c BarCar.cpp

PassengerCar.o: PassengerCar.cpp PassengerCar.hpp
	g++ -c PassengerCar.cpp

BaggageCar.o: BaggageCar.cpp BaggageCar.hpp
	g++ -c BaggageCar.cpp

clean:
	rm -f ${PROGS} *.o *~
