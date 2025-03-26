CXX = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Card.cpp Deck.cpp Hand.cpp Johnkler.cpp Player.cpp
	$(CXX) $(OPTIONS) main.cpp Card.cpp Deck.cpp Hand.cpp Johnkler.cpp Player.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)
