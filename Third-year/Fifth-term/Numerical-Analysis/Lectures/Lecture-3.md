## Bisection Method
 1- Find $x_{r}$  $$x_{r} = \frac {x_{u}+x_{l}}{2}$$
2- Calculate $f(x)$ for $x_{u}, x_{l}, x_{r}$
3- Compare the sign of the result of $f(x)$
4- For the next iteration, make the interval between $-, +$
5- Calculate $E_{a}$ after the second iteration for $x_{r}$, and <span class="red">stop</span> when $E_{a} \leq E_{s}$

-> Number of iterations: $$n > \log_{2}{\frac{x_{u}-x_{l}}{E_{s}}}$$
##### Advantages:
+ It always converges.
+ It’s the only method which is easy to determine the number of iteration needed.
##### Disadvantages:
+ It’s convergence is slow.

****
## Secant Method
1- Find $c$ $$c = b - f(b) \cdot \frac{b-a}{f(b) - f(a)} $$
2- For the next iteration, the interval will be -> $a = b,\ b = c$
3- <span class="red">Stop</span> when $|f(c)| \leq E_{s}$

##### Advantages:
+ If it reaches the solution it will converge faster than the <span class="blue">bisection</span> method.
##### Disadvantages:
+ It may not reach a solution (it diverts), as in <span class="blue">Bisection</span> method, we check the **sign** of $f(a)$ and $f(b)$ but in <span class="blue">Secant</span> we could discard the part that had a root

****





## False Position Method
1- Find $c$ $$c = b - f(b) \cdot \frac{b-a}{f(b) - f(a)} $$
2- Calculate $f(x)$ for $a, b, c$
3- Compare the sign of the result of $f(x)$
4- For the next iteration, make the interval between $-, +$
5- <span class="red">Stop</span> when $|f(c)| \leq E_{s}$

**-> This method <span class="green">faster</span> than Bisection method.**

*****
## Newton Raphson Method
1- Find $x_{i+1}$ $$x_{i+1} = x_{i} - \frac{f(x_{i})}{f`(x_{i})}$$
2- <span class="red">Stop</span> when $|x_{i+1}-x_{i}| \leq E_{s}$
