all: SingleBoard.cpp MultiBoard.cpp main.cpp
	g++ -o ultimate SingleBoard.cpp MultiBoard.cpp main.cpp
clean:
	rm ultimate