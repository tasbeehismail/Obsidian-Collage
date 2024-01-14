vector<int> adj[N];
int dis[N], par[N];

# BFS code:
int n, m;
vector<int> adj[N];
int dis[N], par[N];
void BFS(int src){// O(n + m)
    clr(dis, OO);
    queue<int> q;
    dis[src] = 0;
    par[src] = src;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child : adj[node]){
            if(dis[child] == OO) { //first visit give us the least distance, and the best path
                q.push(child);
                dis[child] = dis[node] + 1;
                par[child] = node;
            }
        }
    }
}
--------------------------------------------------------------------------------------------------------------------
# is cyclic?
make queue with pairs(child, parent) //the cause of child in queue in parent
and after is !visited do ->
    else if(child != parent){ // one child have two parents
        cout << "YES";
--------------------------------------------------------------------------------------------------------------------
# is one connected or count connected components:
int c = 0;
loop(i, 1, n + 1){ // for in nodes
    if(dis[i] == OO){
        //c++; //BFS(i);
        cout << "NO";
        return;
    }
}
--------------------------------------------------------------------------------------------------------------------
# get the shortest path from src to node:
vector<int> getPath(int node, int src){
      vector<int> path{node};
      do{
          node = par[node];
          path.push_back(node);
      }while(node != src);

      reverse(all(path));

      return path;
}
--------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------
# isBipartite check code:
int bi[N];
bool isBipartite(int src){// two sets, not have edges between every node in one set
    // *notes -> any cycle in graph have (odd) nodes so it not bipartite
    // -> it can be biColored
    clr(bi, OO);
    queue<int> q;
    bi[src] = 1;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child : adj[node]){
            if(bi[child] == OO) {
                q.push(child);
                bi[child] = 3 - bi[node]; // 1 for set1, 2 for set2 other is not declared
            }else if(bi[child] == bi[node]){
                return false;
            }
        }
    }
    return true;
}
