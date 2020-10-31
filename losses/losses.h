#ifndef LOSSES_H
#define LOSSES_H

#include <cmath>
#include "../utils/matrix.h"

namespace loss {
    double mse(const Matrix& ytrue, const Matrix& ypred);
    Matrix msePrime(const Matrix& ytrue, const Matrix& ypred);
}

#endif
