#include "activation_layer.h"

ActivationLayer::ActivationLayer(double (*activation)(double), double (*activationPrime)(double)) {
    this->mActivation = activation;
    this->mActivationPrime = activationPrime;
}

Matrix ActivationLayer::forwardPropagation(const Matrix& input) {
    this->mInput = input;
    this->mOutput = function(input, this->mActivation);
    return this->mOutput;
}

Matrix ActivationLayer::backwardPropagation(const Matrix& outputError, double learningRate) {
    return multiply(outputError, function(this->mInput, this->mActivationPrime));
}
