#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> distancia(n, -1); //O(V)

void BFS(int s, const vector<vector<int>>& aristas){
    distancia[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v : aristas[u]){//O(E)
            if(distancia[v] == -1){
                Q.push(v);
                distancia[v] = distancia[u] + 1;
            }
        }
    }
}