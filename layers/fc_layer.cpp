#include "fc_layer.h"

FCLayer::FCLayer(int inputSize, int outputSize) : Layer() {
    resize(this->mWeights, inputSize, outputSize);
    resize(this->mBias, 1, outputSize);
    applyFunction(this->mWeights, util::randomize);
    applyFunction(this->mBias, util::randomize);
}

Matrix FCLayer::forwardPropagation(const Matrix& input) {
    this->mInput = input;
    this->mOutput = add(dot(input, this->mWeights), this->mBias);
    return this->mOutput;
}

Matrix FCLayer::backwardPropagation(const Matrix& outputError, double learningRate) {
    Matrix inputError = dot(outputError, transpose(this->mWeights));
    Matrix weightsGrad = dot(transpose(this->mInput), outputError);
    this->mWeights = subtract(this->mWeights, multiply(weightsGrad, learningRate));
    this->mBias = subtract(this->mBias, multiply(outputError, learningRate));
    return inputError;
}
