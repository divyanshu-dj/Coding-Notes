int main() {
  int n, m;
  cin>>n>>m;
  int graph[n+1][m+1] = 0;
  
  for( int i=0, i<m, i++) {
    int u, v;
    cin>>u>>v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  return 0;
}
