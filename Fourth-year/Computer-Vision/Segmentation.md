## **1. What is?**
- **<span class="red">Definition</span>**: The process of partitioning an image into multiple regions or segments based on pixel characteristics.
- **<span class="red">Purpose</span>**:
  - **Separate foreground from background**: Isolate objects of interest.
  - **Cluster regions based on similarities**: Group pixels with similar color, intensity, or shape.
- **<span class="blue">Example</span>**: In medical imaging, segmentation is used to detect and label *tumors* in a patient’s brain.
## **2. Why is Important?**
- **<span class="red">Key Benefits</span>**:
  - **Object Isolation**: Isolate objects of interest for further analysis.
  - **Pattern Recognition**: First step in recognizing patterns
  - **Region of Interest (ROI) Processing**: Focus on specific parts.
## **3. Approaches to Image Segmentation**
##### **3.1 Discontinuity-Based** (Boundary)
- **<span class="red">Definition</span>**: Partitioning an image based on ==sharp changes== in intensity (e.g., edges, lines, points).
- **<span class="red">Methods</span>**:
  - **Edge Detection**: Identify/ Locate boundaries between regions. ---> Derivative-based edge detectors are <span class="red">sensitive to noise</span>
    - **Gradient-Based**: Sobel, Prewitt, Roberts.
    - **Gaussian/ Laplacian-Based**: Canny edge detection, Laplacian of Gaussian (LoG).
  - **Line Detection**: Detect one-pixel-wide lines (horizontal, vertical, diagonal $45^{\circ}, -45^{\circ}$). <span class="blue">Operations: Filtering, Thresholding</span> 
  - **Point Detection**: Detect isolated points of intensity change. <span class="blue">Using: Laplacian Filter</span>
##### **3.2 Similarity-Based (Region)**
- **<span class="red">Definition</span>**: Partitioning an image into **regions** with ==similar== properties (e.g., intensity, color, texture).
- **<span class="red">Methods</span>**:
  - **Thresholding** -> <span class="blue">Example</span>: **Global** (single threshold) & **Local** (different thresholds)
  - **Region-Based** -> <span class="blue">Example</span> **Region Growing** & **Region Splitting and Merging**
  - **Clustering-Based**
## **4. Edge Detection**
#### 4.1 What is an Edge?
- **<span class="red">Definition</span>**: A set of connected points that lie on the boundary between two regions.
- **<span class="red">Edge Models</span>**:
  - **Step Edge**: A Sudden/ abrupt change in intensity.
  - **Ramp Edge**: Gradual transition in intensity.
  - **Roof Edge**: A peak or ridge in intensity.
#### 4.2 Techniques: 

1. **<span class="blue">First-Order Derivatives</span>**: (**Gradient operator**) measures the rate of change of pixel intensity.
   - ##### Image Gradient and Its Properties: 
	- The **gradient** of an image $f$ at location $(x, y)$ is denoted by $\nabla f = \text{grad}(f) = \begin{bmatrix} {g_{x}} \\ g_{y} \end{bmatrix} = \begin{bmatrix} \frac{\partial f}{\partial x} \\ \frac{\partial f}{\partial y} \end{bmatrix}$ 
	- The **magnitude** of the gradient vector $\nabla f$, denoted as: $M(x, y) = \text{mag}(\nabla f) = \sqrt{\left(g_{x}\right)^2 + \left(g_{y}\right)^2}$
	- The **direction** of the gradient vector is given by the angle: $\alpha(x, y) = \tan^{-1}\left(\frac{g_{y}}{g_{x}}\right)$
   - ##### Common Edge Detectors:
	   - **Sobel Operator (0, 1, 2)**: Uses two `3x3` <span class= "red">convolution</span> kernels, one for changes in x-direction ==(horizontal)== and y-direction ==(vertical)==.
	   - **Prewitt Operator (0, 1)**: Similar to Sobel but with different kernels.
	   - **Roberts Cross Operator (0,1)**: Detects diagonal edges using `2x2` kernels.
   - ##### Steps in Edge Detection:
	1. **Filtering**: Apply a kernel (e.g., Sobel, Prewitt) to detect edges.
	2. **Gradient Calculation**: Compute the gradient magnitude and direction.
	3. **Thresholding** <span class="red">(Optional)</span>: Highlight significant edges and suppress noise.
----
2. **<span class="blue">Second-Order Derivatives</span>**: (**Laplacian Operator**) measures the rate of change of the first derivative.
   - Useful for detecting edges: 
	   - using <span class="red">Convolution</span> with a Laplacian kernel/ mask.
	   - using zero-crossings in the second derivative.
   - Used to highlight areas of rapid intensity change.
   - Is very sensitive to noise.
   - ##### Laplacian of Gaussian (LoG)
	- **<span class="red">Definition</span>**: A technique that combines Gaussian smoothing with Laplacian edge detection.
	- **<span class="red">Purpose</span>**: Reduces noise while detecting edges involves **smoothing**
	- **<span class="blue">Example</span>**: Detecting edges in noisy medical images.