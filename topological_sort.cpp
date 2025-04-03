#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TopologicalSort {
private:
    void DFS(vector<int> adj[], int node, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                DFS(adj, it, visited, st);
            }
        }
        st.push(node);
    }

public:
    void main() {
        int V = 6;  
        vector<int> adj[V];

        // Define a valid DAG
        adj[0] = {1, 2}; 
        adj[1] = {3};     
        adj[2] = {3, 4};  
        adj[3] = {5};     
        adj[4] = {5};     
        adj[5] = {};      

        vector<bool> visited(V, false);
        stack<int> st;

        // Perform DFS-based topological sort
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited, st);
            }
        }

        
        // Print the topological order
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }
};

int main() {
    TopologicalSort obj;
    obj.main();
    return 0;
}
