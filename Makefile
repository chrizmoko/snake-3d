# Global variables

flags = -std=c++17 -Wall -pedantic-errors -Werror
comp = g++

src = src/
bin = bin/
dep = dep/

output = Main.exe

# Global labels

all: $(bin)Snake.o $(bin)Grid.o $(bin)Main.o 
	rm -f $(output)
	$(comp) $(flags) $(bin)Snake.o $(bin)Grid.o $(bin)Main.o -o $(output)

clean:
	rm -f $(bin)*.o
	rm -f $(output)

# Helper labels

$(bin)Snake.o: $(src)Snake.hpp $(src)Snake.cpp $(src)SnakeDirection.hpp $(src)GridPoint.hpp
	$(comp) $(flags) $(src)Snake.cpp -c -o $(bin)Snake.o

$(bin)Grid.o: $(src)Grid.hpp $(src)Grid.cpp $(src)GridCell.hpp $(src)GridException.hpp
	$(comp) $(flags) $(src)Grid.cpp -c -o $(bin)Grid.o

$(bin)Main.o: $(src)Main.cpp $(src)Snake.hpp $(src)GridPoint.hpp
	$(comp) $(flags) $(src)Main.cpp -c -o $(bin)Main.o
