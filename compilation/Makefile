CC = g++
CFLAGS = -std=c++11 -Wall
GRID = ../simulation/Grid
ANTS = ../simulation/Ants
SIM = ../simulation
AFF = ../affichage
MAI = ..

all:images

images: main
	./main

main: main.o simulation.o generationppm.o EnsCoord.o Coordonate.o Ant.o Case.o Grid.o
	$(CC) $(CFLAGS) -o main main.o simulation.o generationppm.o EnsCoord.o Coordonate.o Ant.o Case.o Grid.o
    
main.o: $(MAI)/main.cpp generationppm.o simulation.o
	$(CC) $(CFLAGS) -c $(MAI)/main.cpp -o main.o
    
    
run_test: Test
	./Test  

Test: Test.o EnsCoord.o Coordonate.o Ant.o Case.o Grid.o
	$(CC) $(CFLAGS) -o Test Test.o EnsCoord.o Coordonate.o Ant.o Case.o Grid.o

Test.o: $(GRID)/Test.cpp
	$(CC) $(CFLAGS) -c $(GRID)/Test.cpp -o Test.o

run_test_aff: Test_affi
	./Test_affi


Test_affi: Test_affi.o generationppm.o
	$(CC) $(CFLAGS) -o Test_affi Test_affi.o generationppm.o EnsCoord.o Coordonate.o Ant.o Case.o Grid.o
    
Test_affi.o: $(AFF)/Test.cpp generationppm.o
	$(CC) $(CFLAGS) -c $(AFF)/Test.cpp -o Test_affi.o
    

simulation.o: $(SIM)/simulation.hpp $(SIM)/simulation.cpp Grid.o
	$(CC) $(CFLAGS) -c $(SIM)/simulation.cpp -o simulation.o

generationppm.o: $(AFF)/generationppm.hpp $(AFF)/generationppm.cpp Grid.o
	$(CC) $(CFLAGS) -c $(AFF)/generationppm.cpp -o generationppm.o

Grid.o:$(GRID)/Grid.hpp $(GRID)/Grid.cpp EnsCoord.o Coordonate.o Case.o
	$(CC) $(CFLAGS) -c $(GRID)/Grid.cpp -o Grid.o
    
Case.o: $(GRID)/Case.hpp $(GRID)/Case.cpp Coordonate.o Ant.o
	$(CC) $(CFLAGS) -c $(GRID)/Case.cpp -o Case.o
    
EnsCoord.o: $(GRID)/EnsCoord.hpp $(GRID)/EnsCoord.cpp Coordonate.o 
	$(CC) $(CFLAGS) -c $(GRID)/EnsCoord.cpp -o EnsCoord.o

Ant.o: $(ANTS)/Ant.hpp $(ANTS)/Ant.cpp Coordonate.o
	$(CC) $(CFLAGS) -c $(ANTS)/Ant.cpp -o Ant.o

Coordonate.o: $(GRID)/Coordonate.hpp $(GRID)/Coordonate.cpp
	$(CC) $(CFLAGS) -c $(GRID)/Coordonate.cpp -o Coordonate.o
    

clean:
	rm -rf *o
	rm -rf *ppm
	rm -rf *jpg
	rm -rf core.*
	rm Test_affi
	rm Test