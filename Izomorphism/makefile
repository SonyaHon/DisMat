all: main1.o Graph.o
	g++ main1.o Graph.o -ofast -o out
	rm *.o
main1.o: main1.cpp
	g++ -c main1.cpp
Graph.o: Graph.cpp
	g++ -c Graph.cpp
