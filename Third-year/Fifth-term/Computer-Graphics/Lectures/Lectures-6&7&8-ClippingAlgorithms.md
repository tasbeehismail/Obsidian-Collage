## Defintion:
+ Remove extra parts <span class="red">"portion"</span> of output primitives outside clipping window.
+ *complex* geometry than rectangular boxes.

| Clipping Window | Viewport |
|-----| -----|
| select what we will see from world | indicates where it is to be viewed on the output device|

![[2D-clipping.png]]

+ We can use any shape but usually a clipping regions is a rectangle in standard position.
+ Used to:
	+ extract a designated portion of scene (2D or 3D).
	+ antialias object boundaries, to mange multi-window environment.
	+ allow parts of picture to be moved, copied or erased.
+ ## What we will clip it and its algorithms?
	+ ### Point:  **P =** (x, y) $$ xw_{min} \leq x \leq xw_{max} \ \&\& \ yw_{min} \leq y \leq yw_{max} $$ ![[point.png]]
	
	+ ### Line:
		+ #### Cohen-Sutherland -> Clip the against each four edges of clip region:
			1. If both endpoints of line outside **one** edge, <span class="red">discard</span>. *(Trivial Case)*
			2. If both endpoints inside for **all** edges, <span class="green">done</span>. *(Trivial Case)*
			3. If one in and one out, need **calculation**.
				1. Define test bits for a point -> ABRL for above, bottom, right and left. -> 0: in, 1: out.
				2. while both endpoint are not inside, clip for each 4 edge and update their values.
			+ Implementation:  
				```embed-cpp
				PATH: "vault://Code/clipLine-algo1.cpp"
				```
			+ Disadvantage: Fixed order Testing, cause needless clipping (external intersections). 
			+ Efficient when it accept and reject trivially:
				+ If clip window very large than scene data -> most primitives are accepted.
				+ If clip window very small than scene data -> most primitives are rejected.
			+ Advantage: 
				+ Good for hardware, cause bitwise operations.
				+ Easy with 3D scenes.
		
		+ #### Liang-Barsky -> skipped 
			+ Easy with 3D scenes.
		  
		+ #### Nicholl-Lee-Nicholl (NLN) -> Creating more regions around the clipping window, it avoids multiple line-intersection calculations:
			+ Trivial acceptance or rejection (Initial testing) is not possible, so can be done using Cohen-Sutherland method.
			+ compared to Liang-Barsky it preforms fewer comparisons and divisions.
			+ Applied only to 2D clipping, because it is very complex and long comparison with 3D.
			+ ##### Algorithm:
				+ For line with endpoints P_0 P_end, there are 3 different positions to consider, and all others derived from these by symmetry considerations.
					+ inside clipping window.
					+ in an edge region.
					+ in a corner region.
				+ For each case:
					+ Use simple test for P_end with (<span class="red">slope</span>, >, <).
					+ And find which of 4 regions lies in.
					+ Then calculate the line intersection with the corresponding boundary.
				+ Case 1 -> when P_0 is inside: **short line will be accept in cohen-sutherland testing**.
				 ![[case1-NLN.png]]
				+ Case 2 -> when P_0 is in an edge region: **3 cases with 3 probabilities, one of them will be reject in cohen-sutherland testing**.
				 ![[case2-NLN.png]]
				 + Case 3 -> when P_0 is in corner region: **2 possibilities (above, left of the clipping window) each has 3 cases with 3 probabilities, one of them will be reject in cohen-sutherland testing**.
				  ![[case3-NLN.png]]
				+ To determine in which region P_end lies we compare slope of line P_0 P_end to slopes of the boundaries of the NLN regions.
					+ For example,  with LT in case 2:
				 $$ \dfrac{y_{T} - y_{0}}{x_{R} - x_{0}} < \dfrac{y_{end} - y_{0}}{x_{end} - x_{0}} < \dfrac{y_{T} - y_{0}}{x_{L} - x_{0}} $$
			+ ##### Advantages:
				+ Simple and efficient.
				+ Fast and robust, can handle a wide variety of input line segments.
			+ ##### Disadvantages:
				+ **Not** guaranteed to find the optimal solution.
				+ Can be <span class="red">computationally expensive</span>.
				+ Can produce <span class="red">unpredictable results</span>. if input data not formatted.
				+ <span class="red">unsuitable for 3D</span>, because number of cases very large.
	
	+ ### Polygon Fill-Area: is a 2D geometric figure has a finite number of sides, made of straight lines connected to each other.
		+ <span class="yellow">We can't apply line-clipping method, because it not produce a closed poly-line and not have an information to how close boundary around clipped fill area.</span>
		+ #### Sutherland-Hodgeman: for convex-polygon
			1. Send the polygon vertices trough each clipping stage.
			2. Check each edge of the polygon against all window boundaries. **(LRBT)**
			3. The output is sequence of vertices define the clipped polygon boundaries.
			+ ##### Algorithm:
				+ V1 outside, V2 inside -> V1_new, V2
				+ V1 inside, V2 inside -> V1, V2
				+ V1 inside, V2 outside -> V1, V2_new
				+ V1 outside, V2 outside -> none
				  but this is made a repeated points, so to facilitate it and passing from one stage to next we will:
				  + out -> in (V1_new, V2)
				  + in -> in (V2)
				  + in -> out (V1_new)
				  + out -> out (none)
				   ![[polygonClipping-accurate.png]] 
			+ ##### Disadvantages: 
				+ Make extraneous lines for concave polygon, but correctly with convex polygons.
				+ Clipping other shapes: Circle, Ellipse, Curve can't applied with it.
				+ Clipping a shape in Circle window or any curve window (not rectangle) can't applied with it.
	
		+ #### Weiler-Atherton: 
			+ <span class="red">No extra</span> clipping outside window.
			+ Works for <span class="red">arbitrary</span> shapes. 
			+ Avoids <span class="red">degenerate</span> polygons.
			+ ##### Algorithm:
				+ For a **counterclockwise** traversal:
					1. For an <span class="green">outside-to-inside</span>, follow the <span class="red">polygon boundary</span>.
					2. For an <span class="green">inside-to-outside</span>, follow the <span class="red">clipping window boundary</span>.
				   ![[Weiler-Atherton.png]]
			+ ##### Disadvantages:  
				+ Extended to **complex** situations with arbitrary window.
				+ Stability **issues** arises for some cases.

+ ###  Note!!!
|Convex|Concave|
|-----| -----|
|All interior angles < 180| At least one angle > 180 and < 360|
|All diagonals inside the closed figure| At least one diagonal outside the close figure|

![[convexVsConcave.png]]