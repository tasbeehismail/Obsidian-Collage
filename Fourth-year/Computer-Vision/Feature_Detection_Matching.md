### 1.1 **Feature Detection**
- **Definition**: <span class="red">Identifying specific points</span> or patterns in an image with <span class="red">distinctive</span> characteristics.
- #### **Techniques**:
	- ##### **1. Edge Detection**: "<span class="red">Boundaries</span> where the image brightness changes"
	   - ==**Sobel Operator**==: Computes the <span class="red">gradient</span> of image intensity to highlight edges.
	   - ==**Canny Edge Detector**==: A <span class="red">multi-stage algorithm</span> that detects a wide range of edges.
	- ##### **2. Corner Detection**: "<span class="red">Points</span> where two or more edges meet"
	   - ==**Harris Corner Detector**==: Uses the <span class="red">differential</span> of the corner score to find corners. ---> is <span class="red">not</span> invariant to scale and rotation.
	- ##### 3. **Blob Detection**: "<span class="red">Regions</span> in the image that differ in properties"
	   - ==**Laplacian of Gaussian (LoG)**==: Detects blobs by <span class="red">finding zero-crossings</span> in the Laplacian of the image.
	   - ==**Difference of Gaussians (DoG)**==: <span class="red">Approximates</span> LoG by subtracting two blurred images.
	   - ==**SimpleBlobDetector**==: Detects blobs <span class="red">based on parameters</span> like area, circularity, and convexity.
### 1.2 **Feature Description**
- **Definition**: ==Describing== detected <span class="red">features</span> in a way that can be used for matching or recognition.
  - **Key Point**: Descriptors <span class="red">encode</span> features into ==numerical vectors== for comparison.
  - ### **Feature Descriptors**:
	1. **<span class="blue">Scale-Invariant Feature Transform (SIFT)</span>**: local features in images, <span class="red">Invariant to scale and rotation</span>.
	     - #### **Advantages**:
	       - **Locality**: Features are <span class="red">local</span>, making them robust to occlusion.
	       - **Distinctiveness**: <span class="red">Matched to a large</span> database of objects.
	       - **Quantity**: <span class="red">Many features</span> for small objects.
	       - **Efficiency**: Close to real-time <span class="red">performance</span>.
	       - **Extensibility**: Easily be extended to a wide range of <span class="red">different feature types</span>.
	     - #### SIFT Algorithm Steps
		     - ##### 1. **Scale-space Extrema Selection**
				- **Goal**: Identify potential keypoints at <span class="red">different scales</span> for <span class="red">finding features</span>.
				- **Process**:
				  - Construct a **Gaussian pyramid** by convolving the image with  <span class="red">Gaussian kernels</span> of increasing scales.
				  - Generate **Difference of Gaussians (DoG)** images by subtracting adjacent <span class="red">Gaussian-blurred images</span>.
				  - **Keypoints Detection**: Search for <span class="red">local extrema (minima or maxima)</span>. <span class ="blue">(8 neighbors + 9 next + 9 previous = 26 checks)</span>.
				- **Mathematical Formulation**:
				  - Gaussian <span class="red">blurring</span>: $L(x, y, \sigma) = G(x, y, \sigma) * I(x, y)$      ......      $G(x, y, \sigma) = \frac{1}{2\pi\sigma^2} e^{-\frac{x^2 + y^2}{2\sigma^2}}$
				    - Where:
				      - $L(x, y, \sigma)$: Blurred image at scale $\sigma$.
				      - $G(x, y, \sigma)$: Gaussian kernel.
				      - $I(x, y)$: Input image.
				  - Difference of Gaussians (DoG): $D(x, y, \sigma) = L(x, y, k\sigma) - L(x, y, \sigma) = L(x, y, \sigma) = (G(x, y, \sigma) - G(x, y, k\sigma)) * I(x, y)$
			- ##### 2. **Keypoint Localization**
				- **Goal**: <span class="red">Accurately locate</span> the keypoints by refining their positions.
				- **Process**:
				  - Reject  <span class="red">low-contrast</span> keypoints ==(less than a threshold, e.g., 0.03)==.
				  - Eliminate/ Get rid edge  <span class="red">are not as useful as features</span> using a method similar to the **<span class="blue">Harris Corner Detector</span>**.
				  - Refine the positions of the remaining keypoints.
			- ##### 3. **Orientation Assignment**
				- **Goal**: <span class="red">Assign an orientation</span> to each keypoint to achieve **rotation invariance**.
				- **Process**:
				  - Compute the gradient <span class="red">magnitude and orientation</span> in a region around each keypoint.
				  - Create an **orientation histogram** with <span class="blue">36 bins (each covering 10 degrees = 360 degrees)</span>.
				  - Assign the dominant orientation (==peak== in the histogram) to the keypoint.
				- **Mathematical Formulation**:
				  - Gradient magnitude: 
					  $m(x, y) = \sqrt{(L(x+1, y) - L(x-1, y))^2 + (L(x, y+1) - L(x, y-1))^2}$
				  - Gradient orientation: 
					  $\theta(x, y) = \tan^{-1}\left(\frac{L(x, y+1) - L(x, y-1)}{L(x+1, y) - L(x-1, y)}\right)$
			- ##### 4. **Keypoint Descriptor**
				- **Goal**: <span class="red">Describing</span> the keypoints <span class="blue">(highly distinctive and invariant)</span> as a high dimensional vector .
				- **Process**:
				  - Take a ==**16x16 window**== around the keypoint.
				  - Divide the window into ==**4x4 sub-blocks**== and Compute gradient orientations
				  - Create an ==**8-bin histogram**== (each bin covers $45^{\circ}$).
				  - Concatenate the histograms to form a ==**128-dimensional feature vector**== (4x4 sub-blocks × 8 bins).
			- ##### 5. **Keypoint Matching**
				- **Goal**: Match keypoints between <span class="red">two images</span>.
				- **Process**:
				  - Compare the descriptors of keypoints in different images using **<span class="blue">Euclidean distance</span>** or <span class="blue">cosine similarity</span>.
				  - Identify the <span class="red">nearest neighbors</span> for each keypoint.
### 1.3. **Feature Extraction**
- **Definition**: ==Reducing== <span class="red">a large input</span> dataset into relevant features for processing.
  - **Benefits**:
    - Less memory usage.
    - Faster processing time.
### 2. **Applications of Feature Detection and Description**
used in various computer vision applications:
- **<span class="blue">Object Recognition</span>**: Identifying and <span class="red">classifying objects</span> in an image.
- **<span class="blue">Image Matching</span>**: Finding <span class="red">similar images</span> or matching features between images.
- **<span class="blue">Motion Tracking</span>**: <span class="red">Tracking object movement</span> across a sequence of images.
- **<span class="blue">3D Reconstruction</span>**: Building <span class="red">3D models from multiple 2D</span> images.
