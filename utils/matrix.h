#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cassert>
#include <iostream>

typedef double Unit;
typedef std::vector<Unit> Vector;
typedef std::vector<Vector> Matrix;

int height(const Matrix& m);
int width(const Matrix& m);

Matrix create(int height, int width);
void resize(Matrix& m, int height, int width);

Matrix add(const Matrix& a, const Matrix& b);
Matrix subtract(const Matrix& a, const Matrix& b);
Matrix multiply(const Matrix& a, const Matrix& b);
Matrix multiply(const Matrix& a, double lambda);
Matrix dot(const Matrix& a, const Matrix& b);
Matrix transpose(const Matrix& m);

Matrix function(const Matrix& m, double (*fun)(double x));
void applyFunction(Matrix& m, double (*fun)(double x));

#endif
