# Old Driver Tree

## Codeforces 896C Willem, Chtholly and Seniorious
题目链接：http://codeforces.com/contest/896/problem/C
### 题意
维护一个支持如下操作的数据结构：
- 区间修改
- 区间加
- 区间求第 $k$ 大
- 区间求 $\sum_{i=l}^r a_i^x \mod y$

数据随机

### 题解
注意到有区间修改操作并且数据随机，所以我们只要ODT暴力搞就可以了。
时间复杂度 $O(n \log n)$

