PHONY: config debug-config clean all main default sandbox debug-sandbox

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
	(cd ..; ./waf configure -j 8  -d release)

debug-config: clean
	(cd ..; ./waf configure -j 8 -d debug)

hello: hello.o
	g++ -o hello $<

debug-sandbox:
	(ulimit -m 1000000)
	(cd ..; ./waf --run sandbox --command-template="gdb --args %s -ex run")
	
sandbox:
	(ulimit -m 1000000)
	(cd ..; ./waf --jobs=8 --run sandbox)

debug:
	(ulimit -m 1000000)
	(cd ..; ./waf --jobs=8 --run eunet-simulation --command-template="gdb -ex run --args %s")

run:
	(ulimit -m 1000000)
	(cd ..; ./waf -d release --run eunet-simulation)

