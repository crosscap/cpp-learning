.PHONY: all clean

all: user

user: user.o
	g++ -o user user.o

user.o: user.cpp
	gcc -c user.cpp

clean:
	rm -f user user.o
