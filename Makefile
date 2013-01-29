CXXFLAGS=-v -Wall -I/usr/include/ns3.14.1 -O0 -L/usr/lib

default: main

main: InternetRouter.o CoreSwitch.o TopologyHelper.o main.o
	g++ -o main $(CXXFLAGS)  \
	/usr/lib/libns3.14.1-core.a  \
	/usr/lib/libns3.14.1-csma.a  \
	/usr/lib/libns3.14.1-internet.a  \
	/usr/lib/libns3.14.1-network.a  \
	$^

main.s: main.cc
	g++ $(CXXFLAGS) -S $<

main.o: main.cc

clean:
	rm -rf main.s *.o

hello: hello.o
	g++ -o hello $<

debug:
	(ulimit -m 1000000)
	(cd ..; ./waf --run eunet-simulation --command-template="gdb --args %s")

