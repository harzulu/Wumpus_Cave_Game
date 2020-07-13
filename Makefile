CC = g++
exe_file = wumpus
$(exe_file): player.o main.o event.o room.o wumpus.o bats.o pit.o gold.o
	$(CC) player.o main.o event.o room.o wumpus.o bats.o pit.o gold.o -o $(exe_file)
player.o: player.cpp
	$(CC) -c player.cpp
main.o: main.cpp
	$(CC) -c main.cpp
event.o: event.cpp
	$(CC) -c event.cpp
room.o: room.cpp
	$(CC) -c room.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp

clean:
	rm –f *.out *.o $(exe_file)