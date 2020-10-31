#include "utils.h"

void util::initRand() {
    srand(time(0));
}

double util::randomize(double x) {
    return ((double) rand() / RAND_MAX - 0.5);
}
