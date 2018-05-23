# treedp

## codeforces 274b Zero Tree
题目链接：http://codeforces.com/contest/274/problem/B
### 题意
有一颗树，每次选择一颗从一节点出发的子树加一或减一，问最少次数让所有节点值为0。
### 题解
<br/>树形dp</br>

<br/>设置 up[i] 与 down[i] 作为每个节点加或减的次数。</br>
<br/>转移方程为 up[u] = max(up[u],up[v])，down[u]同理。</br>
<br/>再判断对子树加减后是否让该节点值增加或减小，再加上相应的 up[i] 与 down[i] 的值。</br>
<br/>最后输出 up[1] + down[1] ，因为每次加减必从根节点出发。</br>


## hdu 1520 Anniversary party
题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1520
### 题意
有一颗树，可以选择一些节点，相邻的节点不能选择，问怎样选择的值最大。
### 题解
<br/>树形dp</br>

<br/>设置 dp[i][0] 为不选择 i 个节点而 dp[i][1] 为选择第 i 个节点。</br>
<br/>则有转移方程为 dp[u][0] += max(dp[v][0],dp[v][1]), dp[u][1] += dp[v][0];</br>
<br/>则 max(dp[root][0],dp[root][1]) 为答案。</br>


## hdu 3534 tree
题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=3534
### 题意
求树中的直径，并求直径的个数。
### 题解
<br/>树形dp</br>

<br/>dp[i][0] 表示为该节点下的最长距离。</br><br/>dp[i][1] 表示为该节点下的次长距离。（可以为0）</br><br/>dp[i][2] 表示为该节点下最长距离的个数。</br>
<br/>dp[i][3] 表示为该节点下次长距离的个数。<br/><br/>dp[i][4] 表示该节点下是否有两条以上的最长距离。</br><br/>dp[i][5] 表示该节点如果有两条以上最长距离可以组成多少答案的个数。</br><br/>先求出最长距离然后遍历每个节点的最长距离的个数相加。</br>


## bzoj 1040 骑士
题目链接：https://www.lydsy.com/JudgeOnline/problem.php?id=1040
### 题意
n个骑士，每个骑士有且仅有一个讨厌的人且具有一定的战斗力，问如何组成一个都不讨厌彼此的战斗力最高的骑士军团。
### 题解
<br/>树形dp（基环树）</br>

<br/> dp[i][0] 表示不选取该点，dp[i][1] 表示选取该点。</br>
<br/>因为有 n 条边，所以必定有环，且题目并没说联通，证明可能有多个环套树。</br>
<br/>如果把骑士与其讨厌的骑士相连，则成了相邻的节点不选求最大值。因为相邻的节点必不同时选取，则可以找到环任意取一条边，删掉这条边后取边的两端点分别做树形 dp 求不取这两点的最大值。多个联通块的最大值相加就是答案。</br>


## hdu 4044 GeoDefense 
题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=4044
### 题意
现有一个塔防游戏。有一棵树，每个点可以安装一个炮台（多种炮台选择，炮台有花费与伤害），从 1 节点到各个叶子节点路径上受到的伤害为该叶子节点的伤害，如何使最小伤害值的叶子节点的伤害值最大。
### 题解
<br/>树形dp（树上背包）</br>

<br/>定义 dp[i][j] 为到第 i 个点还剩 j 钱数可以造成的最大最小伤害。</br>
<br/>如果是叶子节点，则可以递推出该节点的 dp[i][j]。</br>
<br/>不是叶子节点，则先更新如果不在该点建塔的 dp[i][j] 。再更新在该点建塔的 dp[i][j]。</br>


## hdu 2196 Computer
题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2196
### 题意
求一棵树上各个点到其他点的最大距离
### 题解
<br/>树形dp</br>

<br/> dp[i][0] dp[i][1] dp[i][2] dp[i][3] 分别代表该点到其子树的最长距离以及次长距离，以及最长距离所通过的第一个子节点和该节点从父节点出发的最长距离。</br>
<br/>先通过一次 dfs 求出 0、1、2 再通过一次 dfs 从上到下更新 3 。（子节点 3 的最长距离可能是在其父节点的子树上或者父节点的 3 ）</br>


## bzoj 3242 快餐店
题目链接：https://www.lydsy.com/JudgeOnline/problem.php?id=3242
### 题意
给一个 n 个点 n 条边的联通图，求一个点到图上任一点的最大距离最小。
### 题解
<br/>树形dp（基环树）</br>

<br/> 因为有 n 条边可知该图有且仅有一个环，并可知如果在树上此问题的解为树的直径除 2 。</br>
<br/>可以考虑找到环，并把环上的点从 1 到 cnt 编号。每次拆掉环上的一条边求拆掉后树的直径，拆掉的最小的树的直径就是我们要找的直径。但考虑到最大距离可能在环上某点的子树上，所以还要求环上每个点的子树上的直径的最大值，并用这个最大值与上一步求的最小值取一个 max 就是答案。</br>
<br/>但如果每拆一条边求一次树直径，复杂度的平方的。我们可以考虑递推出答案。</br>
<br/>我们先从 1 到 cnt 遍历环上的点。u[i] 为从 1 到 i 点中所有点的最大深度加这点到 1 点的距离的最大值；v[i]为从 1 点到 i 点中两个点的距离加两点深度和的最大值。再从 cnt 到 1 遍历一次同理得到 u1[i] 和 v1[i]。</br>
<br/>那么答案就是所有的 v[i] 与 v1[i+1] 与 u[i] + u1[i+1] + dis[1 to cnt] 的最大值与子树直径最大值取 max 。</br>