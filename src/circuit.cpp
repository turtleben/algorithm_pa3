#include "circuit.hpp"

using namespace std;

struct CmpByBoundingAndLength {
    bool operator() (const Net* net1, const Net* net2) {
        int n1 = net1->boundingBox(); int n2 = net2->boundingBox();
        int w1 = net1->wireLength(); int w2 = net2->wireLength();
        if ( n1 < n2) return true;
        else if (n1 == n2 && w1 < w2) return true;
        else return false;
    }
} compare;

void  Circuit::setBoundingBox() {
    for (unsigned i = 0; i < _vNet.size(); ++i) {
        for (unsigned j = 0; j < _vNet.size(); ++j) {
            if (i != j) {
                pair<int, int> sj = _vNet[j]->source();
                pair<int, int> tj = _vNet[j]->target();
                pair<int, int> si = _vNet[i]->source();
                pair<int, int> ti = _vNet[i]->target();
                if ( (sj.first - si.first) * (sj.first - ti.first) <= 0 && (sj.second - si.second) * (sj.second - ti.second) <= 0 )
                    _vNet[i]->addBoundingBox();
                if ( (tj.first - si.first) * (tj.first - ti.first) <= 0 && (tj.second - si.second) * (tj.second - ti.second) <= 0 )
                    _vNet[i]->addBoundingBox();
            }
        }
        _mNet.emplace(_vNet[i]->source(), _vNet[i]);
    }
    sort(_vNet.begin(), _vNet.end(), compare);
}

void  Circuit::outfile(char * filename) {
    ofstream ofs;
    ofs.open(filename);
    for (unsigned i = 0; i < _vNet.size(); ++i) {
        ofs << _vNet[i]->id() << " " << _vNet[i]->stepsize() << endl;
        for (unsigned j = 0; j < _vNet[i]->stepsize(); ++j) {
            ofs << _vNet[i]->step(j, 0).first << " " << _vNet[i]->step(j, 0).second << " ";
            ofs << _vNet[i]->step(j, 1).first << " " << _vNet[i]->step(j, 1).second << endl;
        }
    }
}