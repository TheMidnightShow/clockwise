CC=g++ -std=c++20

S=./src
O=./obj

OBJ=							\
			$(O)/main.o	\

clockwise: $(OBJ)
	$(CC) $(OBJ) -o $@

$(O)/%.o: $(S)/%.cpp
	$(CC) $< -c -o $@
