#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

#include <cmath>

namespace activation {
    double sigmoid(double x);
    double sigmoidPrime(double x);
    double tanh(double x);
    double tanhPrime(double x);
}

#endif
