isap

```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 10000;
const int MAXM = 10000;
const int inf = 0x3f3f3f3f;
 
struct ISAP{
    int s, t, n;
 
    struct node{
        int v, c;
        node *next, *back;
    } Edge[4*MAXM], *adj[MAXN+10], *ecnt;
    int d[MAXN+10], num[MAXN+10];
 
    ISAP(){
        memset(adj, 0, sizeof adj);
        ecnt = Edge;
    }
 
    inline void addedge(int u, int v, int c)
    {
        node* p = ++ecnt;
        p->v=v; p->c=c; p->next=adj[u]; adj[u]=p; p->back=p+1;
        p = ++ecnt;
        p->v=u; p->c=0; p->next=adj[v]; adj[v]=p; p->back=p-1;
    }
 
    int aug(int u, int augco)
    {
        int augc = 0;
        int mind = n-1;
        if (u == t) return augco;
 
        for (node* p = adj[u]; p ; p = p->next)
        {
            int v = p->v, c = p->c;
            if (c > 0)
            {
                if (d[u] == d[v] + 1)
                {
                    int delta = min(c, augco - augc);
                    delta = aug(v, delta);
                    augc += delta;
                    p->c -= delta;
                    p->back->c += delta;
                    if (augco == augc) return augc;
                    if (d[s] >= n) return augc;
                }
                mind = min(mind, d[v]);
            }
        }
 
        if (!augc)
        {
            num[d[u]]--;
            if (num[d[u]]==0) d[s]=n;
            d[u] = mind + 1;
            num[d[u]]++;
        }
        return augc;
    }
 
    int Maxflow(int ss, int tt, int nn)
    {
        s = ss; t = tt; n = nn;
        int f = 0;
        for (int i=1; i<=n; i++) d[i] = num[i] = 0;
 
        while(d[s] < n)
        {
            f += aug(s, inf);
        }
        return f;
    }
} sp;
 
int m, n;
 
void read()
{
    scanf("%d%d", &m, &n);
    for (int i=1; i<=m; i++)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        sp.addedge(u, v, c);
    }
}
 
int main()
{
    read();
    int ans = sp.Maxflow(1, n, n);
    printf("%d", ans);
}
```



