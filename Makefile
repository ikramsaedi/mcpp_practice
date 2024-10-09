.default: all

all: week01_example

clean:
	rm -f week01_example *.o

week01_example: week01_example.o  Env.o # compiled version of 
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp

# for anything that has a .o at the end, compile the c++ file, with this command
# for all .o files, will compile the 
%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^