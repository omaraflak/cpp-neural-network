#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "../layers/layer.h"

class Network {
private:
    std::vector<Layer*> mLayers;
    double (*mLoss)(const Matrice&, const Matrice&);
    Matrice (*mLossPrime)(const Matrice&, const Matrice&);

public:
    Network(){}
    void addLayers(const std::vector<Layer*>& layers);
    void use(double (*loss)(const Matrice&, const Matrice&), Matrice (*lossPrime)(const Matrice&, const Matrice&));
    void fit(const std::vector<Matrice>& input, const std::vector<Matrice>& output, int epochs, double learningRate);
    std::vector<Matrice> predict(const std::vector<Matrice>& input);
};

#endif
