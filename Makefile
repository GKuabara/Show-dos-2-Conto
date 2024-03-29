SRC = source/*.cpp
#SRC = source/arts.cpp source/dataset.cpp source/game.cpp source/player.cpp source/question.cpp
INCLUDE = includes/
MAIN = ./main.cpp
OUT =./game
FLAGS = -g -pthread -lm
VFLAGS = --show-leak-kinds=all --leak-check=full --track-origins=yes

do_run: 
	@make all 
	@make run

all:
	@g++ $(MAIN) $(SRC) -o $(OUT) -I $(INCLUDE) $(FLAGS)
run:
	@$(OUT) 
valgrind:
	valgrind $(VFLAGS) $(OUT)