## Types of Errors:
#### Absolute Error:
###### Where $N$ is $Exact$, $n$ is $Approximated$ $$|e| = |N - n|$$
#### Relative Error:
###### $$|\frac{e}{N}| \sim |\frac{e}{n}|$$$$|\frac{N-n}{N}| \sim |\frac{N-n}{n}|$$
****
## Floating Point Arithmetic & Rounding

###### The Form: $$y = f_{y}*10^e + g_{y}*10^{e-t} $$
###### Where,   $0.1 < |y| < 1$
###### $$N = y,\ n = f_{y}*10^e,\ e = g_{y}*10^{e-t}$$

#### - Example (Chopping Rounding)
###### <span class="blue">-> Truncate after e digits without rounding</span>
###### $y = 12.53678,\ t = 3$
###### $f_{y} = 0.125,\ g_{y} = 0.3678,\ e = 2,\ e - t = -1$

###### $$y = 0.125 * 10^2 + 0.3678*10^{-1}$$
###### Approximated number:  $\bar{y} \ = 0.125*10^{2}$
###### Absolute Error: $|e_{y}| = |y - \bar{y}| = |0.3678*10^{-1}|$
###### Relative Error: $|\frac{e_{y}}{\bar{y}}| = 2.9424*10^{-3}$


------

#### - Example (Symmetric Rounding)
###### <span class="blue">-> Rounding up</span>
###### $y = 15.29478,\ t = 3$
###### Approximated number:  $\bar{y} \ = 0.153*10^{2}$
###### Absolute Error: $|e_{y}| = |y - \bar{y}| = 0.522*10^{-2}$
###### Relative Error: $|\frac{e_{y}}{\bar{y}}| \simeq 0.34117*10^{-3}$


###### -> The maximum bound for chopping round off error is <span class="red">double</span> that of Symmetric. (The Proof at slide 31)

-----
## Process Graph
###### - Addition Graph:

###### $$\frac{e_{y}}{y} = \frac{e_{x_{1}}}{x_{1}} . \frac{x_{1}}{y} + \frac{e_{x_{2}}}{x_{2}} . \frac{x_{2}}{y} + r_{a}$$
------
###### - Subtraction Graph: 
![[Sub-graph.png]]
###### $$\frac{e_{y}}{y} = \frac{e_{x_{1}}}{x_{1}} . \frac{x_{1}}{y} - \frac{e_{x_{2}}}{x_{2}} . \frac{x_{2}}{y} + r_{s}$$
------
###### - Multiplication Graph: 
![[Mul-graph.png]]
###### $$\frac{e_{y}}{y} = \frac{e_{a}}{a} + \frac{e_{x}}{x} + r_{m}$$
------
###### - Division Graph: 
![[Div-graph.png]]
###### $$\frac{e_{y}}{y} = \frac{e_{a}}{a} - \frac{e_{x}}{x} + r_{d}$$