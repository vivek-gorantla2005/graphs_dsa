#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class bfs {
private:
    vector<vector<int>> matrix;
    vector<int>& ans;  
    vector<int> visited;
    int V;

public:
    bfs(int V, vector<vector<int>>& matrix, vector<int>& ans) : ans(ans) {
        this->V = V;
        this->matrix = matrix;
        visited.resize(V, 0);
    }

    void bfs_func(int node) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;  

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr); 
            
            for (int i = 0; i < V; i++) { 
                if (matrix[curr][i] == 1 && visited[i] == 0) { 
                    visited[i] = 1; 
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    int V = 5;
    vector<vector<int>> matrix = {
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 1}, 
        {1, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1}, 
        {0, 1, 0, 1, 0}
    };
    
    vector<int> ans;
    bfs b(V, matrix, ans);
    b.bfs_func(0);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
