#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class FloydWarshall{
    private:
        int V;
        vector<vector<int>> dist;
    public:
        // Constructor
        FloydWarshall(int V) {
            this->V = V;
            dist.resize(V, vector<int>(V, INT_MAX));
            for (int i = 0; i < V; i++) {
                dist[i][i] = 0;
            }
        }

        // Add an edge with a weight
        void addEdge(int u, int v, int weight) {
            dist[u][v] = weight;
        }

        // Run Floyd-Warshall algorithm
        void runFloydWarshall() {
            for (int k = 0; k < V; k++) {
                for(int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }

        void printDistances() {
            cout << "Shortest distances between every pair of vertices:" << endl;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][j] == INT_MAX)
                        cout << "INF ";
                    else
                        cout << dist[i][j] << " ";
                }
                cout << endl;
            }
        }
};

// Main function
int main() {
    int V = 4;
    FloydWarshall fw(V);

    // Add edges
    fw.addEdge(0, 1, 5);
    fw.addEdge(0, 2, 10);
    fw.addEdge(1, 2, 3);
    fw.addEdge(2, 3, 1);
    fw.addEdge(3, 0, 2);

    fw.runFloydWarshall();
    fw.printDistances();

    return 0;
}
