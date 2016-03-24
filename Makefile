CC=g++

EXECUTABLES=qsortCpp hsort

OBJS=qsortExampleMod.o hsortExample.o StudentRecord.o

REBUILDABLES=$(EXECUTABLES) $(OBJS)

all: $(EXECUTABLES)

clean:
	-rm -f *.o
	-rm -f $(REBUILDABLES)

qsortCpp: qsortExampleMod.o StudentRecord.o
	$(CC) -g -std=c++11 -o $@ $^

hsort: hsortExample.o StudentRecord.o
	$(CC) -g -std=c++11 -o $@ $^

*.o: *.cpp
	$(CC) -g -std=c++11 -o $@ $^

StudentRecord.o: StudentRecord.cpp StudentRecord.h

qsortExampleMod.o: qsortExampleMod.cpp LinkedList.h

hsortExample.o: hsortExample.cpp LinkedList.h