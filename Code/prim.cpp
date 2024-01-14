void prim(int src, graph& g, int* dis, int* prev, int* cost){
	 
    for(int i = 0; i < g.nodes; i++){
        dis[i] = INT_MAX;
        cost[i] = 0;
        prev[i] = 0;
    }

    priority_queue<pair<int, int> > pq;
    pq.push({0, src});

    while(pq.size() > 0){
        int vertex = pq.top().second;
        pq.pop();
    
        cost[vertex] = 1;
      
        for(int i = g.nindex[vertex]; i < g.index[vertex + 1]; i++){
            int n = g.list[i];
            int trip = g.weight[n];
      
            if(color[n] == 0 && dist[n] > trip){
                dist[n] = trip;
                prev[n] = vertex;
                pq.push({dist[n], n});
            }
        }
    }
}
