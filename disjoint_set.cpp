#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // Initialize parent of each element as itself
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Path compression
    int findUparent(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = findUparent(parent[u]);n
    }

    // Union by rank
    void unionRank(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if (ulp_u == ulp_v) return; // Already in the same set

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by size
    void unionSize(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if (ulp_u == ulp_v) return; // Already in the same set

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    // Check if two elements belong to the same set
    bool isConnected(int u, int v) {
        return findUparent(u) == findUparent(v);
    }
};

int main() {
    DisjointSet ds(7); // 7 elements

    ds.unionRank(1, 2);
    ds.unionRank(2, 3);
    ds.unionRank(4, 5);
    ds.unionRank(6, 7);
    ds.unionRank(5, 6);

    cout << "Is 3 and 7 connected? " << (ds.isConnected(3, 7) ? "Yes" : "No") << endl;
    
    ds.unionRank(3, 7); // Connect 3 and 7
    cout << "Is 3 and 7 connected after union? " << (ds.isConnected(3, 7) ? "Yes" : "No") << endl;

    return 0;
}
