
## Direct Methods for Solving Linear Systems

| Properties| indirect methods| direct methods |
|----------| ------------| ---------|
| | Approximate solution |  Exact solutions |
| | Unknown number of iterations |  Known number of iterations|

###### - Swap -> $E_{i} \leftrightarrow E_{j}$
###### - Scale -> $\lambda E_{i} \to E_{i}$
###### - Pivot (Arithmetic Operation) -> $\lambda E_{i}\ ± \ E_{j}\to E_{i}$ -> just first here is changed!!

_____
#### Gauss Elimination

$$\left (\begin{bmatrix}{cc|c}  
1 & y_{0} & z_{0} & a\\  
0 & 1& z_{1} & b\\
0 & 0 & 1 & 
\end{bmatrix})\right$$
###### -> solve using back substitution 