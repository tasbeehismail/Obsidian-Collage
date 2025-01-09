# Support Vector Machines (SVMs)
#### What is SVM?
- A **supervised learning algorithm** used for **classification** and **regression**.
- Goal: Find the **best boundary (hyperplane)** to separate data points of different classes.
#### Key Concepts
1. **Hyperplane**:
   - A **decision boundary** that separates classes.
   - In 2D: A line.
   - In 3D: A plane.
   - In higher dimensions: A hyperplane.
2. **Support Vectors**:
   - The data points **<span class="red">closest to the hyperplane</span>**.
   - They determine the **<span class="red">position and orientation</span>** of the hyperplane.
3. **Margin**:
   - The **distance** between the hyperplane and the nearest data points (support vectors).
   - SVM tries to **<span class="red">maximize this margin</span>** for better accuracy.
4. **Optimization**:
   - SVM solves a **<span class="red">convex optimization problem</span>** to:
     - **<span class="red">Minimize classification error</span>**.
     - **<span class="red">Maximize the margin</span>**.
#### Linear vs. Non-Linear SVM
- **Linear SVM**: Used when data is **<span class="red">linearly separable</span>** (you can draw a straight line to separate classes).
- **Non-Linear SVM**: Used when data is **<span class="red">not linearly separable</span>**. It uses **<span class="red">kernels</span>** to map data into higher dimensions.
#### Kernels
- **Linear Kernel**: For **<span class="red">linearly separable data</span>**.
- **Polynomial Kernel**: Maps data into **<span class="red">polynomial space</span>**.
- **RBF Kernel**: Handles **<span class="red">non-linear relationships</span>**.
- **Sigmoid Kernel**: Used in **<span class="red">neural network-like applications</span>**.
#### Applications
- **Text Classification**: **<span class="blue">Spam detection</span>**.
- **Image Recognition**: **<span class="blue">Classifying images</span>**.
- **Bioinformatics**: **<span class="blue">Gene classification</span>**.
- **Financial Predictions**: **<span class="blue">Stock market analysis</span>**.
#### Advantages
- Works well in **<span class="red">high-dimensional spaces</span>**.
- **<span class="red">Memory efficient</span>** (uses only support vectors).
- Effective for **<span class="red">clear margin separation</span>**.
#### Disadvantages
- Computationally expensive for **<span class="red">large datasets</span>**.
- Sensitive to **<span class="red">kernel choice</span>** and **<span class="red">parameters</span>**.
- Struggles with **<span class="red">overlapping classes</span>**.
#### Soft Margin vs. Hard Margin
- **Hard Margin**: **<span class="red">No misclassification allowed</span>** (strict separation).
- **Soft Margin**: Allows some misclassification for better generalization (controlled by parameter **<span class="red">C</span>**).



----
----

# Random Forest
#### What is?
- A **supervised learning algorithm** used for **classification** ، **regression** and **feature selection**.
- Builds **multiple decision trees** and combines their results to improve accuracy and reduce overfitting.
#### Key Concepts
1. **Decision Trees**:
   - Individual predictors that split data into branches based on feature values.
   - Each tree is trained on a **<span class="red">random subset of data (bagging)</span>** and a **<span class="red">random subset of features (feature randomness)</span>**.
2. **Bagging (Bootstrap Aggregation)**:
   - Combines results from multiple trees to **<span class="red">stabilize predictions</span>**.
3. **Feature Randomness**:
   - Each tree uses a **<span class="red">random subset of features</span>** to split nodes.
   - Ensures **<span class="red">diversity among trees</span>** and improves generalization.
#### How It Works
1. Create **<span class="red">random subsets</span>** of the dataset.
2. Train a **<span class="red">decision tree</span>** on each subset using a random feature subset.
3. For **<span class="red">classification</span>**: Final prediction is the **<span class="red">majority vote</span>** of all trees. (الأغلب)
4. For **<span class="red">regression</span>**: Final output is the **<span class="red">average</span>** of predictions from all trees. (المتوسط)
#### Applications
- **Classification**: **<span class="blue">Medical diagnosis</span>**, **<span class="blue">fraud detection</span>**, **<span class="blue">customer segmentation</span>**.
- **Regression**: **<span class="blue">Predicting house prices</span>**, **<span class="blue">weather forecasting</span>**, **<span class="blue">financial modeling</span>**.
- **Feature Selection**: Identifies **<span class="blue">important variables</span>** in datasets.
#### Advantages
- **<span class="red">High Accuracy</span>**: Aggregates predictions from many trees, making it robust to noise.
- **<span class="red">Handles Overfitting</span>**: Reduces overfitting compared to single decision trees.
- **<span class="red">Works with Non-Linear Data</span>**: Handles complex relationships between features and target variables.
- **<span class="red">Feature Importance</span>**: Identifies the significance of different features in prediction.
#### Disadvantages
- **<span class="red">Computationally Intensive</span>**: Building multiple trees requires more computational power and time.
- **<span class="red">Less Interpretable</span>**: Harder to interpret compared to a single decision tree.
- **<span class="red">Sensitive to Noisy Data</span>**: Noise in the data can still influence predictions.
#### Parameters
- **Number of Trees (n_estimators)**: Controls the **<span class="red">number of decision trees</span>** in the forest.
- **Max Depth**: Limits the **<span class="red">depth of each tree</span>** to prevent overfitting.
- **Max Features**: Determines the **<span class="red">number of features</span>** to consider for splitting nodes.
- **Min Samples Split**: Minimum number of samples required to **<span class="red">split a node</span>**.