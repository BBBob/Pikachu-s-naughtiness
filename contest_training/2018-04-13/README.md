# 牛客练习赛15 
题目地址：https://www.nowcoder.com/acm/contest/83#question
# 题解
## A 吉姆的运算式
根据题意，很容易知道就是求输入中的最后一个数字。  
那么直接按照读入优化的方式找到最后一个数就好了。  
时间复杂度 $O(n)$
## B 沃老师学生的成绩
很简单的结构体排序，唯一要注意的是写 `cmp` 函数的时候记得要用引用，否则加上复制字符串的时间就会超时。
## C 吉姆的奇思妙想
根据题意就是要找到一个最小的点 $i$ 使得 $a \times deg_i^2 \le b \times m$
因为 $deg_i$ 是升序的，所以我们对$i$进行二分。
注意 $deg_i^2$ 可能会爆 `long long` 所以两边要开根号。
我们再维护 $deg_i^2 \times freq_i $ 和 $freq_i$ 的前缀和，就能 $O(1)$ 算出答案。
前缀和时间复杂度 $O(n)$
二分时间复杂度 $O(\log n)$
总时间复杂度 $O(n)$
## D 队列重排

## E 无向图的弦

## F 最小生成树
