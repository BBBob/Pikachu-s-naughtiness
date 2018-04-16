# 后缀自动机

## 洛谷 P1368 工艺
题目链接：https://www.luogu.org/problemnew/show/P1368
### 题意
求字典序最小的循环子串
### 题解
将字符串复制一遍添加到最后，建立后缀自动机。
然后沿着最小的边走 $n$ 步，即可得到答案。
