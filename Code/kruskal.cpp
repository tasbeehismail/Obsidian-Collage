vector<vector<int>> kruskal(vector<vector<pair<int, int>>>& graph) {
	int n = graph.size();
	vector<vector<int>> result;
	vector<pair<int, pair<int, int>>> edges; // (weight, (u, v))

	for (int u = 0; u < n; ++u) {
	    for (auto& edge : graph[u]) {
	        int v = edge.first;
	        int weight = edge.second;
	        edges.push_back({weight, {u, v}});
	    }
	}

	sort(edges.begin(), edges.end());

	UnionFind uf(n);

	for (auto& edge : edges) {
	    int u = edge.second.first;
	    int v = edge.second.second;
	    int weight = edge.first;

	    if (uf.find(u) != uf.find(v)) {
	        uf.unite(u, v);
	        result.push_back({u, v, weight});
	    }
	}

	return result;
}