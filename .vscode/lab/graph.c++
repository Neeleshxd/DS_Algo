#include<bits/stdc++.h>
using namespace std;

void graph(int n, int m, vector<vector<pair<int, int>>>& adj) {
  for(int i=0; i<m; i++) {
    int u, v, w;
    cout << "Enter the first vertex, the second vertex, and the weight of the edge: ";
    cin >> u >> v >> w;
    adj[u].push_back({v, w}); // u-->v directional graph with weight w
  }
}

void shortestPath(int src, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "The shortest distance from node ";
    for(int i = 0; i < n; ++i)
        cout << src << " to node " << i << " is " << dist[i] << endl;
}

int main() {
  int n;
  cout << "Enter the number of vertices: ";
  cin >> n;
  int m;
  cout << "Enter the number of edges: ";
  cin >> m;
  vector<vector<pair<int, int>>> adj(n+1);
  graph(n, m, adj);
  int src;
  cout << "Enter the source vertex for Dijkstra's algorithm: ";
  cin >> src;
  shortestPath(src, n, adj);
  return 0;
}