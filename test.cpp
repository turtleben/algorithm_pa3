#include<cstdio>
#include<ext/pb_ds/priority_queue.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using namespace __gnu_pbds;

struct Cmp {
    bool operator() (const int v1, const int v2) {
        return v1 < v2; 
    }
} ha;

int main() {
    // __gnu_pbds::priority_queue<int, Cmp > pq;
    // pq.push(5);
    // pq.push(4);
    // pq.push(3);
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    map<int, int, Cmp> v;
    v.emplace(3, 3);
    v.emplace(2,2);
    v.emplace(5, 5);
    // sort(v.begin(), v.end(), ha);
    cout<<v.begin()->second<<endl;
}