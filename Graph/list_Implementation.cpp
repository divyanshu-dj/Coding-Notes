int main() {
  int n, m;
  cin>>n>>m;
  vector<int> graph[n+1];

  for( int i=0; i<m; i++) {
    int u, v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  return 0;
}




///////////////////////////////Approach 2////////////////////////////////////////
#include<list>
using namespace std;
template <typename T>

class graph {
public:
  unordered_map<T, list<T> adj;

  void addEdge(T u, T v, bool direction) {
    //direction = 0 => undirected
    //direction = 1 => directed graph

    //create an edge from u to v
    adj[u].push_back(v);
    if(direction == 0) 
      adj[v].push_back(u);
  }
  void printAdjList(){
    for(auto i:adj) {
      cout<< i.first<<"->";
      for(auto j:i.second) {
        cout<<j<<",";
      }
      cout<<endl;
    }
  }
};

