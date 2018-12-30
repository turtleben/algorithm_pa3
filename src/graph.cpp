#include "graph.hpp"

// using namespace std;
// using namespace __gnu_pbds;

void Graph::constructGraph() {
    cout<<"consturct graph .......\n";
    int h = _circuit->hTileNum();
    int v = _circuit->vTileNum();
    int i = 0, j = 0;
    while (j < v) {
        i = 0;
        while (i < h) {
            pair<int, int> p = make_pair(i, j);
            Vertex* v = new Vertex(p);
            _vVertex.push_back(v);
            _mVertex.emplace(p, v);
            i++;
        }
        j++;
    }
    i = 0, j = 0;
    while (j < v) {
        i = 0;
        while (i < h) 
        {
            if (j == 0){
                if (i == 0){
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j+1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i+1, j)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1);
                }
                else if (i == h-1){
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j+1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i-1, j)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1);
                }
                else{
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j+1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i-1, j)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i+1, j)];
                    Edge* edge2 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1); vs->pushEdge(edge2);
                }
            }
            else if (j == v-1){
                if (i == 0){
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j-1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i+1, j)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1);
                }
                else if (i == h-1){
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j-1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i-1, j)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1);
                }
                else{
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j-1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i-1, j)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i+1, j)];
                    Edge* edge2 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1); vs->pushEdge(edge2);
                }
            }
            else{
                if (i == 0){
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j-1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i, j+1)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i+1, j)];
                    Edge* edge2 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1); vs->pushEdge(edge2);
                }
                else if (i == h-1){
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j-1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i, j+1)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i-1, j)];
                    Edge* edge2 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1); vs->pushEdge(edge2);
                }
                else{
                    Vertex* vs = _mVertex[make_pair(i, j)];
                    Vertex* vt = _mVertex[make_pair(i, j-1)];
                    Edge* edge = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i, j+1)];
                    Edge* edge1 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i+1, j)];
                    Edge* edge2 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vt = _mVertex[make_pair(i-1, j)];
                    Edge* edge3 = new Edge(_circuit->capacity(), 1, vt, vs);
                    vs->pushEdge(edge); vs->pushEdge(edge1); vs->pushEdge(edge2); vs->pushEdge(edge3);
                }
            }
            i++;
        }
        j++;
    }
    int totaledge = 0;
    for (int i = 0; i < _vVertex.size(); ++i) {
        totaledge += _vVertex[i]->edgesize();
    }
    // cout<<"vertex size = "<<_vVertex.size()<<endl;
    // cout<<"edge size = "<<totaledge<<endl;
}

void Graph::initialSingleSource(Vertex* source) {
    // cout<<"initial songle source ....\n";
    for (unsigned i = 0; i < _vVertex.size(); ++i) {
        _vVertex[i]->setDistance((double)INT_MAX);
        _vVertex[i]->setPredecessor(0);
    }
    source->setDistance(0);
}

stack<pair<int, int>> Graph::shortestPath(Vertex* source, Vertex* target) {
    initialSingleSource(source);
    // cout<<"shortest path ....\n";
    __gnu_pbds::priority_queue<Vertex*, Cmp, pairing_heap_tag> pQueue;
    map<Vertex* , __gnu_pbds::priority_queue<Vertex*, Cmp, pairing_heap_tag>::point_iterator> a_it;
    
    for (unsigned i = 0; i < _vVertex.size(); ++i) {
        a_it.emplace(_vVertex[i] , pQueue.push(_vVertex[i]));
    }
    while(pQueue.size() != 0) {
        Vertex* u = pQueue.top();
        pQueue.pop();
        vector<Edge*> vEdge = u->vEdge();
        for (unsigned i = 0; i < vEdge.size(); ++i) {
            Vertex* v = vEdge[i]->target();
            if (v->distance() > u->distance() + vEdge[i]->weight()) {
                v->setDistance(u->distance() + vEdge[i]->weight());
                v->setPredecessor(u);
                pQueue.modify(a_it[v] ,v);
            }
        }
    }
    stack<pair<int, int>> step;
    while (target != 0 && target->predecessor() != 0) {
        // cout<<"target "<<target->place().first<<" "<<target->place().second<<endl;
        step.push(target->place());
        Vertex* source = target;
        target = target->predecessor();
        // cout<<"target "<<target->place().first<<" "<<target->place().second<<endl;
        // cout<<"predecessor ..."<<endl;
        // cout<< "edge "<< target->edge(source)<<endl;
        target->edge(source)->addDemand();
        target->edge(source)->updateWeight(); 
        // cout<<"update weight..."<<endl;
    }
    step.push(source->place());
    return step;
}

void Graph::solve() {
    constructGraph();
    // cout<<"net size = "<<_circuit->netSize()<<endl;
    for (unsigned i = 0; i < _circuit->netSize(); ++i) {
        Net* net = _circuit->net(i);
        Vertex* source = _mVertex[net->source()];
        Vertex* target = _mVertex[net->target()];
        // cout<<"source "<<net->source().first<<" "<<net->source().second<<endl;
        stack<pair<int, int>> step = shortestPath(source, target);
        // cout<<"path .... step size = "<<step.size()<<endl;
        while (step.size() >= 2) {
            vector<pair<int, int>> v;
            v.push_back(step.top());
            // cout<<step.top().first<<" "<<step.top().second<<endl;
            step.pop();
            v.push_back(step.top());
            net->pushPath(v);
        }
    }
    // for (int i = 0; i < _vVertex.size(); ++i) {
    //     vector<Edge*> v = _vVertex[i]->vEdge();
    //     for (int j = 0; j < v.size(); ++j){
    //         v[j]->resetdemand();
    //     }
    // }
    // for (unsigned i = 0; i < _circuit->netSize(); ++i) {
    //     Net* net = _circuit->net(i);
    //     Vertex* source = _mVertex[net->source()];
    //     Vertex* target = _mVertex[net->target()];
    //     // cout<<"source "<<net->source().first<<" "<<net->source().second<<endl;
    //     stack<pair<int, int>> step = shortestPath(source, target);
    //     // cout<<"path .... step size = "<<step.size()<<endl;
    //     while (step.size() >= 2) {
    //         vector<pair<int, int>> v;
    //         v.push_back(step.top());
    //         // cout<<step.top().first<<" "<<step.top().second<<endl;
    //         step.pop();
    //         v.push_back(step.top());
    //         net->pushPath(v);
    //     }
    // }
}