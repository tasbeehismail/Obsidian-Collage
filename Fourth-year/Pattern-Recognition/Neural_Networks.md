## Introduction
- A method of computing based on interconnected processing elements (neurons).
- Key Features: 
	- Solve real-world problems
	- Learn from experience to improve performance
	- Can handle incomplete information 
## Neurons
- **Biological Neuron:**
	- Receive Signals
	- Processes the signal
	- Sends signals out
- **Artificial Neuron:**
	- Receive input
	- Multiplies inputs by weights
	- Applies Activation Function
	- Output the result
## Activation Functions
- Threshold Function: Outputs 1 if the input is positive, otherwise 0
- Sigmoid Function: `output = 1 / (1 + e^(-input))` (outputs a value between 0 and 1) -> "based on probability"
## Types of Neural Networks
- **Connection Type**
	- Feedforward (static): one direction
	- Feedback (dynamic): allowing the network to have memory
- **Topology**
	- Single Layer: one step
	- Multi-Layer: multiple steps
	- Recurrent
- **Learning Methods**
	- Supervised: Like training a model with labeled data (known inputs and outputs)
	- Unsupervised: Like clustering/ finding patterns data without labels
	- Reinforcement: Like optimizing a solution through trial and error
## Applications of Neural Networks
- **Pattern Recognition**: (e.g., recognizing faces or handwriting).
- **Investment Analysis**: (e.g., stock prices).
- **Control Systems**: (e.g., autonomous vehicles).
- **Marketing**: (e.g., grouping customers based on behavior).
- **Forecasting**: (e.g., weather prediction).
## Advantages of Neural Networks
- **Nonlinearity**: Can solve problems that linear programs can not.
- **Fault Tolerance**: It can keep working even if some neurons fail.
- **Learning Ability**: It learns from data without being explicitly programmed.
- **Versatility**: Can be applied to almost any problem (e.g., classification, regression, clustering).
## Disadvantages of Neural Networks
- **Training Time**: It can take a long time to train, especially for large networks.
- **Hardware Requirements**: It needs special hardware (e.g., GPUs).
- **Complexity**: It can be hard to understand and fine-tune.