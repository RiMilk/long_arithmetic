CC=g++
CFLAGS=-c -Wall
SOURSE= long_arithmetic/long_arithmetic.cpp long_arithmetic/value.cpp long_arithmetic/value.h long_arithmetic/LongArithmeticOperation.cpp long_arithmetic/LongArithmeticOperation.h
OBJECTS=$(SOURSE:.cpp=.o)
EXECUTABLE=longa


all:	$(SOURSE) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	del *.o $(EXECUTABLE).exe