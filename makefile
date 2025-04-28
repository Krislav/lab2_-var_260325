CC = g++
CFLAGS = -Wall -Wextra -g

SRCS = main.cpp Tests.cpp
HEADERS = ArraySequence.h ListSequence.h LinkedList.h DynamicArray.h Errors.h ImmutableArraySequence.h ImmutableListSequence.h Sequence.h Tests.h
OBJS = $(SRCS:.cpp=.o)

TARGET = result

.PHONY: all clean cleanall rebuild run rerun

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q /F $(OBJS)

cleanall:
	del /Q /F $(OBJS) $(TARGET).exe

rebuild:
	make cleanall
	make

run:
	.\$(TARGET)

rerun:
	make rebuild
	make run