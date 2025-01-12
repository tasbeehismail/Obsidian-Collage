### **1.1. Key Concepts**
- **Goal**: Convert raw image data into a simpler, more usable form.
- **Why?**:
  - Easier to understand.
  - Less memory, and faster processing.
- **What to Represent?**:
  - **<span class="red">Boundary/Shape</span>**: Object outline (e.g., <span class="blue">circle, square</span>).
  - **<span class="red">Region</span>**: Internal properties (e.g., <span class="blue">color, texture</span>).
  - **<span class="red">Relations</span>**: How objects interact (e.g., <span class="blue">connected regions</span>).
### **1.2 Representation vs. Description**
- **<span class="red">Representation</span>**: How we **encode** the information (e.g., boundary, region).
  - **Two Types**:
    1. **<span class="red">External Representation</span>**: Focuses on the **boundary** (shape).
       - Example: a circle by its outline or a square by its edges.
    2. **<span class="red">Internal Representation</span>**: Focuses on the **pixels of the region** (color, texture).
- **<span class="red">Description</span>**: How we **describe** the features of the region (e.g., length, orientation).
  - Example: Describing a boundary by its length or the orientation of a line.
### **1.3 Common Methods**
1. **<span class="red">Chain Codes</span>**: Represent boundaries using directional numbers.
2. **<span class="red">Polygonal Approximations</span>**: Approximate boundaries with polygons.
3. **<span class="red">Boundary Segments</span>**: Break boundaries into smaller parts.
4. **<span class="red">Skeletons</span>**: Represent regions using their medial axes.
---
## **2. Chain Codes**
### **2.1 What is a Chain Code?**
- **<span class="red">Definition</span>**: A sequence of numbers representing boundary directions.
- **<span class="red">Types</span>**:
  - **4-connectivity**: 4 directions (<span class="blue">right, down, left, up</span>).
  - **8-connectivity**: 8 directions (<span class="blue">including diagonals</span>).
### **2.2 Problems with Chain Codes**
1. **<span class="red">Long Codes</span>**: Complex shapes → long sequences.
2. **<span class="red">Noise Sensitivity</span>**: Small boundary changes → big code changes.
### **2.3 Resampling**
- **<span class="red">What?</span>**: Increase grid spacing and assign boundary points to grid nodes.
- **<span class="red">Why?</span>**:
  - Reduces code length.
  - Less sensitive to noise.
- **<span class="red">Trade-off</span>**: Loss of fine details.
### **2.4 Normalization**
- **<span class="red">Starting Point</span>**: Treat chain code as a circular sequence.
  - Find the smallest integer sequence.
  - **Example**: <span class="blue">`101003333222`</span> → <span class="blue">`003333222101`</span>.
- **<span class="red">Rotation</span>**: Use **<span class="red">First Difference (FD)</span>**.
  - **FD** = Number of direction changes between adjacent elements (<span class="blue">counterclockwise</span>).
  - **Example**: Chain code <span class="blue">`10103322`</span> → FD = <span class="blue">`3133030`</span>.
  - **FD is <span class="red">rotation invariant</span>**.