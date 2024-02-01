raftWars: raftWars.o tests.o
	g++ -o raftWars raftWars.o tests.o .\include\serial\SerialPort.cpp

raftWars.o: raftWars.cpp tests.h
	g++ -c raftWars.cpp 

tests.o: tests.cpp tests.h
	g++ -c tests.cpp


