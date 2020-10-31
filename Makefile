CXX = g++
FLAGS = -std=c++11
EXEC = main
OBJ = obj
BIN = bin

MKDIR_P = mkdir -p
RM_R = rm -r

.PHONY : all
all : directories examples

.PHONY : examples
examples : $(OBJ)/network.o $(OBJ)/matrix.o $(OBJ)/fc_layer.o $(OBJ)/activation_layer.o $(OBJ)/utils.o $(OBJ)/activations.o $(OBJ)/losses.o
	$(CXX) $^ examples/example1.cpp -o $(BIN)/example1 $(FLAGS)

$(OBJ)/utils.o : utils/utils.cpp utils/utils.h
	$(CXX) -c $< -o $@ $(FLAGS)

$(OBJ)/activations.o : activations/activations.cpp activations/activations.h
	$(CXX) -c $< -o $@ $(FLAGS)

$(OBJ)/losses.o : losses/losses.cpp losses/losses.h
	$(CXX) -c $< -o $@ $(FLAGS)

$(OBJ)/network.o : network/network.cpp network/network.h
	$(CXX) -c $< -o $@ $(FLAGS)

$(OBJ)/activation_layer.o : layers/activation_layer.cpp layers/activation_layer.h layers/layer.h
	$(CXX) -c $< -o $@ $(FLAGS)

$(OBJ)/fc_layer.o : layers/fc_layer.cpp layers/fc_layer.h layers/layer.h
	$(CXX) -c $< -o $@ $(FLAGS)

$(OBJ)/matrix.o : utils/matrix.cpp utils/matrix.h
	$(CXX) -c $< -o $@ $(FLAGS)

.PHONY : directories
directories :
	$(MKDIR_P) $(OBJ)
	$(MKDIR_P) $(BIN)

.PHONY : clean
clean :
	$(RM_R) $(OBJ)
	$(RM_R) $(BIN)
