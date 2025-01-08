#### What is SVM?
- A **supervised learning algorithm** is used for **classification** and **regression**.
- Goal: Find the **best boundary** (hyperplane) to separate data points of different classes.
#### Key Concepts
1. **Hyperplane**:
   - A decision boundary that separates classes.
   - In 2D: A line.
   - In 3D: A plane.
   - In higher dimensions: A hyperplane.
2. **Support Vectors**:
   - The data points **closest to the hyperplane**.
   - They determine the position and orientation of the hyperplane.
3. **Margin**:
   - The **distance** between the hyperplane and the nearest data points (support vectors).
   - SVM tries to **maximize this margin** for better accuracy.
#### Linear vs. Non-Linear SVM
- **Linear SVM**: Used when data is **linearly separable** (you can draw a straight line to separate classes).
- **Non-Linear SVM**: Used when data is **not linearly separable**. It uses **kernels** to map data into higher dimensions.
#### Kernels
- **Linear Kernel**: For linearly separable data.
- **Polynomial Kernel**: Maps data into polynomial space.
- **RBF Kernel**: Handles non-linear relationships.
- **Sigmoid Kernel**: Used in neural network-like applications.
#### Applications
- **Text Classification**: Spam detection.
- **Image Recognition**: Classifying images.
- **Bioinformatics**: Gene classification.
- **Financial Predictions**: Stock market analysis.
#### Advantages
- Works well in **high-dimensional spaces**.
- Memory efficient (uses only support vectors).
- Effective for **clear margin separation**.
#### Disadvantages
- Computationally expensive for **large datasets**.
- Sensitive to **kernel choice** and **parameters**.
- Struggles with **overlapping classes**.
#### Soft Margin vs. Hard Margin
- **Hard Margin**: No misclassification allowed (strict separation).
- **Soft Margin**: Allows some misclassification for better generalization (controlled by parameter **C**).
----
