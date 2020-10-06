# Global variables

flags = -std=c++17 -Wall -pedantic-errors -Werror
comp = g++

src = src/
bin = bin/

output = Main.exe

# Global tags

all: $(bin)Snake.o $(bin)Main.o 
	rm -f $(output)
	$(comp) $(flags) $(bin)Main.o $(bin)Snake.o -o $(output)

clean:
	rm -f $(bin)*.o
	rm -f $(output)

# Helper tags

$(bin)Snake.o: $(src)Snake.hpp $(src)Snake.cpp $(src)SnakeDirection.hpp $(src)GridPoint.hpp
	$(comp) $(flags) $(src)Snake.cpp -c -o $(bin)Snake.o

$(bin)Main.o: $(src)Main.cpp $(src)Snake.hpp $(src)GridPoint.hpp
	$(comp) $(flags) $(src)Main.cpp -c -o $(bin)Main.o
