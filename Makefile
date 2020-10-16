# Generic global variables

comp = g++
flags = -std=c++17 -Wall -pedantic-errors -Werror

src = src/
bin = bin/
dep = dep/

output = Main.exe

objects = $(bin)Snake.o $(bin)Grid.o $(bin)Main.o
objects2 = $(bin)WindowTester.o

# Include directory

idirs = -IC:\DevLibraries\LibSDL2\include\SDL2

# Link directory and files

ldirs = -LC:\DevLibraries\LibSDL2\lib
libs = -lmingw32 -lSDL2main -lSDL2

# Virtual paths

vpath %.cpp $(src)
vpath %.hpp $(src)

# Global labels

all : $(output)

clean :
	rm -f $(objects) $(objects2) $(output)
	@echo "    [ SUCCESS ] Intermediate objects and executable removed"

# Helper labels

$(output) : $(objects) $(objects2)
	rm -f $@
	$(comp) $^ $(flags) $(idirs) $(ldirs) $(libs) -o $@
	@echo "    [ SUCCESS ] Executable $@ built"
	
# Pattern rule for general compilation

$(bin)%.o : %.cpp
	$(comp) $(flags) $< -c -o $@
	@echo "    [ SUCCESS ] $< --> $@"

# Dependency rules

$(bin)Snake.o : Snake.hpp SnakeDirection.hpp GridPoint.hpp
$(bin)Grid.o : Grid.hpp GridCell.hpp GridException.hpp
$(bin)Main.o : WindowTester.hpp GridPoint.hpp GridCell.hpp

# Other Dependencies
$(bin)WindowTester.o : WindowTester.hpp