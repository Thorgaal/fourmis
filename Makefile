CC = g++
CFLAGS = -std=c++11 -Wall
GRID = simulation/Grid
ANTS = simulation/Ants

all:main

main:main.o 
	$(CC) $(CFLAGS) -o main main.o
    
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
    
run_test: Test
	./Test  

Test: Test.o EnsCoord.o Coordonate.o Ant.o Case.o
	$(CC) $(CFLAGS) -o Test Test.o EnsCoord.o Coordonate.o Ant.o Case.o

Test.o: $(GRID)/Test.cpp
	$(CC) $(CFLAGS) -c $(GRID)/Test.cpp -o Test.o
    
Coordonate.o: $(GRID)/Coordonate.hpp $(GRID)/Coordonate.cpp
	$(CC) $(CFLAGS) -c $(GRID)/Coordonate.cpp -o Coordonate.o
    
EnsCoord.o: $(GRID)/EnsCoord.hpp $(GRID)/EnsCoord.cpp
	$(CC) $(CFLAGS) -c $(GRID)/EnsCoord.cpp -o EnsCoord.o
    
Ant.o: $(ANTS)/Ant.hpp $(ANTS)/Ant.cpp
	$(CC) $(CFLAGS) -c $(ANTS)/Ant.cpp -o Ant.o
    
Case.o: $(GRID)/Case.hpp $(GRID)/Case.cpp
	$(CC) $(CFLAGS) -c $(GRID)/Case.cpp -o Case.o

clean:
	rm -rf *o

