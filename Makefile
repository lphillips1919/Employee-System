CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -std=c++20

# Everything to make in this directory
OBJS = main

# Make everything
all: ${OBJS}

main: Employee.o Menu.o

Employee.o: Employee.h

Menu.o: Menu.h

clean:
	del -f ${OBJS} *.o main.exe