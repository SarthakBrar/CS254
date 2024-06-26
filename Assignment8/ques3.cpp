#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100005];
vector<int> present;
int edg;

struct edge {
    int src, dest, weight;
} edges[100005];

bool cmp(edge x, edge y) {
    return x.weight < y.weight;
}

void initialise(int n) {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int union1(int i, int sum) {
    int x, y;
    x = find(edges[i].src);
    y = find(edges[i].dest);
    if (x != y) {
        parent[x] = y;
        present.push_back(i);
        sum += edges[i].weight;
    }
    return sum;
}

int union2(int i, int sum) {
    int x, y;
    x = find(edges[i].src);
    y = find(edges[i].dest);
    if (x != y) {
        parent[x] = y;
        sum += edges[i].weight;
        edg++;
    }
    return sum;
}

int main() {
    int V, E;
    cin >> V >> E;

    initialise(V);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    sort(edges, edges + E, cmp);

    int sum = 0;
    for (int i = 0; i < E; i++) {
        sum = union1(i, sum);
    }

    cout << sum << "\n";

    int second_best_mst = INT_MAX;

    for (int j = 0; j < E; j++) {
        initialise(V);
        edg = 0;
        sum = 0;
        for (int i = 0; i < E; i++) {
            if (i == present[j])
                continue;
            sum = union2(i, sum);
        }
        if (edg == V - 1) {
            second_best_mst = min(second_best_mst, sum);
        }
    }

    if (second_best_mst != INT_MAX) {
        cout << second_best_mst << "\n";
    } else {
        cout << "No second best MST exists.\n";
    }

    return 0;
}
