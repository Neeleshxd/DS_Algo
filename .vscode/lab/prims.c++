#include<bits/stdc++.h>
using namespace std;

void graph(int n, int m, vector<vector<pair<int, int>>>& adj) {
  for(int i=0; i<m; i++) {
    int u, v, w;
    cout << "Enter the first vertex, the second vertex, and the weight of the edge: ";
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w)); // For undirected graph
  }
}

void prims(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    int start = 0; // Starting vertex
    key[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < n; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;

        int u = min_index;
        mstSet[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
                parent[v] = u, key[v] = weight;
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \t" << key[i] << " \n";
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<vector<pair<int, int>>> adj(n);
    graph(n, m, adj);
    prims(n, adj);
    return 0;
}