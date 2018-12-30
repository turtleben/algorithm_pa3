#ifndef GlobalRoute__edge_h
#define GlobalRoute__edge_h

#include <iostream>
#include <utility>
#include <cstdio>
#include <climits>
#include <math.h>

using namespace std;

class Vertex;

class Edge {
public:
    Edge(){}
    Edge(int c, double w, Vertex* t, Vertex* s):_capacity(c), _weight(w = 0), _target(t), _source(s) { 
        _flag = false;
        _weight = 0;
    }

    inline Vertex* target() { return _target; }
    inline Vertex* source() { return _source; }
    inline double  weight() { return _weight; }

    void addDemand()    { _demand++; }
    void updateWeight() {
        // if (!_flag){
        if (_demand < _capacity)
            // _weight =  10 * (pow(2, _demand/_capacity));
            _weight = 10 * _demand;
            // _weight = 10 * _demand;
        else
            _weight = 100 * _demand  * _capacity;
    }
    void resetdemand() {_demand = 0; _flag = true; }

private:
    int     _capacity;
    int     _demand;
    double  _weight;
    Vertex* _target;
    Vertex* _source;
    bool    _flag;
};

#endif