#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector <int> g[N];
int vis[N];

void dfs(int node){
    for(auto child : g[node]){
        if(!vis[child]){
            vis[child] = 1;
            dfs(child);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u ,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++){
        if(vis[i])
            continue;
        vis[i] = 1;
        dfs(i);
    }
}