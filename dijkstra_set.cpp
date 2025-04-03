//this is dijkstra algorithm using a set data structure
#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class DijkstraAlgo {
public:
    DijkstraAlgo(int V, vector<vector<pair<int, int>>>& adj) {
        this->V = V;
        this->adj = adj;
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s; 

        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int distance = it->first;
            s.erase(it);

            for (auto edge : adj[node]) {
                int adjNode = edge.first;
                int edgeWeight = edge.second;

                if (distance + edgeWeight < dist[adjNode]) {
                    s.erase({dist[adjNode], adjNode}); 
                    dist[adjNode] = distance + edgeWeight;
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

private:
    int V;
    vector<vector<pair<int, int>>> adj;
};

int main() {
    int V, E;
    cout << "Enter number of vertices in the graph: ";
    cin >> V;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Enter edge (u, v, weight): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DijkstraAlgo dijkstraAlgo(V, adj);

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> dist = dijkstraAlgo.dijkstra(src);

    cout << "Shortest distances from source " << src << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
    }

    return 0;
}
