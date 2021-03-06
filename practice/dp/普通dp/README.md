# DP
## ECNU 3329 奇异收缩的剪影 HacherRank Prime XOR
题目链接0: https://www.hackerrank.com/challenges/prime-xor/problem
题目链接1: https://acm.ecnu.edu.cn/problem/3329/

### 题意
给一个有 $n$ 个数的集合,问你它的子集中异或和为素数的集合有多少个.
第一行输入一个整数 $q$，表示测试用例的个数，每个测试用例输入两行，第一行输入一个整数 $n$，代表集合的元素个数，第二行输入 $n$ 个用空格分隔的整数，代表集合的各元素。

**数据范围:**
$ 1 \le q \le 10$
$ 1 \le n \le 10^5$
$ 3500 \le a_i \le 4500$
### 题解
注意到 $a_i$ 范围很小,异或值最大也就只有 $8191$ 因此考虑 $dp[i][j]$ 表示 前 $i$ 个数的子集中异或出 $j$ 的个数.
记 $a[i]$ 的个数为 $num[a[i]]$
那么有 $dp[i][j]=dp[i-1][j]*(1+num[a[i]]/2)+dp[i-1][j \oplus {a[i]}]*((1+num[a[i]])/2)$
因此最坏时间也只有 $10^3 \times 8191 \times 10 = 8 \times 10^7$ 

