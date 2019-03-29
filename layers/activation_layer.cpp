#include "activation_layer.h"

ActivationLayer::ActivationLayer(double (*activation)(double), double (*activationPrime)(double)){
    this->mActivation = activation;
    this->mActivationPrime = activationPrime;
}

Matrice ActivationLayer::forwardPropagation(const Matrice& input){
    this->mInput = input;
    this->mOutput = function(input, this->mActivation);
    return this->mOutput;
}

Matrice ActivationLayer::backwardPropagation(const Matrice& outputError, double learningRate){
    return multiply(outputError, function(this->mInput, this->mActivationPrime));
}
