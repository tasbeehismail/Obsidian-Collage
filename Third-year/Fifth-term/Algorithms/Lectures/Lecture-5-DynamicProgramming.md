- is technique mainly an <span class="red">optimization</span> over plain recursion.
- The idea is to simply <span class="red">store</red> the results pf subproblems, so we don't have to recompute them when needed later.
- will reduce the time complexity from exponential to polynomial.
- It's guarantees correctness and efficiency, because it looks through all possible subproblems.
- A hint for solve the problem with DP, is if it can broken up to smaller and these subproblems can divided to smaller ones, and in this process you will see overlapping subproblems.

## Example:
+ Fibonacci series: $F(n) = F(n-1) + F(n-2)$ 
![[fibTree.png]]

## Approaches:
+ ### Top-down approach:
	+ here memorization is equal to the sum of the recursion and caching.
	+ ##### Advantages:
		+ Easy to understand and implement.
		+ Solve the subproblems only when it's required.
		+ East to debug.
	+ ##### Disadvantages:
		+ Occupies <span class="red">more memory</span> in the call stack, can lead sometimes to stack *overflow*.
		+ Occupies more memory degrades the overall performance.
	```c++
	static int count = 0;
	int fib(int n) {
		if(dp[n] != NULL) return dp[n];
		count++;
		if(n < 0) error;
		if(n == 0) return 0;
		if(n == 1) return 1;
		sum = fib(n-1) + fib(n-2);
		dp[n] = sum; 
	}
```

+ ### Bottom-up approach:
	+ It uses the <span class="red">tabulation</span> technique to implement DP.
	+ But it removes the recursion.
	+ So the stack not overflow, and no overhead of the recursive function.
	+ We store the result of subproblems in matrix.
	+ We start from the beginning, from base case to find the answer for the end.
	+ We use for **loop** to iterate over sub-problems.
	+ Is also known as table filling method.
	```c++
	int fib(int n){
		int A[];
		A[0] = 0, A[1] = 1;
		for( i=2; i<=n; i++){
			A[i] = A[i-1] + A[i-2]
		}
		return A[n];
	}
```

+ It solve many real-life problems such as:
	+ Make a change problem.
	+ Knapsack problem.
	+ Optimal binary search tree.