#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class DijkstraAlgo {
public:
    DijkstraAlgo(int V, vector<vector<pair<int, int>>>& adj) {
        this->V = V;
        this->adj = adj;
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (distance + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
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

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Enter edge (u, v, weight): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // Assuming undirected graph
    }

    DijkstraAlgo dijkstraAlgo(V, adj);

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> dist = dijkstraAlgo.dijkstra(src);

    cout << "Shortest distances from source " << src << ":" << endl;
    for(int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
    }

    return 0;
}
