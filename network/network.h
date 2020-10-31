#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "../layers/layer.h"

class Network {
private:
    std::vector<Layer*> mLayers;
    double (*mLoss)(const Matrix&, const Matrix&);
    Matrix (*mLossPrime)(const Matrix&, const Matrix&);

public:
    Network() {}
    void addLayers(const std::vector<Layer*>& layers);
    void use(double (*loss)(const Matrix&, const Matrix&), Matrix (*lossPrime)(const Matrix&, const Matrix&));
    void fit(const std::vector<Matrix>& input, const std::vector<Matrix>& output, int epochs, double learningRate);
    std::vector<Matrix> predict(const std::vector<Matrix>& input);
};

#endif
