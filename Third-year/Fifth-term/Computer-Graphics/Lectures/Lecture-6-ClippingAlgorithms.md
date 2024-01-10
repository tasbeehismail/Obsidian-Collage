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
+ What we will clip it and its algorithms?
	+ Point:  **P =** $(x, y)$ $$ xw_{min} \leq x \leq xw_{max} \ \&\& \ yw_{min} \leq y \leq yw_{max} $$ ![[point.png]]
	+ Line:
		+ Cohen-Sutherland -> Clip the against each four edges of clip region:
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
			+ Advantage: Good for hardware, cause bitwise operations.
		
		+ Liang-Barsky -> skipped
		  
		+ Nicholl-Lee-Nicholl
		  
	+ Polygon Fill-Area:
		+ Sutherland-Hodgeman
		+ Weiler-Atherton