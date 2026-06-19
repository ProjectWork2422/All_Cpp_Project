CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = app

all: $(TARGET)

$(TARGET): main.cpp test.cpp 
	$(CXX) $(CXXFLAGS) main.cpp  test.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
