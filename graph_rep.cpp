#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool>& visited) {
    cout << node << " ";
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

void BFS(int n, vector<int> adj[]) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;
    
    vector<int> adj[n + 1]; // 1-based index
    
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << "Adjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    cout << "\nBFS Traversal: ";
    BFS(n, adj);
    
    cout << "\nDFS Traversal: ";
    vector<bool> visited(n + 1, false);
    DFS(1, adj, visited);
    
    return 0;
}