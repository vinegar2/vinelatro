CXX = g++
OPTIONS = -Wall
PROGRAM = main.out
TEST = test.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp Card.cpp Deck.cpp Hand.cpp Joker.cpp JokerPool.cpp ShopItem.cpp Player.cpp
	$(CXX) $(OPTIONS) main.cpp Card.cpp Deck.cpp Hand.cpp Joker.cpp JokerPool.cpp ShopItem.cpp Player.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)