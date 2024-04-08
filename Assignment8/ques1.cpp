#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight > e2.weight; // Sorting in non-decreasing order of weights
}

vector<Edge> maximum_spanning_tree(vector<Edge>& edges, int n) {
    UnionFind uf(n);
    sort(edges.begin(), edges.end(), compareEdges); // Sorting edges

    vector<Edge> mst;
    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) // Adding edge to MST if it doesn't create a cycle
            mst.push_back(edge);
    }

    return mst;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.emplace_back(u, v, weight);
    }

    vector<Edge> mst = maximum_spanning_tree(edges, n);

    cout << "Maximum Spanning Tree Edges:" << endl;
    for (const auto& edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }

    return 0;
}
