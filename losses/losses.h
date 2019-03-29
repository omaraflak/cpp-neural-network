#ifndef LOSSES_H
#define LOSSES_H

#include <cmath>
#include "../utils/matrice.h"

namespace loss {
    double mse(const Matrice& ytrue, const Matrice& ypred);
    Matrice msePrime(const Matrice& ytrue, const Matrice& ypred);
}

#endif
