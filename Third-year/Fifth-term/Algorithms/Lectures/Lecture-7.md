## NP-Problems:
+ #### Decidable Problems:
	+ There is an algorithm (TM (Turing Machine)) to solve this problem.
	+ ##### Types: 
		+ Easy Problems (Tractable Problems): There is a poly-time algorithm to solve the problem.
		+ Hard Problems (Intractable Problems): There is a <span class=red> no</span> poly-time algorithm to solve the problem.
+ #### Undecidable Problems:
	+ There is <span class="red">no</span> algorithm to solve this problem
		-> Ex: Halt Problem
		
+ You can't design Turing Machine to check another Turing Machine is true or not.
+ You can't design a program to check another program is free of logical errors or not (NOT syntax).


## Algorithm & Problem Complexity
+ #### Algorithm Complexity:
	+ $T(n)$ is the time/resources required by an algorithm $A$ of size $n$ to solve input $I$.
+ #### Problem Complexity:
	+ The complexity of problem $Q$ is time/resources required by best-known algorithm to <span class=green>solve</span> the problem.
	+ **For any problem** $Q$ should have a Solving Algorithm and a Verification Algorithm.
		+ ##### Solving Algorithm: 
			+ Given an algorithm $A$ and input $I$, the solution algorithm produce output $S$.
		+ ##### Verification Algorithm:
			+ Given Algorithm $A$ and input $I$ output $S$, it’s required to verify that $S$ is the correct output.
		+ ##### Examples:
			+ Search Problem: Give A list $L$ and input $X$, and required the position of $X$ in $L$ if exist.
				+ ###### **Solving Algorithm** → $O(n)$:
					+ Search in array what the index for element $X$.
				+ ###### **Verification Algorithm** → $O(1)$:
					+ Look for the returned index and compare the value inside with the element $X$.
			+ Sort Problem: Give A list $L$ and input $X$, and required sort the list in increasing order.
				+ ###### **Solving Algorithm** → $O(n \log n)$:
					+ Use any searching algorithm like Merge sort.
				+ ###### **Verification Algorithm** → $O(n)$:
					+ Ensure if the is sorted successfully.
		  + **For each problem:** The Complexity of verify algorithm is <span class="blue">less than or equal</span> solving algorithm.

## Complexity Classes
+ ### P-Class:
	+ Class of problem that can be <span class="red">solved</span> in **poly-time**.
+ ### NP-Class:
	+ Class of problem that can be <span class="red">verify</span> algorithm running in **poly-time**.
	+ Ex:-
		+ #### Integer Factorization Problem:
			+ The best known algorithm to solve this problem is called **General number field sieve algorithm**, it's complexity: $O( \exp(( \frac{64}{9} \log N)^{\frac{1}{3}} (\log \log N)^{\frac{2}{3}}))$, $N$ is the number of digits in integer $n$.
+ ### NP-Complete Class:
	+ Class of problem that can be <span class="red">don't have verify</span> algorithm running in **poly-time**.
	+ Ex:- 
		+ #### Traveling Salesman Problem
			+ Solved by **Decision Tree**, and its complexity **Factorial** (Non-Poly).
			+ And its verify complexity Non-Poly too, check it's shortest path again.
		+ #### Approximate algorithms
			+ Found a near optimal solution to hard problems (NP, NP-complete).
			+ Like:
				+ Genetic Algorithms
				+ Genetic Programming
				+ Ant colony Optimization
				+ Particle swarm optimization
				+ Artificial optimization
		+ #### SAT Problem (satisfiability problem)
		+ #### Clique Problem

## RSA -> used in public key encryption in SSL connections.
+ #### RSA-129: having 129 decimal digits (426 bits).
	+ using 1600 work stations.
+ #### RSA-250: having 250 decimal digits (829 bits).
	+ will take about 800,000 years to be factored.
+ #### RSA-2048: having 617 decimal digits (2048 bits).
	+ may not be factorable for many years to come.

## Cryptography:
+ #### Symmetric Encryption Example:
	+ if Alice wants to send to Bob a msg, Assume we converted each letter to its ASCII code and got the following result:
		**MSG** : 0 1 0 0 1 0 1 0 0 1
	+ And we made a balanced key (balanced means: no. of 0’s == no. of 1’s)
		**KEY** : 0 1 1 0 1 0 0 1 0 1
	+ And now we start to encrypt .. with **XOR** for example
		**Encrypted**: 0 0 1 0 0 0 1 1 0 0
	+ Now Bob receives the encrypted MSG
		**Encrypted**: 0 0 1 0 0 0 1 1 0 0
	+ Using the same key and encrypt method XOR
		**KEY** : 0 1 1 0 1 0 0 1 0 1
	+ We get the same MSG
		**MSG** : 0 1 0 0 1 0 1 0 0 1
	
	+ Notes on **Symmetric key** example:
		• The hacker has no more than 50% chance to guess the key!
		• Not Valid if they both doesn’t know each other.
		• Bob & Alice must exchange the key Face to Face or over public channel (Not Secure).

## RSA Algorithm:
*Check steps in slides from 16 to 21*
