all: signal-echo_hw1

signal-echo_hw1: signal-echo_hw1.o
	g++ -o signal-echo_hw1 signal-echo_hw1.o
	
signal-echo_hw1.o: signal-echo_hw1.cpp
        g++ -c signal-echo_hw1.cpp
clean:
       rm -f signal-echo_hw1.o signal-echo_hw1
