#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class BellmanFord {
public:
    int V, E;
    vector<vector<int>> edges; // Stores edges as {u, v, weight}

    BellmanFord(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        //Relax all edges (V - 1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto edge : edges) {
                int u = edge[0], v = edge[1], weight = edge[2];
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // **Negative Cycle Detection**
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative weight cycle!" << endl;
                return;
            }
        }

        cout << "Vertex Distance from Source:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " -> " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
        }
    }
};

int main() {
    int V = 5; 
    int E = 8; 
    BellmanFord graph(V, E);
    
    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    graph.bellmanFord(0);
    
    return 0;
}
