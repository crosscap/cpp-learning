.PHONY: all clean

all: user

user: user.o Vector.o
	g++ -o user user.o Vector.o

user.o: user.cpp
	gcc -c user.cpp

Vector.o: Vector.cpp
	gcc -c Vector.cpp

clean:
	rm -f user user.o Vector.o
