#include<unodered_map>
#include<queue>
#include<list>
#include<set>

//change all the list to set if we need the traversal in lexicographic order
//i.e. if 1 connects with 4 and 8 then after 1 4 should be traversed then 8 not the other way around
// and push_back changes to insert

void prepareAdjList( unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges) {
  for( int i=0; i<edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
  queue<int> q;
  q.push(node);
  visited[node] = 1;

  while(!q.empty()) {
    int frontNode = q.front();
    q.pop();

    //store frontNOde into ans
    ans.push_back(frontNode);

    //traverse all neighbours of frontNode
    for(auto i: adjList[frontNode]) {
      if(!visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
}

//START//
vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
  unordered_map<int, list<int>> adjList;
  vector<int> ans;
  unordered_map<int, bool> visited;

  prepareAdjList(adjList, edges);

  //traverse all component of a graph
  for(int i=0; i<vertex; i++) {
    if(!visited[i]) {
      bfs(adjList, visited, ans, i);
    }
  }
}
