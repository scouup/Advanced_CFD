### 
We shall solve the transient laminar flow problem numerically, by the following algorithm: the explicit Euler scheme in time, and central finite-difference in space,

$$
\frac{u_{j}^{n+1} - u_{j}^{n}}{\Delta t} = g + \nu \frac{u_{j-1}^{n} - 2u_{j}^{n} + u_{j+1}^{n}}{\Delta y^{2}}, 
$$

where:  
- $\Delta y = 2L/N$,  
- $u_{j}^{n} = u(y_{j}, t_{n})$ with $y_{j} = -L + (j - 1)\Delta y$,  
- $t_{n} = n\Delta t$ ($n = 0, 1, 2, 3, \ldots$).  

The two end nodes $j = 1$ and $j = N + 1$ are located on the channel walls.  

**Assumptions:**  
- $L = 1$,  
- $u_{0} \equiv gL^{2}/(2\nu) = 1$,  
- $\nu = 0.1$.  

**Time step size:**  

$\Delta t = 0.32 \frac{\Delta y^{2}}{\nu}$.

### Key Details:  
1. **Numerical Scheme:**  
   - Explicit Euler in time.  
   - Central finite-difference in space.  

2. **Boundary Conditions:**  
   - No-slip walls at $j=1$ and $j=N+1$ ($u_1^n = u_{N+1}^n = 0$).  

3. **Derived Quantities:**  
   - Gravity term $g = \frac{2\nu u_0}{L^2} = 0.2$.  
   - Time step $\Delta t = 3.2 \Delta y^2$ (since $\nu = 0.1$).  

**Note:** The scheme is conditionally stable (CFL condition requires $0.32 < 0.5$ for stability).  

