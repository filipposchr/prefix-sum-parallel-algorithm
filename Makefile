name = program
src = $(wildcard *.cpp)
obj = $(src:.c=.o)

CC = g++

CFLAGS = -std=c++0x -O3

all: $(name)

$(name): $(obj)
	$(CC) $(CFLAGS) -o  $@ $^

run:
	./$(name)

clean:
	rm -f $(name)
