#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class kruskal_algo {
private:
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}
    vector<int> parent;
    vector<int> size;

public:
    kruskal_algo(int V, vector<vector<pair<int, int>>>& adj) {
        this->V = V;
        this->adj = adj;
        parent.resize(V);
        size.resize(V, 1);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUpar(parent[u]); // Path compression
    }

    void union_size(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void getEdges() {
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it.first;
                int w = it.second;
                edges.push_back({w, {u, v}});
            }
        }
    }

    vector<pair<int, pair<int, int>>> kruskalMST() {
        sort(edges.begin(), edges.end());
        vector<pair<int, pair<int, int>>> mst;
        int mstWeight = 0;

        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;
            if (findUpar(u) != findUpar(v)) {
                mstWeight += w;
                mst.push_back(edge);
                union_size(u, v); // Connect the components
            }
        }
        cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
        return mst;
    }
};

nt main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Adding edges in adjacency list representation (undirected graph)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});

    adj[3].push_back({4, 4});
    adj[4].push_back({3, 4});

    adj[0].push_back({4, 6});
    adj[4].push_back({0, 6});

    // Create Kruskal's Algorithm Object
    kruskal_algo kruskal(V, adj);
    kruskal.getEdges();

    // Find and print the MST
    vector<pair<int, pair<int, int>>> mst = kruskal.kruskalMST();
    
    cout << "Edges in Minimum Spanning Tree:\n";
    for (auto edge : mst) {
        cout << edge.second.first << " - " << edge.second.second << " (Weight: " << edge.first << ")\n";
    }

    return 0;
}