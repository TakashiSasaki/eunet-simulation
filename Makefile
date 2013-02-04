.PHONY: config config-debug run run-debug clean all main default sandbox

CXXFLAGS=-v -Wall -I/usr/include/ns3.14.1 -O0 -L/usr/lib -std=gnu++0x
VPATH = eunet-simulation 

default: main

main: InternetRouter.o TopologyHelper.o Sandbox.o main.o TerminalSet.o
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
	(cd ..; ./waf clean)

config: clean
	(cd ..; ./waf configure -d release)

config-debug: clean
	(cd ..; ./waf configure -d release)

hello: hello.o
	g++ -o hello $<

run-sandbox:
	(ulimit -m 1000000)
	(cd ..; ./waf --run sandbox --command-template="gdb --args %s -ex run")
	
run-sandbox:
	(ulimit -m 1000000)
	(cd ..; ./waf --run sandbox)

run-debug:
	(ulimit -m 1000000)
	(cd ..; ./waf --run eunet-simulation --command-template="gdb --args %s")

run:
	(ulimit -m 1000000)
	(cd ..; ./waf -d release --run eunet-simulation)

