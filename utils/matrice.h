#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include <cassert>
#include <iostream>

typedef double Unit;
typedef std::vector<Unit> Vector;
typedef std::vector<Vector> Matrice;

int height(const Matrice& m);
int width(const Matrice& m);

Matrice create(int height, int width);
void resize(Matrice& m, int height, int width);

Matrice add(const Matrice& a, const Matrice& b);
Matrice subtract(const Matrice& a, const Matrice& b);
Matrice multiply(const Matrice& a, const Matrice& b);
Matrice multiply(const Matrice& a, double lambda);
Matrice dot(const Matrice& a, const Matrice& b);
Matrice transpose(const Matrice& m);

Matrice function(const Matrice& m, double (*fun)(double x));
void applyFunction(Matrice& m, double (*fun)(double x));

#endif
