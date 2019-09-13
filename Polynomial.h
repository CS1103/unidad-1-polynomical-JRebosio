//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H


#include <vector>
#include <initializer_list>
using namespace std;


class Polynomial {

public:
    Polynomial(){};
    Polynomial( const vector<pair<double,int>> &u);
    Polynomial(initializer_list<pair<double, int>> p);
    Polynomial(const Polynomial & p);
    ~Polynomial();
    int degree();
    friend string get_expression(Polynomial p);
    friend Polynomial operator + (double, Polynomial & p);
    Polynomial operator+ (const Polynomial & p) ;
    Polynomial operator+ (const double &x);
    Polynomial operator += (const Polynomial & p);
    Polynomial operator += (const double &x);

    Polynomial operator * (const Polynomial & p) ;
    Polynomial operator * (const double &x) ;
    friend Polynomial operator * (double, Polynomial & p);

    Polynomial operator ^ (const int &x) ;


private:
    int m;
    vector<pair<double,int>> v;
};


#endif //POLINOMIO_POLINOMIO_H
