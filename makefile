CC=g++ -std=c++20

S=./src
O=./obj

OBJ=							\
			$(O)/main.o	\
			$(O)/program.o	\

clockwise: $(OBJ)
	$(CC) $(OBJ) -o $@

$(O)/%.o: $(S)/%.cpp
	$(CC) $< -c -o $@
