## 1. **Image Filtering Overview**
- **Purpose**:
  - <span class="red">Remove noise</span>.
  - <span class="red">Sharpen contrast</span>.
  - <span class="red">Highlight contours</span>.
  - <span class="red">Detect edges</span>.
- **Types of Filters**:
  - **Linear Filters**: Also known as <span class="red">convolution filters</span> (e.g., <span class="blue">Gaussian blur</span>, <span class="blue">averaging filter</span>).
  - **Nonlinear Filters**: Moving filter mask based on conditional operations without explicit coefficients (e.g., <span class="blue">min</span>, <span class="blue">max</span>, <span class="blue">median filter</span>).
## 2. **Spatial Filtering**
- **Definition**: Process of applying a <span class="red">filter</span> (mask/kernel/window) to an image.
- **Process**:
  - For each pixel, multiply the filter coefficients with the corresponding pixel values in the neighborhood.
  - Sum the results to get the new pixel value.
- **Mathematical Formulation**:
  - For a 3x3 filter:
   $g(x, y) = \sum_{s=-a}^{a} \sum_{t=-b}^{b} w(s, t) \cdot f(x+s, y+t)$
    Where:
    - $g(x, y)$: Output pixel value.
    - $w(s, t)$: Filter coefficients.
    - $f(x+s, y+t)$: Pixel values in the neighborhood.
### 2.1. **Smoothing Filters**
- **Purpose**: <span class="red">Reduce noise</span> and <span class="red">blur edges</span>.
- **Types**:
  1. **Standard Average Filter**: <span class="blue">Zero padding</span>.
     $\frac{1}{9} \begin{bmatrix} 1 & 1 & 1 \\ 1 & 1 & 1 \\ 1 & 1 & 1 \end{bmatrix}$
  2. **Weighted Average Filter**: <span class="blue">Zero padding</span>.
     $\frac{1}{16} \begin{bmatrix} 1 & 2 & 1 \\ 2 & 4 & 2 \\ 1 & 2 & 1 \end{bmatrix}$
  3. **Median Filter**: <span class="blue">Replicate order</span>.
     - Nonlinear filter that replaces each pixel with the <span class="red">median</span> of its neighborhood after sorting.
     - The size of the neighborhood controls the amount of smoothing.
     - **Steps**:
       1. Sort the pixel values in ascending order.
       2. Replace the center pixel with the median value.
     - **Advantages**:
       - Preserves edges better than linear smoothing filters (<span class="red">less blurring</span>).
       - Effective for removing <span class="blue">impulse noise</span> (e.g., <span class="blue">salt-and-pepper noise</span>).
     - **Disadvantages**:
       - Can erase small details and sharp corners are damaged.
       - Computationally expensive (<span class="red">Time Consuming</span>).
### 2.2. **Sharpening Filters**
- **Purpose**: <span class="red">Highlight fine details</span> and <span class="red">edges</span>.
  1. **Laplacian Filter**: <span class="blue">Replicate order</span>.
     - Second-order derivative operator.
     - Enhances edges by detecting intensity transitions.
     - Formula: $\nabla^2 f(x, y) = f(x+1, y) + f(x-1, y) + f(x, y+1) + f(x, y-1) - 4f(x, y)$
     - Sharpened image: $g(x, y) = f(x, y) + c \cdot \nabla^2 f(x, y)$
       Where $c$ is a constant (typically $c = 1$).
     - **If the filter has a negative center coefficient, then we subtract, rather than add.**
	  - **Variants**:
	     1. **Basic Laplacian**:
	        $\begin{bmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{bmatrix}$ or $\begin{bmatrix} 0 & -1 & 0 \\ -1 & 4 & -1 \\ 0 & -1 & 0 \end{bmatrix}$
	     2. **Another Laplacian**:
	        $\begin{bmatrix} 1 & 1 & 1 \\ 1 & -8 & 1 \\ 1 & 1 & 1 \end{bmatrix}$
	     3. **Composite Laplacian**: $g(x, y) = 5f(x, y) - f(x+1, y) - f(x-1, y) - f(x, y+1) - f(x, y-1)$
	        $\begin{bmatrix} 0 & -1 & 0 \\ -1 & 5 & -1 \\ 0 & -1 & 0 \end{bmatrix}$
