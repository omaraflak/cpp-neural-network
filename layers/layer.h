#ifndef LAYER_H
#define LAYER_H

#include "../utils/matrice.h"

class Layer {
protected:
    Matrice mInput;
    Matrice mOutput;

public:
    Layer(){}
    virtual Matrice forwardPropagation(const Matrice& input)=0;
    virtual Matrice backwardPropagation(const Matrice& outputError, double learningRate)=0;
    virtual ~Layer(){}
};

#endif
