#include<iostream>
#include<vector>
using namespace std;
class dfs{
    vector<vector<int>> adj;
    vector<bool> visited;
    int V;
    dfs(int V,vector<vector<int>> adj,vector<bool> visited){
        this->V=V;
        this->adj=adj;
        this->visited=visited;
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
    }

    void dfs_func(vector<vector<int>> &adj,int node,vector<bool>&visited){
        visited[node] = true;
        for(int it : adj[node]){
            if(!visited[it]){
                dfs_func(adj,it,visited);
            }
        }
    }
};

int main(){
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);

    // Adding edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    dfs d(V,adj,visited);
    d.dfs_func(adj,0,visited);

    return 0;
}