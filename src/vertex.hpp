#ifndef GlobalRoute__vertex_h
#define GlobalRoute__vertex_h

#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <climits>
#include <stack>
#include <map>
// #include "edge.hpp"

using namespace std;

class Edge;

class Vertex {
public:
    Vertex(){}
    Vertex(pair<int, int>p, double d = INT_MAX, Vertex* v = 0):_place(p), _distance(d), _predecessor(v) {}

    void pushEdge       (Edge* e)       { _vEdge.push_back(e); _mEdge.emplace(e->target(), e); }
    void setDistance    (double d)      { _distance = d;        }
    void setPredecessor (Vertex* v)     { _predecessor = v;     }

    inline double distance()  const         { return _distance;     }
    inline vector<Edge*>& vEdge()           { return _vEdge;        }
    inline Vertex*        predecessor()     { return _predecessor;  }
    inline pair<int, int> place()           { return _place;        }
    inline Edge*          edge(Vertex* v)   { return _mEdge[v]; }
    inline int            edgesize()        { return _vEdge.size(); }

private:
    vector<Edge*>       _vEdge;
    map<Vertex*, Edge*> _mEdge;
    double          _distance;
    Vertex*         _predecessor;
    pair<int, int>  _place;
};

#endif