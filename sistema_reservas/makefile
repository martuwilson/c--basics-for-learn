CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
SRC = main.cpp $(wildcard src/*.cpp)
OUT = reservas

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
