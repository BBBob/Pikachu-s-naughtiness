# 线性基
## SGU 275 To xor or not to xor 
题目链接：http://acm.sgu.ru/problem.php?contest=0&problem=275
### 题意
给 $n$ 个数，求它们子集的最大异或和。
### 题解
线性基模板题，求出所有数组成的线性基后，求其异或和即为答案。
## HDU 3949 XOR
题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=3949
### 题意 
给定 $n(n \le 10000)$ 个数 $a_1, a_2, \ldots, a_n$，以及 $Q(Q\le 10000)$ 个询问，每次询问这些数（至少一个，不能不选）能够组成的异或和中第 $k$ 小的数是什么（去掉重复的异或和）。

### 题解
我们求出向量空间 $V$ 的一组线性基 $\mathfrak{B}$。因为向量空间中的任意向量 $\mathbf{u}$ 均可以被表示成 $\mathfrak{B}$ 中向量的唯一线性组合，所以 $\mathfrak{B}$ 中的任意非空子集都可以构成一个向量且互不重复。所以这些数能够组成的异或和的个数为 $2^{\vert \mathfrak{B}\vert} - 1$，特别的，如果 $\vert\mathfrak{B}\vert < n$，则必然存在一个向量组满足线性相关性，这个向量组也就能通过线性组合，异或得到 $0$，则异或和的个数为 $2^{\vert \mathfrak{B}\vert}$ 。
假设线性基中有 $m$ 个基向量，从小到大依次为 $(\mathbf{v}_0, \ldots, \mathbf{v}_{m - 1})$，则第 $k = (b_x\ldots b_0)_2$ 小的数就是：$\oplus_{0\le i\le x}b_i \cdot v_i$
