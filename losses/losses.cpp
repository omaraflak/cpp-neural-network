#include "losses.h"

double loss::mse(const Matrix& ytrue, const Matrix& ypred) {
    assert(height(ytrue)==height(ypred) && width(ytrue)==width(ypred));
    int n = height(ytrue) * width(ytrue);
    double sum = 0.0;
    for(int i=0 ; i<height(ytrue) ; i++) {
        for(int j=0 ; j<width(ytrue) ; j++) {
            sum += pow(ytrue[i][j] - ypred[i][j], 2);
        }
    }
    sum /= n;
    return sum;
}

Matrix loss::msePrime(const Matrix& ytrue, const Matrix& ypred) {
    assert(height(ytrue)==height(ypred) && width(ytrue)==width(ypred));
    double f = 2.0 / (height(ytrue) * width(ytrue));
    return multiply(subtract(ypred, ytrue), f);
}
