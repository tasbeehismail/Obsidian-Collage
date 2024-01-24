## Error
****
+ ### Main Error Types:-
	+ #### Round off Error:
		+ Caused by representing a number approximately like:
			$\frac{1}{3} \simeq 0.33333$
			$\sqrt{ 2 } \simeq 1.4142$
	+ #### Truncation Error:
		+ Error caused by truncating or approximating a mathematical procedure.
			+ Taking only a few terms of a Maclaurin series
			+ Using finite rectangles to approximate an integral.
****
+ ### Measuring Errors:-
	+ #### Why?
		1. To determine the accuracy of numerical results.
		2) To develop stopping criteria for iterative algorithms.
	+ #### Absolute True Error ($E_{T}$):$$=|True\ Value - Approximate\ Value|$$
	+ #### Relative True Error ($\epsilon_{T}$):$$= \frac {True \ Error}{True \ Value} * 100$$
	+ #### Absolute Approximate Error ($E_{a}$): $$=|Present\ Approximation - Previous\ Approximation|$$
	+ #### Relative Approximate Error ($\epsilon_{a}$):$$= \frac {Approximate\ Error}{Present\ Approximation} * 100$$
	+ #### How is Absolute Relative Error used as stopping criterion?
		+ ##### Pre-specified Error = Accepted Error ($\epsilon_{s}$)
			+ if |$\epsilon_{a} \le \epsilon_{s}$| -> <span class="red">stop</span>
			+ else if |$\epsilon_{a} > \epsilon_{s}$| -> <span class="green">proceed</span>



****
## Well Known Problem (Condition)
+ ##### Well-conditioned (insensitive) problem:
	+ small change in input, lead to small changes in result.
+ ##### Ill-conditioned (sensitive) problem:
	+ Any small changes in original problem, cause a dramatic changes in result.
 
 | Original Problem | |
 | :-:| :-: | 
 |![[L3-Ex1.png]]| |




 | <span class="red">Completely Different</span> | |
 | :-:| :-: | 
 |![[L3-Ex2.png]]| |


 | <span class="red">Not Has A Solution!!!</span> | |
 | :-:| :-: | 
 |![[L3-Ex3.png]]| |


