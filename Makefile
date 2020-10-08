# Generic global variables

comp = g++
flags = -std=c++17 -Wall -pedantic-errors -Werror

src = src/
bin = bin/
dep = dep/

output = Main.exe

obs = $(bin)Snake.o $(bin)Grid.o $(bin)Main.o

# Variables to third party libraries

SDL2_h = $(dep)SDL2/include
SDL2_link = -L$(dep)SDL2/lib -lmingw32 -lSDL2main -lSDL2

# Virtual paths

vpath %.cpp $(src)
vpath %.hpp $(src)

# Global labels

all : $(output)

clean :
	rm -f $(obs) $(output)

# Helper labels

$(output) : $(obs)
	rm -f $@
	$(comp) $(flags) $(SDL2_link) $^ -o $@
	

# Pattern rule for general compilation

$(bin)%.o : %.cpp
	$(comp) $(flags) -I$(SDL2_h) $< -c -o $@
	@echo "    [ SUCCESS ] $< --> $@"

# Dependency rules

$(bin)Snake.o : Snake.hpp SnakeDirection.hpp GridPoint.hpp
$(bin)Grid.o : Grid.hpp GridCell.hpp GridException.hpp
$(bin)Main.o : Snake.hpp GridPoint.hpp
