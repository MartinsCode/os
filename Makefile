CC = gcc -pthread

default: all

all: fork fork1 fork3 hello

clean:
	rm -f foo.txt

distclean: clean
	rm -f fork
	rm -f fork1
	rm -f fork3
	rm -f hello


