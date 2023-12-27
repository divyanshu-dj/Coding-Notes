void dfs(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &visited, vector<int> &component) {
  //ans store
  component.push_back(node);
  // mark visited 
  visited[node] = true;

  //hr connected node k liye recursive call
  for(auto i: adj[node]) {
    if(!visited[i]) {
      dfs(i, visited, adj, component);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V,int E, vector<vector<int>> &edges) {

  //prepare adjList
  unordered_map<int, list<int>> adj;
  for(int i=0; i<edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> ans;
  unordered_map<int,bool> visited;

  //for all nodes call DFS, if not visited
  for(int i=0; i<V; i++) {
    if(!vector[i]){
      vector<int> component;
      dfs(i, visited, adj, component);
      ans.push_back(component);
    }
  }
}

////////////////////////////////////////////////////////////Striver Code/////////////////////////////////////////////////////////////////////////

class Solution {
  public:
    void dfs( int node, vector<int> &ls, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        ls.push_back(node);
        
        for( auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, ls, adj, vis);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, ls, adj, vis);
        return ls;
    }
};

