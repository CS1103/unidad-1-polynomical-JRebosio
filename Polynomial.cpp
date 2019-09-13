//
// Created by rudri on 9/12/2019.
//

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <map>

#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial(const vector<pair<double, int>> &u) {
    this->m=u.size();
    this->v=u;
}


Polynomial::Polynomial(initializer_list<pair<double, int>> p) {
    this->m=  p.size();
    v.clear();
    for (auto a: p) v.push_back(a);
}


Polynomial::Polynomial(const Polynomial &p) {
    this->m=p.m;
    this->v=p.v;
}

Polynomial::~Polynomial() {

}

int Polynomial::degree() {
    int mx=0;
    for(int i=0; i<m; i++){
        mx=max(v[i].second,mx);
    }
    return mx;
}

string get_expression(Polynomial p) {
    string s;


    for(int i=0;i<p.m;i++){
        if(p.v[i].second==0) {
            string st=to_string(p.v[i].first);
            for(auto u: st){
                if(u=='.') break;
                s.push_back(u);
            }
            continue;
        }
        else if(p.v[i].first>0) {
            s.push_back('+');
        }
        else {
            s.push_back('-');
        }

        string st=to_string(p.v[i].first);
        string zt=to_string(p.v[i].second);

        for(auto u: st){
            if(u=='-') continue;
            if(u=='.') break;
            s.push_back(u);
        }
        s.push_back('x');
        s.push_back('^');
        for(auto u: zt){
            s.push_back(u);
        }
    }

    return s;
}


Polynomial operator+(double x,  Polynomial &p) {
    Polynomial p2;
    p2=p+x;
    return p2;
}

Polynomial Polynomial::operator+(const  Polynomial &p) {
    map<int, double> map;
    Polynomial p3;
    for (auto a:p.v)
        map[a.second] += a.first;
    for (auto b: v)
        map[b.second] += b.first;

    for (auto const & k: map)
    {
        p3.v.push_back(make_pair(k.second,k.first));
    }

    p3.m=p3.v.size();

    return p3;
}


Polynomial Polynomial::operator+(const double &x) {
    Polynomial p2(*this);
    map<int, double> map;

    for(auto u: p2.v)
        map[u.second]=u.first;
    map[0]+=x;
    p2.v.clear();
    for(auto u: map)
        p2.v.push_back(make_pair(u.second,u.first));
    p2.m=p2.v.size();
    return p2;
}


Polynomial Polynomial::operator+=(const Polynomial &p) {
    *this=*this + p;
    return *this;
}

Polynomial Polynomial::operator+=(const double &x) {
    *this=*this+x;
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial &p) {
    Polynomial mt;
    for(int i=0;i<m;i++) {
        for (int j=0;j<p.m;j++)
            mt.v.push_back(make_pair(v[i].first*p.v[j].first,v[i].second+p.v[j].second ));
    }
    map<int , double> map;
    for (int i=0;i<mt.v.size();i++)
        map[mt.v[i].second]+=mt.v[i].first;

    mt.v.clear();

    for ( auto u: map) {
        if(u.second==0) continue;
        mt.v.push_back(make_pair(u.second,u.first));
    }
    mt.m=mt.v.size();
    return mt;
}

Polynomial Polynomial::operator*(const double &x) {
    Polynomial p2(v);
    for(int i=0; i<m; i++) p2.v[i].first*=x;
    return p2;
}

Polynomial operator*(double x, Polynomial &p) {
    Polynomial p2;
    p2=p*x;
    return p2;
}

Polynomial Polynomial::operator^(const int &x) {
    Polynomial o(v);
    Polynomial u(v);
    for(int i=0; i<x-1; i++)
        u=u*o;
    return u;
}

