//DIJIKSTRA ALGORITHM IN C++
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

class GraphWeighted {
    vector<vector<pair<int, int> > > v;
    typedef pair<int, int> ii;
    typedef vector<ii> vii;

    int nV;
public:
    GraphWeighted(int n) {
        nV = n;
        v.resize(nV, vii());
    }

    addEdge(int src, int dest, int wt) {
        v[src].push_back(make_pair(dest, wt));
        v[dest].push_back(make_pair(src, wt));
    }

    vector<int> dijikstra(int src, int dest) {
        priority_queue<ii, vector<ii>, greater<ii>> minHeap;

        vector<int> dist(nV, 100000000);
        vector<int> burnt(nV, false);
        int wtFromSrc = 0;


        minHeap.push(make_pair(wtFromSrc, src));

        while (minHeap.empty() == false) {

            auto curVtx = minHeap.top();    //this will be burnt now !!!
            minHeap.pop();
            int curVtxId = curVtx.second;
            int wtFromSrc = curVtx.first;

            if (burnt[curVtxId]) continue;

            burnt[curVtxId] = true;
            dist[curVtxId] = wtFromSrc;

            auto& adjList = v[curVtxId];
            for (int i = 0; i < adjList.size(); ++i) {
                ii ngbr = adjList[i];
                if (burnt[ngbr.first] == false) {
                    ii newEdge(wtFromSrc + ngbr.second, ngbr.first);
                    minHeap.push(newEdge);
                }
            }
        }
        return dist;
    }
};

int main() {
    GraphWeighted G(8);
    G.addEdge(1, 2, 10);
    G.addEdge(1, 3, 80);
    G.addEdge(2, 5, 20);
    G.addEdge(2, 3, 6);
    G.addEdge(3, 4, 70);
    G.addEdge(5, 7, 10);
    G.addEdge(7, 6, 5);
    G.addEdge(5, 6, 50);

    auto ans = G.dijikstra(1, 7);
    for(int i = 0; i < ans.size(); ++i){
        cout << i << " " << ans[i] << endl; 
    }

}