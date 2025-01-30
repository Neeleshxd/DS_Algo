#include<bits/stdc++.h>
using namespace std;

void graph(int n, int m, vector<vector<int>>& adj) {
  for(int i=0; i<m; i++) {
    int u, v;
    cout << "Enter the first vertex and the second vertex of the graph: ";
    cin >> u >> v;
    adj[u].push_back(v); // u-->v directional graph
  }
}
void dfs(int node, vector<vector<int>>& adj, vector<int>& li, vector<int>& vis) { 
  vis[node] = 1; // setting the  nodes as visited 
  li.push_back(node);// pushing the visites node in the vector 
  for(auto it : adj[node]) {
    if(!vis[it]) {  // if the node is not visited than call is again made to the function 
      dfs(it, adj, li, vis);
    }
  }
}
void dfs0fGraph(int n,int z,vector<vector<int>>&adj){ // function for calulating the dfs of the graph ..
  vector<int> vis(n+1, 0); // setting all the graphs element to not visites intially 
  int start=z;// intializing  the starting element with the element from where we want the bfs to be started..
  vector<int>li;
  dfs(start,adj,li,vis); // calling the dfs 
    cout << "DFS Traversal: ";
  for(auto it: li) { // iterating through the vector to print the  Dfs 
    cout << it << " ";

}
}
void bfs(int z,int n,vector<vector<int>>&adj){
  int vis[n+1]={0};   // initalizing all elemensts  to null;
  vector<int>bfs;
  vis[z]=1;//than set the 1 index of the vis node value to 1 
  queue<int>q;
  q.push(z);// push the node in the queue
  while(!q.empty()){
    int node=q.front();
    q.pop();     
    bfs.push_back(node);
    for(auto it:adj[node]){//checking the adjacent node of the passed node is visted or not 
      if(!vis[it]){
        vis[it]=1;
        q.push(it);
      }
    }
  }
  cout << "BFS Traversal: ";
  for(auto it: bfs) { // travesing in the whole graph to print values 
    cout << it << " ";
  }
}bool detect(int src,vector<vector<int>>&adj,vector<int>&vis){
  vis[src]={1};
  queue<pair<int,int>>q;// queue pair for passing adjacent node and parent 
  q.push({src,-1});
  int node=q.front().first;// the current node 
  int parent =q.front().second;// the parent node 
  q.pop();
  for(auto adjacentNode:adj[node]){// traversing the node 
   if(!vis[adjacentNode]){//if not visited
    vis[adjacentNode]=1;//than set the visited  node to 1
    q.push({adjacentNode,node});//push it to the queue
   }else if(adjacentNode!=parent){
    return true;
   }
  }
  return false;
}
bool detectCycle(int m, vector<vector<int>>&adj){//detects a cycle function 
  vector<int>vis(m,0);
  for(int i=0;i<m;i++){ // for connected components
    if(!vis[i]){
      if(detect(i,adj,vis)) return true;
    }
  
  }
    return false ;
}
bool dfs(int src,int parent,vector<vector<int>>&adj,vector<int>&vis){
  vis[src]={1};
  for(auto it:adj[src]){
    if(!vis[it]){
   if(dfs(it,src,adj,vis)==true)
    return true;
   
   else if(it!=parent){
   return true;
   }
    }
  }
 return false;
}
bool dfsdetectCy(int m,vector<vector<int>>&adj){
  vector<int>vis(m,0);
  for(int i=0;i<m;i++){
    if(!vis[i]){
      if(dfs(i,-1,adj,vis)==true);
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  cout << "Enter the number of vertices: ";
  cin >> n;
  int m;
  cout << "Enter the number of edges: ";
  cin >> m;
  int z;
  cout<<"Enter the starting vertex for bfs ";
  cin>>z;
  vector<vector<int>> adj(n+1);
  graph(n, m, adj);
  bfs(z,n,adj);
  dfs0fGraph(n,z,adj);
  bool result=detectCycle(m,adj);
  if(result==true){
    cout<<"The graph is cyclic";
  }else{
    cout<<"The graph is not cyclic ";
  }
  return 0;
}