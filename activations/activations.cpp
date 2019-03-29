#include "activations.h"

double activation::sigmoid(double x){
    return 1.0/(1.0+exp(-x));
}

double activation::sigmoidPrime(double x){
    return exp(-x)/pow(1.0+exp(-x), 2);
}
