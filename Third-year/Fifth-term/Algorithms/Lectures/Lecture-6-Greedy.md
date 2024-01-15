+ ## Graph Traversals
	+ #### DFS: 
		+ It is use a <span class="red">stack</span> to keep track of:
			+ nodes to be visited next, or
			+ nodes that we have already visited.
		+ It is "aggressive" in the sense that it examines complete paths.
		![](https://github.com/tasbeehismail/Obsidian-Collage/blob/main/Third-year/Fifth-term/Algorithms/Images/dfs.png)
		```embed-cpp
			PATH: "vault://Code/DFS.cpp"
		```
	+ #### BFS:
		+ It is use a <span class="blue">queue</span> to keep track of:
			+ nodes to be visited next, or
			+ nodes that we have already visited.
		+ It is "cautious" in the sense that it examines every path of length $i$ before going on to paths of length $i+1$.
		![](https://github.com/tasbeehismail/Obsidian-Collage/blob/main/Third-year/Fifth-term/Algorithms/Images/bfs.png)
		```embed-cpp
			PATH: "vault://Code/BFS-and-importantFunctions.cpp"
		```
	 ##### -> Both are O(V+E) complexity
		
+ ## Minimum Spanning Trees (MST)
	+ #### Problem: Laying Telephone Wire: 
		+ ###### Naive approach: ![[wiring1.png]]
		+ ###### Better approach: will minimize the total length of wire connecting the customers.
    	![](https://github.com/tasbeehismail/Obsidian-Collage/blob/main/Third-year/Fifth-term/Algorithms/Images/wiring2.png)
	
	+ It is a subgraph of an undirected weighted graph $G$, such that:
		+ It is a tree (acyclic).
		+ It covers all the vertices $V$, contains $V - 1$ edges.
		+ The total cost with tree edges is the minimum among all possible spanning trees.
		+ No necessarily unique.
	![](https://github.com/tasbeehismail/Obsidian-Collage/blob/main/Third-year/Fifth-term/Algorithms/Images/mst.png)

	+ ### We have two algorithms to generate a MST:
		+ #### Prim: (build tree incrementally)
			+ pick lowest cost edge connected to known (incomplete) ST that does not create a cycle.
			+ expand to include it in the tree.
			```embed-cpp
				PATH: "vault://Code/prim.cpp"
			 ```
		  *Revision The solution and steps of problems in algorithm from slides 19 to 40*
	  
		+ #### Kruskal: (build forest that will finish as a tree)
			+ pick lowest cost edge not yet in a tree that does not create a cycle.
			+ expand the set include edges to include it.
			+  Implementation using adjacency list, priority queues and disjoint sets.
				```embed-cpp
					PATH: "vault://Code/kruskal.cpp"
			   	```
			*Revision The solution and steps of problems in algorithm from slides 43 to 74*

+ ## Dijkstra’s Algorithm
	+ **Single-Source Shortest Path Problem:** is finding the shortest path from src vertex to all other vertices in the graph.
	+ #### Application: 
		+ Maps (Mao Quest, Google Maps)
		+ Routing System
	+ Works on both directed and undirected graphs. and all edges must have non-negative weights.
	+ #### Approach:
		+ Compute for each vertex u the distance to $u$ from the start vertex $v$, that is, the weight of a shortest path between $v$ and $u$.
		+ Keep track of the set of vertices for which the distance has been computed، called $C$.
		+ The algorithm will update a $D[u]$ value when finds a shorter path from $v$ to $u$.
		+ When add the vertex $u$ to $C$, the distance will be equal to final distance between the starting vertex $v$ and vertex $u$.
	*Revision The solution and steps of problem in algorithm from slides 82 to 99*
	```embed-cpp
		PATH: "vault://Code/Dijkstra.cpp"
	```
