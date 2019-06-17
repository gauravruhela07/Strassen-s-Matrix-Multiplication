This code is aimed to design Strassen's Matrix Multiplication which has the time complexity of O(n^2.8) which is considerably better than naive method with time complexity of O(n^3). Strassen's Method follows a divide and conquer approach to do matrix multiplication.

Divide and Conquer:
Following is simple Divide and Conquer method to multiply two square matrices.
1) Divide matrices A and B in 4 sub-matrices of size N/2 x N/2 as shown in the below diagram.
2) Calculate following values recursively. ae + bg, af + bh, ce + dg and cf + dh.
