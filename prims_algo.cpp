#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class PrimsAlgo {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    PrimsAlgo(int V, vector<vector<pair<int, int>>> &adj) {
        this->V = V;
        this->adj = adj;
    }

    int primsMST() {
        int mst = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(V, false); 

        pq.push({0, 0});

        while (!pq.empty()) {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node]) continue;

            visited[node] = true;
            mst += weight;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (!visited[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        return mst;
    }
};

// Example usage
int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Adding edges
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});
    adj[3].push_back({4, 6});
    adj[4].push_back({3, 6});

    PrimsAlgo graph(V, adj);
    cout << "Minimum Cost of MST: " << graph.primsMST() << endl;

    return 0;
}
