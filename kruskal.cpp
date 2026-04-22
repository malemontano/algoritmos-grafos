#include<vector>
#include<tuple>
#include<algorithm>
#include<iostream>
#include "DisjointSet.h"

using namespace std;

vector<tuple<int,int,int>> kruskal(vector<tuple<int,int,int>>& E, int n){
    long long res = 0;
    sort(E.begin(),E.end());
    DisjointSet dsu(n);
    
    vector<tuple<int, int, int>> agm_aristas;
    int aristas = 0;
    for(auto [w,u,v] : E){
        //u y v estan en distinta cc?
        if(dsu.find(u) != dsu.find(v)){
            dsu.unite(u,v);
            res += w; //sumo el peso
            agm_aristas.push_back({w, u, v}); //guardo nueva arista del agm
            aristas++;
            
        }
        if(aristas == n-1) break;
    }
    
    if(aristas == n-1){
        cout<<"Peso del agm: "<<res<<'\n';
        return agm_aristas;
    }else{
        cout<<"IMPOSSIBLE\n";
        return {};
    }
}

int main(){
    // ejemplo de grafo para probar agm
    int n = 5;
    vector<tuple<int, int, int>> E = {
        {1, 0, 1}, // Peso 1, conecta 0 y 1
        {7, 0, 2}, // Peso 7, conecta 0 y 2
        {3, 1, 2}, // Peso 3, conecta 1 y 2
        {4, 1, 3}, // Peso 4, conecta 1 y 3
        {5, 2, 4}, // Peso 5, conecta 2 y 4
        {2, 3, 4}, // Peso 2, conecta 3 y 4
        {6, 1, 4}  // Peso 6, conecta 1 y 4
    };

    vector<tuple<int, int, int>> aristas_agm = kruskal(E, n);

    for(auto [w, u, v]: aristas_agm){
        cout << u << " \t <-> \t " << v << " \t (Peso: " << w << ")" << endl;
    }

    return 1;
}

// Para correr el código:
// g++ kruskal.cpp -o kruskal
// ./kruskal