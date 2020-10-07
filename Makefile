# Global variables

comp = g++
flags = -std=c++17 -Wall -pedantic-errors -Werror

src = src/
bin = bin/
dep = dep/

output = Main.exe

obs = $(bin)Snake.o $(bin)Grid.o $(bin)Main.o

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
	$(comp) $(flags) $^ -o $@

# Pattern rule for general compilation

$(bin)%.o : $(src)%.cpp
	$(comp) $(flags) $< -c -o $@
	@echo built $@ from $<

# Dependency rules
$(bin)Snake.o : $(src)Snake.hpp $(src)SnakeDirection.hpp $(src)GridPoint.hpp
$(bin)Grid.o : $(src)Grid.hpp $(src)GridCell.hpp $(src)GridException.hpp
$(bin)Main.o : $(src)Snake.hpp $(src)GridPoint.hpp