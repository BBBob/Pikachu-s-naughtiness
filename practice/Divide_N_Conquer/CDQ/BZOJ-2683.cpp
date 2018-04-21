#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x&(-x))

using namespace std;

const int maxn = 800000 +10;

struct Node{
    int x, y, A, no, belong, op;
}q[maxn], tq[maxn];
int ans[maxn];

bool operator <(Node a, Node b)
{
    if (a.x == b.x && a.y == b.y) return a.op < b.op;
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int N;
int tree[maxn];
void update(int x, int v)
{
    while(x <= N)
    {
        tree[x] += v;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

void solve(int l, int r)
{
    if (l == r) return;
    int mid = (l+r)>>1;
    for(int i = l ;i <= r; i++)
    {
        if (q[i].no <= mid && q[i].op == 1) update(q[i].y, q[i].A);
        else if (q[i].no > mid && q[i].op == 2)
        {
            if (q[i].A)
                ans[q[i].belong] += getsum(q[i].y) * q[i].A;
        }
    }

    for(int i = l; i <= r; i++)
        if (q[i].no <= mid && q[i].op == 1) update(q[i].y, -q[i].A);

    int l1 = l, l2 = mid + 1;
    for(int i = l; i <= r; i++)
    {
        if (q[i].no <= mid) tq[l1++] = q[i];
        else tq[l2++] = q[i];
    }
    for(int i = l; i <= r; i++)
        q[i] = tq[i];
    solve(l, mid);
    solve(mid+1, r);
}

//T(n)=2*T(n/2)+O(nlogn);

int main()
{
    int T = 0, op, x, y, x1, y1, A, tot = 0;
    scanf("%d", &N);
    while(scanf("%d", &op) && op!=3)
    {
        if (op == 1)
        {
            scanf("%d%d%d", &x, &y, &A);
            q[++tot].op = 1; q[tot] .x = x; q[tot] .y = y; q[tot] .A = A; q[tot] .no = tot;
        }
        else
        {
            scanf("%d%d%d%d", &x, &y, &x1, &y1);
            q[++tot].op = 2; q[tot] .x = x-1; q[tot] .y = y-1; q[tot] .A = 1; q[tot] .no = tot; q[tot] .belong = ++T;
            q[++tot].op = 2; q[tot] .x = x-1; q[tot] .y = y1; q[tot] .A = -1; q[tot] .no = tot; q[tot] .belong = T;
            q[++tot].op = 2; q[tot] .x = x1; q[tot] .y = y-1; q[tot] .A = -1; q[tot] .no = tot; q[tot] .belong = T;
            q[++tot].op = 2; q[tot] .x = x1; q[tot] .y = y1; q[tot] .A = 1; q[tot] .no = tot; q[tot] .belong = T;
        }
    }
    sort(q+1, q+1+tot);
    solve(1, tot);

    for(int i = 1; i <= T; i++)
        printf("%d\n", ans[i]);

    return 0;
}
