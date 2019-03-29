CXX = g++
EXEC = main
OBJ = obj
BIN = bin

MKDIR_P = mkdir -p
RM_R = rm -r

.PHONY : all
all : directories program

.PHONY : program
program : $(OBJ)/main.o $(OBJ)/network.o $(OBJ)/matrice.o $(OBJ)/fc_layer.o $(OBJ)/activation_layer.o $(OBJ)/utils.o $(OBJ)/activations.o $(OBJ)/losses.o
	$(CXX) $^ -o $(BIN)/$(EXEC)

$(OBJ)/main.o : main.cpp
	$(CXX) -c $< -o $@

$(OBJ)/utils.o : utils/utils.cpp utils/utils.h
	$(CXX) -c $< -o $@

$(OBJ)/activations.o : activations/activations.cpp activations/activations.h
	$(CXX) -c $< -o $@

$(OBJ)/losses.o : losses/losses.cpp losses/losses.h
	$(CXX) -c $< -o $@

$(OBJ)/network.o : network/network.cpp network/network.h
	$(CXX) -c $< -o $@

$(OBJ)/activation_layer.o : layers/activation_layer.cpp layers/activation_layer.h layers/layer.h
	$(CXX) -c $< -o $@

$(OBJ)/fc_layer.o : layers/fc_layer.cpp layers/fc_layer.h layers/layer.h
	$(CXX) -c $< -o $@

$(OBJ)/matrice.o : utils/matrice.cpp utils/matrice.h
	$(CXX) -c $< -o $@

.PHONY : directories
directories :
	$(MKDIR_P) $(OBJ)
	$(MKDIR_P) $(BIN)

.PHONY : clean
clean :
	$(RM_R) $(OBJ)
	$(RM_R) $(BIN)
