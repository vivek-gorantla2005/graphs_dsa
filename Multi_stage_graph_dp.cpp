#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the shortest path in a multistage graph
int shortestPath(vector<vector<int>> &matrix, int stages) {
    int n = matrix.size(); 
    vector<int> cost(n, INT_MAX);
    vector<int> path(n, -1);

    cost[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != 0 && cost[j] != INT_MAX) {
                if (matrix[i][j] + cost[j] < cost[i]){
                    cost[i] = matrix[i][j] + cost[j];
                    path[i] = j;
                }
            }
        }
    }

    // Print the shortest path
    cout << "Shortest path: ";
    int start = 0;
    while (start != -1) {
        cout << start << " ";
        start = path[start];
    }
    cout << endl;
    
    return cost[0];
}

int main() {
    int stages = 4; // Example: 4 stages
    vector<vector<int>> matrix = {
        {0, 1, 2, 5, 0, 0},
        {0, 0, 0, 0, 4, 11},
        {0, 0, 0, 0, 9, 5},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    
    int result = shortestPath(matrix, stages);
    cout << "Minimum cost: " << result << endl;
    return 0;
}
