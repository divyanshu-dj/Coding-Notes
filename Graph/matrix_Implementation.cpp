int main() {
  // n=> num of nodes
  // m=> num of edges
  int n, m;
  cin>>n>>m;
  int graph[n+1][n+1] = 0;
  
  for( int i=0, i<m, i++) {
    int u, v;
    cin>>u>>v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  return 0;
}
