#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> adj;
vector<bool> visitado;

void dfs(int v){//O(E)
    visitado[v] = true;

    for(int u : adj[v]){ //miro los vecinos de cada nodo, son como máximo E vecinos
        if(!visitado[u]){
            dfs(u);
        }
    }
}

void recorrer_todo(int n){
    visitado.assign(n, false);
    for(int i=0; i<n; i++){// O(V)
        if(!visitado[i]){
            dfs(i);// se ejecuta una vez por cada nodo
        }
    }
}
//COMPLEJIDAD TOTAL O(V+E)