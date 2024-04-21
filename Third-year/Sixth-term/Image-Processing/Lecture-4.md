| Convolution                                                                                       | Correlation                                                                                                      |
| ------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| To combining two signal with to form a third signal                                               | To compare two signals                                                                                           |
| Continuous:<br>y(t) = x(t) $\bigotimes$ h(t)<br>= $\int_{-\infty}^{\infty} x(\tau)h(t-\tau)d\tau$ | Continuous:<br>c(t) = x(t) $\bigotimes$ h(-t) = x(t) * h(t)<br>= $\int_{-\infty}^{\infty} x(\tau)h(\tau-t)d\tau$ |
| Discrete: <br>y[n] = x[t] and h[t]<br>= $\sum_{k=-\infty}^{\infty}x[k]h[n-k]$                     | Discrete: <br>c[n] = x[t] and h[t]<br>= $\sum_{k=-\infty}^{\infty}x[k]h[k-n]$                                    |
|                                                                                                   |                                                                                                                  |

- **Correlation** of two signals is convolution between **one** signal with **inverse** of other signals.
- In **correlation** process one of the signals is rotated by 180 degree.
- Can make identical results if the signals are rotationally *symmetric*.
```bash
Convolution => two + third = cross-correlation
Correlation => signal > signal  = cross-correlation
Amplitude = cross-correlation X target signal 
```

k = 1/9 -> mean filter which smooths an image
k = 121, 000, -1-2-1 -> sobel edge detector

# Frequency analysis: 
means representing the discrete signal as a function of frequency
- Light –as a signal- is decomposed into different frequency components when emerging outside a *prism*.
- Signal *spectrum* represents signal energy/power as a function of frequency.
	- Low frequency signals
	- High frequency signals
	- Bandpass signals