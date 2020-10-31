#ifndef FCLAYER_H
#define FCLAYER_H

#include "layer.h"
#include "../utils/utils.h"

class FCLayer : public Layer {
private:
    Matrix mWeights;
    Matrix mBias;

public:
    FCLayer(int inputSize, int outputSize);
    Matrix forwardPropagation(const Matrix& input);
    Matrix backwardPropagation(const Matrix& outputError, double learningRate);
    ~FCLayer() {}
};

#endif
