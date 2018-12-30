#ifndef GlobalRoute__circuit__circuit_h
#define GlobalRoute__circuit__circuit_h

#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
// #include "graph.hpp"

using namespace std;

class Net {
public:
    Net() {}
    Net(int i, pair<int, int> s, pair<int, int> t) : _id(i), _source(s), _target(t) {}

    void setId          (int i)                     { _id = i; }
    void setSource      (pair<int, int> p)          { _source = p; }
    void setTarget      (pair<int, int> p)          { _target = p; }
    void pushPath       (vector<pair<int, int>> v)  { _path.push_back(v); }
    void setBoundingBox (int i)                     { _boundingBox = i; }
    void addBoundingBox ()                          { _boundingBox ++; }

    inline pair<int, int>&      source      ()          { return _source;       }
    inline pair<int, int>&      target      ()          { return _target;       } 
    inline const int            boundingBox ()    const { return _boundingBox;  }
    inline int                  id          ()          { return _id;           }
    inline int                  stepsize    ()          { return _path.size();  }
    inline pair<int, int>&      step        (int i, int j) { return _path[i][j]; }       

    inline const int wireLength   () const {
        int x = max(_source.first, _target.first) - min(_source.first, _target.first);
        int y = max(_source.second, _target.second) - min(_source.second, _target.second);
        return x + y;
    }

private:
    int                                 _id;
    int                                 _boundingBox;
    pair<int, int>                      _source;
    pair<int, int>                      _target;
    vector<vector<pair<int, int> > >    _path;
};

class Circuit {
public:
    Circuit(int c, int h, int v):_capacity(c), _hTilesNum(h), _vTilesNum(v) {}
    inline Net* net             (pair<int, int> p)  { return _mNet[p];                  }
    inline Net* net             (int i)             { return _vNet[i];                  }
    inline int& hTileNum        ()                  { return _hTilesNum;                }
    inline int& vTileNum        ()                  { return _vTilesNum;                }
    inline int& capacity        ()                  { return _capacity;                 }
    inline int  netSize         ()                  { return _vNet.size();              }

    void        insertNet       (Net* net )         { _mNet.emplace(net->source(), net);}
    void        pushNet         (Net* net)          { _vNet.push_back(net);             }
    void        setBoundingBox  ();
    void        outfile         (char * filename);
    
private:
    vector<Net*> _vNet;
    map<pair<int, int>, Net*> _mNet;
    int _hTilesNum;
    int _vTilesNum;
    int _capacity;
};

#endif