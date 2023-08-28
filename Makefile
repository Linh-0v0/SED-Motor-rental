# Makefile

CC = g++
CFLAGS = -std=c++11
SOURCES = src/models/User.cpp src/models/Motorbike.cpp src/services/RentalSystem.cpp src/utils/InputValidation.cpp main.cpp
EXECUTABLE = motorbike-rental

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
