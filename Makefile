CXXFLAGS=-v -Wall -I/usr/include/ns3.14.1 -O0

default: main.o

main.s: main.cc
	g++ $(CXXFLAGS) -S $<

clean:
	rm -rf main.s main.o

hello: hello.o
	g++ -o hello $<

