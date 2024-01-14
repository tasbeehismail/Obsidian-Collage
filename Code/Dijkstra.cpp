#include <bits/stdc++.h>
using namespace std;


const ll N = 1e5 + 5, INF  = 2e18 + 5;

vector<pair<int, ll>>adj[N];
ll n, m, dis[N], par[N];

void dij(int src) {
    for (int i = 1; i <= n; i++) 
        dis[i] = INF;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dis[src] = 0;
    pq.emplace(0, src);

    // O((n + m) * log(m))
    while (!pq.empty()) {
        int node = pq.top().S;
        ll curCost = pq.top().F;
        pq.pop();

        if(dis[node] < curCost)
            continue;
        for(auto ch : adj[node]){

            ll child = ch.F, edgeCost = ch.S;
            ll newCost = curCost + edgeCost;

            if(dis[child] > newCost){
                par[child] = node;
                dis[child] = newCost;
                pq.emplace(dis[child], child);
            }
        }
    }
}

vector<int> getPath(int node){
    vector<int>path;

    path.push_back(node);
    while (par[node] != 1){
        node = par[node];
        path.push_back(node);
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) adj[i].clear();

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dij(1);
    if(dis[n] == INF){
        cout << "-1\n";
        return;
    }
    
    vector<int>path;
    int node = n;
    path.push_back(node);
    while (par[node] != 1){
        node = par[node];
        path.push_back(node);
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    
    for(auto i : path)
        cout << i << " ";
}
