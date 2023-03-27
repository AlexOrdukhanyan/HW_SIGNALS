all: signal-echo_hw1

signal-echo_hw1: signal-echo_hw1.cpp
	g++ -o signal-echo_hw1 signal-echo_hw.cpp

clean:
       rm -f signal-echo_hw1
