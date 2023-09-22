# Makefile
# Specify the compiler and compilation flags
CXX = g++
CXXFLAGS = -std=c++11

# Define the target executable name
TARGET = bin/Group15_program

# Define the source files and object files
SRCS = main.cpp src/utils/Time.cpp src/models/UserComment.cpp src/models/User.cpp src/models/Admin.cpp src/models/Motorbike.cpp src/models/UserSystem.cpp src/models/RentalRequest.cpp

# Build rule to compile the program
# $(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run:
	./$(TARGET)

.PHONY: clean
clean:
#For mac
	rm -f $(TARGET)
