# 牛客小白月赛2
题目地址：https://www.nowcoder.com/acm/contest/86#question
## A	数字方阵
## B	小马过河
## C	真真假假
模拟
## D	虚虚实实
### 题意
问是否存在欧拉通路。
### 题解
首先判断是否是连通图，再判断奇度点是否有零个或者两个。

## E	是是非非
经典的尼姆博弈，要注意题目中的获胜条件恰好与尼姆博弈相反。
差点想成了单点操作，区间更新的数据结构2333
实际上维护每次的答案值，更新的时候只需要把对应的点删去再加上就可以了，而删去和加上都只要一次异或操作。
时间复杂度 $O(n)$

## F	黑黑白白
### 题意
给一棵树，两个人从根节点轮流走，不能走的人输，问是否先手必胜。
### 题解
若到一个点先手必胜，则记为 $1$ ，否则记为 $0$ 。
那么我们可以发现对于先手到的点来说，如果存在儿子值为 $1$ ，则当前点为 $1$ ，否则当前点为 $0$ .
对于后手到的点，如果存在儿子值为 $0$ ，则为 $0$ ，否则为 $1$ 。 
那么，我们只需要判断根是否为 $1$ ，就能知道是否先手必胜了。 
时间复杂度 $O(n)$
## G	文
结构体排序。
## H	武
给一个无向图，找出距离起点第 k 近的图。直接深搜就可以了。
## I	艺
## J	美
重排列一个数列，使得所有前后两个数的差值的绝对值之和最大。特别地，第一个的后一个是最后一个。
把数列排序，然后新数列把最小最大交叉放就行。
