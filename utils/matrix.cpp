#include "matrix.h"

int height(const Matrix& m) {
    return m.size();
}

int width(const Matrix& m) {
    assert(m.size()!=0);
    return m[0].size();
}

Matrix create(int height, int width) {
    return Matrix(height, Vector(width, 0));
}

void resize(Matrix& m, int height, int width) {
    m.resize(height);
    for(int i=0 ; i<height ; i++) {
        m[i].resize(width, 0);
    }
}

void display(std::ostream& os, const Matrix& m) {
    for(int i=0 ; i<height(m) ; i++) {
        for(int j=0 ; j<width(m) ; j++) {
            os << m[i][j] << " ";
        }
        os << std::endl;
    }
}

Matrix add(const Matrix& a, const Matrix& b) {
    assert(height(a)==height(b) && width(a)==width(b));
    Matrix result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++) {
        for(int j=0 ; j<width(result) ; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

Matrix subtract(const Matrix& a, const Matrix& b) {
    assert(height(a)==height(b) && width(a)==width(b));
    Matrix result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++) {
        for(int j=0 ; j<width(result) ; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}

Matrix multiply(const Matrix& a, const Matrix& b) {
    assert(height(a)==height(b) && width(a)==width(b));
    Matrix result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++) {
        for(int j=0 ; j<width(result) ; j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
    return result;
}

Matrix multiply(const Matrix& a, double lambda) {
    Matrix result = create(height(a), width(a));
    for(int i=0 ; i<height(result) ; i++) {
        for(int j=0 ; j<width(result) ; j++) {
            result[i][j] = a[i][j] * lambda;
        }
    }
    return result;
}

Matrix dot(const Matrix& a, const Matrix& b) {
    assert(width(a)==height(b));
    Matrix result = create(height(a), width(b));
    Unit sum = 0;
    for (int i=0 ; i<height(a) ; i++) {
        for (int j=0 ; j<width(b) ; j++) {
            for (int h=0 ; h<width(a) ; h++) {
                sum += a[i][h]*b[h][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }
    return result;
}

Matrix transpose(const Matrix& m) {
    Matrix result = create(width(m), height(m));
    for(int i=0 ; i<height(result) ; i++) {
        for(int j=0 ; j<width(result) ; j++) {
            result[i][j] = m[j][i];
        }
    }
    return result;
}

Matrix function(const Matrix& m, double (*fun)(double x)) {
    Matrix result = create(height(m), width(m));
    for (int i=0 ; i<height(result) ; i++) {
        for (int j=0 ; j<width(result) ; j++) {
            result[i][j] = fun(m[i][j]);
        }
    }
    return result;
}

void applyFunction(Matrix& m, double (*fun)(double x)) {
    for (int i=0 ; i<height(m) ; i++) {
        for (int j=0 ; j<width(m) ; j++) {
            m[i][j] = fun(m[i][j]);
        }
    }
}
