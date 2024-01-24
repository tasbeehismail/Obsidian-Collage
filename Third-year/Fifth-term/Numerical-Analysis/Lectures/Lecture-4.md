## Numerical integration:- 
### Midpoint Method
-> The integral is approximated by the area of the <span class="green">rectangle</span>
 $$\int_{a}^{b} f(x)dx = (b-a)f(\frac{a+b}{2})$$
1- Given the width of subinterval $h$, and the integral  
2- The number of sub-intervals $$n = \frac{b-a}{h}$$
3- Draw a line have the values from $a$ to $b$, and every time $+\ h$ to next point
4- Calculate $$I = h[f(x_{0} + \frac{h}{2}) + f(x_{1} + \frac{h}{2}) + \dots + f(x_{n-1} + \frac{h}{2})]$$
****
## Trapezoidal Method
-> The integral is approximated by the area of the <span class="green">trapezoid</span>
$$\int_{a}^{b} f(x)dx = (b-a)(\frac{f(a)+f(b)}{2})$$
1- Given the width of subinterval $h$, and the integral 
2- The number of sub-intervals $$n = \frac{b-a}{h}$$
3- Draw a line have the values from $a$ to $b$, and every time $+\ h$ to next point
4- Calculate $$I = \frac{h}{2}[f(x_{0}) + 2f(x_{1}) + 2f(x_{2})+ \dots + 2f(x_{n-1}) + f(x_{n})]$$
****
## Simpsons Method
-> the integral is to approximate the function to <span class="blue">higher order polynomials</span>
-> The function is approximated by **2nd** order equation
 $$\int_{-h}^{h} f(x)dx = \int_{-h}^{h} p(x)dx = \int_{-h}^{h} (a_{0} + a_{1}x + a_{2}x^2)dx$$ $$= \frac{h}{3}[f(-h) + 4f(0) + f(h)]$$
1- Given the width of subinterval $h$, and the integral 
2- The number of sub-intervals $$n = \frac{b-a}{h}$$
3- Draw a line have the values from $a$ to $b$, and every time $+\ h$ to next point
4- Calculate $$I = \frac{h}{3}[f(x_{0}) + 4f(x_{1}) + 2f(x_{2})+ 4f(x_{3}) + 2f(x_{4}) + \dots + f(x_{n})]$$
###### Note:
 <span class="red"> *The number of sub-intervals must be even</span>
 *****

