# Hidden Markov Models (HMMs)
#### What is an HMM?
- A **<span class="red">statistical model</span>** used to describe systems that evolve over time with **<span class="red">hidden (unobservable) states</span>**.
#### Key Components
1. **States**:
   - A finite set of hidden states, $S = \{S_1, S_2, \dots, S_N\}$.
   - These states are **<span class="red">not directly visible</span>**.
2. **Observations**: Observable data, $O = \{O_1, O_2, \dots, O_T\}$, emitted by the states.
3. **Transition Probabilities (A)**: Probabilities of *moving* from one state to another, $A = P(S_{t+1} | S_t)$.
4. **Emission Probabilities (B)**: Probabilities of *observing* $O_t$ given state $S_t$, $B = P(O_t | S_t)$.
5. **Initial Probabilities ($\pi$)**: Probability *distribution* over the initial states, $\pi = P(S_1)$.
#### Assumptions
1. **Markov Property**: The probability of transitioning to the next state depends only on the **<span class="red">current state</span>**, not the history of past states:
     $P(S_{t+1} | S_t, S_{t-1}, \dots, S_1) = P(S_{t+1} | S_t).$
2. **Observation Independence**: Observations depend only on the **<span class="red">current hidden state</span>**:
     $P(O_t | S_t, S_{t-1}, \dots, S_1) = P(O_t | S_t).$
#### HMM Processes
1. **State Transition**: Describes how the system transitions between hidden states over time.
2. **Observation Generation**: Describes the probability of generating an observation from a hidden state.
#### Inference Problems in HMM
1. **Likelihood Estimation**: Calculating the probability of a sequence of observations given the model, $P(O | \lambda)$.
2. **Decoding**: Determining the **<span class="red">most likely sequence of hidden states</span>** (e.g., using the **<span class="blue">Viterbi algorithm</span>**).
3. **Learning**: Estimating model parameters $(A, B, \pi)$ from data using algorithms like the **<span class="blue">Expectation-Maximization (EM)</span>** or **<span class="blue">Baum-Welch</span>**.
#### Algorithms
1. **Forward Algorithm**: Calculates the likelihood of an observation sequence by summing over all possible state sequences.
2. **Backward Algorithm**: Computes probabilities starting from the end of the observation sequence to the beginning.
3. **Viterbi Algorithm**: Identifies the **<span class="red">most probable sequence of hidden states</span>**.
4. **Baum-Welch Algorithm**: Trains the HMM by optimizing $A, B, \pi$ using observed data.
#### Applications
- **Speech Recognition**: **<span class="blue">Models phonemes and their transitions in spoken language</span>**.
- **Natural Language Processing (NLP)**: **<span class="blue">Part-of-speech tagging, named entity recognition, and text segmentation</span>**.
- **Bioinformatics**: **<span class="blue">Gene prediction and sequence alignment</span>**.
- **Time Series Analysis**: **<span class="blue">Financial data modeling and anomaly detection</span>**.
- **Activity Recognition**: **<span class="blue">Identifying human activities from sensor data</span>**.
#### Advantages
- Handles **<span class="red">sequential data</span>** effectively.
- Provides a **<span class="red">probabilistic framework</span>** for both observable and hidden states.
- Well-suited for applications where the hidden state influences observable outcomes.
#### Limitations
- Assumes **<span class="red">independence of observations</span>** given the current state (may not hold in some datasets).
- Computationally intensive for **<span class="red">large state spaces</span>** or **<span class="red">long sequences</span>**.
- Requires careful **<span class="red">initialization</span>** and **<span class="red">tuning</span>** for effective parameter estimation.
#### Visualization
- Represented as a **<span class="red">directed graph</span>** where nodes are hidden states, edges are transitions, and observable outputs are linked to states.
----
# Self-Organizing Maps (SOMs)
#### What is a SOM?
- An **<span class="red">unsupervised learning algorithm</span>** used for **<span class="red">dimensionality reduction</span>** and **<span class="red">data visualization</span>**.
- Organizes data into a **<span class="red">lower-dimensional grid</span>** (typically 2D) while preserving the **<span class="red">topological relationships</span>** between data points.
#### Key Features
1. **Topology Preservation**: Similar input data points are mapped close to each other on the grid.
2. **Unsupervised Learning**: Does not require labeled data; the algorithm clusters input data based on inherent patterns.
3. **Visualization**: Useful for reducing **<span class="red">high-dimensional data</span>** into a 2D map for easy interpretation.
#### Structure
1. **Input Layer**: Represents the input data in its original dimensionality.
2. **Output Layer**: A grid of neurons (nodes) arranged in a 2D lattice (rectangular or hexagonal).
3. **Weight Vectors**: Each neuron has a weight vector of the same dimension as the input data.
#### Learning Process
1. **Initialization**: Initialize weights of all neurons randomly or based on the input data range.
2. **Training**:
   - **Select Input**: Randomly select an input vector $x$ from the dataset.
   - **Find Best Matching Unit (BMU)**: Identify the neuron whose weight vector $w_j$ is closest to $x$ using a distance metric (e.g., Euclidean distance)
   - **Update Weights**:
     - Adjust the weights of the BMU and its neighbors to move closer to $x$:
       $w_j(t+1) = w_j(t) + \alpha(t) \cdot (x - w_j(t)),$ where $\alpha(t)$ is the learning rate and $w(t)$ is the weight.
   - **Neighborhood Function**: Update weights within a defined radius around the BMU; the radius shrinks over time.
   - **Repeat**: Iterate through the process for all data points over several epochs.
#### Parameters
1. **Learning Rate ($\alpha(t)$)**: Controls the magnitude of weight updates and decreases over time.
2. **Neighborhood Radius**: Defines the extent of weight updates around the BMU and decreases over time.
#### Applications
- **Data Clustering**: **<span class="blue">Groups similar data points together in the map</span>**.
- **Dimensionality Reduction**: **<span class="blue">Reduces high-dimensional data into 2D for easier analysis</span>**.
- **Pattern Recognition**: **<span class="blue">Identifies patterns in datasets like images, texts, and sounds</span>**.
- **Anomaly Detection**: **<span class="blue">Highlights data points that do not fit into established clusters</span>**.
- **Market Segmentation**: **<span class="blue">Classifies customer data into distinct groups</span>**.
#### Advantages
- Preserves **<span class="red">data topology</span>**.
- Provides an **<span class="red">intuitive and interpretable 2D representation</span>** of high-dimensional data.
- Works well with **<span class="red">non-linear data structures</span>**.
#### Limitations
- Requires careful tuning of **<span class="red">learning rate</span>** and **<span class="red">neighborhood radius</span>**.
- Sensitive to the **<span class="red">initialization of weights</span>**.
- Computationally expensive for **<span class="red">very large datasets</span>**.
#### Visualization Techniques
1. **U-Matrix (Unified Distance Matrix)**: Shows distances between neighboring neurons to visualize clusters.
2. **Component Planes**: Displays the distribution of individual input features across the map.
#### Real-World Use Cases
- **Bioinformatics**: **<span class="blue">Analyzing gene expression data</span>**.
- **Image Processing**: **<span class="blue">Classifying image patterns or textures</span>**.
- **Finance**: **<span class="blue">Detecting fraud or segmenting customers</span>**.
- **Robotics**: **<span class="blue">Mapping and navigation tasks</span>**.