#ifndef FCLAYER_H
#define FCLAYER_H

#include "layer.h"
#include "../utils/utils.h"

class FCLayer : public Layer {
private:
    Matrice mWeights;
    Matrice mBias;

public:
    FCLayer(int inputSize, int outputSize);
    Matrice forwardPropagation(const Matrice& input);
    Matrice backwardPropagation(const Matrice& outputError, double learningRate);
    ~FCLayer(){}
};

#endif
