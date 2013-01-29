CXXFLAGS=-v -Wall -I/usr/include/ns3.14.1 -O0 -L/usr/lib

default: main

main: main.o InternetRouter.o
	g++ -o main $(CXXFLAGS)  \
	/usr/lib/libns3.14.1-core.a  \
	/usr/lib/libns3.14.1-csma.a  \
	/usr/lib/libns3.14.1-internet.a  \
	/usr/lib/libns3.14.1-network.a  \
	$? 

main.s: main.cc
	g++ $(CXXFLAGS) -S $<

main.o: main.cc

clean:
	rm -rf main.s main.o hello hello.o

hello: hello.o
	g++ -o hello $<

debug:
	(cd ..; ./waf --run main --command-template="gdb --args %s")

