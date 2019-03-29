#include "matrice.h"

int height(const Matrice& m){
    return m.size();
}

int width(const Matrice& m){
    assert(m.size()!=0);
    return m[0].size();
}

Matrice create(int height, int width){
    return Matrice(height, Vector(width, 0));
}

void resize(Matrice& m, int height, int width){
    m.resize(height);
    for(int i=0 ; i<height ; i++){
        m[i].resize(width, 0);
    }
}

void display(std::ostream& os, const Matrice& m){
    for(int i=0 ; i<height(m) ; i++){
        for(int j=0 ; j<width(m) ; j++){
            os << m[i][j] << " ";
        }
        os << std::endl;
    }
}

Matrice add(const Matrice& a, const Matrice& b){
    assert(height(a)==height(b) && width(a)==width(b));
    Matrice result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++){
        for(int j=0 ; j<width(result) ; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

Matrice subtract(const Matrice& a, const Matrice& b){
    assert(height(a)==height(b) && width(a)==width(b));
    Matrice result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++){
        for(int j=0 ; j<width(result) ; j++){
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

Matrice multiply(const Matrice& a, const Matrice& b){
    assert(height(a)==height(b) && width(a)==width(b));
    Matrice result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++){
        for(int j=0 ; j<width(result) ; j++){
            result[i][j] = a[i][j] * b[i][j];
        }
    }
    return result;
}

Matrice multiply(const Matrice& a, double lambda){
    Matrice result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++){
        for(int j=0 ; j<width(result) ; j++){
            result[i][j] = a[i][j] * lambda;
        }
    }
    return result;
}

Matrice dot(const Matrice& a, const Matrice& b){
    assert(width(a)==height(b));
    Matrice result = create(height(a), width(b));
    Unit sum = 0;
    for (int i=0 ; i<height(a) ; i++){
        for (int j=0 ; j<width(b) ; j++){
            for (int h=0 ; h<width(a) ; h++){
                sum += a[i][h]*b[h][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }
    return result;
}

Matrice transpose(const Matrice& m){
    Matrice result = create(width(m), height(m));
    for(int i=0 ; i<height(result) ; i++){
        for(int j=0 ; j<width(result) ; j++){
            result[i][j] = m[j][i];
        }
    }
    return result;
}

Matrice function(const Matrice& m, double (*fun)(double x)){
    Matrice result = create(height(m), width(m));
    for (int i=0 ; i<height(result) ; i++){
        for (int j=0 ; j<width(result) ; j++){
            result[i][j] = fun(m[i][j]);
        }
    }
    return result;
}

void applyFunction(Matrice& m, double (*fun)(double x)){
    for (int i=0 ; i<height(m) ; i++){
        for (int j=0 ; j<width(m) ; j++){
            m[i][j] = fun(m[i][j]);
        }
    }
}
