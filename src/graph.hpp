#ifndef GlobalRoute__graph__graph_h
#define GlobalRoute__graph__graph_h

#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <climits>
#include <stack>
#include <ext/pb_ds/priority_queue.hpp>
#include "edge.hpp"
#include "vertex.hpp"
#include "circuit.hpp"

using namespace std;
using namespace __gnu_pbds;

// class Edge {
// public:
//     Edge(){}
//     Edge(int c, double w, Vertex* t, Vertex* s):_capacity(c), _weight(w), _target(t), _source(s) {}

//     inline Vertex* source() { return _source; }
//     inline Vertex* target() { return _target; }
//     inline double  weight() { return _weight; }

//     void addDemand()    {_demand++;}
//     void updateWeight() {}

// private:
//     int     _capacity;
//     int     _demand;
//     double  _weight;
//     Vertex* _target;
//     Vertex* _source;
// };

// class Vertex {
// public:
//     Vertex(){}
//     Vertex(pair<int, int>p, double d = INT_MAX, Vertex* v = 0):_place(p), _distance(d), _predecessor(v) {}

//     void pushEdge       (Edge* e)       { _vEdge.push_back(e); _mEdge.emplace(e->target(), e); }
//     void setDistance    (double d)      { _distance = d;        }
//     void setPredecessor (Vertex* v)     { _predecessor = v;     }

//     inline double distance()  const     { return _distance;     }
//     inline vector<Edge*>& vEdge()       { return _vEdge;        }
//     inline Vertex*        predecessor() { return _predecessor;  }
//     inline pair<int, int> place()       { return _place;        }
//     inline Edge*          edge(Vertex* v) { return _mEdge[v]; }

// private:
//     vector<Edge*>       _vEdge;
//     map<Vertex*, Edge*> _mEdge;
//     double          _distance;
//     Vertex*         _predecessor;
//     pair<int, int>  _place;
// };

struct Cmp {
    bool operator() (const Vertex* v1, const Vertex* v2) {
        double d1 = v1->distance(), d2 = v2->distance();
        return d1 > d2; 
    }
};

class Graph {
public:
    Graph() {}
    void pushVertex     (Vertex* v)     { _vVertex.push_back(v);}
    void setCircuit     (Circuit* c)    { _circuit = c;         }
    
    void constructGraph     ();
    void initialSingleSource(Vertex* source);
    void solve              ();  
    stack<pair<int, int>> shortestPath       (Vertex* source, Vertex* target);
private:
    vector<Vertex*>                 _vVertex;
    map<pair<int, int>, Vertex*>    _mVertex;
    Circuit*                        _circuit;
};

#endif