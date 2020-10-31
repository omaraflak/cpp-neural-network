#ifndef ACTIVATION_LAYER_H
#define ACTIVATION_LAYER_H

#include "layer.h"

class ActivationLayer : public Layer {
private:
    double (*mActivation)(double);
    double (*mActivationPrime)(double);

public:
    ActivationLayer(double (*activation)(double), double (*activationPrime)(double));
    Matrix forwardPropagation(const Matrix& input);
    Matrix backwardPropagation(const Matrix& outputError, double learningRate);
    ~ActivationLayer() {}
};

#endif
