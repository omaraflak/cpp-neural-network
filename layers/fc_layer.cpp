#include "fc_layer.h"

FCLayer::FCLayer(int inputSize, int outputSize) : Layer() {
    resize(this->mWeights, inputSize, outputSize);
    resize(this->mBias, 1, outputSize);
    applyFunction(this->mWeights, util::randomize);
    applyFunction(this->mBias, util::randomize);
}

Matrice FCLayer::forwardPropagation(const Matrice& input){
    this->mInput = input;
    this->mOutput = add(dot(input, this->mWeights), this->mBias);
    return this->mOutput;
}

Matrice FCLayer::backwardPropagation(const Matrice& outputError, double learningRate){
    Matrice inputError = dot(outputError, transpose(this->mWeights));
    Matrice weightsGrad = dot(transpose(this->mInput), outputError);
    this->mWeights = subtract(this->mWeights, multiply(weightsGrad, learningRate));
    this->mBias = subtract(this->mBias, multiply(outputError, learningRate));
    return inputError;
}
