#ifndef ACTIVATION_LAYER_H
#define ACTIVATION_LAYER_H

#include "layer.h"

class ActivationLayer : public Layer {
private:
    double (*mActivation)(double);
    double (*mActivationPrime)(double);

public:
    ActivationLayer(double (*activation)(double), double (*activationPrime)(double));
    Matrice forwardPropagation(const Matrice& input);
    Matrice backwardPropagation(const Matrice& outputError, double learningRate);
    ~ActivationLayer(){}
};

#endif
