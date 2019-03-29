#include "network.h"

void Network::addLayers(const std::vector<Layer*>& layers){
    this->mLayers.insert(this->mLayers.begin(), layers.begin(), layers.end());
}

void Network::use(double (*loss)(const Matrice&, const Matrice&), Matrice (*lossPrime)(const Matrice&, const Matrice&)){
    this->mLoss = loss;
    this->mLossPrime = lossPrime;
}

void Network::fit(const std::vector<Matrice>& input, const std::vector<Matrice>& output, int epochs, double learningRate){
    Matrice predicted, error;
    int samples = input.size();
    double err = 0;

    // training loop
    for(int i=0 ; i<epochs ; i++){
        for(int j=0 ; j<samples ; j++){
            // forward propagation
            predicted = input[j];
            for(int k=0 ; k<this->mLayers.size() ; k++){
                predicted = this->mLayers[k]->forwardPropagation(predicted);
            }

            // backward propagation
            error = this->mLossPrime(output[j], predicted);
            for(int k=this->mLayers.size()-1 ; k>=0 ; k--){
                error = this->mLayers[k]->backwardPropagation(error, learningRate);
            }

            // compute error (display purpose)
            err += this->mLoss(output[j], predicted);
        }
        err /= samples;
        std::cout << "Epoch " << i+1 << "/" << epochs << "\terror = " << err << std::endl;
    }
}

std::vector<Matrice> Network::predict(const std::vector<Matrice>& input){
    std::vector<Matrice> result;
    Matrice predicted;
    for(int i=0 ; i<input.size() ; i++){
        predicted = input[i];
        for(int k=0 ; k<this->mLayers.size() ; k++){
            predicted = this->mLayers[k]->forwardPropagation(predicted);
        }
        result.push_back(predicted);
    }
    return result;
}
